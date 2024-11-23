# Important Commands for Laravel

Here's a list of essential Laravel Artisan commands for various tasks, organized by category. These commands are run from the terminal in the root directory of your Laravel project.

---

### **1. General Artisan Commands**

- **List All Commands**:
  ```bash
  php artisan list
  ```
- **View Current Laravel Version**:
  ```bash
  php artisan --version
  ```
- **Clear Cache**:
  ```bash
  php artisan cache:clear
  ```
- **Clear Config Cache**:
  ```bash
  php artisan config:cache
  ```
- **Clear Route Cache**:
  ```bash
  php artisan route:cache
  ```
- **Clear View Cache**:
  ```bash
  php artisan view:clear
  ```

---

### **2. Development Server**

- **Start the Development Server**:
  ```bash
  php artisan serve
  ```

---

### **3. Key and Environment**

- **Generate Application Key**:
  ```bash
  php artisan key:generate
  ```
- **Cache Environment Variables**:
  ```bash
  php artisan config:cache
  ```
- **Clear Config Cache (after updating .env)**:
  ```bash
  php artisan config:clear
  ```

---

### **4. Database & Migrations**

- **Create a Migration**:
  ```bash
  php artisan make:migration create_table_name
  ```
- **Run Migrations**:
  ```bash
  php artisan migrate
  ```
- **Rollback Migrations**:
  ```bash
  php artisan migrate:rollback
  ```
- **Rollback All Migrations**:
  ```bash
  php artisan migrate:reset
  ```
- **Refresh Migrations** (rollback all and re-run):
  ```bash
  php artisan migrate:refresh
  ```
- **Seed Database**:
  ```bash
  php artisan db:seed
  ```
- **Migrate and Seed in One Command**:
  ```bash
  php artisan migrate --seed
  ```

---

### **5. Models, Controllers, and Resources**

- **Generate a Model**:
  ```bash
  php artisan make:model ModelName
  ```
  *Options:*
  - `--migration`: Also create a migration file
  - `--controller`: Also create a controller for the model
  - `--factory`: Also create a factory for the model
  - `--resource`: Also create a resource controller for the model

- **Generate a Controller**:
  ```bash
  php artisan make:controller ControllerName
  ```
  *Options:*
  - `--resource`: Create a RESTful resource controller
  - `--invokable`: Create an invokable controller

- **Generate a Resource**:
  ```bash
  php artisan make:resource ResourceName
  ```

---

### **6. Requests, Middleware, and Commands**

- **Create a Form Request**:
  ```bash
  php artisan make:request RequestName
  ```

- **Create Middleware**:
  ```bash
  php artisan make:middleware MiddlewareName
  ```

- **Create a Custom Command**:
  ```bash
  php artisan make:command CommandName
  ```

---

### **7. Authentication and Authorization**

- **Generate Authentication Scaffolding** (if using Laravel Breeze):
  ```bash
  php artisan breeze:install
  ```
- **Create Policy**:
  ```bash
  php artisan make:policy PolicyName
  ```

---

### **8. Routes and URLs**

- **Display All Routes**:
  ```bash
  php artisan route:list
  ```

---

### **9. Caching and Queueing**

- **Clear Application Cache**:
  ```bash
  php artisan cache:clear
  ```
- **Clear Route Cache**:
  ```bash
  php artisan route:clear
  ```
- **Clear View Cache**:
  ```bash
  php artisan view:clear
  ```
- **Clear Config Cache**:
  ```bash
  php artisan config:clear
  ```
- **Run Queue Worker**:
  ```bash
  php artisan queue:work
  ```
- **Run Queue Listener**:
  ```bash
  php artisan queue:listen
  ```
- **Queue Failed Job Retry**:
  ```bash
  php artisan queue:retry all
  ```

---

### **10. Testing**

- **Run All Tests**:
  ```bash
  php artisan test
  ```

---

### **11. Miscellaneous Commands**

- **Optimize Application**:
  ```bash
  php artisan optimize
  ```
- **Run Scheduled Tasks**:
  ```bash
  php artisan schedule:run
  ```
- **Publish Vendor Files**:
  ```bash
  php artisan vendor:publish
  ```

---

These commands are vital in Laravel development, allowing you to efficiently build, manage, and maintain your application. The `php artisan` commands greatly enhance productivity by automating common tasks, from managing migrations and caching to testing and running scheduled jobs.