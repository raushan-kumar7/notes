# TCS Digital DSA Questions & Patterns - Complete C++ Guide

## Overview
The TCS Digital exam typically includes 2-3 coding questions to be solved within 60 to 90 minutes, covering dynamic programming, string manipulation, sorting and searching algorithms, graph theory, and data structures like arrays, trees, and linked lists.

## 🔥 Most Important DSA Patterns

### 1. Array Manipulation & Two Pointers
**Frequency: Very High**

#### Common Questions:
- **Two Sum Problem**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if(mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
```

- **Maximum Subarray Sum (Kadane's Algorithm)**
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
```

- **Remove Duplicates from Sorted Array**
```cpp
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int i = 0;
    for(int j = 1; j < nums.size(); j++) {
        if(nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
```

### 2. String Manipulation
**Frequency: Very High**

#### Common Questions:
- **Palindrome Check**
```cpp
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        if(!isalnum(s[left])) left++;
        else if(!isalnum(s[right])) right--;
        else if(tolower(s[left]) != tolower(s[right])) return false;
        else {
            left++;
            right--;
        }
    }
    return true;
}
```

- **Longest Common Subsequence**
```cpp
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```

- **Anagram Check**
```cpp
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    for(char c : t) {
        count[c]--;
        if(count[c] < 0) return false;
    }
    return true;
}
```

### 3. Binary Search & Sorting
**Frequency: High**

#### Common Questions:
- **Binary Search Implementation**
```cpp
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

- **Find Peak Element**
```cpp
int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

### 4. Linked Lists
**Frequency: High**

#### Common Questions:
- **Reverse Linked List**
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while(current != nullptr) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
```

- **Detect Cycle in Linked List**
```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
```

### 5. Trees & Binary Trees
**Frequency: Medium-High**

#### Common Questions:
- **Binary Tree Traversals**
```cpp
// Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if(!root) return result;
    
    stack<TreeNode*> st;
    TreeNode* current = root;
    
    while(current || !st.empty()) {
        while(current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}
```

- **Maximum Depth of Binary Tree**
```cpp
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

### 6. Dynamic Programming
**Frequency: Medium**

#### Common Questions:
- **Fibonacci Sequence**
```cpp
int fibonacci(int n) {
    if(n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
```

- **Climbing Stairs**
```cpp
int climbStairs(int n) {
    if(n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for(int i = 3; i <= n; i++) {
        int current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
```

### 7. Hashing & HashMaps
**Frequency: High**

#### Common Questions:
- **First Non-Repeating Character**
```cpp
int firstUniqChar(string s) {
    unordered_map<char, int> count;
    for(char c : s) count[c]++;
    for(int i = 0; i < s.length(); i++) {
        if(count[s[i]] == 1) return i;
    }
    return -1;
}
```

### 8. Stack & Queue Problems
**Frequency: Medium**

#### Common Questions:
- **Valid Parentheses**
```cpp
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((c == ')' && top != '(') ||
               (c == ']' && top != '[') ||
               (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}
```

## 🎯 TCS Digital Specific Pattern Questions

### 1. Matrix Problems
```cpp
// Spiral Matrix Traversal
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if(matrix.empty()) return result;
    
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    
    while(top <= bottom && left <= right) {
        // Traverse right
        for(int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        
        // Traverse down
        for(int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Traverse left
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Traverse up
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
}
```

### 2. Number Theory Problems
```cpp
// GCD and LCM
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// Prime Number Check
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
```

## 📝 Interview Tips & Best Practices

### Code Quality Standards:
1. **Time Complexity**: Always mention time and space complexity
2. **Edge Cases**: Handle null inputs, empty arrays, single elements
3. **Variable Naming**: Use meaningful variable names
4. **Comments**: Add brief comments for complex logic

### Common C++ STL to Master:
```cpp
// Essential STL containers and functions
vector<int> v;
unordered_map<int, int> mp;
unordered_set<int> st;
stack<int> stk;
queue<int> q;
priority_queue<int> pq;

// Important algorithms
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
binary_search(v.begin(), v.end(), target);
lower_bound(v.begin(), v.end(), target);
upper_bound(v.begin(), v.end(), target);
```

### Template for Problem Solving:
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    // Function implementation here
    int solve(vector<int>& nums) {
        // 1. Handle edge cases
        if(nums.empty()) return 0;
        
        // 2. Initialize variables
        
        // 3. Main logic
        
        // 4. Return result
    }
};

int main() {
    // Test cases
    return 0;
}
```

## 🚀 Practice Strategy

### Week 1-2: Foundation
- Arrays and Strings (Two Pointers, Sliding Window)
- Basic Sorting and Searching
- Hash Maps and Sets

### Week 3-4: Intermediate
- Linked Lists (Manipulation, Cycle Detection)
- Stacks and Queues
- Binary Trees (Traversals, Basic Operations)

### Week 5-6: Advanced
- Dynamic Programming (Basic patterns)
- Graph Algorithms (BFS, DFS)
- Advanced Tree Problems

### Mock Interview Preparation:
1. Practice coding on whiteboard/paper
2. Explain your approach before coding
3. Test with multiple examples
4. Optimize your solution

## 🎓 Additional Resources

- **Practice Platforms**: LeetCode, GeeksforGeeks, HackerRank
- **Focus Areas**: Easy to Medium level problems
- **Time Management**: 15-20 minutes per coding question
- **Communication**: Practice explaining your thought process clearly

Remember: TCS Digital interviews focus more on problem-solving approach and code quality rather than just getting the correct answer. Always explain your thinking process!