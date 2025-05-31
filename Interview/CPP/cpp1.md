# Complete C++ Interview Preparation Guide

## Table of Contents
1. [Core Language Concepts](#core-language-concepts)
2. [Object-Oriented Programming](#object-oriented-programming)
3. [Standard Template Library (STL)](#standard-template-library-stl)
4. [Common Interview Questions](#common-interview-questions)
5. [Data Structures & Algorithms](#data-structures--algorithms)
6. [Advanced Topics](#advanced-topics)
7. [Practice Problems](#practice-problems)
8. [Interview Strategy](#interview-strategy)

---

## Core Language Concepts

### 1. Memory Management

#### Stack vs Heap
**Stack Memory:**
- Stores local variables and function parameters
- Automatically managed (allocated/deallocated)
- Fast access, limited size (~1-8MB)
- Variables destroyed when scope ends
- Memory layout: LIFO (Last In, First Out)

```cpp
void function() {
    int x = 10;        // Stack allocation
    char arr[100];     // Stack allocation
    // Automatically cleaned up when function ends
}
```

**Heap Memory:**
- Stores dynamically allocated objects
- Manually managed (new/delete, malloc/free)
- Slower access, large size (limited by system RAM)
- Programmer responsible for cleanup
- Can cause memory leaks if not properly managed

```cpp
void function() {
    int* ptr = new int(10);    // Heap allocation
    int* arr = new int[100];   // Heap allocation
    
    // Must manually clean up
    delete ptr;
    delete[] arr;
}
```

#### Pointers vs References

**Pointers:**
- Variables that store memory addresses
- Can be null, reassigned, and perform arithmetic
- Require dereferencing (*) to access value
- Can point to different objects during lifetime

```cpp
int x = 10, y = 20;
int* ptr = &x;     // Points to x
*ptr = 15;         // Changes x to 15
ptr = &y;          // Now points to y
ptr = nullptr;     // Can be null
```

**References:**
- Aliases for existing variables
- Must be initialized, cannot be reassigned
- Cannot be null, no arithmetic operations
- Direct access without dereferencing

```cpp
int x = 10;
int& ref = x;      // Reference to x
ref = 20;          // Changes x to 20
// int& ref2;      // Error: must initialize
// ref = y;        // Error: cannot reassign
```

#### Smart Pointers (C++11+)

**unique_ptr:**
- Exclusive ownership of a resource
- Cannot be copied, only moved
- Automatically deletes resource when destroyed

```cpp
#include <memory>

std::unique_ptr<int> ptr = std::make_unique<int>(42);
// std::unique_ptr<int> ptr2 = ptr;  // Error: cannot copy
std::unique_ptr<int> ptr2 = std::move(ptr);  // OK: transfer ownership
```

**shared_ptr:**
- Shared ownership among multiple pointers
- Reference counted - resource deleted when count reaches 0
- Can be copied and assigned

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
std::shared_ptr<int> ptr2 = ptr1;  // Both point to same resource
// Resource deleted when both ptr1 and ptr2 are destroyed
```

**weak_ptr:**
- Non-owning reference to shared_ptr managed object
- Breaks circular dependencies
- Must check validity before use

```cpp
std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;

if (auto locked = weak.lock()) {  // Convert to shared_ptr
    std::cout << *locked << std::endl;
}
```

#### RAII (Resource Acquisition Is Initialization)
Philosophy where resource lifetime is tied to object lifetime:
- Constructor acquires resources
- Destructor releases resources
- Ensures cleanup even with exceptions

```cpp
class FileManager {
private:
    std::FILE* file;
    
public:
    FileManager(const std::string& filename) 
        : file(std::fopen(filename.c_str(), "r")) {
        if (!file) {
            throw std::runtime_error("Cannot open file");
        }
    }
    
    ~FileManager() {
        if (file) {
            std::fclose(file);
        }
    }
    
    // Prevent copying to avoid double-close
    FileManager(const FileManager&) = delete;
    FileManager& operator=(const FileManager&) = delete;
};
```

---

## Object-Oriented Programming

### Classes and Objects

**Encapsulation:**
Bundling data and methods that operate on that data within a single unit.

```cpp
class BankAccount {
private:
    double balance;        // Data hiding
    std::string accountNumber;
    
public:
    // Constructor
    BankAccount(const std::string& accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance) {}
    
    // Public interface
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    double getBalance() const { return balance; }
};
```

### Constructors

**Types of Constructors:**

```cpp
class MyClass {
private:
    int value;
    std::string name;
    
public:
    // Default constructor
    MyClass() : value(0), name("") {}
    
    // Parameterized constructor
    MyClass(int v, const std::string& n) : value(v), name(n) {}
    
    // Copy constructor
    MyClass(const MyClass& other) : value(other.value), name(other.name) {
        std::cout << "Copy constructor called\n";
    }
    
    // Move constructor (C++11)
    MyClass(MyClass&& other) noexcept 
        : value(other.value), name(std::move(other.name)) {
        other.value = 0;
        std::cout << "Move constructor called\n";
    }
    
    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            value = other.value;
            name = other.name;
        }
        return *this;
    }
    
    // Move assignment operator (C++11)
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            value = other.value;
            name = std::move(other.name);
            other.value = 0;
        }
        return *this;
    }
};
```

### Inheritance

**Types of Inheritance:**

```cpp
class Animal {
protected:
    std::string name;
    
public:
    Animal(const std::string& n) : name(n) {}
    virtual void makeSound() = 0;  // Pure virtual function
    virtual ~Animal() {}           // Virtual destructor
};

// Public inheritance - "is-a" relationship
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    void makeSound() override {
        std::cout << name << " barks!\n";
    }
};

// Private inheritance - "implemented-in-terms-of"
class Timer : private std::vector<int> {
public:
    void addTime(int seconds) {
        push_back(seconds);  // Can use base class methods
    }
    // vector methods not accessible to Timer users
};
```

### Polymorphism

**Runtime Polymorphism (Virtual Functions):**

```cpp
class Shape {
public:
    virtual double area() const = 0;      // Pure virtual
    virtual void draw() const {           // Virtual with default implementation
        std::cout << "Drawing a shape\n";
    }
    virtual ~Shape() {}                   // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        std::cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
};

// Usage
void processShape(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;  // Runtime polymorphism
    shape.draw();
}
```

**Compile-time Polymorphism (Function Overloading):**

```cpp
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    int add(int a, int b, int c) {
        return a + b + c;
    }
};
```

### Operator Overloading

```cpp
class Complex {
private:
    double real, imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Binary operators
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    // Comparison operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    
    // Stream operators (as friend functions)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};
```

---

## Standard Template Library (STL)

### Containers

#### Sequence Containers

**std::vector:**
- Dynamic array, contiguous memory
- Fast random access O(1)
- Fast insertion/deletion at end O(1)
- Slow insertion/deletion in middle O(n)

```cpp
#include <vector>

std::vector<int> vec = {1, 2, 3, 4, 5};
vec.push_back(6);           // Add to end
vec.pop_back();             // Remove from end
vec.insert(vec.begin() + 2, 10);  // Insert at position
vec.erase(vec.begin() + 1); // Remove at position

// Iteration
for (const auto& elem : vec) {
    std::cout << elem << " ";
}
```

**std::list:**
- Doubly linked list
- No random access
- Fast insertion/deletion anywhere O(1)

```cpp
#include <list>

std::list<int> lst = {1, 2, 3, 4, 5};
lst.push_front(0);          // Add to beginning
lst.push_back(6);           // Add to end
lst.remove(3);              // Remove all elements with value 3

auto it = std::find(lst.begin(), lst.end(), 4);
if (it != lst.end()) {
    lst.insert(it, 99);     // Insert before position
}
```

**std::deque:**
- Double-ended queue
- Fast insertion/deletion at both ends O(1)
- Random access O(1)

```cpp
#include <deque>

std::deque<int> dq = {3, 4, 5};
dq.push_front(2);           // Add to front
dq.push_back(6);            // Add to back
dq.pop_front();             // Remove from front
dq.pop_back();              // Remove from back
```

#### Associative Containers

**std::set/std::multiset:**
- Ordered collection of unique/non-unique elements
- Implemented as balanced BST (usually Red-Black tree)
- All operations O(log n)

```cpp
#include <set>

std::set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5} - duplicates removed
s.insert(2);                         // {1, 2, 3, 4, 5}
s.erase(3);                          // {1, 2, 4, 5}

auto it = s.find(4);
if (it != s.end()) {
    std::cout << "Found: " << *it << std::endl;
}

// Multiset allows duplicates
std::multiset<int> ms = {1, 2, 2, 3, 3, 3};
```

**std::map/std::multimap:**
- Ordered key-value pairs
- Keys are unique in map, can repeat in multimap
- All operations O(log n)

```cpp
#include <map>

std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
ages.insert({"Charlie", 35});

// Safe access
if (ages.find("Alice") != ages.end()) {
    std::cout << "Alice is " << ages["Alice"] << " years old\n";
}

// Iteration
for (const auto& pair : ages) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
```

#### Unordered Containers (Hash Tables)

**std::unordered_set/std::unordered_multiset:**
- Hash table implementation
- Average O(1) operations, worst case O(n)
- No ordering guarantee

```cpp
#include <unordered_set>

std::unordered_set<int> us = {1, 2, 3, 4, 5};
us.insert(6);
us.erase(3);

if (us.count(4) > 0) {
    std::cout << "4 is in the set\n";
}
```

**std::unordered_map/std::unordered_multimap:**
- Hash table for key-value pairs
- Average O(1) operations

```cpp
#include <unordered_map>

std::unordered_map<std::string, int> umap;
umap["key1"] = 10;
umap["key2"] = 20;

auto it = umap.find("key1");
if (it != umap.end()) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```

### Iterators

**Types of Iterators:**

```cpp
#include <vector>
#include <iterator>

std::vector<int> vec = {1, 2, 3, 4, 5};

// Forward iterator
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// Reverse iterator
for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    std::cout << *it << " ";
}

// Const iterator
for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    // *it = 10;  // Error: cannot modify through const iterator
    std::cout << *it << " ";
}
```

### Algorithms

**Common STL Algorithms:**

```cpp
#include <algorithm>
#include <numeric>
#include <vector>

std::vector<int> vec = {5, 2, 8, 1, 9, 3};

// Sorting
std::sort(vec.begin(), vec.end());                    // Ascending
std::sort(vec.begin(), vec.end(), std::greater<>());  // Descending

// Searching
auto it = std::find(vec.begin(), vec.end(), 5);
bool found = std::binary_search(vec.begin(), vec.end(), 5);

// Transformation
std::vector<int> squared(vec.size());
std::transform(vec.begin(), vec.end(), squared.begin(), 
               [](int x) { return x * x; });

// Reduction
int sum = std::accumulate(vec.begin(), vec.end(), 0);
int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<>());

// Filtering
std::vector<int> evens;
std::copy_if(vec.begin(), vec.end(), std::back_inserter(evens),
             [](int x) { return x % 2 == 0; });

// For each
std::for_each(vec.begin(), vec.end(), [](int& x) { x *= 2; });
```

---

## Common Interview Questions

### 1. What's the difference between C and C++?

**C Language:**
- Procedural programming paradigm
- No classes or objects
- Manual memory management
- Function-based code organization
- Limited standard library
- No function overloading
- No references, only pointers

**C++ Language:**
- Multi-paradigm (procedural, OOP, generic, functional)
- Classes, objects, inheritance, polymorphism
- Both manual and automatic memory management (RAII, smart pointers)
- Object-oriented code organization
- Rich standard library (STL)
- Function and operator overloading
- References and pointers
- Templates for generic programming
- Exception handling

### 2. Explain Virtual Functions

Virtual functions enable runtime polymorphism (dynamic binding):

```cpp
class Animal {
public:
    virtual void sound() {  // Virtual function
        std::cout << "Animal makes a sound\n";
    }
    
    virtual ~Animal() {}    // Virtual destructor (important!)
};

class Dog : public Animal {
public:
    void sound() override { // Override keyword (C++11)
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Cat meows\n";
    }
};

// Runtime polymorphism
void makeSound(Animal* animal) {
    animal->sound();  // Calls appropriate derived class method
}

int main() {
    Animal* animals[] = {new Dog(), new Cat()};
    
    for (Animal* animal : animals) {
        makeSound(animal);  // Dog barks, Cat meows
        delete animal;
    }
    
    return 0;
}
```

**Virtual Function Table (vtable):**
- Each class with virtual functions has a vtable
- Contains pointers to virtual function implementations
- Each object has a pointer to its class's vtable
- Enables dynamic dispatch at runtime

### 3. What is RAII?

**Resource Acquisition Is Initialization** is a programming idiom:

```cpp
class DatabaseConnection {
private:
    void* connection;
    
public:
    // Resource acquired in constructor
    DatabaseConnection(const std::string& connectionString) {
        connection = connectToDatabase(connectionString);
        if (!connection) {
            throw std::runtime_error("Failed to connect");
        }
        std::cout << "Database connected\n";
    }
    
    // Resource released in destructor
    ~DatabaseConnection() {
        if (connection) {
            disconnectFromDatabase(connection);
            std::cout << "Database disconnected\n";
        }
    }
    
    // Prevent copying to avoid double-cleanup
    DatabaseConnection(const DatabaseConnection&) = delete;
    DatabaseConnection& operator=(const DatabaseConnection&) = delete;
    
    // Allow moving
    DatabaseConnection(DatabaseConnection&& other) noexcept 
        : connection(other.connection) {
        other.connection = nullptr;
    }
    
    void query(const std::string& sql) {
        // Use the connection
        executeQuery(connection, sql);
    }
};

void processData() {
    try {
        DatabaseConnection db("server=localhost");  // Resource acquired
        db.query("SELECT * FROM users");
        // If exception occurs, destructor still called
        throw std::runtime_error("Some error");
    } catch (...) {
        // Database automatically disconnected via destructor
    }
    // Database automatically disconnected when db goes out of scope
}
```

### 4. Explain Move Semantics (C++11)

Move semantics allow transferring resources instead of copying:

```cpp
class String {
private:
    char* data;
    size_t size;
    
public:
    // Constructor
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
        std::cout << "Constructor: " << data << std::endl;
    }
    
    // Copy constructor (expensive)
    String(const String& other) {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor: " << data << std::endl;
    }
    
    // Move constructor (cheap)
    String(String&& other) noexcept {
        data = other.data;          // Transfer ownership
        size = other.size;
        other.data = nullptr;       // Leave other in valid state
        other.size = 0;
        std::cout << "Move constructor: " << data << std::endl;
    }
    
    // Copy assignment
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
            std::cout << "Copy assignment: " << data << std::endl;
        }
        return *this;
    }
    
    // Move assignment
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assignment: " << data << std::endl;
        }
        return *this;
    }
    
    ~String() {
        delete[] data;
        std::cout << "Destructor" << std::endl;
    }
};

String createString() {
    return String("Hello, World!");  // Return by value triggers move
}

int main() {
    String s1("Original");           // Constructor
    String s2 = s1;                  // Copy constructor
    String s3 = std::move(s1);       // Move constructor
    String s4 = createString();      // Move constructor (RVO may optimize this)
    
    return 0;
}
```

### 5. What are Templates?

Templates enable generic programming:

**Function Templates:**
```cpp
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Template specialization
template<>
const char* maximum<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// Usage
int maxInt = maximum(10, 20);           // T = int
double maxDouble = maximum(3.14, 2.71); // T = double
```

**Class Templates:**
```cpp
template<typename T, size_t N>
class Array {
private:
    T data[N];
    
public:
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    size_t size() const {
        return N;
    }
    
    // Member function template
    template<typename U>
    void fill(const U& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = static_cast<T>(value);
        }
    }
};

// Usage
Array<int, 5> intArray;
Array<std::string, 3> stringArray;
```

**Variadic Templates (C++11):**
```cpp
template<typename... Args>
void print(Args... args) {
    ((std::cout << args << " "), ...);  // C++17 fold expression
    std::cout << std::endl;
}

// Recursive version (pre-C++17)
template<typename T>
void printRecursive(T&& t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void printRecursive(T&& t, Args&&... args) {
    std::cout << t << " ";
    printRecursive(args...);
}

// Usage
print(1, 2.5, "hello", 'c');  // Output: 1 2.5 hello c
```

---

## Data Structures & Algorithms

### Common Problem-Solving Patterns

#### 1. Two Pointers Technique

**Valid Palindrome:**
```cpp
bool isPalindrome(const std::string& s) {
    int left = 0, right = s.length() - 1;
    
    while (left < right) {
        while (left < right && !std::isalnum(s[left])) left++;
        while (left < right && !std::isalnum(s[right])) right--;
        
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}
```

**Two Sum (Sorted Array):**
```cpp
std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1};  // 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return {};  // No solution found
}
```

#### 2. Sliding Window Technique

**Longest Substring Without Repeating Characters:**
```cpp
int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_set<char> window;
    int left = 0, maxLength = 0;
    
    for (int right = 0; right < s.length(); right++) {
        while (window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]);
        maxLength = std::max(maxLength, right - left + 1);
    }
    
    return maxLength;
}
```

**Maximum Sum Subarray of Size K:**
```cpp
int maxSumSubarray(const std::vector<int>& arr, int k) {
    if (arr.size() < k) return -1;
    
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    int maxSum = windowSum;
    for (int i = k; i < arr.size(); i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = std::max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

#### 3. Binary Search

**Basic Binary Search:**
```cpp
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  // Not found
}
```

**Search in Rotated Sorted Array:**
```cpp
int searchRotated(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}
```

#### 4. Dynamic Programming

**Fibonacci (Bottom-up):**
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    
    int prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}
```

**Longest Common Subsequence:**
```cpp
int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    int m = text1.length(), n = text2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}
```

#### 5. Graph Traversal

**Depth-First Search (DFS):**
```cpp
class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    
    void dfsUtil(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }
    
public:
    Graph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Undirected graph
    }
    
    void dfs(int startVertex) {
        std::vector<bool> visited(vertices, false);
        dfsUtil(startVertex, visited);
    }
};
```

**Breadth-First Search (BFS):**
```cpp
void Graph::bfs(int startVertex) {
    std::vector<bool> visited(vertices, false);
    std::queue<int> queue;
    
    visited[startVertex] = true;
    queue.push(startVertex);
    
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";
        
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}
```

#### 6. Tree Traversal

**Binary Tree Node:**
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

**Tree Traversals:**
```cpp
class BinaryTree {
public:
    // Inorder: Left -> Root -> Right
    void inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            std::cout << root->val << " ";
            inorderTraversal(root->right);
        }
    }
    
    // Preorder: Root -> Left -> Right
    void preorderTraversal(TreeNode* root) {
        if (root) {
            std::cout << root->val << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    
    // Postorder: Left -> Right -> Root
    void postorderTraversal(TreeNode* root) {
        if (root) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            std::cout << root->val << " ";
        }
    }
    
    // Level-order (BFS)
    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;
        
        std::queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            std::cout << node->val << " ";
            
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }
    }
};
```

### Time Complexity Analysis

**Big O Notation:**
- **O(1)**: Constant time - array access, hash table operations (average)
- **O(log n)**: Logarithmic - binary search, balanced tree operations
- **O(n)**: Linear - linear search, single loop
- **O(n log n)**: Linearithmic - efficient sorting algorithms (merge sort, heap sort)
- **O(n²)**: Quadratic - nested loops, bubble sort
- **O(2ⁿ)**: Exponential - recursive fibonacci, subset generation
- **O(n!)**: Factorial - permutation generation

**Space Complexity:**
- Additional memory used by algorithm
- Consider recursion stack space
- In-place algorithms use O(1) extra space

---

## Advanced Topics

### 1. Exception Handling

**Basic Exception Handling:**
```cpp
#include <stdexcept>
#include <iostream>

class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero error";
    }
};

double divide(double numerator, double denominator) {
    if (denominator == 0.0) {
        throw DivisionByZeroException();
    }
    return numerator / denominator;
}

void demonstrateExceptions() {
    try {
        double result = divide(10.0, 0.0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivisionByZeroException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception caught" << std::endl;
    }
}
```

**RAII with Exceptions:**
```cpp
class ResourceManager {
private:
    int* resource;
    
public:
    ResourceManager() : resource(new int[1000]) {
        std::cout << "Resource acquired\n";
    }
    
    ~ResourceManager() {
        delete[] resource;
        std::cout << "Resource released\n";
    }
    
    void doWork() {
        // Even if this throws, destructor will be called
        throw std::runtime_error("Something went wrong");
    }
};

void testRAII() {
    try {
        ResourceManager rm;
        rm.doWork();  // Throws exception
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        // Resource automatically cleaned up
    }
}
```

### 2. Multithreading (C++11+)

**Basic Threading:**
```cpp
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>

// Simple thread creation
void workerFunction(int id) {
    std::cout << "Worker " << id << " is working\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Worker " << id << " finished\n";
}

void basicThreading() {
    std::vector<std::thread> threads;
    
    // Create threads
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back(workerFunction, i);
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
}
```

**Thread Synchronization:**
```cpp
class ThreadSafeCounter {
private:
    mutable std::mutex mtx;
    int count = 0;
    
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++count;
    }
    
    int getValue() const {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
};

// Producer-Consumer pattern
class ProducerConsumer {
private:
    std::queue<int> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    bool finished = false;
    static const size_t MAX_SIZE = 10;
    
public:
    void produce(int value) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return buffer.size() < MAX_SIZE; });
        
        buffer.push(value);
        std::cout << "Produced: " << value << std::endl;
        cv.notify_all();
    }
    
    int consume() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !buffer.empty() || finished; });
        
        if (buffer.empty()) return -1;  // No more items
        
        int value = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << value << std::endl;
        cv.notify_all();
        return value;
    }
    
    void finish() {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
        cv.notify_all();
    }
};
```

**Atomic Operations:**
```cpp
#include <atomic>

class AtomicCounter {
private:
    std::atomic<int> count{0};
    
public:
    void increment() {
        count.fetch_add(1, std::memory_order_relaxed);
    }
    
    int getValue() const {
        return count.load(std::memory_order_relaxed);
    }
    
    bool compareAndSwap(int expected, int desired) {
        return count.compare_exchange_weak(expected, desired);
    }
};
```

### 3. Lambda Functions (C++11+)

**Basic Lambda Syntax:**
```cpp
// [capture](parameters) -> return_type { body }

auto add = [](int a, int b) -> int {
    return a + b;
};

// Type deduction
auto multiply = [](int a, int b) {
    return a * b;  // Return type deduced as int
};

std::cout << add(5, 3) << std::endl;       // 8
std::cout << multiply(4, 6) << std::endl;  // 24
```

**Capture Modes:**
```cpp
void lambdaCaptures() {
    int x = 10, y = 20;
    
    // Capture by value
    auto lambda1 = [x, y](int z) {
        return x + y + z;  // x and y are copied
    };
    
    // Capture by reference
    auto lambda2 = [&x, &y](int z) {
        x += z;  // Modifies original x
        return x + y;
    };
    
    // Capture all by value
    auto lambda3 = [=](int z) {
        return x + y + z;  // All local variables copied
    };
    
    // Capture all by reference
    auto lambda4 = [&](int z) {
        x += z;  // All local variables by reference
        return x + y;
    };
    
    // Mixed capture
    auto lambda5 = [x, &y](int z) {
        // x by value, y by reference
        y += z;
        return x + y;
    };
    
    // Generalized capture (C++14)
    auto lambda6 = [value = x * 2](int z) {
        return value + z;
    };
}
```

**Lambda with STL Algorithms:**
```cpp
void lambdaWithSTL() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Find first even number
    auto it = std::find_if(numbers.begin(), numbers.end(), 
                          [](int n) { return n % 2 == 0; });
    
    // Transform to squares
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(),
                  [](int n) { return n * n; });
    
    // Count numbers greater than 5
    int count = std::count_if(numbers.begin(), numbers.end(),
                             [](int n) { return n > 5; });
    
    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(),
             [](int a, int b) { return a > b; });
    
    // Custom predicate with capture
    int threshold = 6;
    auto newEnd = std::remove_if(numbers.begin(), numbers.end(),
                                [threshold](int n) { return n < threshold; });
    numbers.erase(newEnd, numbers.end());
}
```

### 4. Perfect Forwarding and Universal References

**Universal References (C++11):**
```cpp
template<typename T>
void func(T&& param) {  // Universal reference (not rvalue reference!)
    // T&& can bind to both lvalues and rvalues
}

void testUniversalReferences() {
    int x = 42;
    func(x);        // T deduced as int&, param is int&
    func(42);       // T deduced as int, param is int&&
    func(std::move(x)); // T deduced as int, param is int&&
}
```

**Perfect Forwarding:**
```cpp
#include <utility>

// Without perfect forwarding - creates unnecessary copies
template<typename T>
void imperfectWrapper(T param) {
    someFunction(param);  // Always passes by value
}

// With perfect forwarding - preserves value category
template<typename T>
void perfectWrapper(T&& param) {
    someFunction(std::forward<T>(param));
}

// Example: Factory function
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Usage
class MyClass {
public:
    MyClass(int a, const std::string& s) { /* ... */ }
};

auto obj = make_unique<MyClass>(42, std::string("hello"));
```

---

## Practice Problems

### Easy Level

#### 1. Reverse a String
```cpp
std::string reverseString(std::string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

// Or using STL
std::string reverseStringSTL(std::string s) {
    std::reverse(s.begin(), s.end());
    return s;
}
```

#### 2. Find Maximum Element
```cpp
int findMaximum(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Array is empty");
    }
    
    int maxVal = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Using STL
int findMaximumSTL(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Array is empty");
    }
    return *std::max_element(arr.begin(), arr.end());
}
```

#### 3. Check if Number is Prime
```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
```

### Medium Level

#### 1. Merge Two Sorted Arrays
```cpp
std::vector<int> mergeSortedArrays(const std::vector<int>& arr1, 
                                  const std::vector<int>& arr2) {
    std::vector<int> result;
    result.reserve(arr1.size() + arr2.size());
    
    size_t i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i++]);
        } else {
            result.push_back(arr2[j++]);
        }
    }
    
    // Add remaining elements
    while (i < arr1.size()) {
        result.push_back(arr1[i++]);
    }
    while (j < arr2.size()) {
        result.push_back(arr2[j++]);
    }
    
    return result;
}
```

#### 2. LRU Cache Implementation
```cpp
#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cache;  // key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;  // Key not found
        }
        
        // Move to front (most recently used)
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        
        if (it != map.end()) {
            // Update existing key
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
        } else {
            // Add new key
            if (cache.size() >= capacity) {
                // Remove least recently used
                int lruKey = cache.back().first;
                cache.pop_back();
                map.erase(lruKey);
            }
            
            cache.emplace_front(key, value);
            map[key] = cache.begin();
        }
    }
};
```

#### 3. Validate Binary Search Tree
```cpp
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;
    
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }
    
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}
```

### Hard Level

#### 1. Serialize and Deserialize Binary Tree
```cpp
class Codec {
public:
    // Encodes a tree to a single string
    std::string serialize(TreeNode* root) {
        std::ostringstream oss;
        serializeHelper(root, oss);
        return oss.str();
    }
    
private:
    void serializeHelper(TreeNode* node, std::ostringstream& oss) {
        if (!node) {
            oss << "null,";
        } else {
            oss << node->val << ",";
            serializeHelper(node->left, oss);
            serializeHelper(node->right, oss);
        }
    }
    
public:
    // Decodes your encoded data to tree
    TreeNode* deserialize(const std::string& data) {
        std::istringstream iss(data);
        return deserializeHelper(iss);
    }
    
private:
    TreeNode* deserializeHelper(std::istringstream& iss) {
        std::string val;
        std::getline(iss, val, ',');
        
        if (val == "null") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }
};
```

#### 2. Find Median of Two Sorted Arrays
```cpp
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;
    
    while (left <= right) {
        int partition1 = (left + right) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (std::max(maxLeft1, maxLeft2) + 
                       std::min(minRight1, minRight2)) / 2.0;
            } else {
                return std::max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            right = partition1 - 1;
        } else {
            left = partition1 + 1;
        }
    }
    
    throw std::invalid_argument("Input arrays are not sorted");
}
```

---

## Interview Strategy

### Preparation Timeline

**4-6 Weeks Before Interview:**
- Review all fundamental C++ concepts
- Practice basic data structures implementation
- Solve 50+ easy problems on LeetCode/HackerRank

**2-3 Weeks Before Interview:**
- Focus on medium-level algorithm problems
- Practice system design questions (for senior roles)
- Mock interviews with friends/online platforms

**1 Week Before Interview:**
- Review your solutions to hard problems
- Practice explaining code on whiteboard
- Prepare questions to ask the interviewer

### During the Interview

**Problem-Solving Approach:**
1. **Understand the Problem**
   - Ask clarifying questions
   - Identify inputs, outputs, constraints
   - Work through examples

2. **Plan Your Solution**
   - Discuss approach with interviewer
   - Consider edge cases
   - Analyze time/space complexity

3. **Implement**
   - Write clean, readable code
   - Use meaningful variable names
   - Add comments for complex logic

4. **Test Your Solution**
   - Walk through with examples
   - Check edge cases
   - Fix bugs if found

**Communication Tips:**
- Think out loud during problem-solving
- Explain your reasoning for design choices
- Be open to feedback and suggestions
- Ask questions when stuck

**Common Mistakes to Avoid:**
- Jumping into coding without understanding
- Not considering edge cases
- Writing buggy code due to rushing
- Not testing the solution
- Poor variable naming
- Not handling memory management properly

### What Interviewers Look For

**Technical Skills:**
- Strong understanding of C++ fundamentals
- Knowledge of data structures and algorithms
- Ability to write clean, efficient code
- Understanding of time/space complexity

**Problem-Solving Ability:**
- Systematic approach to breaking down problems
- Ability to handle complex requirements
- Creative thinking for optimization

**Communication:**
- Clear explanation of thought process
- Ability to discuss trade-offs
- Good collaboration skills

**Code Quality:**
- Readable and maintainable code
- Proper error handling
- Consideration of edge cases
- Good software engineering practices

### Sample Interview Questions

**Language-Specific Questions:**
1. Explain the difference between `delete` and `delete[]`
2. What happens if you don't declare a destructor as virtual?
3. When would you use `const` keyword in different contexts?
4. Explain the difference between shallow copy and deep copy
5. What is the diamond problem in multiple inheritance?

**Design Questions:**
1. Design a thread-safe singleton class
2. Implement a memory pool allocator
3. Design a cache with TTL (Time To Live)
4. Implement a thread-safe producer-consumer queue

**Algorithm Questions:**
1. Find the kth largest element in an array
2. Implement a trie (prefix tree)
3. Design and implement a hash table
4. Solve the N-Queens problem

### Final Checklist

**Technical Preparation:**
- [ ] Master all C++ fundamentals
- [ ] Understand STL containers and their complexities
- [ ] Practice implementing data structures from scratch
- [ ] Solve problems across all difficulty levels
- [ ] Understand memory management and RAII
- [ ] Know when to use different language features

**Soft Skills:**
- [ ] Practice explaining code verbally
- [ ] Prepare questions about the company/role
- [ ] Mock interview practice
- [ ] Time management during coding
- [ ] Stress management techniques

**Day of Interview:**
- [ ] Get good sleep the night before
- [ ] Arrive early and prepared
- [ ] Bring multiple copies of resume
- [ ] Stay calm and think systematically
- [ ] Ask for clarification when needed
- [ ] Thank the interviewer at the end

Remember: Interviews are not just about getting the right answer, but demonstrating your problem-solving process, communication skills, and ability to work with others. Focus on showing your thought process and be confident in your abilities!

---

*Good luck with your C++ interview preparation! Remember to practice regularly and stay confident in your abilities.*