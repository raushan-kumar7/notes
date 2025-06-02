# Complete STL Guide for TCS Digital Interview

## 1. STL Components Overview

### Core Components:
- **Containers**: Data structures to store objects
- **Iterators**: Objects that point to elements in containers
- **Algorithms**: Functions that perform operations on containers
- **Function Objects (Functors)**: Objects that can be called like functions

## 2. Containers - Complete Details

### 2.1 Sequence Containers

#### Vector
```cpp
#include <vector>
vector<int> v = {1, 2, 3, 4, 5};

// Common Operations:
v.push_back(6);           // O(1) amortized
v.pop_back();             // O(1)
v.insert(v.begin()+2, 10); // O(n)
v.erase(v.begin()+1);     // O(n)
v.size();                 // O(1)
v.capacity();             // O(1)
v.resize(10);             // O(n)
v.reserve(100);           // O(n)
v.clear();                // O(n)
v.empty();                // O(1)
v[0] = 100;               // O(1) - no bounds checking
v.at(0) = 100;            // O(1) - with bounds checking
v.front();                // O(1)
v.back();                 // O(1)
```

**Key Points:**
- Dynamic array, elements stored contiguously
- Automatic memory management
- When capacity is exceeded, entire vector is reallocated (typically doubles)
- Iterator invalidation occurs during reallocation

#### Deque (Double-ended queue)
```cpp
#include <deque>
deque<int> dq = {1, 2, 3};

dq.push_front(0);         // O(1)
dq.push_back(4);          // O(1)
dq.pop_front();           // O(1)
dq.pop_back();            // O(1)
dq.insert(dq.begin()+1, 5); // O(n)
dq.erase(dq.begin());     // O(n)
```

**Key Points:**
- Efficient insertion/deletion at both ends
- Random access like vector
- Not stored contiguously in memory

#### List (Doubly Linked List)
```cpp
#include <list>
list<int> lst = {1, 2, 3};

lst.push_front(0);        // O(1)
lst.push_back(4);         // O(1)
lst.pop_front();          // O(1)
lst.pop_back();           // O(1)
lst.insert(++lst.begin(), 5); // O(1)
lst.erase(lst.begin());   // O(1)
lst.remove(3);            // O(n) - removes all elements with value 3
lst.sort();               // O(n log n)
lst.reverse();            // O(n)
lst.unique();             // O(n) - removes consecutive duplicates
```

**Key Points:**
- No random access (no [] operator)
- Efficient insertion/deletion anywhere
- Bidirectional iterators only

#### Forward List (Singly Linked List)
```cpp
#include <forward_list>
forward_list<int> flst = {1, 2, 3};

flst.push_front(0);       // O(1)
flst.pop_front();         // O(1)
flst.insert_after(flst.begin(), 5); // O(1)
flst.erase_after(flst.begin());     // O(1)
```

#### Array
```cpp
#include <array>
array<int, 5> arr = {1, 2, 3, 4, 5};

arr[0] = 10;              // O(1)
arr.at(1) = 20;           // O(1)
arr.fill(0);              // O(n)
arr.size();               // O(1) - compile time constant
```

### 2.2 Associative Containers

#### Set/Multiset
```cpp
#include <set>
set<int> s = {3, 1, 4, 1, 5}; // {1, 3, 4, 5} - duplicates removed

s.insert(2);              // O(log n)
s.erase(3);               // O(log n)
s.find(4);                // O(log n) - returns iterator
s.count(1);               // O(log n) - returns 0 or 1 for set
s.lower_bound(3);         // O(log n) - first element >= 3
s.upper_bound(3);         // O(log n) - first element > 3
s.equal_range(3);         // O(log n) - pair of lower_bound and upper_bound

multiset<int> ms = {1, 2, 2, 3};
ms.count(2);              // returns 2
```

**Key Points:**
- Implemented as Red-Black Tree
- Elements always sorted
- Set: unique elements, Multiset: allows duplicates

#### Map/Multimap
```cpp
#include <map>
map<string, int> m;

m["apple"] = 5;           // O(log n)
m.insert({"banana", 3});  // O(log n)
m.insert(make_pair("cherry", 7)); // O(log n)
m.erase("apple");         // O(log n)
m.find("banana");         // O(log n)
m.count("cherry");        // O(log n)

// Iteration
for(auto& p : m) {
    cout << p.first << ": " << p.second << endl;
}

multimap<string, int> mm;
mm.insert({"fruit", 1});
mm.insert({"fruit", 2});  // allows duplicate keys
```

### 2.3 Unordered Associative Containers

#### Unordered Set/Multiset
```cpp
#include <unordered_set>
unordered_set<int> us = {1, 2, 3, 4};

us.insert(5);             // O(1) average, O(n) worst
us.erase(2);              // O(1) average, O(n) worst
us.find(3);               // O(1) average, O(n) worst
us.count(1);              // O(1) average, O(n) worst

// Hash function properties
us.bucket_count();        // number of buckets
us.load_factor();         // average elements per bucket
us.max_load_factor();     // maximum load factor
```

#### Unordered Map/Multimap
```cpp
#include <unordered_map>
unordered_map<string, int> um;

um["key1"] = 100;         // O(1) average
um.insert({"key2", 200}); // O(1) average
um.erase("key1");         // O(1) average
um.find("key2");          // O(1) average
```

### 2.4 Container Adaptors

#### Stack
```cpp
#include <stack>
stack<int> stk;

stk.push(10);             // O(1)
stk.push(20);             // O(1)
stk.top();                // O(1) - returns 20
stk.pop();                // O(1) - removes top element
stk.empty();              // O(1)
stk.size();               // O(1)
```

#### Queue
```cpp
#include <queue>
queue<int> q;

q.push(10);               // O(1)
q.push(20);               // O(1)
q.front();                // O(1) - returns 10
q.back();                 // O(1) - returns 20
q.pop();                  // O(1) - removes front element
q.empty();                // O(1)
q.size();                 // O(1)
```

#### Priority Queue
```cpp
#include <queue>
priority_queue<int> pq;                    // max heap by default

pq.push(30);              // O(log n)
pq.push(10);              // O(log n)
pq.push(20);              // O(log n)
pq.top();                 // O(1) - returns 30
pq.pop();                 // O(log n) - removes top element

// Min heap
priority_queue<int, vector<int>, greater<int>> min_pq;

// Custom comparator
auto cmp = [](int a, int b) { return a > b; }; // min heap
priority_queue<int, vector<int>, decltype(cmp)> custom_pq(cmp);
```

## 3. Iterators - Complete Guide

### Iterator Categories:
1. **Input Iterator**: Read-only, forward movement
2. **Output Iterator**: Write-only, forward movement
3. **Forward Iterator**: Read/write, forward movement
4. **Bidirectional Iterator**: Read/write, forward/backward movement
5. **Random Access Iterator**: Read/write, jump to arbitrary position

### Iterator Operations:
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Basic operations
auto it = v.begin();      // points to first element
auto end_it = v.end();    // points past last element
auto rit = v.rbegin();    // reverse iterator to last element
auto rend_it = v.rend();  // reverse iterator past first element

// Operations
*it;                      // dereference
++it;                     // pre-increment
it++;                     // post-increment
--it;                     // pre-decrement (bidirectional+)
it--;                     // post-decrement (bidirectional+)
it + n;                   // advance by n (random access only)
it - n;                   // move back by n (random access only)
it1 - it2;                // distance between iterators (random access)

// Iterator functions
advance(it, n);           // advance iterator by n positions
distance(it1, it2);       // distance between iterators
next(it, n);              // return iterator advanced by n
prev(it, n);              // return iterator moved back by n
```

### Iterator Invalidation Rules:
- **Vector**: Invalidated on reallocation (push_back when capacity exceeded, insert, erase)
- **Deque**: Invalidated on insert/erase except at ends
- **List**: Only invalidated for erased elements
- **Set/Map**: Only invalidated for erased elements
- **Unordered containers**: May be invalidated on rehashing

## 4. Algorithms - Complete Reference

### 4.1 Non-modifying Algorithms

#### Searching
```cpp
#include <algorithm>
vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1};

// Linear search
find(v.begin(), v.end(), 3);              // returns iterator to first 3
find_if(v.begin(), v.end(), [](int x) { return x > 3; }); // first element > 3
find_if_not(v.begin(), v.end(), [](int x) { return x < 3; }); // first element not < 3

// Binary search (requires sorted range)
vector<int> sorted_v = {1, 2, 3, 4, 5};
binary_search(sorted_v.begin(), sorted_v.end(), 3); // returns bool
lower_bound(sorted_v.begin(), sorted_v.end(), 3);   // iterator to first >= 3
upper_bound(sorted_v.begin(), sorted_v.end(), 3);   // iterator to first > 3
equal_range(sorted_v.begin(), sorted_v.end(), 3);   // pair of lower_bound, upper_bound

// Count
count(v.begin(), v.end(), 3);             // count occurrences of 3
count_if(v.begin(), v.end(), [](int x) { return x > 3; }); // count elements > 3

// Search subsequence
vector<int> pattern = {2, 3};
search(v.begin(), v.end(), pattern.begin(), pattern.end());

// Adjacent elements
adjacent_find(v.begin(), v.end());        // find first adjacent equal elements
```

#### Comparison
```cpp
equal(v1.begin(), v1.end(), v2.begin()); // check if ranges are equal
mismatch(v1.begin(), v1.end(), v2.begin()); // find first difference
lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()); // lexicographic comparison
```

### 4.2 Modifying Algorithms

#### Copying
```cpp
vector<int> source = {1, 2, 3, 4, 5};
vector<int> dest(5);

copy(source.begin(), source.end(), dest.begin());
copy_if(source.begin(), source.end(), dest.begin(), [](int x) { return x > 2; });
copy_n(source.begin(), 3, dest.begin());  // copy first 3 elements
copy_backward(source.begin(), source.end(), dest.end()); // copy in reverse order
```

#### Transforming
```cpp
transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; }); // square each element
transform(v1.begin(), v1.end(), v2.begin(), result.begin(), plus<int>()); // add corresponding elements
```

#### Filling
```cpp
fill(v.begin(), v.end(), 42);             // fill with value 42
fill_n(v.begin(), 3, 0);                  // fill first 3 elements with 0
generate(v.begin(), v.end(), rand);       // fill with generated values
generate_n(v.begin(), 3, rand);           // fill first 3 elements with generated values
```

#### Replacing
```cpp
replace(v.begin(), v.end(), 3, 99);       // replace all 3s with 99
replace_if(v.begin(), v.end(), [](int x) { return x > 5; }, 0); // replace elements > 5 with 0
replace_copy(v.begin(), v.end(), dest.begin(), 3, 99); // copy with replacement
```

#### Removing
```cpp
remove(v.begin(), v.end(), 3);            // move elements != 3 to front, return new end
remove_if(v.begin(), v.end(), [](int x) { return x > 5; }); // remove elements > 5
remove_copy(v.begin(), v.end(), dest.begin(), 3); // copy without element 3

// Note: remove doesn't actually delete elements, use erase-remove idiom:
v.erase(remove(v.begin(), v.end(), 3), v.end());

unique(v.begin(), v.end());               // remove consecutive duplicates
```

#### Reversing and Rotating
```cpp
reverse(v.begin(), v.end());              // reverse elements
rotate(v.begin(), v.begin() + 2, v.end()); // rotate left by 2 positions
```

### 4.3 Sorting Algorithms

```cpp
vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

// Sorting
sort(v.begin(), v.end());                 // O(n log n) - ascending
sort(v.begin(), v.end(), greater<int>()); // descending
sort(v.begin(), v.end(), [](int a, int b) { return a > b; }); // custom comparator

// Partial sorting
partial_sort(v.begin(), v.begin() + 3, v.end()); // sort first 3 elements
nth_element(v.begin(), v.begin() + 3, v.end());  // 3rd element in correct position

// Stable sorting
stable_sort(v.begin(), v.end());          // maintains relative order of equal elements

// Heap operations
make_heap(v.begin(), v.end());            // make max heap
push_heap(v.begin(), v.end());            // after adding element at end
pop_heap(v.begin(), v.end());             // move max to end
sort_heap(v.begin(), v.end());            // sort heap (destroys heap property)
```

### 4.4 Set Operations (on sorted ranges)

```cpp
vector<int> v1 = {1, 2, 3, 4};
vector<int> v2 = {3, 4, 5, 6};
vector<int> result(8);

set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

includes(v1.begin(), v1.end(), v2.begin(), v2.end()); // check if v1 includes all of v2
```

### 4.5 Permutation Algorithms

```cpp
vector<int> v = {1, 2, 3};

next_permutation(v.begin(), v.end());     // generate next permutation
prev_permutation(v.begin(), v.end());     // generate previous permutation

// Generate all permutations
do {
    // process permutation
} while(next_permutation(v.begin(), v.end()));
```

### 4.6 Numeric Algorithms

```cpp
#include <numeric>
vector<int> v = {1, 2, 3, 4, 5};

accumulate(v.begin(), v.end(), 0);        // sum with initial value 0
accumulate(v.begin(), v.end(), 1, multiplies<int>()); // product

inner_product(v1.begin(), v1.end(), v2.begin(), 0); // dot product

partial_sum(v.begin(), v.end(), result.begin()); // cumulative sum
adjacent_difference(v.begin(), v.end(), result.begin()); // differences between adjacent elements

iota(v.begin(), v.end(), 1);              // fill with consecutive values starting from 1
```

## 5. Function Objects and Lambda Expressions

### Built-in Function Objects
```cpp
#include <functional>

// Arithmetic
plus<int>(), minus<int>(), multiplies<int>(), divides<int>(), modulus<int>()
negate<int>()

// Comparison
equal_to<int>(), not_equal_to<int>(), greater<int>(), less<int>()
greater_equal<int>(), less_equal<int>()

// Logical
logical_and<bool>(), logical_or<bool>(), logical_not<bool>()

// Usage
transform(v.begin(), v.end(), v.begin(), negate<int>());
sort(v.begin(), v.end(), greater<int>());
```

### Lambda Expressions
```cpp
// Basic lambda
auto lambda = [](int x) { return x * 2; };

// Capture clauses
int factor = 3;
auto multiply = [factor](int x) { return x * factor; }; // capture by value
auto increment = [&factor](int x) { factor++; return x + factor; }; // capture by reference
auto mixed = [=, &factor](int x) { return x * factor; }; // capture all by value except factor

// Generic lambda (C++14)
auto generic = [](auto x, auto y) { return x + y; };

// Usage with algorithms
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
count_if(v.begin(), v.end(), [](int x) { return x > 5; });
```

## 6. Time Complexities - Complete Reference

### Container Operations

| Container | Access | Insert | Delete | Search |
|-----------|--------|--------|--------|--------|
| vector | O(1) | O(1) amortized end, O(n) middle | O(n) | O(n) |
| deque | O(1) | O(1) ends, O(n) middle | O(1) ends, O(n) middle | O(n) |
| list | O(n) | O(1) | O(1) | O(n) |
| set/map | O(log n) | O(log n) | O(log n) | O(log n) |
| unordered_set/map | O(1) avg, O(n) worst | O(1) avg, O(n) worst | O(1) avg, O(n) worst | O(1) avg, O(n) worst |

### Algorithm Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| sort | O(n log n) | O(log n) |
| stable_sort | O(n log n) | O(n) |
| binary_search | O(log n) | O(1) |
| find | O(n) | O(1) |
| reverse | O(n) | O(1) |
| rotate | O(n) | O(1) |
| unique | O(n) | O(1) |
| merge | O(n + m) | O(1) |
| set_union | O(n + m) | O(1) |
| next_permutation | O(n) | O(1) |

## 7. Common Interview Questions & Answers

### Q1: When to use vector vs list vs deque?
**Answer:**
- **Vector**: When you need random access, cache-friendly performance, and mostly append operations
- **List**: When you need frequent insertions/deletions in the middle and don't need random access
- **Deque**: When you need efficient insertions/deletions at both ends with random access

### Q2: Map vs Unordered_map?
**Answer:**
- **Map**: Use when you need sorted order, guaranteed O(log n) operations, or when hash function is expensive
- **Unordered_map**: Use when you don't need sorting and want O(1) average case performance

### Q3: What happens when vector capacity is exceeded?
**Answer:**
Vector allocates new memory (typically double the current capacity), copies all elements to new location, and deallocates old memory. This makes all iterators and references invalid.

### Q4: How to avoid iterator invalidation?
**Answer:**
- Use indices instead of iterators when possible
- Store end() iterator separately and update after modifications
- Use container methods that return valid iterators (like erase() returning next valid iterator)

### Q5: Difference between remove() and erase()?
**Answer:**
- **remove()**: Algorithm that moves elements, doesn't change container size
- **erase()**: Container method that actually removes elements and reduces size
- Use erase-remove idiom: `v.erase(remove(v.begin(), v.end(), val), v.end());`

### Q6: Custom comparator examples?
```cpp
// For sorting pairs by second element
sort(pairs.begin(), pairs.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
});

// For priority queue (min heap of pairs by first element)
auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first; // Note: reversed for min heap
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

### Q7: How to iterate and modify container simultaneously?
```cpp
// Correct way with vector
for(auto it = v.begin(); it != v.end(); ) {
    if(*it % 2 == 0) {
        it = v.erase(it); // erase returns next valid iterator
    } else {
        ++it;
    }
}

// Reverse iteration for vector
for(auto it = v.rbegin(); it != v.rend(); ++it) {
    // safe to erase using base()
}
```

## 8. Advanced Topics

### Custom Hash Function
```cpp
struct MyHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_set<pair<int,int>, MyHash> my_set;
```

### Memory Management
```cpp
// Vector capacity management
vector<int> v;
v.reserve(1000);      // pre-allocate capacity
v.shrink_to_fit();    // reduce capacity to size

// Clear vs reset
v.clear();            // size becomes 0, capacity unchanged
v = vector<int>();    // both size and capacity become 0
```

### Thread Safety
STL containers are not thread-safe for modifications. Multiple threads can safely read, but any modification requires external synchronization.

## 9. Best Practices for TCS Digital Interview

1. **Know time complexities** of all operations
2. **Understand when iterators are invalidated**
3. **Practice erase-remove idiom**
4. **Know difference between find() and count() for different containers**
5. **Understand move semantics** with containers (C++11+)
6. **Be familiar with range-based for loops** and their limitations
7. **Know how to use custom comparators** with associative containers
8. **Understand the trade-offs** between different containers
9. **Practice common algorithmic patterns** using STL
10. **Be able to write efficient code** using appropriate STL components

## 10. Sample Problems

### Problem 1: Find kth largest element
```cpp
int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums[k-1];
}
```

### Problem 2: Group anagrams
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for(string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto& p : groups) {
        result.push_back(move(p.second));
    }
    return result;
}
```

### Problem 3: Sliding window maximum
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;
    
    for(int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}
```