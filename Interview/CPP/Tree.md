# TCS Digital - Tree Interview Questions & Answers (C++)

## Tree Node Structure
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

## 1. Tree Traversals (Most Common Pattern)

### Question 1: Implement all three DFS traversals
**Answer:**
```cpp
// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorderTraversal(root->left, result);
    preorderTraversal(root->right, result);
}

// Postorder Traversal (Left -> Right -> Root)
void postorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->val);
}

// Level Order Traversal (BFS)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

## 2. Tree Properties & Validation

### Question 2: Check if a binary tree is a valid BST
**Answer:**
```cpp
bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

bool validate(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;
    
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }
    
    return validate(node->left, minVal, node->val) && 
           validate(node->right, node->val, maxVal);
}
```

### Question 3: Find height/depth of binary tree
**Answer:**
```cpp
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Check if tree is balanced
bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

int checkBalance(TreeNode* node) {
    if (!node) return 0;
    
    int left = checkBalance(node->left);
    if (left == -1) return -1;
    
    int right = checkBalance(node->right);
    if (right == -1) return -1;
    
    if (abs(left - right) > 1) return -1;
    
    return 1 + max(left, right);
}
```

## 3. Path Problems (Very Common in TCS)

### Question 4: Root to leaf path sum
**Answer:**
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

// Find all root-to-leaf paths with given sum
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    findPaths(root, targetSum, path, result);
    return result;
}

void findPaths(TreeNode* node, int sum, vector<int>& path, 
               vector<vector<int>>& result) {
    if (!node) return;
    
    path.push_back(node->val);
    
    if (!node->left && !node->right && sum == node->val) {
        result.push_back(path);
    } else {
        findPaths(node->left, sum - node->val, path, result);
        findPaths(node->right, sum - node->val, path, result);
    }
    
    path.pop_back(); // backtrack
}
```

### Question 5: Maximum path sum in binary tree
**Answer:**
```cpp
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}

int maxPathSumHelper(TreeNode* node, int& maxSum) {
    if (!node) return 0;
    
    int left = max(0, maxPathSumHelper(node->left, maxSum));
    int right = max(0, maxPathSumHelper(node->right, maxSum));
    
    maxSum = max(maxSum, node->val + left + right);
    
    return node->val + max(left, right);
}
```

## 4. Tree Construction Problems

### Question 6: Construct binary tree from inorder and preorder
**Answer:**
```cpp
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    
    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorderMap, preorderIndex, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorderMap,
                         int& preorderIndex, int left, int right) {
    if (left > right) return nullptr;
    
    int rootVal = preorder[preorderIndex++];
    TreeNode* root = new TreeNode(rootVal);
    
    int inorderIndex = inorderMap[rootVal];
    
    root->left = buildTreeHelper(preorder, inorderMap, preorderIndex, left, inorderIndex - 1);
    root->right = buildTreeHelper(preorder, inorderMap, preorderIndex, inorderIndex + 1, right);
    
    return root;
}
```

## 5. Binary Search Tree Operations

### Question 7: Insert and Delete in BST
**Answer:**
```cpp
// Insert in BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// Delete from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Node has two children
        TreeNode* minRight = findMin(root->right);
        root->val = minRight->val;
        root->right = deleteNode(root->right, minRight->val);
    }
    
    return root;
}

TreeNode* findMin(TreeNode* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}
```

### Question 8: Find Kth smallest element in BST
**Answer:**
```cpp
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorderKth(root, k, count, result);
    return result;
}

void inorderKth(TreeNode* node, int k, int& count, int& result) {
    if (!node || count >= k) return;
    
    inorderKth(node->left, k, count, result);
    
    count++;
    if (count == k) {
        result = node->val;
        return;
    }
    
    inorderKth(node->right, k, count, result);
}
```

## 6. Common Tree Utility Problems

### Question 9: Lowest Common Ancestor (LCA)
**Answer:**
```cpp
// LCA in Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

// LCA in BST (more efficient)
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestorBST(root->left, p, q);
    }
    
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestorBST(root->right, p, q);
    }
    
    return root;
}
```

### Question 10: Convert BST to sorted array/linked list
**Answer:**
```cpp
// Convert BST to sorted array
void bstToArray(TreeNode* root, vector<int>& result) {
    if (!root) return;
    
    bstToArray(root->left, result);
    result.push_back(root->val);
    bstToArray(root->right, result);
}

// Convert BST to sorted doubly linked list
TreeNode* convertBSTtoDLL(TreeNode* root) {
    if (!root) return nullptr;
    
    TreeNode* head = nullptr;
    TreeNode* prev = nullptr;
    
    convertToDLLHelper(root, head, prev);
    return head;
}

void convertToDLLHelper(TreeNode* node, TreeNode*& head, TreeNode*& prev) {
    if (!node) return;
    
    convertToDLLHelper(node->left, head, prev);
    
    if (!prev) {
        head = node;
    } else {
        prev->right = node;
        node->left = prev;
    }
    prev = node;
    
    convertToDLLHelper(node->right, head, prev);
}
```

## Key Interview Tips for TCS Digital:

1. **Always start with the basic tree structure definition**
2. **Handle edge cases** (null root, single node)
3. **Explain time and space complexity**
4. **Use clear variable names and add comments**
5. **Practice drawing trees while explaining your approach**
6. **Know the difference between Binary Tree and BST operations**
7. **Be ready to code both recursive and iterative solutions**

## Time Complexities to Remember:
- Tree Traversals: O(n)
- BST Search/Insert/Delete: O(log n) average, O(n) worst
- Tree Height: O(n)
- Path Problems: O(n)
- LCA: O(n) for binary tree, O(log n) for BST

## Common Follow-up Questions:
- "Can you solve this iteratively?"
- "What if the tree is very deep? (stack overflow concern)"
- "How would you optimize this for space?"
- "What if we need to handle duplicate values?"