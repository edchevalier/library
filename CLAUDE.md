# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ library management system using object-oriented programming principles. The project implements a class hierarchy for managing library resources and users with polymorphism.

## Build and Development Commands

Since this is a simple C++ project without a build system, compile using:

```bash
# Compile the main program
g++ -std=c++11 -I. -IRessources *.cpp Ressources/*.cpp -o library

# Run the program
./library
```

For individual file compilation during development:
```bash
# Compile specific classes for testing
g++ -std=c++11 -c -I. -IRessources filename.cpp
```

## Architecture

### Class Hierarchies

**User Hierarchy:**
- `User` (base class) - Common user attributes and virtual methods
- `Admin` (derived) - Administrative users
- `Client` (derived) - Library clients

**Resource Hierarchy:**
- `Resource` (base class) - Common resource attributes (id, title, author)
- `Book` (derived) - Books with summary, pages, and collection
- `Video` (derived) - Videos with production company and duration
- `Reviews` (derived from Book) - Review publications with editor and articles
- Other media types: `CD`, `DVD`, `VHS`, `Digital`

### File Organization

- Root directory: User classes (`User.hpp/cpp`, `Admin.hpp/cpp`, `Client.hpp/cpp`) and `main.cpp`
- `Ressources/` directory: All resource-related classes
- `AllClasses.hpp`: Convenience header for including main classes
- `Session.cpp`: Empty file for future session management

### Key Design Patterns

- **Inheritance**: Both User and Resource hierarchies use public inheritance
- **Polymorphism**: Virtual `printDetails()` methods in base classes allow runtime method resolution
- **Encapsulation**: Protected members in base classes, private members in derived classes

### Development Notes

- All classes follow consistent naming conventions with PascalCase
- Headers use `#pragma once` for include guards
- Virtual methods are properly overridden with `override` keyword
- The project uses French comments and variable names in some places
- `main.cpp` contains comprehensive tests demonstrating polymorphism and all class functionalities

### Code Structure Patterns

- Each class has its own `.hpp` and `.cpp` files
- Constructors include both default and parameterized versions
- Consistent getter/setter patterns across all classes
- Base classes use protected members to allow derived class access
- Virtual destructors should be added to base classes for proper cleanup