# Unit II :: PHP Arrays and Functions
## Topics
PHP Associative Arrays, PHP Multi-Dimensional Arrays, PHP Functions, Syntax, Arguments and Variables, References, Pass by Value & Pass by references, Return Values, Variable Scope, PHP include() and PHP require(), PHP Enumerated Arrays

---


### **PHP Arrays**

Arrays in PHP are used to store multiple values in a single variable. PHP supports three types of arrays:

#### 1. **PHP Associative Arrays**

An **associative array** stores data in key-value pairs, where each key is associated with a specific value.

Example:
```php
$person = array(
    "name" => "John",
    "age" => 25,
    "city" => "New York"
);
echo $person["name"]; // Outputs: John
```

In associative arrays, keys are not automatically numeric but can be strings or integers.

#### 2. **PHP Multi-Dimensional Arrays**

A **multi-dimensional array** is an array of arrays. It allows you to store more complex data structures (e.g., tables, matrices, etc.).

Example:
```php
$students = array(
    array("John", 25, "A"),
    array("Jane", 22, "B"),
    array("Doe", 24, "A")
);

echo $students[1][0]; // Outputs: Jane
```

You can access the elements by providing two or more indices.

#### 3. **PHP Enumerated Arrays**

An **enumerated array** is a basic array that stores values with numerical indices, starting from 0 by default.

Example:
```php
$colors = array("Red", "Green", "Blue");
echo $colors[1]; // Outputs: Green
```

You can also create enumerated arrays manually with custom indices:
```php
$fruits = array(1 => "Apple", 2 => "Banana");
```

---

### **PHP Functions**

Functions in PHP allow you to group code into reusable blocks.

#### 1. **PHP Function Syntax**

To define a function in PHP, use the `function` keyword followed by the function name and a pair of parentheses `()`.

Example:
```php
function greet() {
    echo "Hello, World!";
}
greet(); // Outputs: Hello, World!
```

#### 2. **Arguments and Variables**

Functions can accept parameters (arguments) and work with variables.

Example:
```php
function add($a, $b) {
    return $a + $b;
}
echo add(5, 3); // Outputs: 8
```

You can also pass default values to arguments:
```php
function greet($name = "Guest") {
    echo "Hello, $name!";
}
greet(); // Outputs: Hello, Guest!
greet("John"); // Outputs: Hello, John!
```

#### 3. **References (Pass by Reference)**

By default, PHP passes arguments to functions **by value** (copies the value). However, you can pass arguments **by reference** using the `&` symbol.

- **Pass by Value**: The original value is not modified.
  
Example:
```php
function addFive($number) {
    $number += 5;
}
$number = 10;
addFive($number);
echo $number; // Outputs: 10 (value remains unchanged)
```

- **Pass by Reference**: The original value is modified.
  
Example:
```php
function addFive(&$number) {
    $number += 5;
}
$number = 10;
addFive($number);
echo $number; // Outputs: 15 (value is changed)
```

#### 4. **Return Values**

Functions can return values using the `return` keyword.

Example:
```php
function multiply($a, $b) {
    return $a * $b;
}
$result = multiply(4, 5);
echo $result; // Outputs: 20
```

#### 5. **Variable Scope**

PHP has different variable scopes:
- **Global Scope**: Variables declared outside functions or classes are in the global scope.
- **Local Scope**: Variables declared inside a function are in the local scope and cannot be accessed outside the function.
- **Global Keyword**: To access a global variable inside a function, use the `global` keyword.

Example:
```php
$globalVar = "I am global";

function test() {
    global $globalVar;
    echo $globalVar; // Outputs: I am global
}
test();
```

You can also use the `$GLOBALS` array to access global variables within functions:
```php
$globalVar = "I am global";

function test() {
    echo $GLOBALS['globalVar']; // Outputs: I am global
}
test();
```

---

### **PHP Include and Require**

Both `include()` and `require()` are used to include the content of one PHP file into another. The difference between them is how they handle errors.

#### 1. **include()**

The `include()` statement includes a file into the current file. If the file is not found, it will produce a warning, but the script will continue executing.

Example:
```php
include('header.php');
```

#### 2. **require()**

The `require()` statement includes a file into the current file. If the file is not found, it will produce a fatal error, and the script will stop executing.

Example:
```php
require('header.php');
```

In general:
- Use `include()` if the file is not critical for the script to continue.
- Use `require()` if the file is essential for the script’s functionality.

You can also use `include_once()` and `require_once()` to ensure the file is included only once, even if it’s called multiple times.

---

### **Summary:**

- **Arrays** in PHP allow you to store multiple values. There are indexed, associative, and multi-dimensional arrays.
- **Functions** are reusable blocks of code, which can accept parameters, return values, and have different scopes for variables.
- **Pass-by-value** copies the variable’s value, whereas **pass-by-reference** modifies the original variable.
- Use `include()` and `require()` to incorporate external files, with `require()` halting execution on failure, while `include()` only gives a warning.
