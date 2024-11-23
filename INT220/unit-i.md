# Unit I :: PHP Fundamentals
## Topics
PHP, MySQL and XAMPP Installation, PHP Basic Syntax, PHP Data Types, PHP Variables, PHP Constants, PHP Expressions, PHP Operators, PHP Control Structures, PHP Loops

---

Here’s an overview of the PHP fundamentals you mentioned:

### 1. **PHP, MySQL, and XAMPP Installation**

- **PHP**: PHP (Hypertext Preprocessor) is a widely-used open-source server-side scripting language for web development. It is used to create dynamic web pages.
- **MySQL**: MySQL is an open-source relational database management system. It is commonly used with PHP to store data for web applications.
- **XAMPP**: XAMPP is a free and open-source cross-platform web server solution that includes Apache, MySQL, and PHP. It allows you to run PHP and MySQL locally on your machine for development purposes.
  
#### Steps to Install:
1. **Download XAMPP** from the [official website](https://www.apachefriends.org/index.html).
2. **Install XAMPP** and select the components (Apache, MySQL, PHP) you want to install.
3. **Start Apache and MySQL** through the XAMPP Control Panel.
4. **Test PHP** by creating a PHP file (`test.php`) in the `htdocs` folder inside the XAMPP installation directory and accessing it via `http://localhost/test.php`.

### 2. **PHP Basic Syntax**

- PHP code is embedded within HTML code using `<?php` and `?>` tags.
  
Example:
```php
<?php
  echo "Hello, World!";
?>
```

- PHP statements end with a semicolon (`;`).

### 3. **PHP Data Types**
PHP supports several data types:
- **String**: Represents textual data (e.g., `"Hello World"`).
- **Integer**: Represents whole numbers (e.g., `100`).
- **Float (double)**: Represents numbers with decimal points (e.g., `10.5`).
- **Boolean**: Represents two possible values: `true` or `false`.
- **Array**: Represents a collection of values (indexed or associative).
- **Object**: Represents an instance of a class.
- **NULL**: Represents an empty variable.

### 4. **PHP Variables**

- Variables in PHP start with the `$` symbol followed by the variable name. They are dynamically typed, meaning the type is determined by the value assigned.
  
Example:
```php
$name = "John";
$age = 25;
```

- Variable names must begin with a letter or underscore and can contain letters, numbers, and underscores.

### 5. **PHP Constants**

- Constants are defined using the `define()` function and cannot be changed once set.

Example:
```php
define("SITE_NAME", "My Website");
echo SITE_NAME;  // Outputs: My Website
```

### 6. **PHP Expressions**

- An expression is a combination of values, variables, operators, and functions that can be evaluated to produce a result.
  
Example:
```php
$sum = 5 + 10;  // Expression that evaluates to 15
```

### 7. **PHP Operators**

PHP supports several types of operators:
- **Arithmetic Operators**: Used for mathematical operations.
  ```php
  $a + $b;  // Addition
  $a - $b;  // Subtraction
  $a * $b;  // Multiplication
  $a / $b;  // Division
  $a % $b;  // Modulus
  ```
  
- **Assignment Operators**: Used to assign values.
  ```php
  $x = 10;  // Assigns 10 to $x
  $x += 5;  // Adds 5 to $x (equivalent to $x = $x + 5)
  ```

- **Comparison Operators**: Used to compare values.
  ```php
  $a == $b;  // Equal
  $a != $b;  // Not equal
  $a > $b;   // Greater than
  $a < $b;   // Less than
  ```

- **Logical Operators**: Used for logical operations.
  ```php
  $a && $b;  // Logical AND
  $a || $b;  // Logical OR
  ! $a;       // Logical NOT
  ```

### 8. **PHP Control Structures**

- **If-Else**: Used to execute code based on conditions.
  ```php
  if ($age >= 18) {
    echo "You are an adult.";
  } else {
    echo "You are a minor.";
  }
  ```

- **Switch**: Used for multiple conditions.
  ```php
  switch ($day) {
    case 1:
      echo "Monday";
      break;
    case 2:
      echo "Tuesday";
      break;
    default:
      echo "Invalid day";
  }
  ```

### 9. **PHP Loops**

Loops are used to repeat a block of code.

- **For Loop**: Used when the number of iterations is known.
  ```php
  for ($i = 0; $i < 5; $i++) {
    echo $i;
  }
  ```

- **While Loop**: Used when the condition is evaluated before each iteration.
  ```php
  $i = 0;
  while ($i < 5) {
    echo $i;
    $i++;
  }
  ```

- **Do-While Loop**: Used when the condition is evaluated after each iteration.
  ```php
  $i = 0;
  do {
    echo $i;
    $i++;
  } while ($i < 5);
  ```

These are the basics to get started with PHP. As you dive deeper, you’ll explore advanced concepts such as functions, forms, sessions, cookies, and object-oriented programming.