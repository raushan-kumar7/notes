# TCS Digital Role - DBMS & SQL Interview Guide

## DBMS Theory Concepts

### 1. Database Fundamentals
- **Database**: Organized collection of structured information stored electronically
- **DBMS**: Software that interacts with users, applications, and database to capture and analyze data
- **Data Independence**: Ability to modify schema at one level without affecting schema at next higher level
  - Physical Data Independence
  - Logical Data Independence

### 2. ACID Properties
- **Atomicity**: Transaction is all-or-nothing
- **Consistency**: Database remains in valid state before and after transaction
- **Isolation**: Concurrent transactions don't interfere with each other
- **Durability**: Committed changes are permanent

### 3. Normalization
- **1NF**: Eliminate repeating groups, atomic values
- **2NF**: 1NF + eliminate partial dependencies
- **3NF**: 2NF + eliminate transitive dependencies
- **BCNF**: 3NF + every determinant is a candidate key

### 4. Relationships
- **One-to-One (1:1)**: Each record in Table A relates to one record in Table B
- **One-to-Many (1:M)**: One record in Table A relates to multiple records in Table B
- **Many-to-Many (M:M)**: Multiple records in both tables can relate to each other

### 5. Keys
- **Primary Key**: Uniquely identifies each record
- **Foreign Key**: Links two tables together
- **Candidate Key**: Minimal set of attributes that uniquely identify a tuple
- **Super Key**: Set of attributes that uniquely identify a tuple
- **Composite Key**: Primary key with multiple columns

### 6. Indexing
- **Clustered Index**: Data rows stored in order of index key
- **Non-Clustered Index**: Logical order different from physical order
- **B-Tree Index**: Balanced tree structure for efficient searching
- **Hash Index**: Uses hash function for direct access

### 7. Transactions and Concurrency
- **Lock-based Protocols**: Shared locks, Exclusive locks
- **Deadlock**: Circular wait condition
- **Isolation Levels**: Read Uncommitted, Read Committed, Repeatable Read, Serializable

## SQL Practical Questions

### 1. Basic SQL Operations

#### Sample Tables for Practice:
```sql
-- Employee Table
CREATE TABLE Employee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    department VARCHAR(30),
    salary DECIMAL(10,2),
    manager_id INT,
    hire_date DATE
);

-- Department Table
CREATE TABLE Department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(30),
    location VARCHAR(50)
);
```

### 2. Common Interview Queries

#### Find Second Highest Salary
```sql
-- Method 1: Using LIMIT
SELECT salary FROM Employee 
ORDER BY salary DESC 
LIMIT 1 OFFSET 1;

-- Method 2: Using Subquery
SELECT MAX(salary) FROM Employee 
WHERE salary < (SELECT MAX(salary) FROM Employee);

-- Method 3: Using ROW_NUMBER()
SELECT salary FROM (
    SELECT salary, ROW_NUMBER() OVER (ORDER BY salary DESC) as rn
    FROM Employee
) t WHERE rn = 2;
```

#### Find Nth Highest Salary
```sql
SELECT salary FROM (
    SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) as rank
    FROM Employee
) t WHERE rank = N;
```

#### Find Employees with Same Salary
```sql
SELECT e1.emp_name, e1.salary
FROM Employee e1, Employee e2
WHERE e1.salary = e2.salary AND e1.emp_id != e2.emp_id;
```

#### Find Duplicate Records
```sql
SELECT emp_name, COUNT(*) as count
FROM Employee
GROUP BY emp_name
HAVING COUNT(*) > 1;
```

#### Delete Duplicate Records (Keep One)
```sql
DELETE e1 FROM Employee e1, Employee e2
WHERE e1.emp_id > e2.emp_id AND e1.emp_name = e2.emp_name;
```

### 3. Advanced SQL Queries

#### Employees Earning More Than Their Manager
```sql
SELECT e.emp_name, e.salary
FROM Employee e
JOIN Employee m ON e.manager_id = m.emp_id
WHERE e.salary > m.salary;
```

#### Department-wise Highest Salary
```sql
SELECT department, MAX(salary) as max_salary
FROM Employee
GROUP BY department;
```

#### Running Total
```sql
SELECT emp_name, salary,
       SUM(salary) OVER (ORDER BY emp_id) as running_total
FROM Employee;
```

#### Rank Employees by Salary in Each Department
```sql
SELECT emp_name, department, salary,
       RANK() OVER (PARTITION BY department ORDER BY salary DESC) as rank
FROM Employee;
```

### 4. Window Functions
```sql
-- ROW_NUMBER(), RANK(), DENSE_RANK()
SELECT emp_name, salary,
       ROW_NUMBER() OVER (ORDER BY salary DESC) as row_num,
       RANK() OVER (ORDER BY salary DESC) as rank,
       DENSE_RANK() OVER (ORDER BY salary DESC) as dense_rank
FROM Employee;

-- LAG and LEAD
SELECT emp_name, salary,
       LAG(salary) OVER (ORDER BY salary) as prev_salary,
       LEAD(salary) OVER (ORDER BY salary) as next_salary
FROM Employee;
```

### 5. Date Functions
```sql
-- Current date operations
SELECT CURDATE(), NOW(), YEAR(hire_date), MONTH(hire_date)
FROM Employee;

-- Date difference
SELECT emp_name, DATEDIFF(CURDATE(), hire_date) as days_employed
FROM Employee;
```

## Interview Tips & Common Questions

### Theoretical Questions with Detailed Answers:

#### 1. Explain the difference between DELETE, TRUNCATE, and DROP

**DELETE:**
- Removes specific rows based on WHERE condition
- Can be rolled back (uses transaction log)
- Triggers are fired
- Slower for large datasets
- Example: `DELETE FROM Employee WHERE salary < 30000;`

**TRUNCATE:**
- Removes all rows from table but keeps structure
- Cannot be rolled back (minimal logging)
- Faster than DELETE for all rows
- Resets identity counter
- Example: `TRUNCATE TABLE Employee;`

**DROP:**
- Removes entire table structure and data
- Cannot be rolled back
- Frees up storage space completely
- Example: `DROP TABLE Employee;`

#### 2. What is the difference between WHERE and HAVING?

**WHERE:**
- Filters rows before grouping
- Cannot use aggregate functions
- Applied to individual rows
- Example: `SELECT * FROM Employee WHERE salary > 50000;`

**HAVING:**
- Filters groups after GROUP BY
- Can use aggregate functions
- Applied to grouped results
- Example: `SELECT department, AVG(salary) FROM Employee GROUP BY department HAVING AVG(salary) > 60000;`

#### 3. Explain different types of JOINs with examples

**INNER JOIN:**
```sql
-- Returns only matching records from both tables
SELECT e.emp_name, d.dept_name
FROM Employee e
INNER JOIN Department d ON e.department = d.dept_name;
```

**LEFT JOIN (LEFT OUTER JOIN):**
```sql
-- Returns all records from left table, matching from right
SELECT e.emp_name, d.dept_name
FROM Employee e
LEFT JOIN Department d ON e.department = d.dept_name;
```

**RIGHT JOIN (RIGHT OUTER JOIN):**
```sql
-- Returns all records from right table, matching from left
SELECT e.emp_name, d.dept_name
FROM Employee e
RIGHT JOIN Department d ON e.department = d.dept_name;
```

**FULL OUTER JOIN:**
```sql
-- Returns all records when there's a match in either table
SELECT e.emp_name, d.dept_name
FROM Employee e
FULL OUTER JOIN Department d ON e.department = d.dept_name;
```

**CROSS JOIN:**
```sql
-- Cartesian product of both tables
SELECT e.emp_name, d.dept_name
FROM Employee e
CROSS JOIN Department d;
```

#### 4. What are stored procedures and functions?

**Stored Procedures:**
- Pre-compiled SQL statements stored in database
- Can have input/output parameters
- Can perform DML operations (INSERT, UPDATE, DELETE)
- Cannot be used in SELECT statements
- Example:
```sql
DELIMITER //
CREATE PROCEDURE GetEmployeesByDept(IN dept_name VARCHAR(30))
BEGIN
    SELECT * FROM Employee WHERE department = dept_name;
END //
DELIMITER ;
```

**Functions:**
- Return a single value
- Can only perform SELECT operations
- Can be used in SELECT, WHERE clauses
- Must return a value
- Example:
```sql
CREATE FUNCTION CalculateBonus(salary DECIMAL(10,2))
RETURNS DECIMAL(10,2)
BEGIN
    RETURN salary * 0.10;
END;
```

#### 5. Difference between clustered and non-clustered index

**Clustered Index:**
- Data pages are stored in order of index key
- Only one per table (usually on primary key)
- Faster for range queries
- Data retrieval is faster
- Example: Primary key automatically creates clustered index

**Non-Clustered Index:**
- Logical order different from physical storage order
- Multiple non-clustered indexes per table
- Contains pointers to actual data rows
- Slower than clustered for data retrieval
- Example: Index on frequently searched columns

#### 6. Explain database normalization with examples

**First Normal Form (1NF):**
- Eliminate repeating groups
- Each cell contains atomic values

Before 1NF:
| emp_id | emp_name | phone_numbers |
|--------|----------|---------------|
| 1 | John | 123-456, 789-012 |

After 1NF:
| emp_id | emp_name | phone_number |
|--------|----------|--------------|
| 1 | John | 123-456 |
| 1 | John | 789-012 |

**Second Normal Form (2NF):**
- Must be in 1NF
- Eliminate partial dependencies

**Third Normal Form (3NF):**
- Must be in 2NF
- Eliminate transitive dependencies

#### 7. What are triggers and their types?

**Triggers:** Special stored procedures that execute automatically in response to database events.

**Types:**
- **BEFORE triggers:** Execute before the triggering event
- **AFTER triggers:** Execute after the triggering event
- **INSTEAD OF triggers:** Replace the triggering event (views)

**By Event:**
- INSERT triggers
- UPDATE triggers
- DELETE triggers

Example:
```sql
CREATE TRIGGER salary_audit
AFTER UPDATE ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO audit_log (emp_id, old_salary, new_salary, change_date)
    VALUES (NEW.emp_id, OLD.salary, NEW.salary, NOW());
END;
```

#### 8. Explain ACID properties with real-world examples

**Atomicity:** All-or-nothing principle
- Example: Bank transfer - either both debit and credit happen, or neither

**Consistency:** Database remains in valid state
- Example: Account balance cannot be negative (if business rule)

**Isolation:** Concurrent transactions don't interfere
- Example: Two people booking last seat on flight - only one succeeds

**Durability:** Committed changes are permanent
- Example: Once payment is confirmed, it survives system crashes

### Practical Scenarios with Solutions:

#### 1. Design a database schema for an e-commerce system

```sql
-- Customers Table
CREATE TABLE Customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone VARCHAR(15),
    created_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Products Table
CREATE TABLE Products (
    product_id INT PRIMARY KEY AUTO_INCREMENT,
    product_name VARCHAR(100) NOT NULL,
    description TEXT,
    price DECIMAL(10,2) NOT NULL,
    stock_quantity INT DEFAULT 0,
    category_id INT,
    created_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Orders Table
CREATE TABLE Orders (
    order_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_id INT NOT NULL,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    total_amount DECIMAL(10,2) NOT NULL,
    status ENUM('pending', 'processing', 'shipped', 'delivered', 'cancelled'),
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)
);

-- Order Items Table
CREATE TABLE Order_Items (
    order_item_id INT PRIMARY KEY AUTO_INCREMENT,
    order_id INT NOT NULL,
    product_id INT NOT NULL,
    quantity INT NOT NULL,
    unit_price DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES Orders(order_id),
    FOREIGN KEY (product_id) REFERENCES Products(product_id)
);
```

#### 2. Write queries to find patterns in sales data

**Monthly Sales Report:**
```sql
SELECT 
    YEAR(order_date) as year,
    MONTH(order_date) as month,
    COUNT(*) as total_orders,
    SUM(total_amount) as monthly_revenue,
    AVG(total_amount) as avg_order_value
FROM Orders
WHERE status = 'delivered'
GROUP BY YEAR(order_date), MONTH(order_date)
ORDER BY year DESC, month DESC;
```

**Top 5 Customers by Revenue:**
```sql
SELECT 
    c.customer_id,
    CONCAT(c.first_name, ' ', c.last_name) as customer_name,
    COUNT(o.order_id) as total_orders,
    SUM(o.total_amount) as total_spent
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
WHERE o.status = 'delivered'
GROUP BY c.customer_id, customer_name
ORDER BY total_spent DESC
LIMIT 5;
```

**Products Never Ordered:**
```sql
SELECT p.product_id, p.product_name
FROM Products p
LEFT JOIN Order_Items oi ON p.product_id = oi.product_id
WHERE oi.product_id IS NULL;
```

#### 3. Optimize slow-running queries

**Before Optimization:**
```sql
-- Slow query - no indexes, inefficient joins
SELECT *
FROM Orders o, Customers c, Order_Items oi, Products p
WHERE o.customer_id = c.customer_id
AND o.order_id = oi.order_id
AND oi.product_id = p.product_id
AND o.order_date BETWEEN '2024-01-01' AND '2024-12-31';
```

**After Optimization:**
```sql
-- Add indexes first
CREATE INDEX idx_orders_date ON Orders(order_date);
CREATE INDEX idx_orders_customer ON Orders(customer_id);
CREATE INDEX idx_order_items_order ON Order_Items(order_id);
CREATE INDEX idx_order_items_product ON Order_Items(product_id);

-- Optimized query with proper JOINs and limited columns
SELECT 
    o.order_id,
    c.first_name,
    c.last_name,
    o.order_date,
    o.total_amount
FROM Orders o
INNER JOIN Customers c ON o.customer_id = c.customer_id
WHERE o.order_date BETWEEN '2024-01-01' AND '2024-12-31'
ORDER BY o.order_date DESC;
```

#### 4. Handle NULL values in calculations

```sql
-- Wrong way - NULLs will make entire calculation NULL
SELECT emp_name, salary + bonus as total_compensation
FROM Employee;

-- Right way - handle NULLs properly
SELECT 
    emp_name,
    salary + COALESCE(bonus, 0) as total_compensation,
    CASE 
        WHEN bonus IS NULL THEN 'No Bonus'
        ELSE CONCAT('Bonus: 

### Performance Optimization with Detailed Explanations:

#### 1. Use appropriate indexes
```sql
-- Create indexes on frequently queried columns
CREATE INDEX idx_employee_dept ON Employee(department);
CREATE INDEX idx_employee_salary ON Employee(salary);
CREATE INDEX idx_employee_hire_date ON Employee(hire_date);

-- Composite index for queries filtering multiple columns
CREATE INDEX idx_employee_dept_salary ON Employee(department, salary);
```

#### 2. Avoid SELECT * 
```sql
-- Bad practice - retrieves unnecessary data
SELECT * FROM Employee WHERE department = 'IT';

-- Good practice - specify only needed columns
SELECT emp_id, emp_name, salary FROM Employee WHERE department = 'IT';
```

#### 3. Use LIMIT for large datasets
```sql
-- Without LIMIT - processes all records
SELECT emp_name, salary FROM Employee ORDER BY salary DESC;

-- With LIMIT - more efficient for top results
SELECT emp_name, salary FROM Employee ORDER BY salary DESC LIMIT 10;
```

#### 4. Proper use of WHERE clauses
```sql
-- Inefficient - function on column prevents index usage
SELECT * FROM Employee WHERE YEAR(hire_date) = 2023;

-- Efficient - allows index usage
SELECT * FROM Employee WHERE hire_date >= '2023-01-01' AND hire_date < '2024-01-01';
```

#### 5. Avoid unnecessary JOINs
```sql
-- Unnecessary JOIN if only employee data needed
SELECT e.emp_name, e.salary 
FROM Employee e 
JOIN Department d ON e.department = d.dept_name;

-- Direct query when department data not needed
SELECT emp_name, salary FROM Employee;
```

#### 6. Use EXPLAIN to analyze query execution
```sql
-- Analyze query performance
EXPLAIN SELECT e.emp_name, d.dept_name
FROM Employee e
JOIN Department d ON e.department = d.dept_name
WHERE e.salary > 50000;
```

### Common Mistakes to Avoid with Solutions:

#### 1. Not handling NULL values
```sql
-- Wrong - NULL comparison always returns unknown
SELECT * FROM Employee WHERE bonus = NULL;

-- Correct - use IS NULL or IS NOT NULL
SELECT * FROM Employee WHERE bonus IS NULL;

-- Handle NULLs in calculations
SELECT emp_name, salary + COALESCE(bonus, 0) as total_pay FROM Employee;
```

#### 2. Incorrect use of GROUP BY with aggregate functions
```sql
-- Wrong - non-aggregate column without GROUP BY
SELECT department, emp_name, AVG(salary) FROM Employee;

-- Correct - either group by all non-aggregate columns
SELECT department, AVG(salary) FROM Employee GROUP BY department;

-- Or use window functions
SELECT department, emp_name, AVG(salary) OVER (PARTITION BY department) as dept_avg
FROM Employee;
```

#### 3. Mixing aggregate and non-aggregate columns
```sql
-- Wrong - mixing aggregate with non-aggregate
SELECT department, emp_name, COUNT(*) FROM Employee GROUP BY department;

-- Correct - consistent aggregation
SELECT department, COUNT(*) as emp_count FROM Employee GROUP BY department;
```

#### 4. Inefficient subqueries instead of JOINs
```sql
-- Inefficient subquery
SELECT emp_name FROM Employee 
WHERE department IN (SELECT dept_name FROM Department WHERE location = 'New York');

-- Efficient JOIN
SELECT e.emp_name 
FROM Employee e
JOIN Department d ON e.department = d.dept_name
WHERE d.location = 'New York';
```

### Quick Revision Points with Examples:

#### Primary vs Foreign Key
```sql
-- Primary Key - uniquely identifies each record
CREATE TABLE Employee (
    emp_id INT PRIMARY KEY,  -- Primary key
    emp_name VARCHAR(50)
);

-- Foreign Key - references another table
CREATE TABLE Orders (
    order_id INT PRIMARY KEY,
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)  -- Foreign key
);
```

#### INNER vs OUTER JOIN
```sql
-- INNER JOIN - only matching records
SELECT e.emp_name, d.dept_name
FROM Employee e
INNER JOIN Department d ON e.department = d.dept_name;

-- LEFT OUTER JOIN - all from left table + matching from right
SELECT e.emp_name, d.dept_name
FROM Employee e
LEFT JOIN Department d ON e.department = d.dept_name;
```

#### UNION vs UNION ALL
```sql
-- UNION - removes duplicates
SELECT emp_name FROM Employee WHERE department = 'IT'
UNION
SELECT emp_name FROM Employee WHERE salary > 50000;

-- UNION ALL - keeps all records (faster)
SELECT emp_name FROM Employee WHERE department = 'IT'
UNION ALL
SELECT emp_name FROM Employee WHERE salary > 50000;
```

#### GROUP BY vs ORDER BY
```sql
-- GROUP BY - groups rows for aggregation
SELECT department, COUNT(*) as emp_count
FROM Employee
GROUP BY department;

-- ORDER BY - sorts the result set
SELECT emp_name, salary
FROM Employee
ORDER BY salary DESC;
```

#### Subquery vs JOIN Performance
```sql
-- Correlated subquery (slower)
SELECT emp_name FROM Employee e1
WHERE salary > (SELECT AVG(salary) FROM Employee e2 WHERE e2.department = e1.department);

-- Window function (faster)
SELECT emp_name FROM (
    SELECT emp_name, salary, AVG(salary) OVER (PARTITION BY department) as dept_avg
    FROM Employee
) t WHERE salary > dept_avg;
```

## Practice Strategy:
1. Start with basic SELECT, INSERT, UPDATE, DELETE
2. Master JOINs and subqueries
3. Practice window functions and CTEs
4. Solve complex analytical queries
5. Focus on query optimization techniques
6. Practice explaining your approach verbally, bonus)
    END as bonus_status
FROM Employee;
```

#### 5. Create reports with aggregations and grouping

**Sales Summary Report:**
```sql
SELECT 
    p.product_name,
    COUNT(oi.order_item_id) as times_ordered,
    SUM(oi.quantity) as total_quantity_sold,
    SUM(oi.quantity * oi.unit_price) as total_revenue,
    AVG(oi.unit_price) as avg_selling_price,
    RANK() OVER (ORDER BY SUM(oi.quantity * oi.unit_price) DESC) as revenue_rank
FROM Products p
JOIN Order_Items oi ON p.product_id = oi.product_id
JOIN Orders o ON oi.order_id = o.order_id
WHERE o.status = 'delivered'
    AND o.order_date >= DATE_SUB(CURDATE(), INTERVAL 1 YEAR)
GROUP BY p.product_id, p.product_name
HAVING total_revenue > 1000
ORDER BY total_revenue DESC;
```

**Customer Segmentation Analysis:**
```sql
WITH customer_metrics AS (
    SELECT 
        c.customer_id,
        CONCAT(c.first_name, ' ', c.last_name) as customer_name,
        COUNT(o.order_id) as total_orders,
        SUM(o.total_amount) as lifetime_value,
        AVG(o.total_amount) as avg_order_value,
        DATEDIFF(CURDATE(), MAX(o.order_date)) as days_since_last_order
    FROM Customers c
    LEFT JOIN Orders o ON c.customer_id = o.customer_id
    WHERE o.status = 'delivered' OR o.status IS NULL
    GROUP BY c.customer_id, customer_name
)
SELECT 
    customer_name,
    total_orders,
    lifetime_value,
    avg_order_value,
    days_since_last_order,
    CASE 
        WHEN total_orders = 0 THEN 'Never Purchased'
        WHEN days_since_last_order <= 30 THEN 'Active'
        WHEN days_since_last_order <= 90 THEN 'At Risk'
        ELSE 'Inactive'
    END as customer_segment,
    CASE 
        WHEN lifetime_value >= 1000 THEN 'High Value'
        WHEN lifetime_value >= 500 THEN 'Medium Value'
        WHEN lifetime_value > 0 THEN 'Low Value'
        ELSE 'No Value'
    END as value_segment
FROM customer_metrics
ORDER BY lifetime_value DESC;
```

### Performance Optimization:
- Use appropriate indexes
- Avoid SELECT *
- Use LIMIT for large datasets
- Proper use of WHERE clauses
- Avoid unnecessary JOINs
- Use EXPLAIN to analyze query execution

### Common Mistakes to Avoid:
- Not handling NULL values
- Incorrect use of GROUP BY with aggregate functions
- Mixing aggregate and non-aggregate columns without GROUP BY
- Not using proper JOIN conditions
- Inefficient subqueries instead of JOINs

## Quick Revision Points:
- **Primary vs Foreign Key**: Primary uniquely identifies, Foreign references another table
- **INNER vs OUTER JOIN**: INNER returns matching records, OUTER includes non-matching
- **UNION vs UNION ALL**: UNION removes duplicates, UNION ALL keeps all
- **GROUP BY vs ORDER BY**: GROUP BY groups rows, ORDER BY sorts results
- **Subquery vs JOIN**: Subqueries can be slower, JOINs generally more efficient

## Practice Strategy:
1. Start with basic SELECT, INSERT, UPDATE, DELETE
2. Master JOINs and subqueries
3. Practice window functions and CTEs
4. Solve complex analytical queries
5. Focus on query optimization techniques
6. Practice explaining your approach verbally