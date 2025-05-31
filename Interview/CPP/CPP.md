# C++ Interview Preparation Guide

## Core Language Concepts

### 1. Memory Management
- **Stack vs Heap**: Stack for local variables, heap for dynamic allocation
- **Pointers vs References**: References are aliases, pointers can be reassigned
- **Smart Pointers**: `unique_ptr`, `shared_ptr`, `weak_ptr` for automatic memory management
- **Memory Leaks**: Always pair `new` with `delete`, prefer RAII

### 2. Object-Oriented Programming
- **Classes and Objects**: Encapsulation, data members, member functions
- **Constructors**: Default, parameterized, copy, move constructors
- **Destructors**: Virtual destructors for base classes
- **Inheritance**: Public, private, protected inheritance
- **Polymorphism**: Virtual functions, pure virtual functions, abstract classes
- **Operator Overloading**: Common operators like `=`, `+`, `<<`, `>>`

### 3. STL (Standard Template Library)
- **Containers**: `vector`, `list`, `deque`, `set`, `map`, `unordered_set`, `unordered_map`
- **Iterators**: Input, output, forward, bidirectional, random access
- **Algorithms**: `sort`, `find`, `binary_search`, `transform`, `for_each`
- **Function Objects**: Functors, lambdas

## Common Interview Questions

### 1. What's the difference between C and C++?
- C++ supports OOP, function overloading, templates, references
- C++ has better type checking and standard library
- C is procedural, C++ supports multiple paradigms

### 2. Explain virtual functions
```cpp
class Base {
public:
    virtual void show() { cout << "Base"; }
    virtual ~Base() {} // Virtual destructor
};

class Derived : public Base {
public:
    void show() override { cout << "Derived"; }
};
```

### 3. What is RAII?
Resource Acquisition Is Initialization - resources are tied to object lifetime
```cpp
class FileHandler {
    FILE* file;
public:
    FileHandler(const char* name) : file(fopen(name, "r")) {}
    ~FileHandler() { if(file) fclose(file); }
};
```

### 4. Explain move semantics
- Introduced in C++11 to avoid unnecessary copying
- `std::move()` converts lvalue to rvalue reference
- Move constructor: `MyClass(MyClass&& other)`

### 5. What are templates?
Generic programming feature allowing type-independent code
```cpp
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

## Data Structures & Algorithms

### Common Patterns
1. **Two Pointers**: Array problems, palindromes
2. **Sliding Window**: Substring problems
3. **Binary Search**: Sorted arrays, search spaces
4. **Dynamic Programming**: Optimization problems
5. **Graph Traversal**: DFS, BFS
6. **Tree Traversal**: Inorder, preorder, postorder

### Time Complexities to Know
- **Vector**: Access O(1), Insert/Delete at end O(1)
- **List**: Access O(n), Insert/Delete O(1)
- **Set/Map**: Search/Insert/Delete O(log n)
- **Unordered Set/Map**: Average O(1), worst O(n)

## Code Examples to Practice

### 1. Implement a Stack
```cpp
template<typename T>
class Stack {
private:
    vector<T> data;
public:
    void push(const T& item) { data.push_back(item); }
    void pop() { if(!empty()) data.pop_back(); }
    T& top() { return data.back(); }
    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};
```

### 2. Singleton Pattern
```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if(!instance) {
            instance = new Singleton();
        }
        return instance;
    }
};
```

### 3. Binary Search Implementation
```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

## Advanced Topics

### 1. Exception Handling
- `try`, `catch`, `throw` blocks
- Standard exceptions: `std::exception`, `std::runtime_error`
- RAII ensures cleanup even with exceptions

### 2. Multithreading (C++11+)
- `std::thread`, `std::mutex`, `std::lock_guard`
- Thread synchronization and race conditions
- `std::atomic` for lock-free programming

### 3. Lambda Functions
```cpp
auto lambda = [capture](parameters) -> return_type {
    // function body
};
```

### 4. Perfect Forwarding
```cpp
template<typename T>
void wrapper(T&& arg) {
    func(std::forward<T>(arg));
}
```

## Interview Tips

### Preparation Strategy
1. **Practice coding on whiteboard/paper** - no IDE help
2. **Explain your thought process** while coding
3. **Test your code** with examples
4. **Discuss time/space complexity**
5. **Know when to use which STL container**

### Common Mistakes to Avoid
- Forgetting to handle edge cases (empty arrays, null pointers)
- Not initializing variables
- Memory leaks with dynamic allocation
- Infinite loops or incorrect loop conditions
- Not considering integer overflow

### What Interviewers Look For
- **Problem-solving approach**: Break down complex problems
- **Code quality**: Clean, readable, well-structured code
- **Communication**: Explain reasoning and trade-offs
- **Debugging skills**: Ability to find and fix errors
- **Knowledge depth**: Understanding of underlying concepts

## Sample Questions by Difficulty

### Easy
- Reverse a string
- Find maximum element in array
- Check if number is prime
- Implement basic calculator

### Medium
- Merge two sorted arrays
- Find longest substring without repeating characters
- Implement LRU cache
- Validate binary search tree

### Hard
- Serialize/deserialize binary tree
- Find median of two sorted arrays
- Design data structure for range queries
- Implement thread-safe bounded buffer

## Final Preparation Checklist
- [ ] Review OOP principles and examples
- [ ] Practice STL container usage
- [ ] Implement common data structures from scratch
- [ ] Solve 20-30 coding problems of varying difficulty
- [ ] Understand time/space complexity analysis
- [ ] Practice explaining code verbally
- [ ] Review system design basics for senior positions