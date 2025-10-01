# Diagrammes de Séquences - Système de Gestion de Bibliothèque

## 1. Authentification et Démarrage de Session

```mermaid
sequenceDiagram
    participant U as Utilisateur
    participant S as Session
    participant L as Library
    
    U->>S: run()
    S->>U: Afficher choix mode (utilisateur/admin)
    U->>S: Choisir mode (1 ou 2)
    
    alt Mode Administrateur
        S->>U: Demander mot de passe
        U->>S: Saisir mot de passe
        alt Mot de passe correct
            S->>S: isAdmin = true
            S->>U: Authentification réussie
        else Mot de passe incorrect
            S->>S: isAdmin = false
            S->>U: Basculement mode utilisateur
        end
    end
    
    loop Session active
        alt Mode Admin
            S->>S: runAdminMenu()
        else Mode Utilisateur
            S->>S: runUserMenu()
        end
    end
    
    S->>S: bye()
    S->>U: Fin de session
```

## 2. Recherche de Ressources

```mermaid
sequenceDiagram
    participant U as Utilisateur
    participant S as Session
    participant L as Library
    participant R as Resource
    
    U->>S: Choisir option "Rechercher"
    S->>U: Demander requête de recherche
    U->>S: Saisir requête (titre/auteur)
    S->>S: search(query)
    S->>L: getResources()
    L->>S: vector<Resource*>
    
    loop Pour chaque ressource
        S->>R: getTitle() + getAuthor()
        R->>S: string
        S->>S: Vérifier correspondance avec query
        alt Correspondance trouvée
            S->>S: Ajouter à results
        end
    end
    
    S->>U: Afficher résultats de recherche
    loop Pour chaque résultat
        S->>R: printDetails()
        R->>U: Afficher détails
    end
```

## 3. Emprunt de Ressource (Mode Utilisateur)

```mermaid
sequenceDiagram
    participant U as Utilisateur
    participant S as Session
    participant L as Library
    participant User as User
    participant R as Resource
    
    U->>S: Choisir "Emprunter ressource"
    S->>S: borrowResourceMenu()
    S->>U: Demander ID utilisateur
    U->>S: Saisir userId
    S->>L: findUser(userId)
    L->>S: User* ou nullptr
    
    alt Utilisateur trouvé
        S->>U: Demander ID ressource
        U->>S: Saisir resourceId
        S->>L: findResource(resourceId)
        L->>S: Resource* ou nullptr
        
        alt Ressource trouvée
            S->>User: borrowResource(resource)
            User->>R: isAvailable()
            R->>User: bool
            
            alt Ressource disponible
                User->>R: setBorrowedBy(userId)
                R->>User: Confirmation
                User->>S: true
                S->>U: "Ressource empruntée avec succès!"
            else Ressource non disponible
                User->>S: false
                S->>U: "Échec de l'emprunt"
            end
        else Ressource non trouvée
            S->>U: "Ressource non trouvée"
        end
    else Utilisateur non trouvé
        S->>U: "Utilisateur non trouvé"
    end
```

## 4. Retour de Ressource

```mermaid
sequenceDiagram
    participant U as Utilisateur
    participant S as Session
    participant L as Library
    participant User as User
    participant R as Resource
    
    U->>S: Choisir "Rendre ressource"
    S->>S: returnResourceMenu()
    S->>U: Demander ID utilisateur
    U->>S: Saisir userId
    S->>L: findUser(userId)
    L->>S: User* ou nullptr
    
    alt Utilisateur trouvé
        S->>U: Demander ID ressource
        U->>S: Saisir resourceId
        S->>L: findResource(resourceId)
        L->>S: Resource* ou nullptr
        
        alt Ressource trouvée
            S->>User: returnResource(resource)
            User->>R: getBorrowedBy()
            R->>User: userId emprunteur
            
            alt Utilisateur est l'emprunteur
                User->>R: setBorrowedBy(-1)
                R->>User: Confirmation
                User->>S: true
                S->>U: "Ressource rendue avec succès!"
            else Utilisateur n'est pas l'emprunteur
                User->>S: false
                S->>U: "Échec de la restitution"
            end
        else Ressource non trouvée
            S->>U: "Ressource non trouvée"
        end
    else Utilisateur non trouvé
        S->>U: "Utilisateur non trouvé"
    end
```

## 5. Ajout de Ressource (Mode Admin)

```mermaid
sequenceDiagram
    participant A as Admin
    participant S as Session
    participant L as Library
    participant R as Resource
    
    A->>S: Choisir "Ajouter ressource"
    S->>S: addResourceMenu()
    S->>A: Afficher types de ressources
    A->>S: Choisir type (1-6)
    S->>A: Demander informations communes
    A->>S: Saisir ID, titre, auteur
    
    alt Type = Book
        S->>A: Demander résumé, pages, collection
        A->>S: Saisir informations spécifiques
        S->>S: new Book(id, title, author, summary, pages, collection)
    else Type = CD
        S->>A: Demander durée, pistes, compagnie
        A->>S: Saisir informations spécifiques
        S->>S: new CD(id, title, author, duration, tracks, company)
    else Type = DVD
        S->>A: Demander compagnie, durée
        A->>S: Saisir informations spécifiques
        S->>S: new DVD(id, title, author, company, duration, chapters)
    else Type = Digital
        S->>A: Demander format, taille, URL
        A->>S: Saisir informations spécifiques
        S->>S: new Digital(id, title, author, format, size, url)
    end
    
    S->>L: addResource(newResource)
    L->>L: resources.push_back(resource)
    L->>S: Confirmation
    S->>A: "Ressource ajoutée avec succès!"
```

## 6. Ajout d'Utilisateur (Mode Admin)

```mermaid
sequenceDiagram
    participant A as Admin
    participant S as Session
    participant L as Library
    participant U as User
    
    A->>S: Choisir "Ajouter utilisateur"
    S->>S: addUserMenu()
    S->>A: Afficher types d'utilisateurs
    A->>S: Choisir type (Client/Admin)
    S->>A: Demander ID et email
    A->>S: Saisir informations communes
    S->>A: Demander prénom et nom
    A->>S: Saisir prénom et nom
    
    alt Type = Client
        S->>S: new Client(id, firstName, lastName, email)
    else Type = Admin
        S->>S: new Admin(id, firstName, lastName, email)
    end
    
    S->>L: addUser(newUser)
    L->>L: users.push_back(user)
    L->>S: Confirmation
    S->>A: "Utilisateur ajouté avec succès!"
```

## 7. Consultation des Détails d'une Ressource

```mermaid
sequenceDiagram
    participant U as Utilisateur
    participant S as Session
    participant L as Library
    participant R as Resource
    
    U->>S: Choisir "Afficher détails ressource"
    S->>U: Demander ID ressource
    U->>S: Saisir resourceId
    S->>S: printDetails(resourceId)
    S->>L: findResource(resourceId)
    L->>S: Resource* ou nullptr
    
    alt Ressource trouvée
        S->>R: printDetails()
        R->>U: Afficher détails complets
    else Ressource non trouvée
        S->>U: "Aucune ressource trouvée avec l'ID"
    end
```

## 8. Sauvegarde/Chargement de Données

```mermaid
sequenceDiagram
    participant App as Application
    participant FM as FileManager
    participant L as Library
    participant F as Fichier
    
    App->>FM: loadUsers("data/utilisateurs.txt")
    FM->>F: Lire fichier utilisateurs
    F->>FM: Données utilisateurs
    loop Pour chaque ligne
        FM->>FM: Parser données utilisateur
        FM->>FM: new User(type approprié)
    end
    FM->>App: vector<User*>
    
    App->>FM: loadResources("data/ressources.txt")
    FM->>F: Lire fichier ressources
    F->>FM: Données ressources
    loop Pour chaque ligne
        FM->>FM: Parser données ressource
        FM->>FM: new Resource(type approprié)
    end
    FM->>App: vector<Resource*>
    
    App->>L: addUser() / addResource()
    L->>L: Ajouter aux collections
    
    Note over App,F: À la fin de session
    App->>FM: saveUsers("data/utilisateurs.txt", users)
    FM->>F: Écrire données utilisateurs
    App->>FM: saveResources("data/ressources.txt", resources)
    FM->>F: Écrire données ressources
```

## Cas d'Utilisation Identifiés

### Utilisateur Standard (Client)
1. **Authentification** - Se connecter au système
2. **Recherche** - Rechercher des ressources par titre/auteur
3. **Consultation** - Voir les détails d'une ressource
4. **Emprunt** - Emprunter une ressource disponible
5. **Retour** - Rendre une ressource empruntée
6. **Visualisation** - Voir toutes les ressources disponibles

### Administrateur
7. **Gestion des ressources** - Ajouter/supprimer des ressources
8. **Gestion des utilisateurs** - Ajouter/supprimer des utilisateurs
9. **Consultation avancée** - Voir toutes les informations de la bibliothèque
10. **Sauvegarde** - Sauvegarder les données (implicite via FileManager)

### Système
11. **Persistance** - Charger/sauvegarder les données depuis/vers les fichiers
12. **Validation** - Vérifier la disponibilité des ressources
13. **Gestion d'état** - Suivre les emprunts en cours