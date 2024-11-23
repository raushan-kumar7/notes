# Unit VI :: Basic MySQL and SQL Queries
## Topics
Database Basics, Indexes, PHP MyAdmin, Connect & Pconnect, 
MySQL Create, MySQL Insert, MySQL Select, MySQL Update, MySQL Delete, MySQL Truncate, MySQL 
Drop, WHERE condition, Order By and Group By, Having, LIKE, AND OR operators, SQL functions 
AVG, COUNT, SUM, MIN, MAX, LCASE, UCASE

---

### **Basic MySQL and SQL Queries**

MySQL is an open-source relational database management system (RDBMS) that uses Structured Query Language (SQL) for querying and managing data. Below is a breakdown of the core concepts and SQL queries you'll need to interact with a MySQL database.

---

### **1. Database Basics**

A **database** is a collection of organized data, typically stored in tables. These tables contain **rows** and **columns**, where:
- **Columns** represent attributes or fields.
- **Rows** represent records or data entries.

- **Database Management System (DBMS)**: A software used to manage databases (e.g., MySQL, PostgreSQL).
- **MySQL**: A widely used DBMS for managing relational databases.

### **2. Indexes**

An **index** is a data structure that improves the speed of data retrieval operations on a table at the cost of additional space and slower write operations.

- **Primary Index**: Automatically created on the primary key.
- **Secondary Index**: Created on non-primary key columns.

#### Example:
```sql
CREATE INDEX index_name ON table_name(column_name);
```

### **3. PHPMyAdmin**

**PHPMyAdmin** is a web-based interface for managing MySQL databases. It allows users to:
- Create, modify, and delete databases and tables.
- Execute SQL queries.
- Export/import data.

### **4. Connect & Pconnect**

- **mysqli_connect()**: Establishes a connection to the MySQL database.
- **mysqli_pconnect()**: Creates a persistent connection, which is kept open for reuse.

#### Example (PHP):
```php
// Using mysqli_connect()
$connection = mysqli_connect("localhost", "root", "", "database_name");

// Using mysqli_pconnect()
$connection = mysqli_pconnect("localhost", "root", "", "database_name");
```

### **5. MySQL Create**

The `CREATE` statement is used to create databases, tables, and other objects.

#### Example:
```sql
-- Create a new database
CREATE DATABASE mydatabase;

-- Create a table in the database
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50),
    email VARCHAR(100),
    password VARCHAR(255)
);
```

### **6. MySQL Insert**

The `INSERT INTO` statement is used to add new records to a table.

#### Example:
```sql
-- Insert a single row
INSERT INTO users (username, email, password) VALUES ('john_doe', 'john@example.com', 'password123');

-- Insert multiple rows
INSERT INTO users (username, email, password) 
VALUES 
    ('alice', 'alice@example.com', 'password123'),
    ('bob', 'bob@example.com', 'password123');
```

### **7. MySQL Select**

The `SELECT` statement is used to retrieve data from a table.

#### Example:
```sql
-- Select all columns from the 'users' table
SELECT * FROM users;

-- Select specific columns
SELECT username, email FROM users;

-- Select with WHERE condition
SELECT * FROM users WHERE id = 1;
```

### **8. MySQL Update**

The `UPDATE` statement is used to modify existing records in a table.

#### Example:
```sql
-- Update a record
UPDATE users SET email = 'john_doe_updated@example.com' WHERE id = 1;
```

- Always use `WHERE` condition with `UPDATE` to avoid updating all rows.

### **9. MySQL Delete**

The `DELETE` statement is used to remove records from a table.

#### Example:
```sql
-- Delete a record
DELETE FROM users WHERE id = 1;

-- Delete all records (be cautious)
DELETE FROM users;
```

### **10. MySQL Truncate**

The `TRUNCATE` statement is used to delete all rows from a table, but it does not remove the table structure.

#### Example:
```sql
-- Truncate the table (removes all rows)
TRUNCATE TABLE users;
```

### **11. MySQL Drop**

The `DROP` statement is used to remove tables, databases, or other database objects permanently.

#### Example:
```sql
-- Drop a table
DROP TABLE users;

-- Drop a database
DROP DATABASE mydatabase;
```

### **12. WHERE Condition**

The `WHERE` clause is used to filter records based on specific conditions.

#### Example:
```sql
-- Select users where the username is 'john_doe'
SELECT * FROM users WHERE username = 'john_doe';

-- Select users where the age is greater than 30
SELECT * FROM users WHERE age > 30;
```

### **13. Order By and Group By**

- **ORDER BY**: Sorts the result set by one or more columns.
- **GROUP BY**: Groups rows that have the same values into summary rows.

#### Example:
```sql
-- Order by column in ascending order
SELECT * FROM users ORDER BY username ASC;

-- Group by a column and count the number of users in each group
SELECT country, COUNT(*) AS user_count FROM users GROUP BY country;
```

### **14. Having**

The `HAVING` clause is used to filter groups after the `GROUP BY` operation, similar to how `WHERE` filters rows.

#### Example:
```sql
-- Select countries with more than 5 users
SELECT country, COUNT(*) AS user_count 
FROM users 
GROUP BY country 
HAVING COUNT(*) > 5;
```

### **15. LIKE**

The `LIKE` operator is used to search for a specified pattern in a column.

#### Example:
```sql
-- Select users whose username starts with 'john'
SELECT * FROM users WHERE username LIKE 'john%';

-- Select users whose email contains 'example'
SELECT * FROM users WHERE email LIKE '%example%';
```

### **16. AND / OR Operators**

The `AND` and `OR` operators are used to combine multiple conditions in a `WHERE` clause.

#### Example:
```sql
-- Select users who are older than 18 and live in 'USA'
SELECT * FROM users WHERE age > 18 AND country = 'USA';

-- Select users who are either from 'USA' or 'Canada'
SELECT * FROM users WHERE country = 'USA' OR country = 'Canada';
```

### **17. SQL Functions**

SQL provides several aggregate and string functions that can be used to manipulate and analyze data.

#### Aggregate Functions:
- **AVG()**: Returns the average value.
- **COUNT()**: Returns the number of rows.
- **SUM()**: Returns the sum of a column.
- **MIN()**: Returns the minimum value.
- **MAX()**: Returns the maximum value.

#### Example:
```sql
-- Get the average age of users
SELECT AVG(age) FROM users;

-- Count the number of users
SELECT COUNT(*) FROM users;

-- Get the total salary of all employees
SELECT SUM(salary) FROM employees;

-- Get the minimum and maximum age
SELECT MIN(age), MAX(age) FROM users;
```

#### String Functions:
- **LCASE()**: Converts a string to lowercase.
- **UCASE()**: Converts a string to uppercase.

#### Example:
```sql
-- Convert the username to lowercase
SELECT LCASE(username) FROM users;

-- Convert the email to uppercase
SELECT UCASE(email) FROM users;
```

---

### **Summary of SQL Queries in MySQL:**

- **Database & Table Management**: `CREATE DATABASE`, `CREATE TABLE`, `DROP DATABASE`, `DROP TABLE`.
- **Data Manipulation**: `INSERT INTO`, `UPDATE`, `DELETE`, `TRUNCATE`.
- **Data Retrieval**: `SELECT`, `WHERE`, `ORDER BY`, `GROUP BY`, `HAVING`, `LIKE`.
- **Operators**: `AND`, `OR`, `LIKE`.
- **Aggregate Functions**: `AVG()`, `COUNT()`, `SUM()`, `MIN()`, `MAX()`.
- **String Functions**: `LCASE()`, `UCASE()`.

These basic SQL operations and functions are essential for interacting with databases, performing CRUD (Create, Read, Update, Delete) operations, and analyzing data.