# Diagramme des Classes - Système de Gestion de Bibliothèque

```mermaid
classDiagram
    %% Hiérarchie des utilisateurs
    class User {
        #int idUser
        #string firstName
        #string lastName
        #string emailAddress
        +virtual printDetails()
        +virtual ~User()
    }

    class Admin {
        +printDetails() override
    }

    class Client {
        +printDetails() override
    }

    %% Hiérarchie des ressources
    class Resource {
        #int idResource
        #string title
        #string author
        #int borrowedBy
        +virtual printDetails()
        +setTitle(string)
        +setAuthor(string)
        +setIdResource(int)
        +setBorrowedBy(int)
        +getTitle() string
        +getAuthor() string
        +getIdResource() int
        +getBorrowedBy() int
        +isAvailable() bool
        +borrowResource(int) bool
        +returnResource(int) bool
        +virtual ~Resource()
    }

    class Book {
        -string summary
        -int pagesNumber
        -string collection
        +printDetails() override
    }

    class Reviews {
        -string editor
        -int nbArticles
        -vector~string~ articles
        +printDetails() override
    }

    class Video {
        #string productionCompany
        #float duration
        +printDetails() override
    }

    class DVD {
        -int chapterNumber
        +printDetails() override
    }

    class VHS {
        +printDetails() override
    }

    class CD {
        -double duration
        -int tracksNumber
        -string productionCompany
        +printDetails() override
    }

    class Digital {
        -string type
        -double size
        -string path
        +printDetails() override
    }

    %% Classes de gestion
    class Library {
        -vector~User*~ users
        -vector~Resource*~ resources
        +addUser(User*)
        +removeUser(int)
        +findUser(int) User*
        +showAllUsers()
        +addResource(Resource*)
        +removeResource(int)
        +findResource(int) Resource*
        +showAllResources()
        +showLibraryInfo()
        +getUsers() vector~User*~
        +getResources() vector~Resource*~
        +borrowResource(int, int) bool
        +returnResource(int, int) bool
        +showBorrowedResources(int)
        +showAvailableResources()
    }

    class Session {
        -Library* library
        -vector~Resource*~ results
        +run()
        +search(string) vector~Resource*~
        +runUserMenu() bool
        +runAdminMenu() bool
        +addResourceMenu()
        +addUserMenu()
    }

    class FileManager {
        +loadUsers(string) vector~User*~
        +saveUsers(string, vector~User*~)
        +loadResources(string) vector~Resource*~
        +saveResources(string, vector~Resource*~)
    }

    %% Relations d'héritage
    User <|-- Admin
    User <|-- Client
    Resource <|-- Book
    Resource <|-- Video
    Resource <|-- CD
    Resource <|-- Digital
    Book <|-- Reviews
    Video <|-- DVD
    Video <|-- VHS

    %% Relations d'association/composition
    Library o-- User : contient *
    Library o-- Resource : contient *
    Client --> Resource : emprunte *
    Resource --> User : emprunté par
    Session --> Library : utilise
    Session --> Resource : recherche
    FileManager ..> User : crée/sauvegarde
    FileManager ..> Resource : crée/sauvegarde
```

## Structure du Projet

### Hiérarchie des Utilisateurs
- **User** (classe abstraite)
  - **Admin** : Utilisateur administrateur
  - **Client** : Utilisateur standard

### Hiérarchie des Ressources
- **Resource** (classe abstraite)
  - **Book** : Livres avec résumé, pages, collection
    - **Reviews** : Revues avec éditeur et articles
  - **Video** : Vidéos avec société de production et durée
    - **DVD** : DVDs avec nombre de chapitres
    - **VHS** : Cassettes VHS
  - **CD** : CDs audio avec durée et nombre de pistes
  - **Digital** : Ressources numériques avec type, taille et chemin

### Classes de Gestion
- **Library** : Gestionnaire principal des utilisateurs et ressources
- **Session** : Interface utilisateur et logique de session
- **FileManager** : Gestion de la persistance des données

### Gestion des Emprunts
- **Resource** : Contient un attribut `borrowedBy` pour traquer l'utilisateur emprunteur
- **Library** : Fournit des méthodes pour emprunter et retourner des ressources
- **Client** : Peut emprunter plusieurs ressources simultanément
- **Relations** : Association entre Client et Resource via les emprunts

### Fonctionnalités d'Emprunt
- ✅ **Emprunt** : `borrowResource(userId, resourceId)`
- ✅ **Retour** : `returnResource(userId, resourceId)`
- ✅ **Disponibilité** : `isAvailable()` pour vérifier si une ressource est libre
- ✅ **Suivi** : Chaque ressource garde l'ID de l'utilisateur qui l'a empruntée
- ✅ **Affichage** : Ressources empruntées par utilisateur et ressources disponibles

### Caractéristiques du Design
- ✅ **Polymorphisme** : Méthodes virtuelles `printDetails()`
- ✅ **Encapsulation** : Membres protected/private
- ✅ **Héritage** : Hiérarchies logiques
- ✅ **Composition** : Library contient des collections de pointeurs
- ✅ **Gestion d'état** : Suivi des emprunts via `borrowedBy`