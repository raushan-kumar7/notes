Here’s a curated list of **top SQL interview questions** (especially relevant for **TCS Digital** and similar roles), similar to the examples you gave:

---

### 🔍 **Top SQL Query-Based Interview Questions**

1. **Find the second highest salary from the Employee table.**

   ```sql
   SELECT MAX(salary) 
   FROM employees 
   WHERE salary < (SELECT MAX(salary) FROM employees);
   ```

2. **Find user details where name starts with 'S'.**

   ```sql
   SELECT * FROM users WHERE name LIKE 'S%';
   ```

3. **Find the nth highest salary (e.g., 3rd highest).**

   ```sql
   SELECT DISTINCT salary 
   FROM employees 
   ORDER BY salary DESC 
   LIMIT 1 OFFSET 2;
   ```

4. **Find duplicate records in a table.**

   ```sql
   SELECT name, COUNT(*) 
   FROM users 
   GROUP BY name 
   HAVING COUNT(*) > 1;
   ```

5. **Get the count of employees in each department.**

   ```sql
   SELECT department, COUNT(*) 
   FROM employees 
   GROUP BY department;
   ```

6. **Find employees who have no manager.**

   ```sql
   SELECT * FROM employees WHERE manager_id IS NULL;
   ```

7. **Retrieve top 3 highest salaries.**

   ```sql
   SELECT DISTINCT salary 
   FROM employees 
   ORDER BY salary DESC 
   LIMIT 3;
   ```

8. **Find employees who joined in the last 6 months.**

   ```sql
   SELECT * 
   FROM employees 
   WHERE joining_date >= DATE_SUB(CURDATE(), INTERVAL 6 MONTH);
   ```

9. **Find users whose email domain is 'gmail.com'.**

   ```sql
   SELECT * 
   FROM users 
   WHERE email LIKE '%@gmail.com';
   ```

10. **Find departments having more than 5 employees.**

```sql
SELECT department, COUNT(*) 
FROM employees 
GROUP BY department 
HAVING COUNT(*) > 5;
```

11. **Get the highest salary in each department.**

```sql
SELECT department, MAX(salary) 
FROM employees 
GROUP BY department;
```

12. **List employees with same salary.**

```sql
SELECT salary 
FROM employees 
GROUP BY salary 
HAVING COUNT(*) > 1;
```

13. **Find employee names containing 'an'.**

```sql
SELECT * FROM employees WHERE name LIKE '%an%';
```

14. **Find all employees who joined between 2023 and 2024.**

```sql
SELECT * FROM employees 
WHERE YEAR(joining_date) BETWEEN 2023 AND 2024;
```

15. **Get total salary spent in each department.**

```sql
SELECT department, SUM(salary) 
FROM employees 
GROUP BY department;
```

---

Would you like the same list with **table creation scripts and sample data** to practice too?
