# Unit I :: Introduction to MVC Laravel Framework
## Topics
Overview of Laravel, Laravel Features, Laravel Installation and Composer, Laravel Application Structure, Laravel Configuration- Environmental Configuration, Database Configuration


---

Here's an introduction to the **MVC Laravel Framework**, covering Laravel's features, installation, application structure, and configuration.

---

### **1. Overview of Laravel**

**Laravel** is a popular PHP framework that follows the MVC (Model-View-Controller) architecture. It is designed to make the development process smoother and more enjoyable by providing tools and libraries for common tasks such as routing, authentication, session management, and caching. Laravel is known for its expressive syntax, powerful tools, and emphasis on clean, maintainable code.

---

### **2. Key Features of Laravel**

- **MVC Architecture**: Enforces separation of concerns, which organizes code in a structured way.
- **Routing**: Manages URL routes easily using expressive syntax.
- **Eloquent ORM**: Simplifies database interactions by providing an intuitive, object-relational mapping (ORM) layer.
- **Blade Templating Engine**: Enables dynamic content rendering in views with minimal PHP code.
- **Authentication and Authorization**: Simplifies user authentication and access control.
- **Artisan Command-Line Tool**: Automates repetitive tasks like migrations, seeding, and more.
- **RESTful Controllers**: Manages resourceful routes efficiently for REST APIs.
- **Task Scheduling**: Handles automated task scheduling using the built-in scheduler.
- **Unit Testing**: Built-in support for unit tests to ensure code reliability.
- **Localization and Caching**: Enhances performance and adaptability for multiple locales.

---

### **3. Laravel Installation and Composer**

Laravel requires **Composer**, a dependency manager for PHP, to manage its libraries and packages.

**Steps to Install Laravel:**

1. **Install Composer**: First, download and install Composer from [https://getcomposer.org](https://getcomposer.org).
2. **Install Laravel via Composer**:
   Open your terminal and run:
   ```bash
   composer create-project laravel/laravel example-app
   ```
3. **Navigate to the Project**:
   ```bash
   cd example-app
   ```
4. **Run the Local Development Server**:
   Start the built-in development server with:
   ```bash
   php artisan serve
   ```
   This will make the application accessible at `http://localhost:8000`.

---

### **4. Laravel Application Structure**

Once installed, Laravel applications have a structured file organization. Here’s an overview of the main directories:

- **app/**: Contains the core application code, including Models, Controllers, and Middleware.
- **bootstrap/**: Initializes the framework and loads configurations.
- **config/**: Holds configuration files for services, database, app settings, etc.
- **database/**: Contains migration, seeder, and factory files for the database.
- **public/**: The entry point for all web requests, which holds front-facing assets like CSS, JavaScript, and images.
- **resources/**: Contains views, raw assets (like CSS and JS files), and language files.
- **routes/**: Defines web routes (`web.php`), API routes (`api.php`), and console routes.
- **storage/**: Stores cached views, logs, and other files generated by Laravel.
- **tests/**: Contains unit and feature tests.
- **vendor/**: Holds Composer dependencies.

---

### **5. Laravel Configuration**

Configuration files are located in the `config/` directory, each responsible for different aspects of the application.

#### Environmental Configuration

Laravel utilizes **environment files** (`.env`) to set up environment-specific configurations. These files store sensitive information like database credentials, API keys, and environment variables, which can be referenced throughout the application.

- **Setting up the `.env` file**:
  - Copy `.env.example` to `.env` if it doesn’t already exist:
    ```bash
    cp .env.example .env
    ```
  - **Generate an Application Key** (required to secure sessions and other encrypted data):
    ```bash
    php artisan key:generate
    ```

#### Database Configuration

Database configuration is managed within the `.env` file and `config/database.php`. You can set up connections for different database types like MySQL, SQLite, PostgreSQL, etc.

In the `.env` file:
```dotenv
DB_CONNECTION=mysql
DB_HOST=127.0.0.1
DB_PORT=3306
DB_DATABASE=your_database
DB_USERNAME=your_username
DB_PASSWORD=your_password
```

Then, Laravel will use these settings to connect to the specified database.

---

### **Getting Started with Laravel**

After configuring the environment and database, you can start building out your application. Use **Artisan CLI commands** for tasks like setting up migrations (`php artisan migrate`), creating models (`php artisan make:model ModelName`), and setting up controllers (`php artisan make:controller ControllerName`).

Laravel’s ecosystem and extensive documentation make it accessible and powerful for developers at all levels. With Laravel, you have a robust platform for building modern, scalable applications with ease.