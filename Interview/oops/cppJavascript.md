# TCS Digital Interview Questions & Answers

## C++ Questions and Answers

### Basic Level Questions

#### 1. What is the difference between C and C++?

**Answer:**
- **C** is a procedural programming language, while **C++** is an object-oriented programming language
- **C** supports only built-in data types, while **C++** supports both built-in and user-defined data types (classes)
- **C** uses functions for code organization, while **C++** uses classes and objects
- **C++** supports features like inheritance, polymorphism, encapsulation, and abstraction
- **C++** has additional libraries like STL (Standard Template Library)
- **C++** supports function overloading and operator overloading, C doesn't
- **C++** has better type checking and supports references along with pointers

#### 2. Explain the difference between struct and class in C++

**Answer:**
- **Default Access Level:**
  - `struct`: Members are **public** by default
  - `class`: Members are **private** by default
- **Usage Convention:**
  - `struct`: Typically used for simple data containers
  - `class`: Used for complex objects with behavior (methods)
- **Functionality:** Both can have constructors, destructors, member functions, and inheritance

```cpp
struct Point {
    int x, y;  // public by default
};

class Rectangle {
    int width, height;  // private by default
public:
    void setDimensions(int w, int h) {
        width = w; height = h;
    }
};
```

#### 3. What are access specifiers? Explain public, private, and protected

**Answer:**
- **public**: Members are accessible from anywhere in the program
- **private**: Members are only accessible within the same class
- **protected**: Members are accessible within the class and its derived classes

```cpp
class Example {
private:
    int privateVar;     // Only accessible within this class
    
protected:
    int protectedVar;   // Accessible in this class and derived classes
    
public:
    int publicVar;      // Accessible everywhere
    
    void publicMethod() {
        privateVar = 10;    // OK - same class
        protectedVar = 20;  // OK - same class
    }
};
```

#### 4. What is a constructor and destructor?

**Answer:**
**Constructor:**
- Special member function called automatically when an object is created
- Same name as the class, no return type
- Used for initialization

**Destructor:**
- Special member function called automatically when an object is destroyed
- Same name as class with `~` prefix, no return type, no parameters
- Used for cleanup (releasing memory, closing files, etc.)

```cpp
class Student {
private:
    string name;
    int* grades;
    
public:
    // Constructor
    Student(string n) : name(n) {
        grades = new int[10];
        cout << "Constructor called for " << name << endl;
    }
    
    // Destructor
    ~Student() {
        delete[] grades;
        cout << "Destructor called for " << name << endl;
    }
};
```

#### 5. Difference between call by value and call by reference

**Answer:**
**Call by Value:**
- Copy of the actual parameter is passed
- Changes don't affect the original variable
- More memory usage due to copying

**Call by Reference:**
- Address of the actual parameter is passed
- Changes affect the original variable
- More memory efficient

```cpp
// Call by value
void byValue(int x) {
    x = 100;  // Original variable unchanged
}

// Call by reference
void byReference(int& x) {
    x = 100;  // Original variable modified
}

int main() {
    int num = 10;
    byValue(num);      // num remains 10
    byReference(num);  // num becomes 100
}
```

### Intermediate Level Questions

#### 1. What is virtual function and why is it used?

**Answer:**
A virtual function enables **runtime polymorphism** (dynamic binding). It allows a derived class to override a base class method, and the correct version is called based on the object type at runtime.

```cpp
class Animal {
public:
    virtual void makeSound() {  // Virtual function
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {  // Override base class method
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* ptr = new Dog();
    ptr->makeSound();  // Outputs: "Dog barks" (runtime polymorphism)
    delete ptr;
}
```

#### 2. Explain function overloading and operator overloading

**Answer:**
**Function Overloading:**
- Multiple functions with the same name but different parameters
- Resolved at compile time (compile-time polymorphism)

**Operator Overloading:**
- Giving additional meanings to operators for user-defined types

```cpp
// Function Overloading
class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

// Operator Overloading
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

#### 3. What is the difference between delete and delete[] operators?

**Answer:**
- **delete**: Used to deallocate memory for a single object
- **delete[]**: Used to deallocate memory for an array of objects

```cpp
int* ptr = new int(10);        // Single object
int* arr = new int[10];        // Array of objects

delete ptr;     // Correct for single object
delete[] arr;   // Correct for array

// Wrong usage:
// delete arr;     // Undefined behavior
// delete[] ptr;   // Undefined behavior
```

#### 4. What are inline functions? Advantages and disadvantages?

**Answer:**
**Inline Functions:** Functions expanded at compile time instead of being called.

**Advantages:**
- Eliminates function call overhead
- Faster execution for small functions
- Better optimization by compiler

**Disadvantages:**
- Increases code size (code bloat)
- Not suitable for large functions
- Debugging can be difficult

```cpp
inline int square(int x) {
    return x * x;
}

int main() {
    int result = square(5);  // Expanded to: int result = 5 * 5;
}
```

#### 5. Explain static members in a class

**Answer:**
**Static members** belong to the class rather than any specific object.

**Static Variables:**
- Shared by all objects of the class
- Only one copy exists in memory
- Must be defined outside the class

**Static Functions:**
- Can be called without creating an object
- Can only access static members

```cpp
class Counter {
private:
    static int count;  // Static variable declaration
    
public:
    Counter() { count++; }
    
    static int getCount() {  // Static function
        return count;
    }
};

int Counter::count = 0;  // Static variable definition

int main() {
    Counter c1, c2;
    cout << Counter::getCount();  // Outputs: 2
}
```

### Advanced Level Questions

#### 1. What is RAII (Resource Acquisition Is Initialization)?

**Answer:**
RAII is a programming idiom where resource allocation is tied to object lifetime. Resources are acquired in the constructor and released in the destructor.

**Benefits:**
- Automatic resource management
- Exception safety
- Prevents resource leaks

```cpp
class FileHandler {
private:
    FILE* file;
    
public:
    FileHandler(const char* filename) {
        file = fopen(filename, "r");  // Acquire resource
        if (!file) throw runtime_error("Cannot open file");
    }
    
    ~FileHandler() {
        if (file) fclose(file);  // Release resource
    }
    
    // Prevent copying to avoid double deletion
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
};
```

#### 2. Explain move semantics and rvalue references

**Answer:**
**Move Semantics:** Transfers ownership of resources instead of copying them.
**Rvalue References:** References to temporary objects (using `&&`).

```cpp
class MyString {
private:
    char* data;
    size_t size;
    
public:
    // Move constructor
    MyString(MyString&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;  // Transfer ownership
        other.size = 0;
    }
    
    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};
```

#### 3. Difference between shallow copy and deep copy

**Answer:**
**Shallow Copy:**
- Copies only the immediate members
- Pointers are copied, not the data they point to
- Can lead to double deletion problems

**Deep Copy:**
- Copies all data, including dynamically allocated memory
- Creates independent copies

```cpp
class ShallowCopy {
    int* data;
public:
    ShallowCopy(int val) : data(new int(val)) {}
    
    // Default copy constructor (shallow copy)
    // ShallowCopy(const ShallowCopy& other) : data(other.data) {}
};

class DeepCopy {
    int* data;
public:
    DeepCopy(int val) : data(new int(val)) {}
    
    // Deep copy constructor
    DeepCopy(const DeepCopy& other) : data(new int(*other.data)) {}
    
    ~DeepCopy() { delete data; }
};
```

---

## JavaScript Questions and Answers

### Basic Level Questions

#### 1. What are the different data types in JavaScript?

**Answer:**
**Primitive Types:**
- `number`: 42, 3.14
- `string`: "Hello", 'World'
- `boolean`: true, false
- `undefined`: Variable declared but not assigned
- `null`: Intentional absence of value
- `symbol`: Unique identifier (ES6)
- `bigint`: Large integers (ES2020)

**Non-Primitive Types:**
- `object`: Arrays, objects, functions, dates, etc.

```javascript
let num = 42;                    // number
let str = "Hello";               // string
let bool = true;                 // boolean
let undef;                       // undefined
let empty = null;                // null
let sym = Symbol('id');          // symbol
let big = 123n;                  // bigint
let obj = { name: "John" };      // object
let arr = [1, 2, 3];            // object (array)
```

#### 2. Explain the difference between == and === operators

**Answer:**
**== (Equality Operator):**
- Performs type coercion before comparison
- Converts operands to the same type

**=== (Strict Equality Operator):**
- No type coercion
- Compares both value and type

```javascript
console.log(5 == "5");    // true (type coercion)
console.log(5 === "5");   // false (different types)

console.log(true == 1);   // true (true converted to 1)
console.log(true === 1);  // false (different types)

console.log(null == undefined);   // true (special case)
console.log(null === undefined);  // false (different types)
```

#### 3. What is hoisting in JavaScript?

**Answer:**
Hoisting is JavaScript's behavior of moving variable and function declarations to the top of their scope during compilation.

```javascript
// Variable hoisting
console.log(x);  // undefined (not error)
var x = 5;

// Equivalent to:
var x;
console.log(x);  // undefined
x = 5;

// Function hoisting
sayHello();  // "Hello!" (works)

function sayHello() {
    console.log("Hello!");
}

// let and const are hoisted but not initialized
console.log(y);  // ReferenceError
let y = 10;
```

#### 4. Difference between null and undefined

**Answer:**
**undefined:**
- Default value for uninitialized variables
- Missing function parameters
- Missing object properties

**null:**
- Intentional absence of value
- Must be explicitly assigned

```javascript
let a;                    // undefined
let b = null;            // null

function test(param) {
    console.log(param);   // undefined if not passed
}

let obj = {};
console.log(obj.name);   // undefined

// Type checking
console.log(typeof undefined);  // "undefined"
console.log(typeof null);       // "object" (quirk)
```

#### 5. What are template literals?

**Answer:**
Template literals allow embedded expressions and multi-line strings using backticks.

```javascript
const name = "John";
const age = 30;

// String interpolation
const message = `Hello, my name is ${name} and I'm ${age} years old`;

// Multi-line strings
const multiLine = `
    This is a
    multi-line
    string
`;

// Expression evaluation
const result = `The sum is ${5 + 3}`;

// Tagged templates
function highlight(strings, ...values) {
    return strings.reduce((result, string, i) => {
        return result + string + (values[i] ? `<mark>${values[i]}</mark>` : '');
    }, '');
}

const highlighted = highlight`Name: ${name}, Age: ${age}`;
```

### Intermediate Level Questions

#### 1. Explain closures with an example

**Answer:**
A closure is a function that has access to variables in its outer (enclosing) scope even after the outer function has returned.

```javascript
function outerFunction(x) {
    // Outer variable
    let outerVar = x;
    
    // Inner function has access to outerVar
    function innerFunction(y) {
        console.log(outerVar + y);
    }
    
    return innerFunction;
}

const myClosure = outerFunction(10);
myClosure(5); // 15

// Practical example: Counter
function createCounter() {
    let count = 0;
    
    return {
        increment: () => ++count,
        decrement: () => --count,
        getCount: () => count
    };
}

const counter = createCounter();
console.log(counter.increment()); // 1
console.log(counter.increment()); // 2
console.log(counter.getCount());  // 2
```

#### 2. Difference between function declaration and function expression

**Answer:**

```javascript
// Function Declaration
// - Hoisted completely
// - Can be called before definition
sayHello(); // Works

function sayHello() {
    console.log("Hello!");
}

// Function Expression
// - Not hoisted
// - Cannot be called before definition
// sayBye(); // Error: Cannot access 'sayBye' before initialization

const sayBye = function() {
    console.log("Bye!");
};

// Arrow Function Expression
const greet = (name) => {
    return `Hello, ${name}!`;
};

// Key differences:
// 1. Hoisting behavior
// 2. Function expressions can be anonymous
// 3. Arrow functions don't have their own 'this'
```

#### 3. How does prototypal inheritance work?

**Answer:**
JavaScript objects inherit properties and methods from other objects through the prototype chain.

```javascript
// Constructor function
function Animal(name) {
    this.name = name;
}

// Add method to prototype
Animal.prototype.speak = function() {
    console.log(`${this.name} makes a sound`);
};

// Create instances
const dog = new Animal("Dog");
dog.speak(); // "Dog makes a sound"

// Inheritance
function Dog(name, breed) {
    Animal.call(this, name);  // Call parent constructor
    this.breed = breed;
}

// Set up inheritance
Dog.prototype = Object.create(Animal.prototype);
Dog.prototype.constructor = Dog;

// Override method
Dog.prototype.speak = function() {
    console.log(`${this.name} barks`);
};

const myDog = new Dog("Buddy", "Golden Retriever");
myDog.speak(); // "Buddy barks"

// ES6 Class Syntax
class AnimalES6 {
    constructor(name) {
        this.name = name;
    }
    
    speak() {
        console.log(`${this.name} makes a sound`);
    }
}

class DogES6 extends AnimalES6 {
    constructor(name, breed) {
        super(name);
        this.breed = breed;
    }
    
    speak() {
        console.log(`${this.name} barks`);
    }
}
```

#### 4. What are Promises and how do they work?

**Answer:**
Promises represent the eventual completion or failure of an asynchronous operation.

```javascript
// Creating a Promise
const myPromise = new Promise((resolve, reject) => {
    const success = true;
    
    setTimeout(() => {
        if (success) {
            resolve("Operation successful!");
        } else {
            reject("Operation failed!");
        }
    }, 1000);
});

// Using Promises
myPromise
    .then(result => console.log(result))
    .catch(error => console.error(error));

// Promise chaining
fetch('/api/user')
    .then(response => response.json())
    .then(user => fetch(`/api/posts/${user.id}`))
    .then(response => response.json())
    .then(posts => console.log(posts))
    .catch(error => console.error('Error:', error));

// Promise.all() - Wait for all promises
Promise.all([
    fetch('/api/users'),
    fetch('/api/posts'),
    fetch('/api/comments')
])
.then(responses => {
    console.log('All requests completed');
})
.catch(error => {
    console.error('One or more requests failed');
});

// Promise states:
// 1. Pending: Initial state
// 2. Fulfilled: Operation completed successfully
// 3. Rejected: Operation failed
```

#### 5. Explain the concept of 'this' keyword in different contexts

**Answer:**

```javascript
// Global context
console.log(this); // Window object (browser) or global (Node.js)

// Object method
const obj = {
    name: 'John',
    greet: function() {
        console.log(this.name); // 'John' - this refers to obj
    }
};

// Arrow functions don't have their own 'this'
const obj2 = {
    name: 'Jane',
    greet: () => {
        console.log(this.name); // undefined - this refers to global
    }
};

// Constructor function
function Person(name) {
    this.name = name;
    this.greet = function() {
        console.log(this.name); // this refers to the instance
    };
}

const person1 = new Person('Alice');
person1.greet(); // 'Alice'

// Event handler
button.addEventListener('click', function() {
    console.log(this); // this refers to the button element
});

// Explicit binding
const person = { name: 'Bob' };
function introduce() {
    console.log(`Hi, I'm ${this.name}`);
}

introduce.call(person);    // 'Hi, I'm Bob'
introduce.apply(person);   // 'Hi, I'm Bob'
const boundIntroduce = introduce.bind(person);
boundIntroduce();          // 'Hi, I'm Bob'
```

### Advanced Level Questions

#### 1. What is the Event Loop and how does it work?

**Answer:**
The Event Loop is JavaScript's concurrency model that handles asynchronous operations.

**Components:**
- **Call Stack**: Executes functions (LIFO)
- **Web APIs**: Handle async operations (setTimeout, fetch, etc.)
- **Callback Queue**: Holds completed callbacks (FIFO)
- **Microtask Queue**: Holds Promise callbacks (higher priority)

```javascript
console.log('1');

setTimeout(() => console.log('2'), 0);

Promise.resolve().then(() => console.log('3'));

console.log('4');

// Output: 1, 4, 3, 2
// Explanation:
// 1. '1' and '4' execute immediately (synchronous)
// 2. Promise callback goes to microtask queue
// 3. setTimeout callback goes to callback queue
// 4. Microtasks execute before regular callbacks
```

#### 2. Explain async/await and its advantages over Promises

**Answer:**
async/await is syntactic sugar over Promises, making asynchronous code look synchronous.

```javascript
// Promise approach
function fetchUserData() {
    return fetch('/api/user')
        .then(response => response.json())
        .then(user => fetch(`/api/posts/${user.id}`))
        .then(response => response.json())
        .then(posts => {
            return { user, posts };
        })
        .catch(error => {
            console.error('Error:', error);
            throw error;
        });
}

// async/await approach
async function fetchUserDataAsync() {
    try {
        const userResponse = await fetch('/api/user');
        const user = await userResponse.json();
        
        const postsResponse = await fetch(`/api/posts/${user.id}`);
        const posts = await postsResponse.json();
        
        return { user, posts };
    } catch (error) {
        console.error('Error:', error);
        throw error;
    }
}

// Advantages of async/await:
// 1. More readable and maintainable
// 2. Better error handling with try/catch
// 3. Easier debugging
// 4. No callback hell or promise chaining

// Parallel execution with async/await
async function fetchMultipleData() {
    try {
        const [users, posts, comments] = await Promise.all([
            fetch('/api/users').then(r => r.json()),
            fetch('/api/posts').then(r => r.json()),
            fetch('/api/comments').then(r => r.json())
        ]);
        
        return { users, posts, comments };
    } catch (error) {
        console.error('Error:', error);
    }
}
```

#### 3. What are higher-order functions? Give examples

**Answer:**
Higher-order functions are functions that either take other functions as arguments or return functions.

```javascript
// Functions that take other functions as arguments
const numbers = [1, 2, 3, 4, 5];

// map is a higher-order function
const doubled = numbers.map(x => x * 2);

// filter is a higher-order function
const evens = numbers.filter(x => x % 2 === 0);

// reduce is a higher-order function
const sum = numbers.reduce((acc, x) => acc + x, 0);

// Custom higher-order function
function withLogging(fn) {
    return function(...args) {
        console.log(`Calling function with args:`, args);
        const result = fn.apply(this, args);
        console.log(`Function returned:`, result);
        return result;
    };
}

const add = (a, b) => a + b;
const loggedAdd = withLogging(add);
loggedAdd(2, 3); // Logs the call and result

// Function that returns a function
function createMultiplier(factor) {
    return function(number) {
        return number * factor;
    };
}

const double = createMultiplier(2);
const triple = createMultiplier(3);

console.log(double(5)); // 10
console.log(triple(5)); // 15

// Practical example: Event handler factory
function createClickHandler(message) {
    return function(event) {
        alert(message);
        console.log('Event:', event);
    };
}

button.addEventListener('click', createClickHandler('Button clicked!'));
```

#### 4. How does garbage collection work in JavaScript?

**Answer:**
JavaScript uses automatic memory management through garbage collection.

**Mark-and-Sweep Algorithm:**
1. **Mark Phase**: Mark all reachable objects from root references
2. **Sweep Phase**: Deallocate unmarked objects

```javascript
// Objects become eligible for GC when no references exist
function createObjects() {
    let obj1 = { name: 'Object 1' };
    let obj2 = { name: 'Object 2' };
    
    obj1.ref = obj2;
    obj2.ref = obj1;  // Circular reference
    
    return obj1;
}

let myObj = createObjects();
// obj2 is still reachable through obj1.ref

myObj = null;
// Now both objects become eligible for GC
// Modern engines can handle circular references

// Memory leaks to avoid:

// 1. Accidental global variables
function createLeak() {
    leakedVar = 'This becomes global';  // No var/let/const
}

// 2. Forgotten timers
const timer = setInterval(() => {
    // Do something
}, 1000);
// clearInterval(timer); // Don't forget to clear

// 3. Detached DOM nodes
let elements = [];
function addElement() {
    const div = document.createElement('div');
    elements.push(div);  // Keeps reference even after removal
    document.body.appendChild(div);
}

// 4. Closures holding large objects
function createClosure() {
    const largeObject = new Array(1000000).fill('data');
    
    return function() {
        // Even if largeObject isn't used,
        // it's kept in memory due to closure
        console.log('Hello');
    };
}
```

#### 5. What are Web APIs and how do they interact with JavaScript?

**Answer:**
Web APIs are browser-provided interfaces that extend JavaScript's capabilities.

```javascript
// DOM API
const element = document.getElementById('myButton');
element.addEventListener('click', handleClick);

// Fetch API
fetch('/api/data')
    .then(response => response.json())
    .then(data => console.log(data));

// Geolocation API
navigator.geolocation.getCurrentPosition(
    position => {
        console.log('Latitude:', position.coords.latitude);
        console.log('Longitude:', position.coords.longitude);
    },
    error => console.error('Geolocation error:', error)
);

// Local Storage API
localStorage.setItem('user', JSON.stringify({ name: 'John' }));
const user = JSON.parse(localStorage.getItem('user'));

// Web Workers API (for heavy computations)
const worker = new Worker('worker.js');
worker.postMessage({ numbers: [1, 2, 3, 4, 5] });
worker.onmessage = function(e) {
    console.log('Result from worker:', e.data);
};

// Intersection Observer API
const observer = new IntersectionObserver(entries => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            console.log('Element is visible');
        }
    });
});

observer.observe(document.querySelector('.target'));

// How Web APIs work with Event Loop:
// 1. JavaScript calls Web API
// 2. Web API handles operation asynchronously
// 3. Callback is placed in callback queue when complete
// 4. Event loop moves callback to call stack when stack is empty
```

---

## Key Interview Tips

### For Technical Questions:
1. **Start with the basic concept** before diving into details
2. **Provide code examples** when possible
3. **Mention real-world use cases** and practical applications
4. **Discuss advantages and disadvantages** of different approaches
5. **Be prepared to write code** on whiteboard or paper

### For Coding Problems:
1. **Understand the problem** completely before coding
2. **Think out loud** - explain your approach
3. **Start with a brute force solution**, then optimize
4. **Test with edge cases** and discuss time/space complexity
5. **Write clean, readable code** with proper variable names

### General Interview Strategy:
1. **Be honest** about what you know and don't know
2. **Ask clarifying questions** when needed
3. **Show enthusiasm** for learning and problem-solving
4. **Practice explaining concepts** to others
5. **Stay calm** and think through problems methodically