Here are the most commonly asked C++ Queue interview questions and answers for TCS Digital roles:

## **Basic Queue Concepts**

**Q1: What is a Queue? What are its characteristics?**
**Answer:** A Queue is a linear data structure that follows FIFO (First In First Out) principle. Key characteristics:
- Elements are added at rear and removed from front
- Two ends: front (for deletion) and rear (for insertion)
- Main operations: enqueue(), dequeue(), front(), rear(), empty()
- Used in scheduling, buffering, BFS traversal
- Can be implemented using arrays, linked lists, or circular arrays

**Q2: How do you implement a queue using arrays?**
**Answer:**
```cpp
class ArrayQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;
    
public:
    ArrayQueue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }
    
    void enqueue(int x) {
        if(count >= capacity) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }
    
    int dequeue() {
        if(count == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return value;
    }
    
    int front() {
        if(count == 0) return -1;
        return arr[frontIndex];
    }
    
    int rear() {
        if(count == 0) return -1;
        return arr[rearIndex];
    }
    
    bool empty() {
        return count == 0;
    }
    
    int size() {
        return count;
    }
};
```

**Q3: How do you implement a queue using linked list?**
**Answer:**
```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* frontNode;
    Node* rearNode;
    int count;
    
public:
    LinkedListQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {}
    
    void enqueue(int x) {
        Node* newNode = new Node(x);
        
        if(rearNode == nullptr) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }
    
    int dequeue() {
        if(frontNode == nullptr) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        
        int value = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        
        if(frontNode == nullptr) {
            rearNode = nullptr;
        }
        
        delete temp;
        count--;
        return value;
    }
    
    int front() {
        if(frontNode == nullptr) return -1;
        return frontNode->data;
    }
    
    int rear() {
        if(rearNode == nullptr) return -1;
        return rearNode->data;
    }
    
    bool empty() {
        return frontNode == nullptr;
    }
    
    int size() {
        return count;
    }
};
```

## **Circular Queue**

**Q4: Implement Circular Queue**
**Answer:**
```cpp
class CircularQueue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    
public:
    CircularQueue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = -1;
        rearIndex = -1;
    }
    
    bool enqueue(int x) {
        if(isFull()) {
            return false;
        }
        
        if(isEmpty()) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % capacity;
        }
        
        arr[rearIndex] = x;
        return true;
    }
    
    bool dequeue() {
        if(isEmpty()) {
            return false;
        }
        
        if(frontIndex == rearIndex) {
            frontIndex = rearIndex = -1;
        } else {
            frontIndex = (frontIndex + 1) % capacity;
        }
        
        return true;
    }
    
    int front() {
        if(isEmpty()) return -1;
        return arr[frontIndex];
    }
    
    int rear() {
        if(isEmpty()) return -1;
        return arr[rearIndex];
    }
    
    bool isEmpty() {
        return frontIndex == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (rearIndex + 1) % capacity == frontIndex;
    }
};
```

## **Queue using Stacks**

**Q5: Implement Queue using two stacks**
**Answer:**
```cpp
class QueueUsingStacks {
private:
    stack<int> input;
    stack<int> output;
    
public:
    void enqueue(int x) {
        input.push(x);
    }
    
    int dequeue() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        if(output.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        int result = output.top();
        output.pop();
        return result;
    }
    
    int front() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        if(output.empty()) return -1;
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

// Alternative: Using single stack (recursive)
class QueueUsingSingleStack {
private:
    stack<int> s;
    
public:
    void enqueue(int x) {
        s.push(x);
    }
    
    int dequeue() {
        if(s.empty()) return -1;
        
        int x = s.top();
        s.pop();
        
        if(s.empty()) {
            return x;
        }
        
        int result = dequeue();
        s.push(x);
        return result;
    }
};
```

## **Priority Queue**

**Q6: Implement Priority Queue using arrays**
**Answer:**
```cpp
class PriorityQueue {
private:
    vector<pair<int, int>> pq; // {priority, value}
    
public:
    void enqueue(int value, int priority) {
        pq.push_back({priority, value});
    }
    
    int dequeue() {
        if(pq.empty()) return -1;
        
        int maxPriorityIndex = 0;
        for(int i = 1; i < pq.size(); i++) {
            if(pq[i].first > pq[maxPriorityIndex].first) {
                maxPriorityIndex = i;
            }
        }
        
        int value = pq[maxPriorityIndex].second;
        pq.erase(pq.begin() + maxPriorityIndex);
        return value;
    }
    
    int front() {
        if(pq.empty()) return -1;
        
        int maxPriorityIndex = 0;
        for(int i = 1; i < pq.size(); i++) {
            if(pq[i].first > pq[maxPriorityIndex].first) {
                maxPriorityIndex = i;
            }
        }
        
        return pq[maxPriorityIndex].second;
    }
    
    bool empty() {
        return pq.empty();
    }
};
```

## **Deque (Double-ended Queue)**

**Q7: Implement Deque**
**Answer:**
```cpp
class Deque {
private:
    vector<int> arr;
    int frontIndex;
    int rearIndex;
    int capacity;
    int count;
    
public:
    Deque(int size) {
        arr.resize(size);
        capacity = size;
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }
    
    bool insertFront(int x) {
        if(count == capacity) return false;
        
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        arr[frontIndex] = x;
        count++;
        return true;
    }
    
    bool insertRear(int x) {
        if(count == capacity) return false;
        
        arr[rearIndex] = x;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(count == 0) return false;
        
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }
    
    bool deleteRear() {
        if(count == 0) return false;
        
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        count--;
        return true;
    }
    
    int getFront() {
        if(count == 0) return -1;
        return arr[frontIndex];
    }
    
    int getRear() {
        if(count == 0) return -1;
        return arr[(rearIndex - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};
```

## **Queue-based Algorithms**

**Q8: Generate Binary Numbers from 1 to N using Queue**
**Answer:**
```cpp
vector<string> generateBinaryNumbers(int n) {
    vector<string> result;
    queue<string> q;
    
    q.push("1");
    
    for(int i = 0; i < n; i++) {
        string current = q.front();
        q.pop();
        result.push_back(current);
        
        q.push(current + "0");
        q.push(current + "1");
    }
    
    return result;
}
```

**Q9: First non-repeating character in stream**
**Answer:**
```cpp
class FirstNonRepeating {
private:
    queue<char> q;
    int freq[26];
    
public:
    FirstNonRepeating() {
        memset(freq, 0, sizeof(freq));
    }
    
    char getFirstNonRepeating(char ch) {
        freq[ch - 'a']++;
        q.push(ch);
        
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        return q.empty() ? '#' : q.front();
    }
};
```

**Q10: Sliding Window Maximum using Deque**
**Answer:**
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // Store indices
    vector<int> result;
    
    for(int i = 0; i < nums.size(); i++) {
        // Remove elements outside current window
        while(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove smaller elements from rear
        while(!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Add to result if window is complete
        if(i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}
```

## **Level Order Traversal**

**Q11: Binary Tree Level Order Traversal**
**Answer:**
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    return result;
}
```

**Q12: Reverse Level Order Traversal**
**Answer:**
```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        int levelSize = q.size();
        vector<int> currentLevel;
        
        for(int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        result.push_back(currentLevel);
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

## **Advanced Queue Problems**

**Q13: Design Hit Counter**
**Answer:**
```cpp
class HitCounter {
private:
    queue<int> hits;
    
public:
    void hit(int timestamp) {
        hits.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!hits.empty() && hits.front() <= timestamp - 300) {
            hits.pop();
        }
        return hits.size();
    }
};
```

**Q14: Moving Average from Data Stream**
**Answer:**
```cpp
class MovingAverage {
private:
    queue<int> window;
    int windowSize;
    double sum;
    
public:
    MovingAverage(int size) : windowSize(size), sum(0.0) {}
    
    double next(int val) {
        window.push(val);
        sum += val;
        
        if(window.size() > windowSize) {
            sum -= window.front();
            window.pop();
        }
        
        return sum / window.size();
    }
};
```

**Q15: Design Circular Queue with fixed size**
**Answer:**
```cpp
class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(isEmpty()) {
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        
        if(head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return data[tail];
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        return !isEmpty() && (tail + 1) % size == head;
    }
};
```

## **STL Queue Operations**

**Q16: Basic STL Queue operations**
**Answer:**
```cpp
#include <queue>

void demonstrateSTLQueue() {
    queue<int> q;
    
    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    
    // Access front and back
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    
    // Check size and empty
    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;
    
    // Dequeue elements
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

// Priority Queue
void demonstratePriorityQueue() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(20);
    
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " "; // 30 20 10
        maxHeap.pop();
    }
}
```

## **Applications and Use Cases**

**Q17: CPU Scheduling using Queue**
**Answer:**
```cpp
struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    
    Process(int i, int bt, int at) : id(i), burstTime(bt), arrivalTime(at) {}
};

void roundRobinScheduling(vector<Process>& processes, int quantum) {
    queue<Process> readyQueue;
    int currentTime = 0;
    
    for(auto& process : processes) {
        readyQueue.push(process);
    }
    
    while(!readyQueue.empty()) {
        Process current = readyQueue.front();
        readyQueue.pop();
        
        int executeTime = min(quantum, current.burstTime);
        currentTime += executeTime;
        current.burstTime -= executeTime;
        
        cout << "Process " << current.id << " executed for " << executeTime << " units\n";
        
        if(current.burstTime > 0) {
            readyQueue.push(current);
        }
    }
}
```

**Q18: Breadth-First Search using Queue**
**Answer:**
```cpp
void BFS(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        for(int neighbor : graph[current]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

## **Time and Space Complexity**

**Q19: Time complexities of Queue operations**
**Answer:**
```
Operation     | Array Queue | Linked List Queue | Circular Queue
--------------|-------------|-------------------|---------------
Enqueue       | O(1)        | O(1)              | O(1)
Dequeue       | O(1)        | O(1)              | O(1)
Front         | O(1)        | O(1)              | O(1)
Rear          | O(1)        | O(1)              | O(1)
Empty         | O(1)        | O(1)              | O(1)
Size          | O(1)        | O(1)              | O(1)
Space         | O(n)        | O(n)              | O(n)
```

**Q20: Common Queue Interview Pitfalls**
**Answer:**
- **Empty Queue Access:** Always check `empty()` before `front()`, `back()`, or `pop()`
- **Circular Queue Full/Empty:** Distinguish between full and empty states
- **Memory Management:** In linked list implementation, properly delete nodes
- **Index Calculation:** In array implementation, handle wrap-around correctly
- **STL Queue:** Remember `pop()` doesn't return the element, use `front()` first

These questions cover fundamental to advanced queue concepts commonly asked in TCS Digital interviews. Practice implementing these solutions and understand their real-world applications for comprehensive preparation.