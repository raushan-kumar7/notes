In Laravel, creating a RESTful API is streamlined using features like routes, controllers, middleware, and Eloquent ORM. Below is a guide to implement a RESTful API in Laravel following the principles you outlined.

---

### 1. **Setting Up a Laravel RESTful API**

#### **Install Laravel**
If you haven’t already, set up a new Laravel project:
```bash
composer create-project --prefer-dist laravel/laravel rest-api
```

#### **Create a Model and Migration**
For example, if you're managing `users` as a resource:
```bash
php artisan make:model User -m
```
This creates a model (`User`) and a migration file for the database table. Update the migration file with necessary fields:
```php
public function up()
{
    Schema::create('users', function (Blueprint $table) {
        $table->id();
        $table->string('name');
        $table->string('email')->unique();
        $table->string('password');
        $table->timestamps();
    });
}
```
Run the migration:
```bash
php artisan migrate
```

---

### 2. **Creating a RESTful Controller**

#### Generate a Controller
```bash
php artisan make:controller UserController --resource
```
The `--resource` flag generates all RESTful methods (`index`, `store`, `show`, `update`, `destroy`).

#### Update the Controller
```php
use App\Models\User;
use Illuminate\Http\Request;

class UserController extends Controller
{
    public function index()
    {
        return response()->json(User::all());
    }

    public function store(Request $request)
    {
        $validated = $request->validate([
            'name' => 'required|string|max:255',
            'email' => 'required|email|unique:users',
            'password' => 'required|min:6',
        ]);

        $user = User::create([
            'name' => $validated['name'],
            'email' => $validated['email'],
            'password' => bcrypt($validated['password']),
        ]);

        return response()->json($user, 201);
    }

    public function show($id)
    {
        $user = User::findOrFail($id);
        return response()->json($user);
    }

    public function update(Request $request, $id)
    {
        $user = User::findOrFail($id);

        $validated = $request->validate([
            'name' => 'sometimes|string|max:255',
            'email' => 'sometimes|email|unique:users,email,' . $id,
            'password' => 'sometimes|min:6',
        ]);

        $user->update($validated);

        return response()->json($user);
    }

    public function destroy($id)
    {
        $user = User::findOrFail($id);
        $user->delete();

        return response()->json(null, 204);
    }
}
```

---

### 3. **Define API Routes**

Update `routes/api.php` to include the routes:
```php
use App\Http\Controllers\UserController;

Route::apiResource('users', UserController::class);
```

This automatically maps the routes to the controller methods:

| HTTP Method | Operation | Endpoint        | Controller Method |
|-------------|-----------|-----------------|-------------------|
| GET         | Retrieve  | `/api/users`    | `index`           |
| GET         | Retrieve  | `/api/users/{id}` | `show`            |
| POST        | Create    | `/api/users`    | `store`           |
| PUT/PATCH   | Update    | `/api/users/{id}` | `update`          |
| DELETE      | Delete    | `/api/users/{id}` | `destroy`         |

---

### 4. **Testing the API**

Use a tool like **Postman** or **cURL** to test your API:

- **GET all users**:
  ```bash
  curl -X GET http://your-app-url/api/users
  ```

- **POST create a user**:
  ```bash
  curl -X POST -H "Content-Type: application/json" \
  -d '{"name": "John Doe", "email": "john@example.com", "password": "secret"}' \
  http://your-app-url/api/users
  ```

- **PUT update a user**:
  ```bash
  curl -X PUT -H "Content-Type: application/json" \
  -d '{"name": "Jane Doe"}' \
  http://your-app-url/api/users/1
  ```

- **DELETE a user**:
  ```bash
  curl -X DELETE http://your-app-url/api/users/1
  ```

---

### 5. **Additional Tips**

#### Use Middleware for Authentication
Enable authentication using Laravel Sanctum or Passport to secure your API.

```bash
composer require laravel/sanctum
php artisan vendor:publish --provider="Laravel\Sanctum\SanctumServiceProvider"
php artisan migrate
```

Add the middleware to `api.php`:
```php
Route::middleware('auth:sanctum')->group(function () {
    Route::apiResource('users', UserController::class);
});
```

#### Enable CORS
To allow cross-origin requests, configure the `cors` middleware in `app/Http/Middleware`.

---

With these steps, you’ve created a fully functional RESTful API in Laravel!