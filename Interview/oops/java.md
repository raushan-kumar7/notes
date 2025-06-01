# Object-Oriented Programming (OOPs) Interview Guide for TCS Digital Role

## Core OOPs Concepts

### 1. Class and Object

**Class**: Blueprint or template for creating objects
**Object**: Instance of a class with actual values

```java
// Java Example
public class Car {
    // Attributes/Properties
    private String brand;
    private String model;
    private int year;
    
    // Constructor
    public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
    
    // Methods
    public void startEngine() {
        System.out.println(brand + " " + model + " engine started!");
    }
    
    // Getters and Setters
    public String getBrand() { return brand; }
    public void setBrand(String brand) { this.brand = brand; }
}

// Creating Objects
Car car1 = new Car("Toyota", "Camry", 2023);
Car car2 = new Car("Honda", "Civic", 2022);
car1.startEngine(); // Output: Toyota Camry engine started!
```

```javascript
// JavaScript Example
class Car {
    constructor(brand, model, year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
    
    startEngine() {
        console.log(`${this.brand} ${this.model} engine started!`);
    }
}

const car1 = new Car("Toyota", "Camry", 2023);
car1.startEngine(); // Output: Toyota Camry engine started!
```

---

## 2. Encapsulation

**Definition**: Bundling data and methods together and restricting access to internal details

**Key Features**:
- Data hiding using access modifiers
- Controlled access through getters/setters
- Protects object integrity

```java
public class BankAccount {
    private double balance;        // Private - hidden from outside
    private String accountNumber;  // Private - hidden from outside
    
    public BankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
    }
    
    // Controlled access through public methods
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        } else {
            System.out.println("Invalid deposit amount");
        }
    }
    
    public boolean withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
            return true;
        } else {
            System.out.println("Insufficient funds or invalid amount");
            return false;
        }
    }
    
    public double getBalance() {
        return balance;  // Read-only access to balance
    }
    
    // Account number is read-only
    public String getAccountNumber() {
        return accountNumber;
    }
}

// Usage
BankAccount account = new BankAccount("12345", 1000.0);
account.deposit(500.0);    // Valid operation
account.withdraw(200.0);   // Valid operation
// account.balance = 5000; // Error! Direct access not allowed
System.out.println("Current balance: $" + account.getBalance());
```

---

## 3. Inheritance

**Definition**: Mechanism where a new class inherits properties and methods from an existing class

**Types**: Single, Multiple (through interfaces), Multilevel, Hierarchical

```java
// Base/Parent Class
public class Vehicle {
    protected String brand;
    protected int year;
    
    public Vehicle(String brand, int year) {
        this.brand = brand;
        this.year = year;
    }
    
    public void start() {
        System.out.println("Vehicle started");
    }
    
    public void displayInfo() {
        System.out.println("Brand: " + brand + ", Year: " + year);
    }
}

// Derived/Child Class
public class Car extends Vehicle {
    private int numberOfDoors;
    
    public Car(String brand, int year, int numberOfDoors) {
        super(brand, year);  // Call parent constructor
        this.numberOfDoors = numberOfDoors;
    }
    
    // Method overriding
    @Override
    public void start() {
        System.out.println("Car engine started with key");
    }
    
    // Additional method specific to Car
    public void honk() {
        System.out.println("Car is honking: Beep beep!");
    }
    
    @Override
    public void displayInfo() {
        super.displayInfo();  // Call parent method
        System.out.println("Number of doors: " + numberOfDoors);
    }
}

// Another derived class
public class Motorcycle extends Vehicle {
    private boolean hasSidecar;
    
    public Motorcycle(String brand, int year, boolean hasSidecar) {
        super(brand, year);
        this.hasSidecar = hasSidecar;
    }
    
    @Override
    public void start() {
        System.out.println("Motorcycle started with kick/button");
    }
    
    public void wheelie() {
        System.out.println("Motorcycle doing a wheelie!");
    }
}

// Usage
Vehicle vehicle = new Vehicle("Generic", 2020);
Car car = new Car("Toyota", 2023, 4);
Motorcycle bike = new Motorcycle("Harley", 2022, false);

car.start();        // Output: Car engine started with key
bike.start();       // Output: Motorcycle started with kick/button
car.honk();         // Car-specific method
bike.wheelie();     // Motorcycle-specific method
```

---

## 4. Polymorphism

**Definition**: Ability of objects to take multiple forms - same interface, different implementations

**Types**: Compile-time (Method Overloading) and Runtime (Method Overriding)

### Method Overloading (Compile-time Polymorphism)
```java
public class Calculator {
    // Same method name, different parameters
    public int add(int a, int b) {
        return a + b;
    }
    
    public double add(double a, double b) {
        return a + b;
    }
    
    public int add(int a, int b, int c) {
        return a + b + c;
    }
    
    public String add(String a, String b) {
        return a + b;
    }
}

Calculator calc = new Calculator();
System.out.println(calc.add(5, 3));           // Output: 8
System.out.println(calc.add(5.5, 3.2));       // Output: 8.7
System.out.println(calc.add(1, 2, 3));        // Output: 6
System.out.println(calc.add("Hello", "World")); // Output: HelloWorld
```

### Method Overriding (Runtime Polymorphism)
```java
// Base class
abstract class Shape {
    protected String color;
    
    public Shape(String color) {
        this.color = color;
    }
    
    // Abstract method - must be implemented by subclasses
    public abstract double calculateArea();
    
    public void displayColor() {
        System.out.println("Color: " + color);
    }
}

// Derived classes
class Circle extends Shape {
    private double radius;
    
    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }
    
    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double length, width;
    
    public Rectangle(String color, double length, double width) {
        super(color);
        this.length = length;
        this.width = width;
    }
    
    @Override
    public double calculateArea() {
        return length * width;
    }
}

class Triangle extends Shape {
    private double base, height;
    
    public Triangle(String color, double base, double height) {
        super(color);
        this.base = base;
        this.height = height;
    }
    
    @Override
    public double calculateArea() {
        return 0.5 * base * height;
    }
}

// Polymorphic usage
public class ShapeDemo {
    public static void printShapeInfo(Shape shape) {
        shape.displayColor();
        System.out.println("Area: " + shape.calculateArea());
        System.out.println("---");
    }
    
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle("Red", 5.0),
            new Rectangle("Blue", 4.0, 6.0),
            new Triangle("Green", 3.0, 4.0)
        };
        
        for (Shape shape : shapes) {
            printShapeInfo(shape);  // Same method call, different behavior
        }
    }
}
```

---

## 5. Abstraction

**Definition**: Hiding complex implementation details and showing only essential features

**Implementation**: Abstract classes and Interfaces

### Abstract Classes
```java
abstract class Animal {
    protected String name;
    protected int age;
    
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    // Concrete method
    public void sleep() {
        System.out.println(name + " is sleeping");
    }
    
    // Abstract methods - must be implemented by subclasses
    public abstract void makeSound();
    public abstract void move();
    
    // Abstract method with default behavior
    public void eat() {
        System.out.println(name + " is eating");
    }
}

class Dog extends Animal {
    public Dog(String name, int age) {
        super(name, age);
    }
    
    @Override
    public void makeSound() {
        System.out.println(name + " says: Woof! Woof!");
    }
    
    @Override
    public void move() {
        System.out.println(name + " is running on four legs");
    }
}

class Bird extends Animal {
    public Bird(String name, int age) {
        super(name, age);
    }
    
    @Override
    public void makeSound() {
        System.out.println(name + " says: Tweet! Tweet!");
    }
    
    @Override
    public void move() {
        System.out.println(name + " is flying with wings");
    }
}
```

### Interfaces
```java
// Interface for flying capability
interface Flyable {
    void fly();
    void land();
    
    // Default method (Java 8+)
    default void checkWeather() {
        System.out.println("Checking weather conditions for flying");
    }
}

// Interface for swimming capability
interface Swimmable {
    void swim();
    void dive();
}

// Multiple interface implementation
class Duck extends Animal implements Flyable, Swimmable {
    public Duck(String name, int age) {
        super(name, age);
    }
    
    @Override
    public void makeSound() {
        System.out.println(name + " says: Quack! Quack!");
    }
    
    @Override
    public void move() {
        System.out.println(name + " is walking on webbed feet");
    }
    
    @Override
    public void fly() {
        System.out.println(name + " is flying gracefully");
    }
    
    @Override
    public void land() {
        System.out.println(name + " landed on water");
    }
    
    @Override
    public void swim() {
        System.out.println(name + " is swimming in the pond");
    }
    
    @Override
    public void dive() {
        System.out.println(name + " dived underwater for food");
    }
}

// Usage
Duck duck = new Duck("Donald", 3);
duck.makeSound();      // Duck-specific implementation
duck.fly();           // Flyable interface method
duck.swim();          // Swimmable interface method
duck.checkWeather();  // Default interface method
```

---

## Advanced OOPs Concepts

### 1. Composition vs Inheritance

**Composition**: "Has-a" relationship
```java
class Engine {
    private String type;
    private int horsepower;
    
    public Engine(String type, int horsepower) {
        this.type = type;
        this.horsepower = horsepower;
    }
    
    public void start() {
        System.out.println(type + " engine started (" + horsepower + " HP)");
    }
}

class Car {
    private Engine engine;  // Composition - Car HAS an Engine
    private String model;
    
    public Car(String model, Engine engine) {
        this.model = model;
        this.engine = engine;
    }
    
    public void start() {
        System.out.println("Starting " + model);
        engine.start();  // Delegating to composed object
    }
}

// Usage
Engine v8Engine = new Engine("V8", 400);
Car sportsCar = new Car("Ferrari", v8Engine);
sportsCar.start();
```

### 2. Static vs Instance Members
```java
public class Student {
    // Static variables - shared among all instances
    private static int totalStudents = 0;
    private static String schoolName = "TCS Digital Academy";
    
    // Instance variables - unique to each object
    private String name;
    private int rollNumber;
    private double gpa;
    
    // Static block - executed when class is first loaded
    static {
        System.out.println("Student class loaded");
        totalStudents = 0;
    }
    
    // Constructor
    public Student(String name, int rollNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
        totalStudents++;  // Increment static counter
    }
    
    // Instance method
    public void study() {
        System.out.println(name + " is studying");
    }
    
    // Static method - can only access static members
    public static int getTotalStudents() {
        return totalStudents;
    }
    
    public static void displaySchoolInfo() {
        System.out.println("School: " + schoolName);
        System.out.println("Total Students: " + totalStudents);
        // System.out.println(name); // Error! Cannot access instance variable
    }
}

// Usage
Student s1 = new Student("Alice", 101);
Student s2 = new Student("Bob", 102);

System.out.println("Total students: " + Student.getTotalStudents()); // Output: 2
Student.displaySchoolInfo();
```

---

## Common Interview Questions & Answers

### Q1: What are the main principles of OOP?
**Answer:** The four main principles are:
1. **Encapsulation**: Bundling data and methods, data hiding
2. **Inheritance**: Code reusability through parent-child relationships
3. **Polymorphism**: Same interface, different implementations
4. **Abstraction**: Hiding complexity, showing only essential features

### Q2: Difference between Abstract Class and Interface?

| Abstract Class | Interface |
|----------------|-----------|
| Can have concrete methods | Only abstract methods (before Java 8) |
| Can have instance variables | Only constants (public static final) |
| Single inheritance | Multiple inheritance supported |
| Can have constructors | Cannot have constructors |
| Access modifiers allowed | Methods are public by default |
| Use `extends` keyword | Use `implements` keyword |

### Q3: What is method overriding vs method overloading?

**Method Overloading (Compile-time polymorphism)**:
- Same method name, different parameters
- Resolved at compile time
- Can have different return types

**Method Overriding (Runtime polymorphism)**:
- Same method signature in parent and child class
- Resolved at runtime
- Must have same return type (or covariant)

### Q4: Explain the concept of "IS-A" vs "HAS-A" relationship?

**IS-A (Inheritance)**:
```java
class Dog extends Animal {  // Dog IS-A Animal
}
```

**HAS-A (Composition)**:
```java
class Car {
    private Engine engine;  // Car HAS-A Engine
}
```

### Q5: What is the difference between aggregation and composition?

**Composition (Strong relationship)**:
- Child cannot exist without parent
- Parent owns the child
```java
class House {
    private Room room;  // Room cannot exist without House
}
```

**Aggregation (Weak relationship)**:
- Child can exist independently
- Parent uses the child
```java
class Department {
    private List<Employee> employees;  // Employee can exist without Department
}
```

---

## Design Patterns (Common in TCS Interviews)

### 1. Singleton Pattern
```java
public class DatabaseConnection {
    private static DatabaseConnection instance;
    private String connectionString;
    
    // Private constructor prevents external instantiation
    private DatabaseConnection() {
        connectionString = "jdbc:mysql://localhost:3306/mydb";
    }
    
    // Thread-safe singleton
    public static synchronized DatabaseConnection getInstance() {
        if (instance == null) {
            instance = new DatabaseConnection();
        }
        return instance;
    }
    
    public void connect() {
        System.out.println("Connected to: " + connectionString);
    }
}

// Usage
DatabaseConnection db1 = DatabaseConnection.getInstance();
DatabaseConnection db2 = DatabaseConnection.getInstance();
System.out.println(db1 == db2); // true - same instance
```

### 2. Factory Pattern
```java
abstract class Shape {
    public abstract void draw();
}

class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Circle");
    }
}

class Rectangle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a Rectangle");
    }
}

class ShapeFactory {
    public static Shape createShape(String shapeType) {
        switch (shapeType.toLowerCase()) {
            case "circle":
                return new Circle();
            case "rectangle":
                return new Rectangle();
            default:
                throw new IllegalArgumentException("Unknown shape: " + shapeType);
        }
    }
}

// Usage
Shape circle = ShapeFactory.createShape("circle");
circle.draw(); // Output: Drawing a Circle
```

---

## Practical Coding Questions for TCS

### Question 1: Employee Management System
```java
abstract class Employee {
    protected String name;
    protected int id;
    protected double baseSalary;
    
    public Employee(String name, int id, double baseSalary) {
        this.name = name;
        this.id = id;
        this.baseSalary = baseSalary;
    }
    
    public abstract double calculateSalary();
    
    public void displayInfo() {
        System.out.println("ID: " + id + ", Name: " + name);
        System.out.println("Salary: $" + calculateSalary());
    }
}

class Developer extends Employee {
    private int linesOfCode;
    private double bonusPerLine = 0.1;
    
    public Developer(String name, int id, double baseSalary, int linesOfCode) {
        super(name, id, baseSalary);
        this.linesOfCode = linesOfCode;
    }
    
    @Override
    public double calculateSalary() {
        return baseSalary + (linesOfCode * bonusPerLine);
    }
}

class Manager extends Employee {
    private int teamSize;
    private double bonusPerMember = 500;
    
    public Manager(String name, int id, double baseSalary, int teamSize) {
        super(name, id, baseSalary);
        this.teamSize = teamSize;
    }
    
    @Override
    public double calculateSalary() {
        return baseSalary + (teamSize * bonusPerMember);
    }
}
```

### Question 2: Banking System with Exception Handling
```java
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

class BankAccount {
    private String accountNumber;
    private double balance;
    private static int totalAccounts = 0;
    
    public BankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
        totalAccounts++;
    }
    
    public synchronized void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException(
                "Insufficient funds. Balance: $" + balance + ", Requested: $" + amount
            );
        }
        balance -= amount;
        System.out.println("Withdrawn: $" + amount + ", New balance: $" + balance);
    }
    
    public synchronized void deposit(double amount) {
        balance += amount;
        System.out.println("Deposited: $" + amount + ", New balance: $" + balance);
    }
    
    public double getBalance() { return balance; }
    public static int getTotalAccounts() { return totalAccounts; }
}
```

## Key Tips for TCS OOPs Interview

1. **Focus on practical examples**: Always provide real-world scenarios
2. **Understand the 'why'**: Don't just memorize concepts, understand their benefits
3. **Code on paper/whiteboard**: Practice writing code without IDE
4. **Design patterns**: Know at least Singleton, Factory, and Observer patterns
5. **Exception handling**: Understand try-catch-finally blocks
6. **Memory management**: Know about stack vs heap, garbage collection basics
7. **Thread safety**: Understand synchronized methods and blocks
8. **SOLID principles**: Single Responsibility, Open-Closed, Liskov Substitution, Interface Segregation, Dependency Inversion

## Common Mistakes to Avoid

1. Confusing composition with inheritance
2. Not understanding the difference between overloading and overriding
3. Misusing static methods and variables
4. Not properly implementing equals() and hashCode() methods
5. Creating memory leaks with improper object references
6. Not handling exceptions appropriately
7. Violating encapsulation by making everything public