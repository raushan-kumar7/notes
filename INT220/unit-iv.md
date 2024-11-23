# Unit IV :: PHP Cookies, Sessions and Strings Handling
## Topics
PHP Cookie Handling, PHP Session Handling, PHP 
Login Session, Strings and Patterns, Matching, PHP Sending Emails, PHP File Uploading, PHP Filters, 
PHP Error Handling

---

### **PHP Cookies, Sessions, and String Handling**

PHP provides several tools for managing user sessions, cookies, handling strings, sending emails, uploading files, and handling errors. These features are crucial for developing interactive and dynamic websites. Below are the key topics related to PHP cookie and session handling, string manipulation, email sending, file uploads, filters, and error handling.

---

### 1. **PHP Cookie Handling**

Cookies are small pieces of data stored on the user's browser that can be used to remember information between page requests.

#### Setting a Cookie:
The `setcookie()` function is used to create a cookie in PHP.

Example:
```php
<?php
// Set a cookie that expires in 1 hour
setcookie("user", "JohnDoe", time() + 3600, "/"); // 3600 seconds = 1 hour
?>
```

Parameters:
- `"user"`: The name of the cookie.
- `"JohnDoe"`: The value of the cookie.
- `time() + 3600`: The expiration time in seconds (1 hour from now).
- `"/"`: The path where the cookie is available. `/` means it's available across the entire website.

#### Accessing a Cookie:
Once a cookie is set, you can access it using the `$_COOKIE` superglobal.

Example:
```php
<?php
if(isset($_COOKIE["user"])) {
    echo "Welcome " . $_COOKIE["user"];
} else {
    echo "Cookie is not set!";
}
?>
```

#### Deleting a Cookie:
To delete a cookie, you can set its expiration time to a time in the past.

Example:
```php
<?php
setcookie("user", "", time() - 3600, "/"); // Delete the cookie by setting expiration time to past
?>
```

### 2. **PHP Session Handling**

Sessions allow you to store user information across multiple pages. Unlike cookies, session data is stored on the server.

#### Starting a Session:
You need to call `session_start()` at the beginning of the script to start a session.

Example:
```php
<?php
session_start(); // Start the session
$_SESSION['username'] = 'JohnDoe'; // Store session data
?>
```

#### Accessing Session Data:
To access session variables, use the `$_SESSION` superglobal.

Example:
```php
<?php
session_start();
echo "Hello, " . $_SESSION['username']; // Output: Hello, JohnDoe
?>
```

#### Destroying a Session:
You can destroy a session with `session_destroy()` to remove all session data.

Example:
```php
<?php
session_start();
session_unset(); // Remove all session variables
session_destroy(); // Destroy the session
?>
```

### 3. **PHP Login Session**

Login sessions allow users to log in and remain authenticated across pages. You can create a simple login system by combining sessions with form handling.

Example:
```php
<?php
session_start(); // Start session

// Assuming credentials are verified
$username = "admin";
$password = "password123";

// Validate credentials (For demonstration purposes)
if ($_POST['username'] == $username && $_POST['password'] == $password) {
    $_SESSION['loggedin'] = true;
    $_SESSION['username'] = $username;
    echo "Logged in successfully!";
} else {
    echo "Invalid credentials!";
}
?>
```

To check if the user is logged in:
```php
<?php
session_start();
if(isset($_SESSION['loggedin']) && $_SESSION['loggedin'] == true) {
    echo "Welcome, " . $_SESSION['username'];
} else {
    echo "Please log in first.";
}
?>
```

### 4. **PHP Strings and Patterns Matching**

PHP provides several functions for manipulating strings and matching patterns.

#### String Functions:
- `strlen()`: Returns the length of a string.
- `substr()`: Returns a part of a string.
- `str_replace()`: Replaces all occurrences of a search string with a replacement string.

Example:
```php
$str = "Hello World!";
echo strlen($str); // Output: 12
echo substr($str, 6, 5); // Output: World
echo str_replace("World", "PHP", $str); // Output: Hello PHP!
```

#### Regular Expressions (Pattern Matching):
PHP supports regular expressions for pattern matching using `preg_match()`, `preg_replace()`, and other functions.

Example:
```php
$pattern = "/^abc/";
$string = "abcdef";
if (preg_match($pattern, $string)) {
    echo "Pattern found!";
} else {
    echo "Pattern not found!";
}
```

### 5. **PHP Sending Emails**

PHP can send emails using the `mail()` function.

#### Sending an Email:
```php
<?php
$to = "recipient@example.com";
$subject = "Test Email";
$message = "Hello, this is a test email.";
$headers = "From: sender@example.com";

if(mail($to, $subject, $message, $headers)) {
    echo "Email sent successfully.";
} else {
    echo "Failed to send email.";
}
?>
```

- `$to`: Recipient's email address.
- `$subject`: Subject of the email.
- `$message`: The content of the email.
- `$headers`: Optional header information like the sender’s email.

### 6. **PHP File Uploading**

PHP allows you to upload files through HTML forms and process them server-side.

#### HTML Form for File Upload:
```html
<form action="upload.php" method="POST" enctype="multipart/form-data">
    Select file to upload: 
    <input type="file" name="fileToUpload" id="fileToUpload">
    <input type="submit" value="Upload File" name="submit">
</form>
```

#### PHP Script to Handle File Upload:
```php
<?php
if(isset($_POST["submit"])) {
    $target_dir = "uploads/";
    $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
    
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        echo "The file ". htmlspecialchars(basename($_FILES["fileToUpload"]["name"])) . " has been uploaded.";
    } else {
        echo "Sorry, there was an error uploading your file.";
    }
}
?>
```

- `$_FILES`: PHP superglobal for accessing file data.
- `move_uploaded_file()`: Moves the uploaded file to a specified location.

### 7. **PHP Filters**

PHP provides filter functions to validate and sanitize data. Some common filters include `FILTER_VALIDATE_EMAIL`, `FILTER_SANITIZE_STRING`, etc.

#### Example of Sanitizing and Validating Email:
```php
$email = "user@example.com";

// Validate email
if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo "Valid email address.";
} else {
    echo "Invalid email address.";
}

// Sanitize email
$sanitized_email = filter_var($email, FILTER_SANITIZE_EMAIL);
echo $sanitized_email; // Output: user@example.com
```

### 8. **PHP Error Handling**

Error handling in PHP can be done using `try-catch` blocks and custom error handlers.

#### Example of Exception Handling:
```php
<?php
try {
    // Some code that may throw an exception
    if (!file_exists("somefile.txt")) {
        throw new Exception("File not found!");
    }
} catch (Exception $e) {
    echo 'Caught exception: ',  $e->getMessage(), "\n";
}
?>
```

#### Custom Error Handler:
```php
<?php
function customError($errno, $errstr) {
    echo "Error: [$errno] $errstr";
}

// Set the custom error handler
set_error_handler("customError");

// Trigger an error
echo($test); // Undefined variable
?>
```

---

### **Summary**

- **Cookies**: Store small pieces of data on the client’s browser using `setcookie()` and access them with `$_COOKIE`.
- **Sessions**: Store data on the server across requests using `session_start()` and access with `$_SESSION`.
- **Login Sessions**: Handle user login states using sessions to authenticate users.
- **Strings and Pattern Matching**: Use functions like `strlen()`, `substr()`, `preg_match()` for string manipulation and pattern matching.
- **Email**: Send emails using `mail()` function.
- **File Uploading**: Handle file uploads with the `$_FILES` superglobal and `move_uploaded_file()`.
- **Filters**: Validate and sanitize data using PHP filters like `FILTER_VALIDATE_EMAIL` and `FILTER_SANITIZE_STRING`.
- **Error Handling**: Handle errors using `try-catch` blocks and custom error handlers.

These topics provide a solid foundation for managing cookies, sessions, and performing common tasks like file uploads, email sending, and error handling in PHP.