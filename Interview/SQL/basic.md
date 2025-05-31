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

### Theoretical Questions You Should Know:
1. Explain the difference between DELETE, TRUNCATE, and DROP
2. What is the difference between WHERE and HAVING?
3. Explain different types of JOINs with examples
4. What are stored procedures and functions?
5. Difference between clustered and non-clustered index
6. Explain database normalization with examples
7. What are triggers and their types?
8. Explain ACID properties with real-world examples

### Practical Scenarios:
1. Design a database schema for an e-commerce system
2. Write queries to find patterns in sales data
3. Optimize slow-running queries
4. Handle NULL values in calculations
5. Create reports with aggregations and grouping

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