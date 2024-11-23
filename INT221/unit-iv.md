# Unit IV :: URL Generation, Request Data and Emails & Laravel Localization and Sessions
## Topics
#### URL Generation, Request Data and Emails ::
Request Data-Retrieval, Old Input, Uploaded Files, Cookies, Sending Emails

#### Laravel Localization and Sessions ::
Laravel Localization and Examples, Laravel Session- Accessing Session Data, Storing Session Data, Deleting Session Data

---


Here's an overview of these Laravel features, focusing on URL generation, request data handling, email sending, localization, and session management.

---

### **URL Generation in Laravel**

Laravel provides a simple way to generate URLs for routes and assets, making it easy to manage links and paths across the application.

- **Generating URLs to Routes**  
  Use the `route` helper to generate URLs for named routes, which helps keep code clean and maintainable:

  ```php
  $url = route('user.profile', ['id' => 1]); // Generates URL for a route named 'user.profile'
  ```

- **Generating URLs for Assets**  
  The `asset` helper generates URLs for assets like CSS, JavaScript, or images located in the `public` folder.

  ```php
  <link rel="stylesheet" href="{{ asset('css/style.css') }}">
  ```

---

### **Request Data**

Handling incoming request data is essential in web applications, and Laravel provides powerful tools for this.

**1. Retrieval**  
   Laravel’s `Request` class retrieves data sent to the application. It can access form data, query parameters, and headers:

   ```php
   $name = $request->input('name'); // Retrieve data from input fields
   $query = $request->query('page'); // Retrieve query parameter
   ```

**2. Old Input**  
   `old` helper retrieves data from the previous request. Useful for repopulating forms after validation errors:

   ```php
   <input type="text" name="name" value="{{ old('name') }}">
   ```

**3. Uploaded Files**  
   Handle file uploads by using Laravel’s `Request` class. It provides methods for validating, storing, and retrieving file information:

   ```php
   if ($request->hasFile('avatar')) {
       $path = $request->file('avatar')->store('avatars');
   }
   ```

**4. Cookies**  
   Laravel’s `cookie` helper makes setting, retrieving, and deleting cookies straightforward.

   - **Setting a Cookie**:
     ```php
     return response('Hello')->cookie('name', 'value', $minutes);
     ```

   - **Retrieving a Cookie**:
     ```php
     $value = $request->cookie('name');
     ```

---

### **Sending Emails**

Laravel provides a clean, simple API for sending emails through a variety of drivers like SMTP, Mailgun, and SES.

- **Basic Email Sending**  
  The `Mail` facade allows for quick and customizable email sending.

  ```php
  Mail::to('example@example.com')->send(new OrderShipped($order));
  ```

- **Markdown Emails**  
  Laravel includes built-in support for Markdown email templates, making it easy to create styled emails.

  ```php
  Mail::to($user->email)->send(new WelcomeEmail($user));
  ```

---

### **Laravel Localization**

Localization lets you create multilingual applications, serving content based on the user’s language preference.

**1. Setting Up Localization**  
   Laravel organizes translations in the `resources/lang` directory, where you create subdirectories for each language (e.g., `en`, `fr`, etc.).

**2. Retrieving Translated Strings**  
   The `trans` helper or `__` function retrieves translated strings:

   ```php
   echo __('messages.welcome'); // Retrieves the translation for the 'welcome' key in the 'messages' file
   ```

**3. Language Switching**  
   Laravel allows switching the app’s language dynamically by setting the locale in the `config/app.php` file or using middleware:

   ```php
   App::setLocale('fr');
   ```

**Example**:
```php
// resources/lang/en/messages.php
return [
    'welcome' => 'Welcome to our application!',
];

// resources/lang/fr/messages.php
return [
    'welcome' => 'Bienvenue dans notre application!',
];
```

---

### **Session Management**

Sessions allow storing user data across requests and are useful for managing things like login states, user preferences, and flash messages.

**1. Accessing Session Data**  
   Retrieve session data using the `session` helper or the `Session` facade:

   ```php
   $value = session('key', 'default'); // Retrieves session value or default
   ```

**2. Storing Session Data**  
   Store data in the session to persist it across requests:

   ```php
   session(['key' => 'value']);
   ```

**3. Flash Data**  
   Flash data is only available during the user’s next request. Useful for one-time messages, such as form submission success.

   ```php
   session()->flash('status', 'Task was successful!');
   ```

**4. Deleting Session Data**  
   Remove data from the session with the `forget` or `flush` methods:

   ```php
   session()->forget('key'); // Removes a single key
   session()->flush();       // Clears all session data
   ```

**Example Use Case**:
```php
if (session()->has('user_id')) {
    echo "Welcome back, user!";
} else {
    session(['user_id' => $user->id]);
}
```

---

These features in Laravel streamline common tasks, from managing URLs and request data to handling sessions and localization, making it easier to build robust, user-friendly applications.


## URL Generation
1. **Current URL:** $currentUrl = url()->current();
2. **Previous URL:** $previousUrl = url()->previous();
3. **Absolute URL:** $absoluteUrl = url('/');
4. **Route URL:** $routeUrl = route('home');
5. **Action URL:** $actionUrl = action('HomeController@index');
6. **Asset URL:** $assetUrl = asset('css/style.css');
7. **Full URL with Query String:** $fullUrl = url()->full();
8. **Secure URL:** $secureUrl = url()->secure();
9. **Current Route Name:** $currentRouteName = route()->current()->getName();
10. **Generate URL Named Route:** $namedRouteUrl = route('profile', ['id' => 1]);

## Request Data
1. **From GET or POST:** $data = request()->all();
2. **From Query String:** $data = request()->query();
3. **From Route Parameters:** $data = request()->route()->parameters();
4. **From Request Headers:** $data = request()->header();
5. **From Request Cookies:** $data = request()->cookie();
6. **From Request Files:** $data = request()->file();
7. **From Request Input:** $data = request()->input();
8. **From Request JSON:** $data = request()->json();

## Cookies
1. **Set Cookie:** $cookie = cookie('name', 'value', 60);
2. **Get Cookie:** $cookie = request()->cookie('name');
3. **Delete Cookie:** $cookie = cookie('name', null);

## Session
1. **Set Session:** $session = session('name', 'value');
2. **Get Session:** $session = session('name');
3. **Delete Session:** $session = session()->forget('name');
4. **Flush Session:** $session = session()->flush();
 
## Flash Session
1. **Set Flash Session:** $flashSession = session()->flash('name', 'value');
2. **Get Flash Session:** $flashSession = session('name');
3. **Keep Flash Session:** $flashSession = session()->keep('name');

## Redirect
1. **Redirect to URL:** $redirect = redirect('/');
2. **Redirect to Route:** $redirect = redirect()->route('home');
3. **Redirect to Action:** $redirect = redirect()->action('HomeController@index');
4. **Redirect to Controller Action:** $redirect = redirect()->controller('HomeController@index');
5. **Redirect to Named Route:** $redirect = redirect()->route('profile', ['id' => 1]);
6. **Redirect to Named Route with Query String:** $redirect = redirect()->route('profile', ['id' => 1])->query(['name' => 'Raushan Kumar']);
 
## View
1. **Render View:** $view = view('home');
2. **Render View with Data:** $view = view('home', ['name' => 'Raushan Kumar']);
3. **Render View with Data and Merge:** $view = view('home', ['name' => 'Raushan Kumar'])->with('email', 'raushan@dev.com');
4. **Render View with Data and Share:** $view = view('home', ['name' => 'Raushan Kumar'])->share('email', 'raushan@dev.com');
5. **Render View with Data and Share Named:** $view = view('home', ['name' => 'Raushan Kumar'])->with('email', 'raushan@dev.com')->withName('user'); 
 
## Response
1. **Create Response:** $response = response('Hello World');
2. **Create Response with Data:** $response = response('Hello World')->header('Content-Type', 'text/plain');
3. **Create Response with JSON:** $response = response()->json(['name' => 'Raushan Kumar']);
4. **Create Response with JSONP:** $response = response()->json(['name' => 'Raushan Kumar'])->jsonp('callback');
5. **Create Response with Redirect:** $response = response()->redirect('/');

## Sending Mail
1. **Send Mail:** $mail = Mail::to('raushan@dev.com')->send(new WelcomeMail());
2. **Send Mail with Data:** $mail = Mail::to('raushan@dev.com')->send(new WelcomeMail(['name' => 'Raushan Kumar']));
3. **Send Mail with View:** $mail = Mail::to('raushan@dev.com')->view('emails.welcome');
 
## Localization
1. **Set Locale:** $locale = app()->setLocale('en');
2. **Get Locale:** $locale = app()->getLocale();
3. **Get Supported Locales:** $supportedLocales = app()->getSupportedLocales();
