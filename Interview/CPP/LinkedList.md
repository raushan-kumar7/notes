Here are the most commonly asked C++ Linked List interview questions and answers for TCS Digital roles:

## **Basic Linked List Concepts**

**Q1: What is a Linked List? What are its characteristics?**
**Answer:** A Linked List is a linear data structure where elements are stored in nodes, and each node contains data and a pointer to the next node. Key characteristics:
- Dynamic size allocation
- Non-contiguous memory storage
- Sequential access (no random access)
- Efficient insertion/deletion at any position
- Extra memory overhead for storing pointers
- Types: Singly, Doubly, Circular Linked Lists

**Q2: Define and implement a basic Singly Linked List**
**Answer:**
```cpp
struct ListNode {
    int data;
    ListNode* next;
    
    ListNode(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
    int size;
    
public:
    LinkedList() : head(nullptr), size(0) {}
    
    void insertAtBeginning(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void insertAtEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    void insertAtPosition(int pos, int val) {
        if(pos < 0 || pos > size) return;
        
        if(pos == 0) {
            insertAtBeginning(val);
            return;
        }
        
        ListNode* newNode = new ListNode(val);
        ListNode* temp = head;
        for(int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteNode(int val) {
        if(!head) return;
        
        if(head->data == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        
        ListNode* current = head;
        while(current->next && current->next->data != val) {
            current = current->next;
        }
        
        if(current->next) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        }
    }
    
    void display() {
        ListNode* temp = head;
        while(temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    int getSize() { return size; }
};
```

## **Traversal and Search Operations**

**Q3: Search for an element in linked list**
**Answer:**
```cpp
bool search(ListNode* head, int target) {
    ListNode* current = head;
    while(current) {
        if(current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Recursive search
bool searchRecursive(ListNode* head, int target) {
    if(!head) return false;
    if(head->data == target) return true;
    return searchRecursive(head->next, target);
}

// Find position of element
int findPosition(ListNode* head, int target) {
    ListNode* current = head;
    int position = 0;
    
    while(current) {
        if(current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Not found
}
```

**Q4: Find length of linked list**
**Answer:**
```cpp
int getLength(ListNode* head) {
    int count = 0;
    ListNode* current = head;
    while(current) {
        count++;
        current = current->next;
    }
    return count;
}

// Recursive approach
int getLengthRecursive(ListNode* head) {
    if(!head) return 0;
    return 1 + getLengthRecursive(head->next);
}
```

## **Reversal Problems**

**Q5: Reverse a linked list (iterative and recursive)**
**Answer:**
```cpp
// Iterative approach
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Recursive approach
ListNode* reverseRecursive(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    
    ListNode* reversedHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return reversedHead;
}
```

**Q6: Reverse linked list in groups of K**
**Answer:**
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    // Check if we have k nodes
    ListNode* current = head;
    int count = 0;
    while(current && count < k) {
        current = current->next;
        count++;
    }
    
    if(count == k) {
        current = reverseKGroup(current, k);
        
        while(count-- > 0) {
            ListNode* next = head->next;
            head->next = current;
            current = head;
            head = next;
        }
        head = current;
    }
    
    return head;
}
```

## **Two Pointer Technique**

**Q7: Find middle of linked list**
**Answer:**
```cpp
ListNode* findMiddle(ListNode* head) {
    if(!head) return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Get both middle nodes for even length
pair<ListNode*, ListNode*> findMiddleNodes(ListNode* head) {
    if(!head) return {nullptr, nullptr};
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return {prev, slow};
}
```

**Q8: Detect cycle in linked list**
**Answer:**
```cpp
bool hasCycle(ListNode* head) {
    if(!head || !head->next) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            return true;
        }
    }
    
    return false;
}

// Find start of cycle
ListNode* detectCycle(ListNode* head) {
    if(!head || !head->next) return nullptr;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Detect cycle
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    if(!fast || !fast->next) return nullptr;
    
    // Find start of cycle
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
```

**Q9: Find Nth node from end**
**Answer:**
```cpp
ListNode* findNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    
    // Move fast pointer n steps ahead
    for(int i = 0; i < n; i++) {
        if(!fast) return nullptr;
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches end
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
```

## **Merge and Sort Operations**

**Q10: Merge two sorted linked lists**
**Answer:**
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    while(l1 && l2) {
        if(l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    current->next = l1 ? l1 : l2;
    return dummy.next;
}

// Recursive approach
ListNode* mergeTwoListsRecursive(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;
    
    if(l1->data <= l2->data) {
        l1->next = mergeTwoListsRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoListsRecursive(l1, l2->next);
        return l2;
    }
}
```

**Q11: Merge Sort on Linked List**
**Answer:**
```cpp
ListNode* mergeSort(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    
    // Find middle
    ListNode* middle = getMiddle(head);
    ListNode* nextOfMiddle = middle->next;
    middle->next = nullptr;
    
    // Recursively sort both halves
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(nextOfMiddle);
    
    // Merge sorted halves
    return mergeTwoLists(left, right);
}

ListNode* getMiddle(ListNode* head) {
    if(!head) return head;
    
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return prev;
}
```

## **Remove/Delete Operations**

**Q12: Remove duplicates from sorted linked list**
**Answer:**
```cpp
ListNode* removeDuplicates(ListNode* head) {
    if(!head) return head;
    
    ListNode* current = head;
    
    while(current->next) {
        if(current->data == current->next->data) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    
    return head;
}
```

**Q13: Remove all duplicates from sorted linked list**
**Answer:**
```cpp
ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* current = head;
    
    while(current) {
        if(current->next && current->data == current->next->data) {
            int duplicateValue = current->data;
            
            while(current && current->data == duplicateValue) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }
            
            prev->next = current;
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return dummy.next;
}
```

**Q14: Delete node with only pointer to node**
**Answer:**
```cpp
void deleteNode(ListNode* node) {
    if(!node || !node->next) return;
    
    // Copy data from next node
    node->data = node->next->data;
    
    // Delete next node
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}
```

## **Advanced Problems**

**Q15: Check if linked list is palindrome**
**Answer:**
```cpp
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    
    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    ListNode* secondHalf = reverseList(slow->next);
    ListNode* firstHalf = head;
    
    // Compare both halves
    while(secondHalf) {
        if(firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    return true;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    
    while(current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}
```

**Q16: Add two numbers represented by linked lists**
**Answer:**
```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    int carry = 0;
    
    while(l1 || l2 || carry) {
        int sum = carry;
        
        if(l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        
        if(l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    
    return dummy.next;
}
```

**Q17: Flatten a multilevel linked list**
**Answer:**
```cpp
struct Node {
    int data;
    Node* next;
    Node* child;
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

Node* flatten(Node* head) {
    if(!head) return head;
    
    Node* current = head;
    
    while(current) {
        if(current->child) {
            Node* next = current->next;
            current->next = current->child;
            current->child = nullptr;
            
            // Find tail of child list
            Node* temp = current->next;
            while(temp->next) {
                temp = temp->next;
            }
            
            temp->next = next;
        }
        current = current->next;
    }
    
    return head;
}
```

## **Doubly Linked List**

**Q18: Implement Doubly Linked List**
**Answer:**
```cpp
struct DoublyListNode {
    int data;
    DoublyListNode* next;
    DoublyListNode* prev;
    
    DoublyListNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;
    int size;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    void insertAtBeginning(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        
        if(!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void insertAtEnd(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        
        if(!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }
    
    void deleteNode(DoublyListNode* node) {
        if(!node) return;
        
        if(node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        
        if(node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        
        delete node;
        size--;
    }
    
    void displayForward() {
        DoublyListNode* current = head;
        while(current) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    
    void displayBackward() {
        DoublyListNode* current = tail;
        while(current) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};
```

## **Circular Linked List**

**Q19: Implement Circular Linked List**
**Answer:**
```cpp
class CircularLinkedList {
private:
    ListNode* tail; // Points to last node
    int size;
    
public:
    CircularLinkedList() : tail(nullptr), size(0) {}
    
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        
        if(!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void deleteNode(int val) {
        if(!tail) return;
        
        ListNode* current = tail->next; // Start from head
        ListNode* prev = tail;
        
        do {
            if(current->data == val) {
                if(current == tail && current->next == current) {
                    // Only one node
                    delete current;
                    tail = nullptr;
                } else {
                    prev->next = current->next;
                    if(current == tail) {
                        tail = prev;
                    }
                    delete current;
                }
                size--;
                return;
            }
            prev = current;
            current = current->next;
        } while(current != tail->next);
    }
    
    void display() {
        if(!tail) return;
        
        ListNode* current = tail->next;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while(current != tail->next);
        cout << "(back to start)" << endl;
    }
};
```

## **Time and Space Complexity**

**Q20: Complexity Analysis of Linked List Operations**
**Answer:**
```
Operation               | Singly LL | Doubly LL | Array
------------------------|-----------|-----------|-------
Access (by index)       | O(n)      | O(n)      | O(1)
Search                  | O(n)      | O(n)      | O(n)
Insertion (beginning)   | O(1)      | O(1)      | O(n)
Insertion (end)         | O(n)*     | O(1)**    | O(1)***
Insertion (middle)      | O(n)      | O(n)      | O(n)
Deletion (beginning)    | O(1)      | O(1)      | O(n)
Deletion (end)          | O(n)      | O(1)**    | O(1)
Deletion (middle)       | O(n)      | O(1)****  | O(n)

* O(1) if tail pointer is maintained
** If tail pointer is maintained
*** Amortized, may require resizing
**** If node reference is given

Space Complexity: O(n) for all linked list types
```

**Advantages of Linked Lists:**
- Dynamic size
- Efficient insertion/deletion
- Memory efficient (no pre-allocation needed)

**Disadvantages of Linked Lists:**
- No random access
- Extra memory for pointers
- Not cache-friendly
- Sequential access only

These questions cover fundamental to advanced linked list concepts commonly asked in TCS Digital interviews. Practice implementing these solutions and understand their time/space complexities for comprehensive preparation.