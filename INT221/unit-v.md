
# Unit V :: Laravel Forms and Validation
#### Topics
Opening Forms, Form Fields, Form Buttons, Form Macro, Form Security, Laravel Validation-Simple Validation, Validation Rules, Error Messages, Custom Validation Rules, Custom Validation Messages

---

In Laravel, forms and validation are important components that help developers build interactive and secure applications. Here's an overview of how to handle forms, validation, and security in Laravel:

### 1. **Opening Forms in Laravel**

Laravel provides several ways to create forms using either Blade templates or the `Form` facade (via Laravel Collective, which needs to be installed separately).

#### Blade Form Syntax:

In Blade, you can create a form using `form` and `@csrf` directives for security.

```php
<form action="{{ route('store') }}" method="POST">
    @csrf
    <!-- Form fields will go here -->
    <button type="submit">Submit</button>
</form>
```

#### Using Laravel Collective:

First, install Laravel Collective via composer:

```bash
composer require "laravelcollective/html"
```

Then, in your Blade template, you can use the `Form` facade:

```php
{!! Form::open(['route' => 'store']) !!}
    <!-- Form fields will go here -->
    {!! Form::submit('Submit') !!}
{!! Form::close() !!}
```

### 2. **Form Fields**

Form fields can be created in Laravel using either the Blade syntax or the Laravel Collective helper functions.

#### Blade Example:

```php
<form action="{{ route('store') }}" method="POST">
    @csrf
    <label for="name">Name</label>
    <input type="text" name="name" id="name" value="{{ old('name') }}">

    <label for="email">Email</label>
    <input type="email" name="email" id="email" value="{{ old('email') }}">

    <button type="submit">Submit</button>
</form>
```

#### Laravel Collective Example:

```php
{!! Form::open(['route' => 'store']) !!}
    {!! Form::label('name', 'Name') !!}
    {!! Form::text('name', old('name')) !!}

    {!! Form::label('email', 'Email') !!}
    {!! Form::email('email', old('email')) !!}

    {!! Form::submit('Submit') !!}
{!! Form::close() !!}
```

### 3. **Form Buttons**

Form buttons are used to submit forms. Laravel Collective provides a helper for buttons, or you can use regular HTML.

#### Blade Example:

```php
<button type="submit">Submit</button>
```

#### Laravel Collective Example:

```php
{!! Form::submit('Submit') !!}
```

### 4. **Form Macro**

Form macros allow you to define reusable custom form elements. This is useful for situations where you need to create custom components multiple times throughout your application.

To define a form macro, you can add it in the `AppServiceProvider`:

```php
public function boot()
{
    Form::macro('customText', function($name, $value = null) {
        return Form::text($name, $value, ['class' => 'custom-class']);
    });
}
```

Now, you can use it in your forms:

```php
{!! Form::customText('name') !!}
```

### 5. **Form Security (CSRF Protection)**

Laravel provides built-in protection against Cross-Site Request Forgery (CSRF) attacks. To include a CSRF token in a form, use the `@csrf` directive in Blade templates.

#### Blade Example:

```php
<form action="{{ route('store') }}" method="POST">
    @csrf
    <input type="text" name="name">
    <button type="submit">Submit</button>
</form>
```

### 6. **Laravel Validation**

Validation ensures that data entered into the form is correct before it is stored in the database. Laravel makes validation simple and convenient.

#### Simple Validation:

To validate form data, use the `validate` method on the request object.

```php
public function store(Request $request)
{
    $request->validate([
        'name' => 'required|string|max:255',
        'email' => 'required|email|unique:users,email',
    ]);

    // If validation passes, continue processing
}
```

### 7. **Validation Rules**

Laravel provides a variety of built-in validation rules, such as:

- `required`: The field must be filled.
- `string`: The field must be a string.
- `email`: The field must be a valid email address.
- `max`: The field must not be greater than a given value.
- `unique`: The field must be unique in a database table.
  
Example:

```php
$request->validate([
    'name' => 'required|string|max:255',
    'email' => 'required|email|unique:users,email',
]);
```

You can also define validation rules dynamically:

```php
$request->validate([
    'name' => ['required', 'string', 'max:255'],
    'email' => ['required', 'email', 'unique:users,email'],
]);
```

### 8. **Error Messages**

When validation fails, Laravel automatically redirects back to the previous page with error messages. You can display these error messages in the view.

#### Blade Example:

```php
<form action="{{ route('store') }}" method="POST">
    @csrf

    <label for="name">Name</label>
    <input type="text" name="name" id="name" value="{{ old('name') }}">
    
    @error('name')
        <div class="error">{{ $message }}</div>
    @enderror

    <label for="email">Email</label>
    <input type="email" name="email" id="email" value="{{ old('email') }}">

    @error('email')
        <div class="error">{{ $message }}</div>
    @enderror

    <button type="submit">Submit</button>
</form>
```

The `@error` directive checks if a validation error exists for the given field and displays the error message.

### 9. **Custom Validation Rules**

You can create custom validation rules by defining your own validation logic.

#### Creating a Custom Validation Rule:

Use the `artisan` command to create a custom rule:

```bash
php artisan make:rule Uppercase
```

This will generate a new rule file in `app/Rules/Uppercase.php`. In this file, you can define your custom validation logic.

```php
namespace App\Rules;

use Illuminate\Contracts\Validation\Rule;

class Uppercase implements Rule
{
    public function passes($attribute, $value)
    {
        return strtoupper($value) === $value;
    }

    public function message()
    {
        return 'The :attribute must be uppercase.';
    }
}
```

#### Using the Custom Validation Rule:

```php
use App\Rules\Uppercase;

$request->validate([
    'name' => ['required', new Uppercase],
]);
```

### 10. **Custom Validation Messages**

You can customize the error messages for validation rules. Pass a custom message as the third parameter to the `validate` method.

```php
$request->validate([
    'name' => 'required|string|max:255',
], [
    'name.required' => 'Please enter your name.',
    'name.max' => 'Your name cannot exceed 255 characters.',
]);
```

You can also customize messages for specific fields:

```php
$request->validate([
    'name' => 'required|string|max:255',
    'email' => 'required|email|unique:users,email',
], [
    'name.required' => 'Please enter your name.',
    'email.unique' => 'The email address is already taken.',
]);
```

### Summary

- **Opening Forms**: You can create forms in Laravel using Blade or Laravel Collective.
- **Form Fields**: Fields can be created using Blade syntax or Laravel Collective helpers.
- **Form Buttons**: You can create buttons using regular HTML or the `Form` facade.
- **Form Macro**: Define custom reusable form elements using macros.
- **Form Security**: Use `@csrf` for CSRF protection.
- **Validation**: Laravel provides an easy-to-use validation mechanism with simple rules and custom messages.
- **Error Messages**: Display validation errors using the `@error` directive in Blade.
- **Custom Validation Rules**: Create your own validation logic by defining custom rules.
- **Custom Validation Messages**: Customize error messages for each validation rule.

---

These techniques enable you to build secure, functional forms with robust validation in Laravel.