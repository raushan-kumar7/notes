# C++ Theoretical Interview Questions & Answers with Examples for TCS Digital

## 1. Basic C++ Concepts

### Q1: What is the difference between C and C++?
**Answer:**
- **C** is a procedural programming language, while **C++** is an object-oriented programming language
- C++ supports classes and objects, C does not
- C++ has function overloading, C does not
- C++ supports references, C only has pointers

**Example:**
```cpp
// C Style (Procedural)
#include <stdio.h>
struct Rectangle {
    int length, width;
};
int area(struct Rectangle r) {
    return r.length * r.width;
}

// C++ Style (Object-Oriented)
#include <iostream>
class Rectangle {
private:
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    int area() { return length * width; }
    void display() { 
        std::cout << "Area: " << area() << std::endl; 
    }
};
```

### Q2: What is a class and object?
**Answer:**
- **Class**: A blueprint or template that defines the structure and behavior of objects
- **Object**: An instance of a class with actual values

**Example:**
```cpp
// Class definition (Blueprint)
class Car {
private:
    string brand;
    string model;
    int year;
    
public:
    // Constructor
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }
    
    // Method
    void displayInfo() {
        cout << brand << " " << model << " (" << year << ")" << endl;
    }
    
    void startEngine() {
        cout << "Engine started!" << endl;
    }
};

int main() {
    // Objects (Instances)
    Car car1("Toyota", "Camry", 2022);    // Object 1
    Car car2("Honda", "Civic", 2021);     // Object 2
    
    car1.displayInfo();  // Toyota Camry (2022)
    car2.displayInfo();  // Honda Civic (2021)
    
    return 0;
}
```

## 2. Object-Oriented Programming

### Q3: Explain the four pillars of OOP with examples.

#### 1. Encapsulation
**Definition**: Bundling data and methods together and hiding internal details.

**Example:**
```cpp
class BankAccount {
private:
    double balance;        // Hidden data
    string accountNumber;  // Hidden data
    
public:
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    
    // Public interface to access private data
    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }
    
    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
    
    double getBalance() const {
        return balance;  // Controlled access
    }
};
```

#### 2. Inheritance
**Definition**: Creating new classes based on existing classes.

**Example:**
```cpp
// Base class (Parent)
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {}
    
    void eat() {
        cout << name << " is eating." << endl;
    }
    
    void sleep() {
        cout << name << " is sleeping." << endl;
    }
    
    virtual void makeSound() {
        cout << name << " makes a sound." << endl;
    }
};

// Derived class (Child)
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}
    
    void makeSound() override {
        cout << name << " barks: Woof! Woof!" << endl;
    }
    
    void wagTail() {
        cout << name << " is wagging tail happily!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}
    
    void makeSound() override {
        cout << name << " meows: Meow! Meow!" << endl;
    }
    
    void purr() {
        cout << name << " is purring contentedly." << endl;
    }
};
```

#### 3. Polymorphism
**Definition**: Same interface with different implementations.

**Example:**
```cpp
// Runtime Polymorphism
void petSound(Animal* pet) {
    pet->makeSound();  // Different sound based on actual object type
}

int main() {
    Animal* pets[3];
    pets[0] = new Dog("Buddy", 3, "Golden Retriever");
    pets[1] = new Cat("Whiskers", 2);
    pets[2] = new Animal("Generic Pet", 1);
    
    for(int i = 0; i < 3; i++) {
        petSound(pets[i]);  // Polymorphic behavior
    }
    
    // Output:
    // Buddy barks: Woof! Woof!
    // Whiskers meows: Meow! Meow!
    // Generic Pet makes a sound.
    
    return 0;
}

// Compile-time Polymorphism (Function Overloading)
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

#### 4. Abstraction
**Definition**: Hiding complex implementation details.

**Example:**
```cpp
// Abstract class
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {}
    
    // Pure virtual function (makes class abstract)
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    
    // Concrete method
    void displayColor() {
        cout << "Color: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    
    double calculateArea() override {
        return 3.14159 * radius * radius;
    }
    
    double calculatePerimeter() override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(string c, double l, double w) : Shape(c), length(l), width(w) {}
    
    double calculateArea() override {
        return length * width;
    }
    
    double calculatePerimeter() override {
        return 2 * (length + width);
    }
};
```

### Q4: What are access specifiers? Explain with example.

**Example:**
```cpp
class Student {
private:              // Only accessible within this class
    int studentID;
    string password;
    
protected:            // Accessible in this class and derived classes
    string name;
    int age;
    
public:               // Accessible from anywhere
    string course;
    
public:
    Student(string n, int a, string c, int id) {
        name = n;         // OK - within same class
        age = a;          // OK - within same class
        course = c;       // OK - within same class
        studentID = id;   // OK - within same class
    }
    
    void displayPublicInfo() {
        cout << "Course: " << course << endl;  // OK - public member
    }
    
    void displayAllInfo() {
        cout << "Name: " << name << endl;           // OK - within same class
        cout << "Age: " << age << endl;             // OK - within same class
        cout << "Student ID: " << studentID << endl; // OK - within same class
    }
};

class GraduateStudent : public Student {
public:
    GraduateStudent(string n, int a, string c, int id) 
        : Student(n, a, c, id) {}
    
    void showInheritedData() {
        cout << "Name: " << name << endl;     // OK - protected in base class
        cout << "Age: " << age << endl;       // OK - protected in base class
        cout << "Course: " << course << endl; // OK - public in base class
        
        // cout << studentID << endl;  // ERROR - private in base class
    }
};

int main() {
    Student s1("John", 20, "Computer Science", 12345);
    
    cout << s1.course << endl;        // OK - public member
    // cout << s1.name << endl;       // ERROR - protected member
    // cout << s1.studentID << endl;  // ERROR - private member
    
    s1.displayPublicInfo();          // OK - public method
    s1.displayAllInfo();             // OK - public method
    
    return 0;
}
```

## 3. Functions and Memory Management

### Q5: Explain function overloading with example.

**Example:**
```cpp
class MathOperations {
public:
    // Function overloading - same name, different parameters
    
    // Version 1: Two integers
    int add(int a, int b) {
        cout << "Adding two integers" << endl;
        return a + b;
    }
    
    // Version 2: Three integers
    int add(int a, int b, int c) {
        cout << "Adding three integers" << endl;
        return a + b + c;
    }
    
    // Version 3: Two doubles
    double add(double a, double b) {
        cout << "Adding two doubles" << endl;
        return a + b;
    }
    
    // Version 4: Array and size
    int add(int arr[], int size) {
        cout << "Adding array elements" << endl;
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    MathOperations math;
    
    cout << math.add(5, 3) << endl;           // Calls version 1
    cout << math.add(5, 3, 2) << endl;       // Calls version 3
    cout << math.add(5.5, 3.2) << endl;      // Calls version 2
    
    int numbers[] = {1, 2, 3, 4, 5};
    cout << math.add(numbers, 5) << endl;    // Calls version 4
    
    return 0;
}
```

### Q6: What is the difference between call by value, call by reference, and call by pointer?

**Example:**
```cpp
#include <iostream>
using namespace std;

// Call by Value - Copy is passed
void callByValue(int x) {
    x = x + 10;
    cout << "Inside callByValue, x = " << x << endl;
}

// Call by Reference - Alias is passed
void callByReference(int &x) {
    x = x + 10;
    cout << "Inside callByReference, x = " << x << endl;
}

// Call by Pointer - Address is passed
void callByPointer(int *x) {
    *x = *x + 10;
    cout << "Inside callByPointer, *x = " << *x << endl;
}

int main() {
    int num = 20;
    
    cout << "Original value: " << num << endl;
    
    // Call by Value
    cout << "\n--- Call by Value ---" << endl;
    callByValue(num);
    cout << "After callByValue, num = " << num << endl;  // num remains 20
    
    // Call by Reference
    cout << "\n--- Call by Reference ---" << endl;
    callByReference(num);
    cout << "After callByReference, num = " << num << endl;  // num becomes 30
    
    // Reset num
    num = 20;
    
    // Call by Pointer
    cout << "\n--- Call by Pointer ---" << endl;
    callByPointer(&num);
    cout << "After callByPointer, num = " << num << endl;  // num becomes 30
    
    return 0;
}

/* Output:
Original value: 20

--- Call by Value ---
Inside callByValue, x = 30
After callByValue, num = 20

--- Call by Reference ---
Inside callByReference, x = 30
After callByReference, num = 30

--- Call by Pointer ---
Inside callByPointer, *x = 30
After callByPointer, num = 30
*/

## 6. Templates and STL

### Q12: What are templates? Explain with examples.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function Template
template<typename T>
T findMax(T a, T b) {
    cout << "Generic findMax called" << endl;
    return (a > b) ? a : b;
}

// Template Specialization
template<>
const char* findMax<const char*>(const char* a, const char* b) {
    cout << "Specialized findMax for const char* called" << endl;
    return (strcmp(a, b) > 0) ? a : b;
}

// Function template with multiple parameters
template<typename T, typename U>
void displayPair(T first, U second) {
    cout << "Pair: (" << first << ", " << second << ")" << endl;
}

// Class Template
template<class T>
class Stack {
private:
    vector<T> elements;
    
public:
    void push(const T& element) {
        elements.push_back(element);
        cout << "Pushed: " << element << endl;
    }
    
    void pop() {
        if(!elements.empty()) {
            cout << "Popped: " << elements.back() << endl;
            elements.pop_back();
        } else {
            cout << "Stack is empty!" << endl;
        }
    }
    
    T top() const {
        if(!elements.empty()) {
            return elements.back();
        }
        throw runtime_error("Stack is empty");
    }
    
    bool empty() const {
        return elements.empty();
    }
    
    size_t size() const {
        return elements.size();
    }
    
    void display() const {
        cout << "Stack contents: ";
        for(const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

// Class template with multiple parameters
template<typename K, typename V>
class KeyValuePair {
private:
    K key;
    V value;
    
public:
    KeyValuePair(K k, V v) : key(k), value(v) {}
    
    K getKey() const { return key; }
    V getValue() const { return value; }
    
    void display() const {
        cout << "Key: " << key << ", Value: " << value << endl;
    }
};

int main() {
    cout << "=== Template Examples ===" << endl;
    
    // Function template usage
    cout << "\n--- Function Templates ---" << endl;
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << endl;
    cout << "Max of 'A' and 'Z': " << findMax('A', 'Z') << endl;
    
    // Template specialization
    const char* str1 = "apple";
    const char* str2 = "banana";
    cout << "Max of strings: " << findMax(str1, str2) << endl;
    
    // Multiple parameter template
    displayPair(1, "Hello");
    displayPair(3.14, 'A');
    
    // Class template usage
    cout << "\n--- Class Templates ---" << endl;
    
    // Integer stack
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    
    cout << "Top element: " << intStack.top() << endl;
    intStack.pop();
    intStack.display();
    
    // String stack
    Stack<string> stringStack;
    stringStack.push("First");
    stringStack.push("Second");
    stringStack.push("Third");
    stringStack.display();
    
    // KeyValue pairs
    cout << "\n--- Multi-parameter Templates ---" << endl;
    KeyValuePair<int, string> kv1(1, "One");
    KeyValuePair<string, double> kv2("PI", 3.14159);
    
    kv1.display();
    kv2.display();
    
    return 0;
}
```

### Q13: What is STL? Explain with examples.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cout << "=== STL Containers and Algorithms Demo ===" << endl;
    
    // === VECTOR ===
    cout << "\n--- Vector Container ---" << endl;
    vector<int> vec = {5, 2, 8, 1, 9};
    cout << "Original vector: ";
    for(int x : vec) cout << x << " ";
    cout << endl;
    
    vec.push_back(3);
    vec.push_back(7);
    cout << "After push_back: ";
    for(int x : vec) cout << x << " ";
    cout << endl;
    
    sort(vec.begin(), vec.end());
    cout << "After sorting: ";
    for(int x : vec) cout << x << " ";
    cout << endl;
    
    // === MAP ===
    cout << "\n--- Map Container ---" << endl;
    map<string, int> studentGrades;
    studentGrades["Alice"] = 95;
    studentGrades["Bob"] = 87;
    studentGrades["Charlie"] = 92;
    studentGrades["Diana"] = 98;
    
    cout << "Student grades:" << endl;
    for(const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Find a student
    string searchName = "Bob";
    auto it = studentGrades.find(searchName);
    if(it != studentGrades.end()) {
        cout << searchName << " found with grade: " << it->second << endl;
    }
    
    // === SET ===
    cout << "\n--- Set Container ---" << endl;
    set<int> uniqueNumbers = {5, 2, 8, 2, 1, 8, 9, 1};
    cout << "Set (duplicates removed, sorted): ";
    for(int x : uniqueNumbers) cout << x << " ";
    cout << endl;
    
    uniqueNumbers.insert(4);
    uniqueNumbers.insert(6);
    cout << "After inserting 4 and 6: ";
    for(int x : uniqueNumbers) cout << x << " ";
    cout << endl;
    
    // === QUEUE ===
    cout << "\n--- Queue Container ---" << endl;
    queue<string> taskQueue;
    taskQueue.push("Task 1");
    taskQueue.push("Task 2");
    taskQueue.push("Task 3");
    
    cout << "Processing tasks:" << endl;
    while(!taskQueue.empty()) {
        cout << "Processing: " << taskQueue.front() << endl;
        taskQueue.pop();
    }
    
    // === STACK ===
    cout << "\n--- Stack Container ---" << endl;
    stack<char> charStack;
    string expression = "ABC";
    
    cout << "Pushing characters: ";
    for(char c : expression) {
        charStack.push(c);
        cout << c << " ";
    }
    cout << endl;
    
    cout << "Popping characters: ";
    while(!charStack.empty()) {
        cout << charStack.top() << " ";
        charStack.pop();
    }
    cout << endl;
    
    // === ALGORITHMS ===
    cout << "\n--- STL Algorithms ---" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Find
    auto findIt = find(numbers.begin(), numbers.end(), 7);
    if(findIt != numbers.end()) {
        cout << "Found 7 at position: " << distance(numbers.begin(), findIt) << endl;
    }
    
    // Count
    int evenCount = 0;
    for(int n : numbers) {
        if(n % 2 == 0) evenCount++;
    }
    cout << "Even numbers count: " << evenCount << endl;
    
    // Transform (square all elements)
    vector<int> squares(numbers.size());
    transform(numbers.begin(), numbers.end(), squares.begin(), 
              [](int x) { return x * x; });
    
    cout << "Original numbers: ";
    for(int x : numbers) cout << x << " ";
    cout << endl;
    
    cout << "Squared numbers: ";
    for(int x : squares) cout << x << " ";
    cout << endl;
    
    // Reverse
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed numbers: ";
    for(int x : numbers) cout << x << " ";
    cout << endl;
    
    return 0;
}
```

## 7. Exception Handling

### Q14: What is exception handling? Explain with examples.

**Example:**
```cpp
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom exception class
class DivisionByZeroException : public exception {
private:
    string message;
    
public:
    DivisionByZeroException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 0 and 150";
    }
};

class Calculator {
public:
    static double divide(double numerator, double denominator) {
        if(denominator == 0) {
            throw DivisionByZeroException("Cannot divide by zero!");
        }
        return numerator / denominator;
    }
    
    static double squareRoot(double number) {
        if(number < 0) {
            throw invalid_argument("Cannot calculate square root of negative number");
        }
        return sqrt(number);
    }
};

class Person {
private:
    string name;
    int age;
    
public:
    Person(string n, int a) : name(n) {
        setAge(a);  // This might throw an exception
    }
    
    void setAge(int a) {
        if(a < 0 || a > 150) {
            throw InvalidAgeException();
        }
        age = a;
    }
    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

void demonstrateBasicExceptionHandling() {
    cout << "\n=== Basic Exception Handling ===" << endl;
    
    try {
        double result1 = Calculator::divide(10, 2);
        cout << "10 / 2 = " << result1 << endl;
        
        double result2 = Calculator::divide(10, 0);  // This will throw
        cout << "This line won't execute" << endl;
    }
    catch(const DivisionByZeroException& e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }
    
    cout << "Program continues after exception handling" << endl;
}

void demonstrateMultipleCatchBlocks() {
    cout << "\n=== Multiple Catch Blocks ===" << endl;
    
    try {
        // Test different scenarios
        Calculator::squareRoot(-5);
    }
    catch(const invalid_argument& e) {
        cout << "Invalid argument exception: " << e.what() << endl;
    }
    catch(const exception& e) {
        cout << "General exception: " << e.what() << endl;
    }
    catch(...) {
        cout << "Unknown exception caught" << endl;
    }
}

void demonstrateExceptionInConstructor() {
    cout << "\n=== Exception in Constructor ===" << endl;
    
    try {
        Person person1("Alice", 25);
        person1.display();
        
        Person person2("Bob", -5);  // This will throw
        person2.display();          // This won't execute
    }
    catch(const InvalidAgeException& e) {
        cout << "Caught age exception: " << e.what() << endl;
    }
}

void demonstrateRethrowingException() {
    cout << "\n=== Rethrowing Exception ===" << endl;
    
    auto processData = [](double value) {
        try {
            if(value < 0) {
                throw runtime_error("Negative value not allowed");
            }
            cout << "Processing value: " << value << endl;
        }
        catch(const runtime_error& e) {
            cout << "Caught in processData: " << e.what() << endl;
            cout << "Logging error and rethrowing..." << endl;
            throw;  // Rethrow the same exception
        }
    };
    
    try {
        processData(10);   // OK
        processData(-5);   // Will throw and rethrow
    }
    catch(const runtime_error& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }
}

void demonstrateResourceManagement() {
    cout << "\n=== RAII and Exception Safety ===" << endl;
    
    class FileHandler {
    private:
        string filename;
        bool isOpen;
        
    public:
        FileHandler(const string& fname) : filename(fname), isOpen(false) {
            cout << "Opening file: " << filename << endl;
            isOpen = true;
            
            // Simulate file opening failure
            if(filename == "nonexistent.txt") {
                throw runtime_error("File not found: " + filename);
            }
        }
        
        ~FileHandler() {
            if(isOpen) {
                cout << "Closing file: " << filename << endl;
            }
        }
        
        void processFile() {
            if(!isOpen) {
                throw runtime_error("File is not open");
            }
            cout << "Processing file: " << filename << endl;
            
            // Simulate processing error
            if(filename == "corrupt.txt") {
                throw runtime_error("File is corrupted");
            }
        }
    };
    
    // Case 1: Normal operation
    try {
        FileHandler file1("data.txt");
        file1.processFile();
        cout << "File processed successfully" << endl;
    }
    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Case 2: Exception during processing
    try {
        FileHandler file2("corrupt.txt");
        file2.processFile();  // Will throw
    }
    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Case 3: Exception during construction
    try {
        FileHandler file3("nonexistent.txt");  // Will throw
        file3.processFile();
    }
    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

int main() {
    cout << "=== Exception Handling Examples ===" << endl;
    
    demonstrateBasicExceptionHandling();
    demonstrateMultipleCatchBlocks();
    demonstrateExceptionInConstructor();
    demonstrateRethrowingException();
    demonstrateResourceManagement();
    
    return 0;
}
```

## 8. Advanced Topics

### Q15: What is the difference between const, static, and inline?

**Example:**
```cpp
#include <iostream>
using namespace std;

class Example {
private:
    static int staticCount;        // Static member variable
    const int constValue;          // Const member variable
    int normalValue;
    
public:
    // Constructor with member initializer list
    Example(int val) : constValue(val), normalValue(val) {
        staticCount++;
        cout << "Constructor called. Object #" << staticCount << endl;
    }
    
    // Const member function - cannot modify object state
    void displayConst() const {
        cout << "Const function - constValue: " << constValue << endl;
        cout << "Const function - normalValue: " << normalValue << endl;
        // constValue = 10;     // ERROR: cannot modify const member
        // normalValue = 20;    // ERROR: cannot modify in const function
    }
    
    // Non-const member function
    void displayNonConst() {
        cout << "Non-const function - can modify members" << endl;
        normalValue = 100;  // OK
        // constValue = 50;  // ERROR: cannot modify const member
    }
    
    // Static member function - can only access static members
    static void displayStaticCount() {
        cout << "Static function - Total objects created: " << staticCount << endl;
        // cout << constValue << endl;  // ERROR: cannot access non-static members
    }
    
    // Inline function - definition in class is automatically inline
    inline int getNormalValue() const {
        return normalValue;
    }
    
    // Inline function with calculation
    inline int calculateDouble() const {
        return normalValue * 2;
    }
};

// Static member definition
int Example::staticCount = 0;

// Inline function outside class
inline int globalAdd(int a, int b) {
    return a + b;
}

// Regular function for comparison
int globalMultiply(int a, int b) {
    return a * b;
}

void demonstrateConstUsage() {
    cout << "\n=== Const Usage Examples ===" << endl;
    
    // Const variables
    const int constVar = 10;
    cout << "Const variable: " << constVar << endl;
    // constVar = 20;  // ERROR: cannot modify const variable
    
    // Const pointers
    int x = 5, y = 10;
    
    const int* ptr1 = &x;        // Pointer to const int
    cout << "Pointer to const: " << *ptr1 << endl;
    // *ptr1 = 15;               // ERROR: cannot modify value through pointer
    ptr1 = &y;                   // OK: can change pointer itself
    
    int* const ptr2 = &x;        // Const pointer to int
    *ptr2 = 15;                  // OK: can modify value
    cout << "Const pointer: " << *ptr2 << endl;
    // ptr2 = &y;                // ERROR: cannot change pointer itself
    
    const int* const ptr3 = &x;  // Const pointer to const int
    // *ptr3 = 20;               // ERROR: cannot modify value
    // ptr3 = &y;                // ERROR: cannot change pointer
    
    // Const objects
    const Example constObj(42);
    constObj.displayConst();     // OK: const function
    // constObj.displayNonConst(); // ERROR: non-const function on const object
}

void demonstrateStaticUsage() {
    cout << "\n=== Static Usage Examples ===" << endl;
    
    // Static local variable
    auto countCalls = []() {
        static int callCount = 0;  // Initialized only once
        callCount++;
        cout << "Function called " << callCount << " times" << endl;
        return callCount;
    };
    
    countCalls();
    countCalls();
    countCalls();
    
    // Static member function
    Example::displayStaticCount();
    
    Example obj1(10);
    Example obj2(20);
    Example obj3(30);
    
    Example::displayStaticCount();
}

void demonstrateInlineUsage() {
    cout << "\n=== Inline Usage Examples ===" << endl;
    
    Example obj(25);
    
    cout << "Normal value: " << obj.getNormalValue() << endl;
    cout << "Double value: " << obj.calculateDouble() << endl;
    
    // Inline functions
    cout << "Global add (inline): " << globalAdd(5, 3) << endl;
    cout << "Global multiply (regular): " << globalMultiply(5, 3) << endl;
    
    // Inline functions are typically faster but increase code size
    // Compiler decides whether to actually inline based on optimization
}

int main() {
    cout << "=== const, static, and inline Examples ===" << endl;
    
    demonstrateConstUsage();
    demonstrateStaticUsage();
    demonstrateInlineUsage();
    
    return 0;
}
```

## 9. Interview Tips and Common Mistakes

### Q16: What are common C++ programming mistakes to avoid?

**Examples of Common Mistakes:**

```cpp
// === MISTAKE 1: Memory Leaks ===
class BadExample {
public:
    void memoryLeak() {
        int* ptr = new int[100];
        // Missing delete[] ptr;  // MEMORY LEAK!
    }
};

class GoodExample {
public:
    void properMemoryManagement() {
        int* ptr = new int[100];
        // ... use ptr ...
        delete[] ptr;  // Proper cleanup
        ptr = nullptr;  // Good practice
    }
};

// === MISTAKE 2: Dangling Pointers ===
int* badPointerUsage() {
    int localVar = 42;
    return &localVar;  // DANGEROUS: returning address of local variable
}

int* goodPointerUsage() {
    int* ptr = new int(42);
    return ptr;  // OK, but caller must delete
}

// === MISTAKE 3: Incorrect Copy Constructor ===
class BadCopy {
private:
    int* data;
    int size;
    
public:
    BadCopy(int s) : size(s) {
        data = new int[size];
    }
    
    // Missing proper copy constructor - SHALLOW COPY PROBLEM!
    
    ~BadCopy() {
        delete[] data;  // Will cause double deletion error
    }
};

class GoodCopy {
private:
    int* data;
    int size;
    
public:
    GoodCopy(int s) : size(s) {
        data = new int[size];
    }
    
    // Proper copy constructor - DEEP COPY
    GoodCopy(const GoodCopy& other) : size(other.size) {
        data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Assignment operator
    GoodCopy& operator=(const GoodCopy& other) {
        if(this != &other) {  // Self-assignment check
            delete[] data;
            size = other.size;
            data = new int[size];
            for(int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    ~GoodCopy() {
        delete[] data;
    }
};
```

## 10. Quick Reference for Interview

### Key Points to Remember:

1. **OOP Concepts**: Always explain with real-world examples
2. **Memory Management**: Know the difference between stack and heap
3. **Polymorphism**: Understand virtual functions and late binding
4. **STL**: Know when to use vector, list, map, set
5. **Exception Handling**: Use RAII for resource management
6. **Templates**: Understand generic programming benefits

### Common Interview Questions Pattern:
- **Theory**: "What is polymorphism?"
- **Example**: "Show me polymorphism with code"
- **Application**: "When would you use polymorphism in a real project?"
- **Comparison**: "What's the difference between virtual and pure virtual functions?"

### Best Practices for Coding in Interview:
1. Always check for null pointers
2. Handle memory allocation failures
3. Use meaningful variable names
4. Comment complex logic
5. Consider edge cases
6. Think about time and space complexity
```

### Q7: What are constructors and destructors? Explain with examples.

**Example:**
```cpp
class Resource {
private:
    string name;
    int* data;
    int size;
    
public:
    // Default Constructor
    Resource() {
        cout << "Default Constructor called" << endl;
        name = "Default";
        size = 0;
        data = nullptr;
    }
    
    // Parameterized Constructor
    Resource(string n, int s) {
        cout << "Parameterized Constructor called for " << n << endl;
        name = n;
        size = s;
        data = new int[size];  // Dynamic memory allocation
        
        // Initialize array
        for(int i = 0; i < size; i++) {
            data[i] = i + 1;
        }
    }
    
    // Copy Constructor
    Resource(const Resource& other) {
        cout << "Copy Constructor called for " << other.name << endl;
        name = other.name + "_Copy";
        size = other.size;
        
        if(other.data != nullptr) {
            data = new int[size];  // Deep copy
            for(int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    
    // Destructor
    ~Resource() {
        cout << "Destructor called for " << name << endl;
        if(data != nullptr) {
            delete[] data;  // Free dynamic memory
            data = nullptr;
        }
    }
    
    void display() {
        cout << "Resource: " << name << ", Size: " << size << endl;
        if(data != nullptr) {
            cout << "Data: ";
            for(int i = 0; i < size; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== Creating objects ===" << endl;
    
    Resource r1;                           // Default constructor
    Resource r2("MainResource", 5);        // Parameterized constructor
    Resource r3 = r2;                      // Copy constructor
    
    cout << "\n=== Displaying objects ===" << endl;
    r1.display();
    r2.display();
    r3.display();
    
    cout << "\n=== End of main (destructors will be called) ===" << endl;
    return 0;
    
    // Destructors are called automatically when objects go out of scope
}

/* Output:
=== Creating objects ===
Default Constructor called
Parameterized Constructor called for MainResource
Copy Constructor called for MainResource

=== Displaying objects ===
Resource: Default, Size: 0

Resource: MainResource, Size: 5
Data: 1 2 3 4 5 

Resource: MainResource_Copy, Size: 5
Data: 1 2 3 4 5 

=== End of main (destructors will be called) ===
Destructor called for MainResource_Copy
Destructor called for MainResource
Destructor called for Default
*/
```

## 4. Advanced Concepts

### Q8: What are virtual functions? Explain with example.

**Example:**
```cpp
class Employee {
protected:
    string name;
    double baseSalary;
    
public:
    Employee(string n, double salary) : name(n), baseSalary(salary) {}
    
    // Virtual function - can be overridden
    virtual double calculateSalary() {
        cout << "Employee::calculateSalary() called" << endl;
        return baseSalary;
    }
    
    // Virtual function
    virtual void displayInfo() {
        cout << "Employee: " << name << endl;
        cout << "Base Salary: $" << baseSalary << endl;
    }
    
    // Non-virtual function
    void showEmployeeType() {
        cout << "Type: General Employee" << endl;
    }
    
    virtual ~Employee() {}  // Virtual destructor
};

class Manager : public Employee {
private:
    double bonus;
    
public:
    Manager(string n, double salary, double b) 
        : Employee(n, salary), bonus(b) {}
    
    // Override virtual function
    double calculateSalary() override {
        cout << "Manager::calculateSalary() called" << endl;
        return baseSalary + bonus;
    }
    
    // Override virtual function
    void displayInfo() override {
        cout << "Manager: " << name << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Bonus: $" << bonus << endl;
    }
    
    // Non-virtual function with same name (function hiding)
    void showEmployeeType() {
        cout << "Type: Manager" << endl;
    }
};

class Developer : public Employee {
private:
    double overtimePay;
    
public:
    Developer(string n, double salary, double overtime) 
        : Employee(n, salary), overtimePay(overtime) {}
    
    // Override virtual function
    double calculateSalary() override {
        cout << "Developer::calculateSalary() called" << endl;
        return baseSalary + overtimePay;
    }
    
    // Override virtual function
    void displayInfo() override {
        cout << "Developer: " << name << endl;
        cout << "Base Salary: $" << baseSalary << endl;
        cout << "Overtime Pay: $" << overtimePay << endl;
    }
};

// Function demonstrating polymorphism
void processEmployee(Employee* emp) {
    cout << "\n--- Processing Employee ---" << endl;
    emp->displayInfo();              // Virtual function - polymorphic call
    cout << "Total Salary: $" << emp->calculateSalary() << endl;  // Virtual function
    emp->showEmployeeType();         // Non-virtual function - static binding
}

int main() {
    Employee* employees[3];
    
    employees[0] = new Employee("John Doe", 50000);
    employees[1] = new Manager("Alice Smith", 80000, 15000);
    employees[2] = new Developer("Bob Johnson", 70000, 10000);
    
    // Polymorphic behavior with virtual functions
    for(int i = 0; i < 3; i++) {
        processEmployee(employees[i]);
    }
    
    // Clean up
    for(int i = 0; i < 3; i++) {
        delete employees[i];
    }
    
    return 0;
}

/* Output:
--- Processing Employee ---
Employee: John Doe
Base Salary: $50000
Employee::calculateSalary() called
Total Salary: $50000
Type: General Employee

--- Processing Employee ---
Manager: Alice Smith
Base Salary: $80000
Bonus: $15000
Manager::calculateSalary() called
Total Salary: $95000
Type: General Employee

--- Processing Employee ---
Developer: Bob Johnson
Base Salary: $70000
Overtime Pay: $10000
Developer::calculateSalary() called
Total Salary: $80000
Type: General Employee
*/
```

### Q9: What is a pure virtual function and abstract class?

**Example:**
```cpp
// Abstract class - contains pure virtual function
class Printer {
protected:
    string brand;
    
public:
    Printer(string b) : brand(b) {}
    
    // Pure virtual functions - must be implemented by derived classes
    virtual void print(string document) = 0;
    virtual void scan() = 0;
    virtual int getPagesPerMinute() = 0;
    
    // Concrete function - can be used by all derived classes
    void displayBrand() {
        cout << "Brand: " << brand << endl;
    }
    
    // Virtual destructor
    virtual ~Printer() {}
};

class LaserPrinter : public Printer {
private:
    int tonerLevel;
    
public:
    LaserPrinter(string b, int toner) : Printer(b), tonerLevel(toner) {}
    
    // Must implement all pure virtual functions
    void print(string document) override {
        if(tonerLevel > 0) {
            cout << "Laser printing: " << document << endl;
            tonerLevel -= 5;
        } else {
            cout << "Error: Toner empty!" << endl;
        }
    }
    
    void scan() override {
        cout << "Laser printer scanning..." << endl;
    }
    
    int getPagesPerMinute() override {
        return 25;  // Laser printers are fast
    }
    
    void checkToner() {
        cout << "Toner level: " << tonerLevel << "%" << endl;
    }
};

class InkjetPrinter : public Printer {
private:
    int inkLevel;
    
public:
    InkjetPrinter(string b, int ink) : Printer(b), inkLevel(ink) {}
    
    // Must implement all pure virtual functions
    void print(string document) override {
        if(inkLevel > 0) {
            cout << "Inkjet printing: " << document << endl;
            inkLevel -= 10;
        } else {
            cout << "Error: Ink cartridge empty!" << endl;
        }
    }
    
    void scan() override {
        cout << "Inkjet printer scanning..." << endl;
    }
    
    int getPagesPerMinute() override {
        return 8;   // Inkjet printers are slower
    }
    
    void checkInk() {
        cout << "Ink level: " << inkLevel << "%" << endl;
    }
};

// Function that works with any printer (polymorphism)
void officePrinting(Printer* printer, string document) {
    printer->displayBrand();
    cout << "Speed: " << printer->getPagesPerMinute() << " pages/minute" << endl;
    printer->print(document);
    printer->scan();
    cout << "------------------------" << endl;
}

int main() {
    // Printer p;  // ERROR: Cannot instantiate abstract class
    
    Printer* printers[2];
    printers[0] = new LaserPrinter("HP LaserJet", 80);
    printers[1] = new InkjetPrinter("Canon Pixma", 60);
    
    string document = "Important Report.pdf";
    
    for(int i = 0; i < 2; i++) {
        officePrinting(printers[i], document);
    }
    
    // Clean up
    delete printers[0];
    delete printers[1];
    
    return 0;
}

/* Output:
Brand: HP LaserJet
Speed: 25 pages/minute
Laser printing: Important Report.pdf
Laser printer scanning...
------------------------
Brand: Canon Pixma
Speed: 8 pages/minute
Inkjet printing: Important Report.pdf
Inkjet printer scanning...
------------------------
*/
```

## 5. Memory Management

### Q10: Explain stack vs heap memory with examples.

**Example:**
```cpp
#include <iostream>
using namespace std;

class StackObject {
private:
    int value;
    char data[100];  // Stack allocated array
    
public:
    StackObject(int v) : value(v) {
        cout << "StackObject created with value: " << value << endl;
    }
    
    ~StackObject() {
        cout << "StackObject destroyed with value: " << value << endl;
    }
    
    void display() {
        cout << "StackObject value: " << value << " (Address: " << this << ")" << endl;
    }
};

class HeapObject {
private:
    int value;
    int* dynamicArray;
    int size;
    
public:
    HeapObject(int v, int s) : value(v), size(s) {
        dynamicArray = new int[size];  // Heap allocation
        for(int i = 0; i < size; i++) {
            dynamicArray[i] = i * value;
        }
        cout << "HeapObject created with value: " << value << " (Address: " << this << ")" << endl;
    }
    
    ~HeapObject() {
        delete[] dynamicArray;  // Must manually free heap memory
        cout << "HeapObject destroyed with value: " << value << endl;
    }
    
    void display() {
        cout << "HeapObject value: " << value << " (Address: " << this << ")" << endl;
        cout << "Dynamic array: ";
        for(int i = 0; i < size; i++) {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;
    }
};

void demonstrateStackAllocation() {
    cout << "\n=== Stack Allocation Demo ===" << endl;
    
    StackObject obj1(10);    // Allocated on stack
    StackObject obj2(20);    // Allocated on stack
    
    obj1.display();
    obj2.display();
    
    // Local variables on stack
    int localVar = 100;
    int localArray[5] = {1, 2, 3, 4, 5};
    
    cout << "Local variable address: " << &localVar << endl;
    cout << "Local array address: " << localArray << endl;
    
    // Objects automatically destroyed when function ends (stack unwinding)
}

void demonstrateHeapAllocation() {
    cout << "\n=== Heap Allocation Demo ===" << endl;
    
    // Dynamic allocation on heap
    HeapObject* heapObj1 = new HeapObject(5, 4);
    HeapObject* heapObj2 = new HeapObject(3, 6);
    
    heapObj1->display();
    heapObj2->display();
    
    // Dynamic arrays
    int* dynamicIntArray = new int[10];
    double* dynamicDoubleArray = new double[20];
    
    cout << "Dynamic int array address: " << dynamicIntArray << endl;
    cout << "Dynamic double array address: " << dynamicDoubleArray << endl;
    
    // Must manually free heap memory
    delete heapObj1;
    delete heapObj2;
    delete[] dynamicIntArray;
    delete[] dynamicDoubleArray;
    
    cout << "Heap memory manually freed" << endl;
}

void demonstrateMemoryLeak() {
    cout << "\n=== Memory Leak Example ===" << endl;
    
    HeapObject* obj = new HeapObject(99, 3);
    obj->display();
    
    // Memory leak - forgot to delete obj
    // delete obj;  // This line should be uncommented to prevent leak
    
    cout << "Function ending - memory leak occurred!" << endl;
}

int main() {
    cout << "=== Memory Management Demonstration ===" << endl;
    
    // Stack allocation demo
    demonstrateStackAllocation();
    
    // Heap allocation demo
    demonstrateHeapAllocation();
    
    // Memory leak demo (commented out to prevent actual leak)
    // demonstrateMemoryLeak();
    
    cout << "\n=== Program ending ===" << endl;
    return 0;
}

/* Output:
=== Memory Management Demonstration ===

=== Stack Allocation Demo ===
StackObject created with value: 10
StackObject created with value: 20
StackObject value: 10 (Address: 0x7fff5fbff6f0)
StackObject value: 20 (Address: 0x7fff5fbff5f0)
Local variable address: 0x7fff5fbff5ec
Local array address: 0x7fff5fbff5d8
StackObject destroyed with value: 20
StackObject destroyed with value: 10

=== Heap Allocation Demo ===
HeapObject created with value: 5 (Address: 0x55555556eb70)
HeapObject created with value: 3 (Address: 0x55555556ec20)
HeapObject value: 5 (Address: 0x55555556eb70)
Dynamic array: 0 5 10 15 
HeapObject value: 3 (Address: 0x55555556ec20)
Dynamic array: 0 3 6 9 12 15 
HeapObject destroyed with value: 5
HeapObject destroyed with value: 3
Heap memory manually freed

=== Program ending ===
*/
```

### Q11: What is the difference between new/delete and malloc/free?

**Example:**
```cpp
#include <iostream>
#include <cstdlib>  // for malloc/free
using namespace std;

class TestClass {
private:
    int value;
    
public:
    TestClass(int v = 0) : value(v) {
        cout << "Constructor called with value: " << value << endl;
    }
    
    ~TestClass() {
        cout << "Destructor called for value: " << value << endl;
    }
    
    void display() {
        cout << "TestClass value: " << value << endl;
    }
    
    void setValue(int v) {
        value = v;
    }
};

int main() {
    cout << "=== new/delete vs malloc/free Comparison ===" << endl;
    
    // === Using new/delete (C++ way) ===
    cout << "\n--- Using new/delete ---" << endl;
    
    // Single object allocation
    TestClass* obj1 = new TestClass(10);  // Calls constructor
    obj1->display();
    delete obj1;  // Calls destructor
    
    // Array allocation
    TestClass* objArray = new TestClass[3];  // Calls default constructor for each
    objArray[0].setValue(100);
    objArray[1].setValue(200);
    objArray[2].setValue(300);
    
    for(int i = 0; i < 3; i++) {
        objArray[i].display();
    }
    delete[] objArray;  // Calls destructor for each object
    
    // === Using malloc/free (C way) ===
    cout << "\n--- Using malloc/free ---" << endl;
    
    // Single object allocation
    TestClass* obj2 = (TestClass*)malloc(sizeof(TestClass));  // No constructor called!
    
    // Manual constructor call using placement new
    new(obj2) TestClass(20);  // Placement new to call constructor
    obj2->display();
    
    // Manual destructor call
    obj2->~TestClass();  // Explicit destructor call
    free(obj2);  // Free memory
    
    // Array allocation with malloc
    TestClass* objArray2 = (TestClass*)malloc(3 * sizeof(TestClass));  // No constructors called!
    
    // Manual constructor calls
    for(int i = 0; i < 3; i++) {
        new(&objArray2[i]) TestClass(i * 10);  // Placement new
    }
    
    for(int i = 0; i < 3; i++) {
        objArray2[i].display();
    }
    
    // Manual destructor calls
    for(int i = 0; i < 3; i++) {
        objArray2[i].~TestClass();  // Explicit destructor call
    }
    free(objArray2);  // Free memory
    
    // === Primitive types comparison ===
    cout << "\n--- Primitive types ---" << endl;
    
    // For primitive types, new/delete and malloc/free behave similarly
    int* intPtr1 = new int(42);
    int* intPtr2 = (int*)malloc(sizeof(int));
    *intPtr2 = 42;
    
    cout << "new allocated int: " << *intPtr1 << endl;
    cout << "malloc allocated int: " << *intPtr2 << endl;
    
    delete intPtr1;
    free(intPtr2);
    
    return 0;
}

/* Output:
=== new/delete vs malloc/free Comparison ===

--- Using new/delete ---
Constructor called with value: 10
TestClass value: 10
Destructor called for value: 10
Constructor called with value: 0
Constructor called with value: 0
Constructor called with value: 0
TestClass value: 100
TestClass value: 200
TestClass value: 300
Destructor called for value: 300
Destructor called for value: 200
Destructor called for value: 100

--- Using malloc/free ---
Constructor called with value: 20
TestClass value: 20
Destructor called for value: 20
Constructor called with value: 0
Constructor called with value: 10
Constructor called with value: 20
TestClass value: 0
TestClass value: 10
TestClass value: 20
Destructor called for value: 20
Destructor called for value: 10
Destructor called for value: 0

--- Primitive types ---
new allocated int: 42
malloc allocated int: 42
*/