# C++ Interview Preparation for TCS Digital

## 1. Basic Concepts

### Object-Oriented Programming (OOP) Pillars
- **Encapsulation**: Bundling data and methods together
- **Inheritance**: Creating new classes based on existing ones
- **Polymorphism**: Same interface, different implementations
- **Abstraction**: Hiding complex implementation details

### Key C++ Features
- **Classes and Objects**
- **Constructors and Destructors**
- **Function Overloading**
- **Operator Overloading**
- **Templates**
- **STL (Standard Template Library)**

## 2. Common Interview Questions & Code Examples

### A. Basic Class Implementation
```cpp
class Student {
private:
    string name;
    int rollNo;
    float marks;

public:
    // Constructor
    Student(string n, int r, float m) : name(n), rollNo(r), marks(m) {}
    
    // Getter methods
    string getName() const { return name; }
    int getRollNo() const { return rollNo; }
    float getMarks() const { return marks; }
    
    // Display method
    void display() {
        cout << "Name: " << name << ", Roll: " << rollNo 
             << ", Marks: " << marks << endl;
    }
};
```

### B. Inheritance Example
```cpp
// Base class
class Shape {
protected:
    int width, height;
public:
    Shape(int w, int h) : width(w), height(h) {}
    virtual int area() = 0; // Pure virtual function
};

// Derived class
class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}
    int area() override {
        return width * height;
    }
};

class Triangle : public Shape {
public:
    Triangle(int w, int h) : Shape(w, h) {}
    int area() override {
        return (width * height) / 2;
    }
};
```

### C. Polymorphism Demo
```cpp
void printArea(Shape* shape) {
    cout << "Area: " << shape->area() << endl;
}

int main() {
    Rectangle rect(10, 5);
    Triangle tri(10, 5);
    
    printArea(&rect); // Output: Area: 50
    printArea(&tri);  // Output: Area: 25
    
    return 0;
}
```

## 3. Important Programming Problems

### A. Array Operations
```cpp
// Find maximum element
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

// Reverse an array
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### B. String Manipulation
```cpp
// Check if string is palindrome
bool isPalindrome(string str) {
    int n = str.length();
    for(int i = 0; i < n/2; i++) {
        if(str[i] != str[n-1-i]) return false;
    }
    return true;
}

// Count vowels and consonants
void countVowelsConsonants(string str) {
    int vowels = 0, consonants = 0;
    for(char c : str) {
        if(isalpha(c)) {
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
}
```

### C. Sorting Algorithms
```cpp
// Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

## 4. STL (Standard Template Library)

### Commonly Used Containers
```cpp
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

// Vector operations
vector<int> v = {1, 2, 3, 4, 5};
v.push_back(6);
v.pop_back();
sort(v.begin(), v.end());

// Map operations
map<string, int> mp;
mp["apple"] = 5;
mp["banana"] = 3;

// Set operations
set<int> s = {3, 1, 4, 1, 5}; // Automatically sorted, duplicates removed

// Queue and Stack
queue<int> q;
stack<int> st;
```

## 5. Pointer Concepts

### Basic Pointers
```cpp
int x = 10;
int* ptr = &x;
cout << "Value: " << *ptr << endl;    // Output: 10
cout << "Address: " << ptr << endl;   // Address of x

// Dynamic memory allocation
int* arr = new int[5];
// Use the array
delete[] arr; // Don't forget to free memory
```

### Function Pointers
```cpp
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {
    int (*operation)(int, int);
    operation = add;
    cout << operation(5, 3) << endl; // Output: 8
    
    operation = multiply;
    cout << operation(5, 3) << endl; // Output: 15
    return 0;
}
```

## 6. Template Programming
```cpp
// Function template
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class template
template<class T>
class Calculator {
public:
    T add(T a, T b) { return a + b; }
    T subtract(T a, T b) { return a - b; }
};

int main() {
    cout << getMax(10, 20) << endl;        // Works with int
    cout << getMax(10.5, 20.3) << endl;    // Works with double
    
    Calculator<int> intCalc;
    Calculator<float> floatCalc;
    
    return 0;
}
```

## 7. Exception Handling
```cpp
#include <stdexcept>

double divide(double a, double b) {
    if(b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    try {
        double result = divide(10, 0);
        cout << result << endl;
    }
    catch(const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
```

## 8. File Handling
```cpp
#include <fstream>

// Writing to file
void writeToFile() {
    ofstream file("example.txt");
    if(file.is_open()) {
        file << "Hello World!" << endl;
        file << "C++ File Handling" << endl;
        file.close();
    }
}

// Reading from file
void readFromFile() {
    ifstream file("example.txt");
    string line;
    if(file.is_open()) {
        while(getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}
```

## 9. Common Interview Problems

### A. Fibonacci Series
```cpp
// Recursive approach
int fibonacci(int n) {
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Iterative approach (more efficient)
int fibonacciIterative(int n) {
    if(n <= 1) return n;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```

### B. Prime Number Check
```cpp
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}
```

### C. Factorial
```cpp
// Recursive
int factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

// Iterative
int factorialIterative(int n) {
    int result = 1;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
```

## 10. Memory Management Tips

- Always match `new` with `delete` and `new[]` with `delete[]`
- Use smart pointers (`unique_ptr`, `shared_ptr`) when possible
- Avoid memory leaks by proper cleanup
- Initialize pointers to `nullptr`
- Check for null pointers before dereferencing

## 11. Interview Tips

### Technical Preparation
- Practice coding problems on paper
- Understand time and space complexity
- Be familiar with STL containers and algorithms
- Know the difference between pass by value, reference, and pointer

### Common Questions to Expect
1. Difference between C and C++
2. What is polymorphism? Explain with example
3. Constructor vs Destructor
4. Virtual functions and pure virtual functions
5. Memory management in C++
6. STL containers and their use cases
7. Templates and their advantages

### Coding Best Practices
- Write clean, readable code
- Use meaningful variable names
- Add comments for complex logic
- Handle edge cases
- Test your code mentally

Remember to practice these concepts hands-on and be prepared to write code on paper or whiteboard during the interview!