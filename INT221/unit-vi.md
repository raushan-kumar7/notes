# Unit VI :: Databases, Schema Builder and Migrations
#### Topics
Databases-Abstraction, Configuration, Preparing, Schema Builder-Creating Tables, Column Types, Special Column Types, Column Modifiers, Updating Tables, Dropping Tables, Schema Tricks, Migrations- Basic Concept, Creating Migrations, Running Migrations, Rolling Back, Migration tricks, Restful API

---

### **Databases in Web Development**

**1. Abstraction**  
   Database abstraction involves creating a layer between application code and the database. This layer lets the application communicate with different databases in a uniform way. In frameworks like Laravel, an ORM (Object-Relational Mapper) such as Eloquent is used for abstraction, allowing developers to interact with the database using object-oriented syntax rather than raw SQL.

**2. Configuration**  
   Database configuration usually involves setting up database connection details such as the hostname, port, database name, username, and password. These settings are typically stored in environment files (e.g., `.env` files in Laravel), which allows for easy configuration across different environments (e.g., development, testing, production).

**3. Preparing Databases**  
   This involves setting up the database itself, often by creating the database, setting up user privileges, and optimizing configurations for application-specific needs. In production, databases are configured to ensure security, performance, and reliability.

---

### **Schema Builder**

The schema builder is used to define the structure of a database. This includes creating tables, setting column types, adding indexes, etc. In Laravel, for example, the schema builder uses a fluent syntax to make this process intuitive.

**1. Creating Tables**  
   You can create tables in your database with the schema builder by defining table names and the columns they should contain.

   ```php
   Schema::create('users', function (Blueprint $table) {
       $table->id();
       $table->string('name');
       $table->string('email')->unique();
       $table->timestamps();
   });
   ```

**2. Column Types**  
   Column types define the kind of data a column will store, such as integers, strings, booleans, dates, etc.

   Examples:
   - `string('name')`: Stores a string, typically with a max length of 255.
   - `integer('age')`: Stores an integer.
   - `boolean('is_active')`: Stores a boolean.

**3. Special Column Types**  
   Some databases and schema builders support special column types, such as:
   - JSON: for storing JSON objects.
   - UUID: for universally unique identifiers.
   - Enum: for storing specific, predefined values.

**4. Column Modifiers**  
   Modifiers like `nullable`, `default`, and `unique` add special constraints or properties to columns.

   Example:
   ```php
   $table->string('email')->nullable()->unique();
   ```

**5. Updating Tables**  
   The schema builder can also modify existing tables. For instance, you can add, rename, or remove columns.

   ```php
   Schema::table('users', function (Blueprint $table) {
       $table->string('phone')->nullable();
   });
   ```

**6. Dropping Tables**  
   Dropping a table removes it from the database entirely.

   ```php
   Schema::dropIfExists('users');
   ```

**7. Schema Tricks**  
   Schema builders often have additional features, such as renaming tables, adding indexes, or setting foreign keys to link tables.

---

### **Migrations**

Migrations help keep track of database changes over time and make it easy to modify the database schema in a version-controlled way.

**1. Basic Concept**  
   A migration is a file that contains database schema changes, which can be versioned and tracked.

**2. Creating Migrations**  
   Migrations are often created with artisan commands (in Laravel) or a similar CLI in other frameworks.

   ```bash
   php artisan make:migration create_users_table
   ```

**3. Running Migrations**  
   Running migrations applies all pending migrations to the database.

   ```bash
   php artisan migrate
   ```

**4. Rolling Back**  
   You can undo migrations with rollback commands, allowing you to revert database changes.

   ```bash
   php artisan migrate:rollback
   ```

**5. Migration Tricks**  
   Advanced migration techniques include seeding databases, setting default values, and handling specific scenarios (like removing columns safely).

---

### **RESTful API**

RESTful APIs provide a way for applications to communicate over HTTP by adhering to REST principles.

**1. Basic Concepts**  
   - **REST (Representational State Transfer)** is a set of principles for designing networked applications.
   - **Resources**: Entities managed by the API, typically represented by database tables (e.g., users, products).
   - **HTTP Methods**: Common methods include GET, POST, PUT, DELETE, each associated with a specific action (e.g., reading, creating, updating, or deleting a resource).
   
   | HTTP Method | Operation   | Example Endpoint             |
   |-------------|-------------|------------------------------|
   | GET         | Retrieve    | `/api/users` or `/api/users/{id}` |
   | POST        | Create      | `/api/users`                |
   | PUT/PATCH   | Update      | `/api/users/{id}`           |
   | DELETE      | Delete      | `/api/users/{id}`           |

**2. Setting Up RESTful Routes**  
   Define routes in your web application to handle RESTful operations on resources. For example, in Laravel:

   ```php
   Route::resource('users', UserController::class);
   ```

**3. Controllers and Methods**  
   Create controllers to manage API logic, including methods for each RESTful operation. Here’s an example of a typical controller method:

   ```php
   public function index() {
       $users = User::all();
       return response()->json($users);
   }
   ```

**4. Middleware**  
   Middleware can be used to handle cross-cutting concerns such as authentication, authorization, and rate limiting in an API.

**5. Request Validation**  
   Validation ensures the API receives correctly structured and complete data, typically managed by request validation classes or inline validation in controllers.

**6. JSON Responses**  
   APIs usually return data in JSON format. You can return JSON using helper functions or by transforming data into JSON in the response.

---