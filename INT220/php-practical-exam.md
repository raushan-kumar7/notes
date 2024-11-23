# INT220: SERVER SIDE SCRIPTING
## Practical Examination and Viva Questions Guide

### PRACTICAL EXAMINATION QUESTIONS

#### Question 1: Form Validation and Database Integration
**Time: 30 minutes | Marks: 15**

Create a PHP registration form with the following requirements:
1. Fields: Username, Email, Password, Confirm Password
2. Implement client-side and server-side validation
3. Store the data in MySQL database
4. Display success message after successful registration

Sample Solution Structure:
```php
<?php
// Database connection
$conn = mysqli_connect("localhost", "username", "password", "database");

// Form validation
if(isset($_POST['submit'])) {
    $username = sanitize_input($_POST['username']);
    $email = sanitize_input($_POST['email']);
    $password = $_POST['password'];
    $confirm_password = $_POST['confirm_password'];
    
    // Validation logic
    if($password !== $confirm_password) {
        $error = "Passwords do not match";
    } else {
        // Insert into database
        $hashed_password = password_hash($password, PASSWORD_DEFAULT);
        $query = "INSERT INTO users (username, email, password) VALUES (?, ?, ?)";
        // Complete the query execution
    }
}

function sanitize_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
?>
```

#### Question 2: Session-Based Shopping Cart
**Time: 45 minutes | Marks: 20**

Create a simple shopping cart using PHP sessions with the following features:
1. Display products from database
2. Add/Remove items from cart
3. Show cart total
4. Implement checkout functionality

#### Question 3: File Upload with Image Processing
**Time: 30 minutes | Marks: 15**

Create a PHP script that:
1. Allows image upload
2. Validates file type and size
3. Creates a thumbnail
4. Stores image information in database

### VIVA QUESTIONS AND ANSWERS

#### Basic PHP Concepts

1. **Q: What is the difference between echo and print in PHP?**
   - A: Both echo and print are used to output data in PHP, but:
     - echo can take multiple parameters and has no return value
     - print can only take one parameter and always returns 1
     - echo is marginally faster than print

2. **Q: Explain the difference between include and require?**
   - A: Both include and require incorporate external files, but:
     - require will produce a fatal error if the file is not found
     - include will only produce a warning
     - Use require when the file is absolutely necessary
     - Use include when the file is optional

#### Arrays and Functions

3. **Q: What are the different types of arrays in PHP?**
   - A: PHP has three types of arrays:
     - Indexed arrays (Numeric arrays)
     - Associative arrays (Key-value pairs)
     - Multidimensional arrays (Arrays containing arrays)

4. **Q: Explain the difference between $$ and $_POST?**
   - A: 
     - $$ is variable variable, allows dynamic variable names
     - $_POST is a superglobal used to collect form data sent with HTTP POST method

#### Sessions and Cookies

5. **Q: What is the difference between sessions and cookies?**
   - A:
     - Sessions are stored on server, cookies on client
     - Sessions are more secure for sensitive data
     - Cookies can persist across browser sessions
     - Sessions typically expire when browser closes

6. **Q: How do you start a session in PHP?**
   - A: Use session_start() at the beginning of the script, before any HTML output

#### Database and MySQL

7. **Q: What are prepared statements and why should we use them?**
   - A:
     - Prepared statements are precompiled SQL statements
     - Prevent SQL injection attacks
     - Improve performance for repeated queries
     - Automatically escape special characters

8. **Q: Explain the difference between mysqli and PDO?**
   - A:
     - PDO can work with multiple database types
     - mysqli is specific to MySQL
     - PDO offers a more consistent API
     - Both support prepared statements and transactions

#### Object-Oriented PHP

9. **Q: What is the difference between abstract class and interface?**
   - A:
     - Abstract classes can have method implementations
     - Interfaces can only have method declarations
     - A class can implement multiple interfaces
     - A class can extend only one abstract class

10. **Q: Explain constructor and destructor in PHP?**
    - A:
      - Constructor (__construct) is called when object is created
      - Destructor (__destruct) is called when object is destroyed
      - Constructor can take parameters, destructor cannot
      - Used for initialization and cleanup respectively

### EVALUATION CRITERIA

#### Practical Examination (50 marks)
- Code functionality: 20 marks
- Proper validation: 10 marks
- Database integration: 10 marks
- Code organization and comments: 5 marks
- Error handling: 5 marks

#### Viva Voce (50 marks)
- Understanding of concepts: 20 marks
- Implementation knowledge: 15 marks
- Problem-solving ability: 10 marks
- Communication skills: 5 marks

### IMPORTANT NOTES FOR EVALUATORS

1. Check if students follow proper coding standards
2. Verify security implementations (input validation, prepared statements)
3. Assess error handling mechanisms
4. Evaluate database design decisions
5. Check for code optimization and best practices

### MARKING SCHEME

- 90-100: Excellent understanding and implementation
- 80-89: Good grasp of concepts with minor improvements needed
- 70-79: Satisfactory performance with some gaps
- 60-69: Basic understanding with significant improvements needed
- Below 60: Needs substantial improvement

