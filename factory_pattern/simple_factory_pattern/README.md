# Factory Design Pattern Explained

The Factory Design Pattern is one of the most commonly used design patterns in object-oriented programming. It belongs to the creational category of design patterns and provides a mechanism to create objects without specifying the exact class that will be instantiated.

## Components:

### 1. Abstract Product:

The abstract product is an abstract class or interface that defines the contract or methods that concrete products should implement. It represents the general set of behaviors that the concrete products must support.

### 2. Concrete Product:

Derived from the abstract product, the concrete product is an actual implementation of the product interface. Multiple concrete products can be created by extending the abstract product, each providing a different implementation.

### 3. Abstract Factory:

The abstract factory is an interface or abstract class that declares the creation methods for a set of products. It typically contains a method for each product that it can produce.

### 4. Concrete Factory:

Derived from the abstract factory, the concrete factory is responsible for creating and returning instances of concrete products. Each concrete factory corresponds to a specific product family and creates products of that family.

## Flow:

1. The client code requests an object by calling a creation method on the factory, rather than invoking a constructor directly.
2. The factory instantiates the appropriate concrete product class and returns it as the abstract product class type.

## Benefits:

- **Decoupling**: The Factory Design Pattern decouples the client code (which needs an object) from the code that instantiates the actual object. This promotes loose coupling in the system.
- **Flexibility**: Since the creation of objects is centralized, introducing new products or changing existing products becomes easier.
- **Consistency**: Factories ensure that the created objects are consistent and adhere to a specific set of behaviors defined by the abstract product.

## Key Concepts:

### Abstract vs. Concrete:

- **Abstract**: In object-oriented design, "abstract" refers to a concept that is not concrete or specific. Abstract classes or interfaces define the structure but don't provide a complete implementation. They serve as blueprints for concrete classes.
- **Concrete**: Concrete classes provide a specific implementation of abstract classes or interfaces. They are instantiable and offer a tangible realization of abstract concepts.

### Factory vs. Product:

- **Factory**: The factory's role is to create and return objects. The type of object the factory creates is determined by the concrete factory's implementation.
- **Product**: The product is the actual object returned by the factory. It adheres to an interface (or abstract class) but has its specific implementation.

## Use Cases:

The Factory Design Pattern is particularly useful in scenarios where:

- The system needs to remain independent of the creation and composition of new objects.
- Classes delegate the responsibility for their instances to a sibling/related class.
- You want to encapsulate the knowledge of which class gets created.

# Factory Design Pattern: Calculator Project

This project demonstrates the use of the Factory Design Pattern to create a simple calculator application. The calculator supports basic mathematical operations like addition, subtraction, multiplication, and division. Additionally, the calculator maintains a session-based history of calculations, allowing users to view previous results.

## Structure:

- **Operation.h**: Contains the abstract product declaration.
- **BasicOperations.h**: Houses the concrete implementations for basic mathematical operations (`Addition`, `Subtraction`, `Multiplication`, and `Division`).
- **OperationFactory.h & OperationFactory.cpp**: Define the factory that produces operation objects.
- **Calculator.h**: Manages calculations and the session-based history.

## Design Principles:

- **Factory Design Pattern**: The Factory Design Pattern abstracts the creation of objects. This abstraction ensures that the code remains extendable and easy to maintain.
- **Separation of Concerns**: By segregating the operations, the factory, and the main logic into separate files, we ensure each part of the code has a distinct responsibility.

## Using the Calculator:

1. Perform calculations using the `calculate` method.
2. After calculations, retrieve the session's history by calling `getHistory`.
3. Clear the session's history using `clearHistory`.

## Compilation & Execution:

Refer to the [Running the Code](#running-the-code) section for steps on compiling and executing the project.

## FAQs: C++ Syntax and Concepts

### 1. What is the Factory Design Pattern?

The Factory Design Pattern is a creational pattern that provides an interface for creating objects but allows subclasses to alter the type of objects that will be created. In our context, we used it to abstract the creation of different mathematical operation objects.

### 2. Why use `Operation*` and what does it mean?

`Operation*` is a pointer to an object of type `Operation`. In C++, pointers are used to store the memory address of an object. In our design, the Factory returns a pointer to a dynamically allocated operation object, allowing us to work with polymorphic behavior and then properly manage the object's lifetime.

### 3. What is the role of `delete op;`?

The line `delete op;` is used to deallocate memory that was dynamically allocated using the `new` operator. In C++, developers are responsible for memory management, and every object created with `new` must eventually be deleted using `delete` to prevent memory leaks.

### 4. How do header files work in C++?

Header files in C++ provide a clear separation of interface (declaration) from implementation. They make the code more modular, facilitate code reusability, and improve compile times. In our design:

- **Operation.h** contains the abstract operation declaration.
- **BasicOperations.h** groups the basic mathematical operations.
- **OperationFactory.h** declares the factory for creating operation objects.
- **Calculator.h** declares the main calculator functionality.

### 5. What does `static Operation* createOperation(const std::string& operatorSymbol);` signify?

This declares a static member function named `createOperation` within the `OperationFactory` class. Being static means this function is associated with the class itself, not any specific instance. It returns a pointer to an `Operation` object and takes a string as its argument, representing the mathematical operator symbol.

### 6. Can we combine declarations and implementations in C++?

Yes, for smaller and self-contained classes, both declarations and implementations can be combined in a header file. However, it's a common practice in larger projects to separate declarations (in `.h` files) from implementations (in `.cpp` files) for better code management and improved compile times.

## History Enhancement:

The calculator maintains a session-based history of calculations. Features include:

- **`addToHistory`**: Adds a calculation to the history.
- **`getHistory`**: Retrieves the current session's history.
- **`clearHistory`**: Clears the current session's history.

## Future Enhancements:

- **Expand Operations**: New mathematical operations can be added by extending the `Operation` class.
- **Persistent History**: Store the history in a persistent storage medium for retrieval across sessions.
- **Advanced History Features**: Searching, undoing calculations, or tagging specific calculations.
