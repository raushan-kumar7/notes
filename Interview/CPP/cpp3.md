# C++ Theoretical Interview Questions & Answers for TCS Digital

## 1. Basic C++ Concepts

### Q1: What is the difference between C and C++?
**Answer:**
- **C** is a procedural programming language, while **C++** is an object-oriented programming language
- C++ supports classes and objects, C does not
- C++ has function overloading, C does not
- C++ supports references, C only has pointers
- C++ has better type checking than C
- C++ supports inline functions, C does not
- C uses `printf/scanf` for I/O, C++ uses `cin/cout`

### Q2: What are the main features of C++?
**Answer:**
- **Object-Oriented Programming**: Classes, objects, inheritance, polymorphism
- **Function Overloading**: Multiple functions with same name but different parameters
- **Operator Overloading**: Redefining operators for user-defined types
- **Templates**: Generic programming support
- **Exception Handling**: try-catch blocks for error handling
- **STL**: Standard Template Library with containers and algorithms
- **References**: Alternative to pointers for aliasing variables

### Q3: What is a class and object?
**Answer:**
- **Class**: A blueprint or template that defines the structure and behavior of objects. It contains data members (variables) and member functions (methods)
- **Object**: An instance of a class. It's a real-world entity that has state (data) and behavior (functions)
- Example: If `Car` is a class, then `myCar` is an object of class `Car`

## 2. Object-Oriented Programming

### Q4: Explain the four pillars of OOP.
**Answer:**
1. **Encapsulation**: Bundling data and methods together in a class and hiding internal details using access specifiers (private, protected, public)

2. **Inheritance**: Creating new classes based on existing classes. Child class inherits properties and methods from parent class

3. **Polymorphism**: Same interface with different implementations. Achieved through function overloading, operator overloading, and virtual functions

4. **Abstraction**: Hiding complex implementation details and showing only essential features. Achieved through abstract classes and interfaces

### Q5: What are access specifiers in C++?
**Answer:**
- **Private**: Members are accessible only within the same class
- **Protected**: Members are accessible within the class and its derived classes
- **Public**: Members are accessible from anywhere in the program

### Q6: What is inheritance? What are its types?
**Answer:**
Inheritance allows a class to inherit properties and methods from another class.

**Types of Inheritance:**
1. **Single Inheritance**: One child class inherits from one parent class
2. **Multiple Inheritance**: One child class inherits from multiple parent classes
3. **Multilevel Inheritance**: Chain of inheritance (A→B→C)
4. **Hierarchical Inheritance**: Multiple child classes inherit from one parent class
5. **Hybrid Inheritance**: Combination of multiple inheritance types

### Q7: What is polymorphism? Explain its types.
**Answer:**
Polymorphism means "many forms" - same interface with different implementations.

**Types:**
1. **Compile-time Polymorphism (Static)**:
   - Function Overloading
   - Operator Overloading

2. **Runtime Polymorphism (Dynamic)**:
   - Virtual Functions
   - Function Overriding

## 3. Functions and Memory Management

### Q8: What is function overloading?
**Answer:**
Function overloading allows multiple functions with the same name but different parameters (number, type, or order). The compiler determines which function to call based on the arguments passed.

Example:
```cpp
int add(int a, int b);
float add(float a, float b);
int add(int a, int b, int c);
```

### Q9: What is the difference between call by value, call by reference, and call by pointer?
**Answer:**
- **Call by Value**: Copy of actual parameter is passed. Changes don't affect original variable
- **Call by Reference**: Alias of actual parameter is passed. Changes affect original variable
- **Call by Pointer**: Address of actual parameter is passed. Changes affect original variable through dereferencing

### Q10: What is a constructor and destructor?
**Answer:**
- **Constructor**: Special member function called automatically when an object is created. Used for initialization
  - Same name as class
  - No return type
  - Can be overloaded

- **Destructor**: Special member function called automatically when an object is destroyed. Used for cleanup
  - Same name as class with ~ prefix
  - No return type or parameters
  - Cannot be overloaded

### Q11: What are the types of constructors?
**Answer:**
1. **Default Constructor**: No parameters
2. **Parameterized Constructor**: Takes parameters for initialization
3. **Copy Constructor**: Creates object as copy of another object
4. **Move Constructor**: Transfers resources from temporary object

## 4. Advanced Concepts

### Q12: What is a virtual function?
**Answer:**
A virtual function is a member function declared with `virtual` keyword in base class. It enables runtime polymorphism by allowing derived classes to override the function. The correct function is called based on the object type, not pointer type.

### Q13: What is a pure virtual function?
**Answer:**
A pure virtual function is declared with `= 0` and has no implementation in the base class. Classes containing pure virtual functions become abstract classes and cannot be instantiated.

### Q14: What is the difference between virtual function and pure virtual function?
**Answer:**
- **Virtual Function**: Has implementation in base class, can be overridden in derived class
- **Pure Virtual Function**: No implementation in base class, must be implemented in derived class

### Q15: What is an abstract class?
**Answer:**
An abstract class contains at least one pure virtual function. It cannot be instantiated but can be used as a base class. Derived classes must implement all pure virtual functions to become concrete classes.

### Q16: What is method overriding?
**Answer:**
Method overriding occurs when a derived class provides a specific implementation of a method that is already defined in its base class. The base class method should be virtual for proper overriding.

## 5. Memory and Pointers

### Q17: What is the difference between stack and heap memory?
**Answer:**
**Stack Memory:**
- Stores local variables and function parameters
- Automatically managed
- Faster access
- Limited size
- LIFO (Last In, First Out)

**Heap Memory:**
- Stores dynamically allocated memory
- Manually managed (new/delete)
- Slower access
- Larger size available
- Random access

### Q18: What is a memory leak?
**Answer:**
Memory leak occurs when dynamically allocated memory is not deallocated, causing the program to consume more memory over time. This happens when `new` is not matched with corresponding `delete`.

### Q19: What is the difference between new/delete and malloc/free?
**Answer:**
- **new/delete**: C++ operators, call constructors/destructors, type-safe, return typed pointer
- **malloc/free**: C library functions, no constructor/destructor calls, require type casting, return void pointer

### Q20: What is a dangling pointer?
**Answer:**
A dangling pointer points to memory that has been deallocated or is no longer valid. Accessing such pointers leads to undefined behavior.

## 6. Templates and STL

### Q21: What are templates in C++?
**Answer:**
Templates enable generic programming by allowing functions and classes to work with different data types without rewriting code. They are resolved at compile time.

**Types:**
- Function Templates
- Class Templates

### Q22: What is STL?
**Answer:**
Standard Template Library (STL) is a collection of template classes and functions that provide common data structures and algorithms.

**Components:**
- **Containers**: vector, list, map, set, etc.
- **Algorithms**: sort, find, reverse, etc.
- **Iterators**: Objects that point to elements in containers

### Q23: What is the difference between vector and array?
**Answer:**
- **Array**: Fixed size, no built-in functions, stored in stack/heap
- **Vector**: Dynamic size, rich set of member functions, automatically manages memory

## 7. Exception Handling

### Q24: What is exception handling in C++?
**Answer:**
Exception handling is a mechanism to handle runtime errors gracefully using try-catch blocks.

**Keywords:**
- **try**: Block containing code that might throw exception
- **catch**: Block that handles specific exceptions
- **throw**: Keyword to throw an exception

### Q25: What is the difference between compile-time and runtime errors?
**Answer:**
- **Compile-time errors**: Syntax errors, type mismatches, detected by compiler
- **Runtime errors**: Logical errors, division by zero, array out of bounds, occur during execution

## 8. File Handling and I/O

### Q26: What are the different file opening modes in C++?
**Answer:**
- **ios::in**: Open for reading
- **ios::out**: Open for writing
- **ios::app**: Append to end of file
- **ios::binary**: Binary mode
- **ios::trunc**: Truncate file to zero length

### Q27: What is the difference between cin/cout and scanf/printf?
**Answer:**
- **cin/cout**: C++ stream-based I/O, type-safe, object-oriented
- **scanf/printf**: C library functions, format specifiers required, faster but less safe

## 9. Miscellaneous

### Q28: What is the scope resolution operator (::)?
**Answer:**
The scope resolution operator (::) is used to:
- Access global variables when local variable has same name
- Access static members of a class
- Define member functions outside class definition
- Access members of a namespace

### Q29: What is the difference between struct and class in C++?
**Answer:**
- **struct**: Members are public by default
- **class**: Members are private by default
- Both support constructors, destructors, inheritance, and member functions

### Q30: What is a friend function?
**Answer:**
A friend function is a non-member function that has access to private and protected members of a class. It's declared inside the class with the `friend` keyword but defined outside the class.

### Q31: What is static keyword in C++?
**Answer:**
**Static** has different meanings in different contexts:
- **Static variables**: Retain value between function calls, initialized once
- **Static member variables**: Shared by all objects of the class
- **Static member functions**: Can be called without creating object, can only access static members

### Q32: What is const keyword in C++?
**Answer:**
**const** makes variables or objects immutable:
- **const variables**: Cannot be modified after initialization
- **const member functions**: Cannot modify object state
- **const parameters**: Cannot be modified inside function

### Q33: What is inline function?
**Answer:**
An inline function is expanded at the point of call instead of being called. It's a request to the compiler for better performance by avoiding function call overhead. Used for small, frequently called functions.

### Q34: What is namespace in C++?
**Answer:**
Namespace is a declarative region that provides scope to identifiers. It helps avoid naming conflicts by grouping related functions, classes, and variables together.

Example: `std` namespace contains standard library components.

### Q35: What is the difference between pass by reference and pass by pointer?
**Answer:**
- **Pass by reference**: 
  - Cannot be null
  - Cannot be reassigned
  - Cleaner syntax
  - Automatically dereferenced

- **Pass by pointer**:
  - Can be null
  - Can be reassigned
  - Requires explicit dereferencing
  - More flexible but potentially unsafe

## Quick Tips for Interview:
1. Always explain with examples when possible
2. Mention practical use cases
3. Be clear about advantages and disadvantages
4. Know the syntax and be ready to write code
5. Understand memory implications of your answers