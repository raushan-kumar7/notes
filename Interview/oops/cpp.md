Here are detailed answers to common C++ OOP interview questions for TCS Digital:

## 1. What is the difference between C and C++?

**Answer:**
- **C** is a procedural programming language, **C++** is object-oriented
- **C++** supports classes, objects, inheritance, polymorphism, encapsulation
- **C++** has additional features like function overloading, operator overloading, templates
- **C++** is a superset of C (most C code works in C++)
- **C** uses `malloc/free`, **C++** uses `new/delete`
- **C++** has better type checking and supports references

## 2. What are the four pillars of OOP?

**Answer:**

**Encapsulation**: Wrapping data and methods together, data hiding
```cpp
class Student {
private:
    int marks;  // hidden
public:
    void setMarks(int m) { marks = (m >= 0) ? m : 0; }
    int getMarks() { return marks; }
};
```

**Inheritance**: Acquiring properties from parent class
```cpp
class Animal {
public:
    void eat() { cout << "Animal eating"; }
};
class Dog : public Animal {
public:
    void bark() { cout << "Dog barking"; }
};
```

**Polymorphism**: Same interface, different behavior
```cpp
class Shape {
public:
    virtual void area() = 0;
};
class Rectangle : public Shape {
public:
    void area() { cout << "Rectangle area"; }
};
```

**Abstraction**: Hiding implementation details, showing only essential features
```cpp
class ATM {
public:
    void withdrawMoney() { /* complex internal process hidden */ }
private:
    void authenticateUser() { }
    void checkBalance() { }
};
```

## 3. Virtual Function vs Pure Virtual Function

**Answer:**

**Virtual Function:**
- Has implementation in base class
- Can be overridden in derived class
- Enables runtime polymorphism
```cpp
class Base {
public:
    virtual void show() { cout << "Base class"; }
};
```

**Pure Virtual Function:**
- No implementation in base class (= 0)
- Must be implemented in derived class
- Makes class abstract
```cpp
class Base {
public:
    virtual void show() = 0;  // pure virtual
};
```

## 4. Types of Constructors

**Answer:**

**Default Constructor**: No parameters
```cpp
class Student {
public:
    Student() { name = "Unknown"; age = 0; }
};
```

**Parameterized Constructor**: Takes parameters
```cpp
class Student {
public:
    Student(string n, int a) { name = n; age = a; }
};
```

**Copy Constructor**: Creates copy of existing object
```cpp
class Student {
public:
    Student(const Student &s) { name = s.name; age = s.age; }
};
```

## 5. Abstract Class vs Interface

**Answer:**

| Abstract Class | Interface |
|---|---|
| Can have both pure virtual and normal functions | Only pure virtual functions |
| Can have data members | No data members (conceptually) |
| Can have constructors | Cannot have constructors |
| Single inheritance in C++ | Multiple inheritance possible |

```cpp
// Abstract Class
class Vehicle {
protected:
    string brand;
public:
    Vehicle(string b) : brand(b) {}
    virtual void start() = 0;  // pure virtual
    void stop() { cout << "Vehicle stopped"; }  // normal function
};

// Interface (pure abstract class)
class Drawable {
public:
    virtual void draw() = 0;
    virtual void resize() = 0;
};
```

## 6. Method Overloading vs Method Overriding

**Answer:**

**Method Overloading** (Compile-time polymorphism):
- Same function name, different parameters
- Resolved at compile time
```cpp
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    float add(float a, float b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};
```

**Method Overriding** (Runtime polymorphism):
- Same function signature in base and derived class
- Uses virtual keyword
- Resolved at runtime
```cpp
class Animal {
public:
    virtual void sound() { cout << "Animal sound"; }
};
class Dog : public Animal {
public:
    void sound() override { cout << "Woof"; }
};
```

## 7. Static vs Dynamic Binding

**Answer:**

**Static Binding** (Early Binding):
- Function call resolved at compile time
- Normal functions, overloaded functions
- Faster execution
```cpp
void display() { cout << "Static binding"; }
display();  // resolved at compile time
```

**Dynamic Binding** (Late Binding):
- Function call resolved at runtime
- Virtual functions
- Slightly slower due to vtable lookup
```cpp
Base* ptr = new Derived();
ptr->virtualFunction();  // resolved at runtime
```

## 8. Multiple Inheritance and Diamond Problem

**Answer:**

**Multiple Inheritance**: Class inheriting from multiple base classes
```cpp
class A { public: void show() {} };
class B { public: void display() {} };
class C : public A, public B {};  // multiple inheritance
```

**Diamond Problem**: Ambiguity when same function exists in multiple base classes
```cpp
class A { public: void func() {} };
class B : public A {};
class C : public A {};
class D : public B, public C {};  // Diamond problem
// D has two copies of A's func()
```

**Solution**: Virtual inheritance
```cpp
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};  // Only one copy of A
```

## 9. What is a Virtual Destructor?

**Answer:**
- Destructor declared as virtual in base class
- Ensures proper cleanup when deleting derived objects through base pointer
```cpp
class Base {
public:
    virtual ~Base() { cout << "Base destructor"; }
};
class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor"; }
};

Base* ptr = new Derived();
delete ptr;  // Calls both destructors if virtual
```

## 10. Friend Function

**Answer:**
- Function that can access private and protected members of a class
- Not a member of the class but has special access
- Declared using `friend` keyword
```cpp
class Box {
private:
    int width;
    friend void printWidth(Box& b);  // friend function
public:
    Box(int w) : width(w) {}
};

void printWidth(Box& b) {
    cout << b.width;  // can access private member
}
```

These answers cover the most frequently asked OOP concepts in TCS Digital interviews. Practice implementing these concepts with code examples.