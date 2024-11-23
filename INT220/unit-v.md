# Unit V :: Object Oriented Programming in PHP
## Topics
Defining PHP Classes, Creating Objects in PHP, Calling Member Functions, Constructor Functions,Inheritance, Function Overriding, Interfaces, Abstract Classes

---

### **Object-Oriented Programming (OOP) in PHP**

Object-Oriented Programming (OOP) is a programming paradigm that organizes code into classes and objects, allowing for more efficient and reusable code. PHP supports OOP concepts such as classes, objects, inheritance, interfaces, and abstract classes. Below are the key topics in PHP OOP.

---

### 1. **Defining PHP Classes**

A **class** is a blueprint for creating objects. It defines properties (variables) and methods (functions) that an object can use.

#### Syntax:
```php
<?php
class ClassName {
    // Properties (Variables)
    public $property1;
    public $property2;

    // Constructor
    public function __construct($param1, $param2) {
        $this->property1 = $param1;
        $this->property2 = $param2;
    }

    // Methods (Functions)
    public function display() {
        echo "Property 1: " . $this->property1;
        echo "Property 2: " . $this->property2;
    }
}
?>
```

- `public`: Visibility keyword that allows the property or method to be accessed outside the class.
- `__construct()`: Constructor method that is called when an object of the class is created.

### 2. **Creating Objects in PHP**

Once a class is defined, you can create instances (objects) of that class using the `new` keyword.

#### Syntax:
```php
<?php
// Create an object of the class
$object1 = new ClassName("Value1", "Value2");
$object1->display();  // Calls the display() method
?>
```

- `$object1` is an instance of the `ClassName` class, with `Value1` and `Value2` passed to the constructor.

### 3. **Calling Member Functions**

Member functions (methods) are functions that belong to a class. You can call them on an object using the `->` operator.

#### Example:
```php
<?php
class Person {
    public $name;
    public $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    public function greet() {
        echo "Hello, my name is " . $this->name . " and I am " . $this->age . " years old.";
    }
}

$person1 = new Person("John", 25);
$person1->greet();  // Output: Hello, my name is John and I am 25 years old.
?>
```

- `$person1->greet()` calls the `greet()` method of the `Person` object.

### 4. **Constructor Functions**

A **constructor** is a special method that is automatically called when an object is created. It is often used to initialize object properties.

#### Example:
```php
<?php
class Car {
    public $make;
    public $model;

    public function __construct($make, $model) {
        $this->make = $make;
        $this->model = $model;
    }

    public function displayInfo() {
        echo "Car make: " . $this->make . ", Model: " . $this->model;
    }
}

$car1 = new Car("Toyota", "Corolla");
$car1->displayInfo();  // Output: Car make: Toyota, Model: Corolla
?>
```

- `__construct()` initializes the object properties when the object is created.

### 5. **Inheritance**

**Inheritance** allows one class to inherit properties and methods from another class. The class that inherits is called the **child class**, and the class being inherited from is called the **parent class**.

#### Syntax:
```php
<?php
class ParentClass {
    public $property;

    public function __construct($property) {
        $this->property = $property;
    }

    public function display() {
        echo "Property: " . $this->property;
    }
}

class ChildClass extends ParentClass {
    public function sayHello() {
        echo "Hello from the child class!";
    }
}

$child = new ChildClass("Inherited Property");
$child->display();  // Inherited method from ParentClass
$child->sayHello(); // Method in ChildClass
?>
```

- `extends`: The `ChildClass` inherits the properties and methods of `ParentClass`.
- The `ChildClass` can also have its own methods.

### 6. **Function Overriding**

**Function Overriding** occurs when a subclass redefines a method that is already defined in its parent class. The child class method will override the parent class method.

#### Syntax:
```php
<?php
class Animal {
    public function speak() {
        echo "The animal makes a sound.";
    }
}

class Dog extends Animal {
    public function speak() {
        echo "The dog barks.";
    }
}

$dog = new Dog();
$dog->speak();  // Output: The dog barks.
?>
```

- The `Dog` class overrides the `speak()` method of the `Animal` class, providing its own implementation.

### 7. **Interfaces**

An **interface** defines a contract for classes. A class that implements an interface must implement all the methods declared in the interface.

#### Syntax:
```php
<?php
interface Animal {
    public function sound(); // Interface method (does not have a body)
}

class Dog implements Animal {
    public function sound() {
        echo "Bark";
    }
}

$dog = new Dog();
$dog->sound();  // Output: Bark
?>
```

- `interface`: Declares an interface.
- `implements`: The class `Dog` implements the `Animal` interface and defines the `sound()` method.

### 8. **Abstract Classes**

An **abstract class** is a class that cannot be instantiated directly and is meant to be inherited by other classes. It may contain abstract methods (methods without implementation) that must be implemented by subclasses.

#### Syntax:
```php
<?php
abstract class Animal {
    abstract public function sound(); // Abstract method, no body

    public function sleep() {
        echo "Sleeping...";
    }
}

class Dog extends Animal {
    public function sound() {
        echo "Bark";
    }
}

$dog = new Dog();
$dog->sound();  // Output: Bark
$dog->sleep();  // Output: Sleeping...
?>
```

- `abstract`: Used to declare abstract methods and classes.
- Abstract classes can have both abstract and concrete methods.
- A subclass must implement all abstract methods.

### **Key Concepts Recap**:

- **Classes**: Templates for creating objects.
- **Objects**: Instances of classes.
- **Constructor**: Initializes properties when an object is created.
- **Inheritance**: A class can inherit properties and methods from another class.
- **Function Overriding**: A subclass can override a parent class method.
- **Interfaces**: Define methods that classes must implement.
- **Abstract Classes**: Classes that cannot be instantiated directly and may contain abstract methods.

---

### **Summary of OOP Concepts in PHP**:

- **Defining Classes**: Classes encapsulate data and behavior.
- **Creating Objects**: Use the `new` keyword to create objects.
- **Member Functions**: Methods inside classes that define behavior.
- **Constructor Functions**: Special methods for initializing objects.
- **Inheritance**: Allows one class to inherit from another.
- **Function Overriding**: Subclass can modify inherited behavior.
- **Interfaces**: Define methods that must be implemented by a class.
- **Abstract Classes**: Serve as a blueprint for other classes, may contain both implemented and unimplemented methods.

These concepts form the foundation of object-oriented programming in PHP, enabling you to write clean, reusable, and maintainable code.