Here are the most commonly asked C++ Stack interview questions and answers for TCS Digital roles:

## **Basic Stack Concepts**

**Q1: What is a Stack? What are its characteristics?**
**Answer:** A Stack is a linear data structure that follows LIFO (Last In First Out) principle. Key characteristics:
- Elements are added and removed from the same end (top)
- Only top element is accessible
- Main operations: push(), pop(), top(), empty()
- Used for function calls, expression evaluation, undo operations
- Can be implemented using arrays or linked lists

**Q2: How do you implement a stack using arrays?**
**Answer:**
```cpp
class ArrayStack {
private:
    int* arr;
    int topIndex;
    int capacity;
    
public:
    ArrayStack(int size) {
        arr = new int[size];
        capacity = size;
        topIndex = -1;
    }
    
    void push(int x) {
        if(topIndex >= capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex < 0) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[topIndex--];
    }
    
    int top() {
        if(topIndex < 0) return -1;
        return arr[topIndex];
    }
    
    bool empty() {
        return topIndex < 0;
    }
    
    int size() {
        return topIndex + 1;
    }
};
```

**Q3: How do you implement a stack using linked list?**
**Answer:**
```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListStack {
private:
    Node* topNode;
    int count;
    
public:
    LinkedListStack() : topNode(nullptr), count(0) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }
    
    int pop() {
        if(topNode == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return value;
    }
    
    int top() {
        if(topNode == nullptr) return -1;
        return topNode->data;
    }
    
    bool empty() {
        return topNode == nullptr;
    }
    
    int size() {
        return count;
    }
};
```

## **Expression Evaluation Problems**

**Q4: Check for balanced parentheses**
**Answer:**
```cpp
bool isBalanced(string expr) {
    stack<char> s;
    
    for(char c : expr) {
        if(c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(s.empty()) return false;
            
            char top = s.top();
            s.pop();
            
            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}
```

**Q5: Evaluate postfix expression**
**Answer:**
```cpp
int evaluatePostfix(string expr) {
    stack<int> s;
    
    for(char c : expr) {
        if(isdigit(c)) {
            s.push(c - '0');
        }
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch(c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }
    return s.top();
}
```

**Q6: Convert infix to postfix**
**Answer:**
```cpp
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop(); // Remove '('
        }
        else { // Operator
            while(!s.empty() && s.top() != '(' && 
                  precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}
```

## **Stack-based Algorithms**

**Q7: Next Greater Element**
**Answer:**
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s; // Store indices
    
    for(int i = 0; i < n; i++) {
        while(!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    
    return result;
}

// For circular array
vector<int> nextGreaterElementCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> s;
    
    for(int i = 0; i < 2 * n; i++) {
        while(!s.empty() && nums[s.top()] < nums[i % n]) {
            result[s.top()] = nums[i % n];
            s.pop();
        }
        if(i < n) s.push(i);
    }
    
    return result;
}
```

**Q8: Largest Rectangle in Histogram**
**Answer:**
```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    
    for(int i = 0; i <= n; i++) {
        int currentHeight = (i == n) ? 0 : heights[i];
        
        while(!s.empty() && heights[s.top()] > currentHeight) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    
    return maxArea;
}
```

**Q9: Valid Parentheses with minimum additions**
**Answer:**
```cpp
int minAddToMakeValid(string s) {
    stack<char> st;
    int unmatched = 0;
    
    for(char c : s) {
        if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            if(!st.empty()) {
                st.pop();
            } else {
                unmatched++; // Unmatched closing bracket
            }
        }
    }
    
    return st.size() + unmatched; // Unmatched opening + closing
}
```

## **Advanced Stack Problems**

**Q10: Implement Min Stack (stack with getMin in O(1))**
**Answer:**
```cpp
class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    
public:
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if(mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

// Space optimized version
class MinStackOptimized {
private:
    stack<long> s;
    long minVal;
    
public:
    void push(int val) {
        if(s.empty()) {
            s.push(0);
            minVal = val;
        } else {
            s.push((long)val - minVal);
            if(val < minVal) minVal = val;
        }
    }
    
    void pop() {
        if(s.top() < 0) {
            minVal = minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top() < 0) return minVal;
        return minVal + s.top();
    }
    
    int getMin() {
        return minVal;
    }
};
```

**Q11: Sort a stack using another stack**
**Answer:**
```cpp
void sortStack(stack<int>& input) {
    stack<int> temp;
    
    while(!input.empty()) {
        int current = input.top();
        input.pop();
        
        while(!temp.empty() && temp.top() > current) {
            input.push(temp.top());
            temp.pop();
        }
        temp.push(current);
    }
    
    while(!temp.empty()) {
        input.push(temp.top());
        temp.pop();
    }
}
```

**Q12: Implement Stack using Queues**
**Answer:**
```cpp
class StackUsingQueues {
private:
    queue<int> q1, q2;
    
public:
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int result = q1.front();
        q1.pop();
        
        swap(q1, q2);
        return result;
    }
    
    int top() {
        if(q1.empty()) return -1;
        
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int result = q1.front();
        q2.push(result);
        q1.pop();
        
        swap(q1, q2);
        return result;
    }
    
    bool empty() {
        return q1.empty();
    }
};
```

## **Stack with STL**

**Q13: Basic STL stack operations**
**Answer:**
```cpp
#include <stack>

void demonstrateSTLStack() {
    stack<int> s;
    
    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    
    // Access top element
    cout << "Top: " << s.top() << endl;
    
    // Check size and empty
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;
    
    // Pop elements
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

**Q14: Reverse a string using stack**
**Answer:**
```cpp
string reverseString(string str) {
    stack<char> s;
    
    // Push all characters
    for(char c : str) {
        s.push(c);
    }
    
    // Pop and build reversed string
    string reversed = "";
    while(!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    
    return reversed;
}
```

## **Applications and Use Cases**

**Q15: Function call stack - how does recursion work?**
**Answer:**
```cpp
// Example: Factorial using recursion
int factorial(int n) {
    // Base case
    if(n <= 1) return 1;
    
    // Recursive call - creates new stack frame
    return n * factorial(n - 1);
}

// Stack frames created:
// factorial(5) -> 5 * factorial(4)
// factorial(4) -> 4 * factorial(3)  
// factorial(3) -> 3 * factorial(2)
// factorial(2) -> 2 * factorial(1)
// factorial(1) -> returns 1
// Then stack unwinds: 2*1, 3*2, 4*6, 5*24 = 120
```

**Q16: Undo functionality implementation**
**Answer:**
```cpp
class UndoSystem {
private:
    stack<string> undoStack;
    stack<string> redoStack;
    string currentState;
    
public:
    UndoSystem(string initial) : currentState(initial) {}
    
    void executeAction(string newState) {
        undoStack.push(currentState);
        currentState = newState;
        
        // Clear redo stack when new action is performed
        while(!redoStack.empty()) redoStack.pop();
    }
    
    void undo() {
        if(undoStack.empty()) return;
        
        redoStack.push(currentState);
        currentState = undoStack.top();
        undoStack.pop();
    }
    
    void redo() {
        if(redoStack.empty()) return;
        
        undoStack.push(currentState);
        currentState = redoStack.top();
        redoStack.pop();
    }
    
    string getCurrentState() {
        return currentState;
    }
};
```

## **Time and Space Complexity Questions**

**Q17: What are the time complexities of stack operations?**
**Answer:**
- Push: O(1)
- Pop: O(1)  
- Top/Peek: O(1)
- Empty: O(1)
- Size: O(1)
- Space Complexity: O(n) where n is number of elements

**Q18: Stack vs Array vs Linked List comparison**
**Answer:**
```
Operation    | Stack | Array | Linked List
-------------|-------|-------|------------
Access       | O(1)* | O(1)  | O(n)
Search       | O(n)  | O(n)  | O(n)
Insertion    | O(1)  | O(n)  | O(1)
Deletion     | O(1)  | O(n)  | O(1)
*Only top element accessible in stack
```

## **Common Interview Traps**

**Q19: What happens when you pop from empty stack?**
**Answer:** 
- STL stack: Undefined behavior (program may crash)
- Custom implementation: Should handle gracefully with error checking
- Always check `empty()` before calling `pop()` or `top()`

**Q20: Stack overflow vs Stack underflow**
**Answer:**
- **Stack Overflow:** Occurs when trying to push onto a full stack (array implementation)
- **Stack Underflow:** Occurs when trying to pop from an empty stack
- **Stack Overflow (recursion):** When recursive calls exceed available memory

These questions cover fundamental to advanced stack concepts commonly asked in TCS Digital interviews. Practice implementing these solutions and understand their applications in real-world scenarios for comprehensive preparation.