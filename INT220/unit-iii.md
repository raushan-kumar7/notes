# Unit III :: PHP Forms
## Topics
PHP Form handling, PHP GET and POST, PHP Form Validation, PHP Form Sanitization

---

### **PHP Forms**

PHP provides robust tools for handling forms, which are essential for capturing user input and interacting with users on a website. Below are key topics for PHP form handling, including methods, validation, and sanitization.

---

### 1. **PHP Form Handling**

When a user submits a form, the data is sent to the server. PHP processes the form data using either the `GET` or `POST` method, depending on how the form is set up.

- **Form Creation**: To create a form, you use the `<form>` HTML element and define input fields.
  
Example:
```html
<form method="POST" action="process.php">
    <label for="name">Name:</label>
    <input type="text" name="name" id="name" required>
    
    <label for="email">Email:</label>
    <input type="email" name="email" id="email" required>
    
    <input type="submit" value="Submit">
</form>
```

In the above form:
- `method="POST"` specifies how the form data will be sent to the server. You can use `GET` or `POST` (more common for form submissions where data should not be exposed in the URL).
- `action="process.php"` specifies the PHP file to process the form data.

#### Processing Form Data in PHP:
To capture the data from the form, PHP uses the `$_GET` or `$_POST` superglobals.

Example (`process.php`):
```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    echo "Name: $name, Email: $email";
}
?>
```

- **`$_POST`** is used for data sent via the `POST` method.
- **`$_GET`** is used for data sent via the `GET` method.

### 2. **PHP GET and POST**

- **GET**: Data sent via the `GET` method is appended to the URL in a query string. This method is suitable for non-sensitive data (e.g., search queries). However, it has size limitations, and data is visible in the URL, so it’s not secure.
  
Example:
```php
<form method="GET" action="process.php">
    <input type="text" name="name" required>
    <input type="submit" value="Submit">
</form>
```
In the above example, the form data will be visible in the URL like `process.php?name=John`.

- **POST**: Data sent via the `POST` method is not visible in the URL, and it's used when submitting sensitive data or large amounts of information. It’s more secure than `GET`.
  
Example:
```php
<form method="POST" action="process.php">
    <input type="password" name="password" required>
    <input type="submit" value="Submit">
</form>
```

### 3. **PHP Form Validation**

Validation ensures that the data entered by the user is in the correct format before processing it. You can validate forms on the client side (using JavaScript) and on the server side (using PHP).

#### Client-Side Validation (HTML5):
HTML5 allows you to specify simple form validations like `required`, `type`, `pattern`, etc.

Example:
```html
<form method="POST" action="process.php">
    <input type="text" name="name" required>
    <input type="email" name="email" required>
    <input type="submit" value="Submit">
</form>
```

Here, the `required` attribute ensures that the user cannot submit the form without entering a value.

#### Server-Side Validation (PHP):
Even if you validate on the client side, you should always validate data on the server side to ensure security.

Example:
```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    
    if (empty($name) || empty($email)) {
        echo "Name and email are required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "Invalid email format.";
    } else {
        echo "Form submitted successfully.";
    }
}
?>
```

In the above example:
- We check if the `name` and `email` fields are empty.
- We use `filter_var()` to validate the email format.

### 4. **PHP Form Sanitization**

Sanitization ensures that the form data is cleaned and safe to use before storing it in a database or using it in further processing. It helps prevent security issues like SQL injection, XSS (Cross-site Scripting), and other attacks.

#### Sanitizing Data:

Sanitizing can be done using PHP functions such as `filter_var()`, `htmlspecialchars()`, and `trim()`.

- **`filter_var()`**: It can sanitize and validate data (like removing unwanted characters).
  
Example (Sanitize email):
```php
$email = filter_var($_POST['email'], FILTER_SANITIZE_EMAIL);
```

- **`htmlspecialchars()`**: Converts special characters to HTML entities to prevent XSS attacks.
  
Example (Sanitize name):
```php
$name = htmlspecialchars($_POST['name']);
```

- **`trim()`**: Removes unnecessary spaces from the beginning and end of the input data.
  
Example:
```php
$name = trim($_POST['name']);
```

#### Example of Combining Sanitization and Validation:
```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Sanitize input data
    $name = htmlspecialchars(trim($_POST['name']));
    $email = filter_var(trim($_POST['email']), FILTER_SANITIZE_EMAIL);
    
    // Validate data
    if (empty($name) || empty($email)) {
        echo "Name and email are required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "Invalid email format.";
    } else {
        echo "Form submitted successfully.";
    }
}
?>
```

In the above code:
- **Sanitization**: Removes unnecessary spaces and converts special characters to HTML entities.
- **Validation**: Ensures that the data is in the correct format.

---

### **Summary**

- **PHP Form Handling**: Forms can be submitted using `GET` or `POST` methods. The `$_GET` and `$_POST` superglobals are used to access the data.
- **GET vs. POST**: `GET` appends data to the URL and is limited in size, while `POST` sends data in the request body and is more secure for sensitive data.
- **Form Validation**: You can validate data using HTML5 attributes on the client side and PHP functions on the server side.
- **Form Sanitization**: Sanitization cleans the data before using it, ensuring no malicious data is processed (e.g., using `filter_var()`, `htmlspecialchars()`, `trim()`).

By combining form validation and sanitization, you ensure both data integrity and security in PHP.