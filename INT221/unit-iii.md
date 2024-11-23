# Unit III :: Controllers, Blade and Advanced Routing
## Topics
Basic Controllers- Creating Controllers, Controller Routing, Controller Middleware, Restful Resource Controllers, Blade- Creating Templates, PHP Output, Controller Structures, Templates Inheritance, Advanced Routing- Named Routes, Secure Routes, Parameter Constraints, Route Groups, Route Prefixing, Domain Routing, URL Generation- The current URL, Generating Framework URLs, Asset URLs, Generation Shortcuts

---

Here's an outline of **Laravel Controllers**, **Blade Templating**, and **Advanced Routing** concepts, which are essential for building a structured, efficient, and scalable Laravel application.

---

### **Controllers in Laravel**

Controllers are the central part of Laravel MVC, managing the application’s logic and routing actions.

**1. Creating Controllers**  
   Use the Artisan command to create a controller:

   ```bash
   php artisan make:controller UserController
   ```

**2. Controller Routing**  
   In `web.php`, route requests to specific controller methods:

   ```php
   Route::get('/users', [UserController::class, 'index']);
   ```

**3. Controller Middleware**  
   Attach middleware directly to a controller to control access. Middleware can be set in the constructor:

   ```php
   class UserController extends Controller
   {
       public function __construct()
       {
           $this->middleware('auth');
       }
   }
   ```

**4. Restful Resource Controllers**  
   Resource controllers provide a standardized way to handle CRUD operations. Use `--resource` when creating the controller to automatically define methods like `index`, `store`, `update`, etc.:

   ```bash
   php artisan make:controller ProductController --resource
   ```

   Register it in routes as a resource:

   ```php
   Route::resource('products', ProductController::class);
   ```

---

### **Blade Templating**

Blade is Laravel’s templating engine, allowing the creation of dynamic, reusable HTML with minimal code.

**1. Creating Templates**  
   Store Blade templates in the `resources/views` directory and use `.blade.php` as the file extension. Example: `home.blade.php`

**2. PHP Output**  
   Display variables using `{{ }}` for safe HTML output and `{!! !!}` for raw HTML output:

   ```php
   <h1>{{ $title }}</h1>
   <div>{!! $content !!}</div>
   ```

**3. Controller Structures**  
   Pass data from controllers to views with the `view` function:

   ```php
   return view('home', ['title' => 'Welcome']);
   ```

**4. Template Inheritance**  
   Blade’s layout inheritance system allows creating a base layout and extending it in child templates.

   - **Base Template (`layouts/app.blade.php`)**:

     ```html
     <html>
     <body>
         <header>@yield('header')</header>
         <div class="content">@yield('content')</div>
         <footer>@yield('footer')</footer>
     </body>
     </html>
     ```

   - **Child Template (`home.blade.php`)**:

     ```php
     @extends('layouts.app')

     @section('header')
         <h1>Home Page</h1>
     @endsection

     @section('content')
         <p>Welcome to the home page!</p>
     @endsection
     ```

---

### **Advanced Routing in Laravel**

Laravel offers a comprehensive routing system for controlling URL access and handling different types of requests.

**1. Named Routes**  
   Named routes simplify URL generation and provide flexibility if the route path changes:

   ```php
   Route::get('/profile', [ProfileController::class, 'show'])->name('profile');
   ```

   Access the URL in views with `route`:

   ```php
   <a href="{{ route('profile') }}">Profile</a>
   ```

**2. Secure Routes**  
   Secure routes using HTTPS:

   ```php
   Route::get('dashboard', function () {
       // Secure route content
   })->middleware('https');
   ```

**3. Parameter Constraints**  
   Apply constraints to route parameters to validate them:

   ```php
   Route::get('/user/{id}', function ($id) {
       // ...
   })->where('id', '[0-9]+');
   ```

**4. Route Groups**  
   Group routes to apply common middleware or prefixes:

   ```php
   Route::middleware(['auth'])->group(function () {
       Route::get('/dashboard', [DashboardController::class, 'index']);
       Route::get('/settings', [SettingsController::class, 'index']);
   });
   ```

**5. Route Prefixing**  
   Add prefixes to grouped routes:

   ```php
   Route::prefix('admin')->group(function () {
       Route::get('/users', [AdminController::class, 'users']);
       Route::get('/settings', [AdminController::class, 'settings']);
   });
   ```

**6. Domain Routing**  
   Use domain routing to manage subdomains:

   ```php
   Route::domain('{account}.example.com')->group(function () {
       Route::get('user/{id}', function ($account, $id) {
           // ...
       });
   });
   ```

---

### **URL Generation**

**1. The Current URL**  
   Laravel provides a `url` helper to retrieve the current URL:

   ```php
   $currentUrl = url()->current();
   ```

**2. Generating Framework URLs**  
   Use the `route` and `action` helpers for generating URLs.

   - **Route URLs**:

     ```php
     $profileUrl = route('profile');
     ```

   - **Controller Action URLs**:

     ```php
     $url = action([UserController::class, 'show'], ['id' => 1]);
     ```

**3. Asset URLs**  
   Use the `asset` helper for assets like images, CSS, and JavaScript files:

   ```php
   <img src="{{ asset('images/logo.png') }}">
   ```

**4. Generation Shortcuts**  
   Shortcuts such as `route` and `url` simplify the process of generating URLs in templates and controllers, ensuring that the application is easily maintainable.

---

By mastering these concepts, you can create a well-organized, scalable Laravel application that leverages the full power of controllers, Blade templating, and advanced routing techniques. These elements streamline development and ensure your application remains structured and efficient.