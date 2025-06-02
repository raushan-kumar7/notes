# TCS Digital - Graph Interview Questions & Answers (C++)

## Graph Representation Methods
```cpp
// 1. Adjacency List (Most Common)
vector<vector<int>> adjList;

// 2. Adjacency Matrix
vector<vector<int>> adjMatrix;

// 3. Edge List
vector<pair<int, int>> edges;

// For Weighted Graphs
vector<vector<pair<int, int>>> weightedAdjList; // {neighbor, weight}
```

## 1. Graph Traversals (Most Common Pattern)

### Question 1: Implement DFS and BFS
**Answer:**
```cpp
// DFS using Recursion
void dfsRecursive(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited, result);
        }
    }
}

// DFS using Stack (Iterative)
vector<int> dfsIterative(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    vector<int> result;
    stack<int> st;
    
    st.push(start);
    visited[start] = true;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        result.push_back(node);
        
        // Add neighbors in reverse order to maintain left-to-right traversal
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                st.push(neighbor);
            }
        }
    }
    return result;
}

// BFS using Queue
vector<int> bfsTraversal(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    vector<int> result;
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}

// Complete Graph Traversal (handles disconnected components)
vector<int> completeGraphTraversal(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsRecursive(i, adj, visited, result);
        }
    }
    return result;
}
```

## 2. Connected Components & Cycle Detection

### Question 2: Count Connected Components
**Answer:**
```cpp
int countConnectedComponents(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfsRecursive(i, adj, visited, vector<int>());
        }
    }
    return components;
}

// Using Union-Find (Disjoint Set Union)
class UnionFind {
public:
    vector<int> parent, rank;
    int components;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        components--;
        return true;
    }
};
```

### Question 3: Cycle Detection in Undirected and Directed Graphs
**Answer:**
```cpp
// Cycle Detection in Undirected Graph using DFS
bool hasCycleUndirected(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (hasCycleUndirected(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // Back edge found
        }
    }
    return false;
}

bool detectCycleUndirected(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleUndirected(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

// Cycle Detection in Directed Graph using DFS (White-Gray-Black)
bool hasCycleDirected(int node, vector<vector<int>>& adj, vector<int>& color) {
    color[node] = 1; // Gray (currently being processed)
    
    for (int neighbor : adj[node]) {
        if (color[neighbor] == 1) { // Back edge to gray node
            return true;
        }
        if (color[neighbor] == 0 && hasCycleDirected(neighbor, adj, color)) {
            return true;
        }
    }
    
    color[node] = 2; // Black (completely processed)
    return false;
}

bool detectCycleDirected(vector<vector<int>>& adj, int n) {
    vector<int> color(n, 0); // 0: White, 1: Gray, 2: Black
    
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (hasCycleDirected(i, adj, color)) {
                return true;
            }
        }
    }
    return false;
}
```

## 3. Shortest Path Algorithms (Very Important for TCS)

### Question 4: Dijkstra's Algorithm
**Answer:**
```cpp
vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src}); // {distance, node}
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue; // Skip if we've found a better path
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

// Print shortest path
vector<int> getShortestPath(int src, int dest, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Reconstruct path
    vector<int> path;
    int current = dest;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());
    
    return (path[0] == src) ? path : vector<int>(); // Return empty if no path
}
```

### Question 5: Floyd-Warshall Algorithm (All Pairs Shortest Path)
**Answer:**
```cpp
vector<vector<int>> floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph;
    
    // Initialize distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] == 0) {
                dist[i][j] = INT_MAX;
            }
        }
    }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    return dist;
}
```

## 4. Topological Sorting (Important for TCS)

### Question 6: Topological Sort (Kahn's Algorithm & DFS)
**Answer:**
```cpp
// Kahn's Algorithm (BFS based)
vector<int> topologicalSortKahn(vector<vector<int>>& adj, int n) {
    vector<int> indegree(n, 0);
    
    // Calculate indegrees
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Check for cycle
    return (result.size() == n) ? result : vector<int>();
}

// DFS based Topological Sort
void topologicalSortDFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFSUtil(neighbor, adj, visited, st);
        }
    }
    
    st.push(node);
}

vector<int> topologicalSortDFS(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFSUtil(i, adj, visited, st);
        }
    }
    
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}
```

## 5. Minimum Spanning Tree (MST)

### Question 7: Kruskal's and Prim's Algorithm
**Answer:**
```cpp
// Edge structure for Kruskal's
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Kruskal's Algorithm
int kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    
    int mstWeight = 0;
    int edgesUsed = 0;
    
    for (const Edge& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mstWeight += edge.weight;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }
    
    return (edgesUsed == n - 1) ? mstWeight : -1; // -1 if no MST possible
}

// Prim's Algorithm
int primMST(vector<vector<pair<int, int>>>& adj, int n) {
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}
    
    int mstWeight = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        
        inMST[u] = true;
        mstWeight += key[u];
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    
    return mstWeight;
}
```

## 6. Bipartite Graph & Graph Coloring

### Question 8: Check if Graph is Bipartite
**Answer:**
```cpp
bool isBipartite(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1);
    
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bipartiteCheck(i, adj, color)) {
                return false;
            }
        }
    }
    return true;
}

bool bipartiteCheck(int start, vector<vector<int>>& adj, vector<int>& color) {
    queue<int> q;
    q.push(start);
    color[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

// DFS version
bool isBipartiteDFS(int node, int c, vector<vector<int>>& adj, vector<int>& color) {
    color[node] = c;
    
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            if (!isBipartiteDFS(neighbor, 1 - c, adj, color)) {
                return false;
            }
        } else if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}
```

## 7. Special Graph Problems (Common in TCS)

### Question 9: Find Strongly Connected Components (Kosaraju's Algorithm)
**Answer:**
```cpp
void dfsFirst(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsFirst(neighbor, adj, visited, st);
        }
    }
    
    st.push(node);
}

void dfsSecond(int node, vector<vector<int>>& revAdj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    
    for (int neighbor : revAdj[node]) {
        if (!visited[neighbor]) {
            dfsSecond(neighbor, revAdj, visited, component);
        }
    }
}

vector<vector<int>> kosarajuSCC(vector<vector<int>>& adj, int n) {
    // Step 1: Fill stack according to finish times
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsFirst(i, adj, visited, st);
        }
    }
    
    // Step 2: Create reverse graph
    vector<vector<int>> revAdj(n);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            revAdj[neighbor].push_back(i);
        }
    }
    
    // Step 3: Process vertices in order of finish times
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            vector<int> component;
            dfsSecond(node, revAdj, visited, component);
            sccs.push_back(component);
        }
    }
    
    return sccs;
}
```

### Question 10: Clone a Graph
**Answer:**
```cpp
// Node definition for graph cloning
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> cloneMap;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }
        
        Node* clone = new Node(node->val);
        cloneMap[node] = clone;
        
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone;
    }
};
```

## 8. Graph Applications & Matrix Problems

### Question 11: Number of Islands (2D Grid DFS/BFS)
**Answer:**
```cpp
int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int rows = grid.size();
    int cols = grid[0].size();
    int islands = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfsIsland(grid, i, j, rows, cols);
            }
        }
    }
    
    return islands;
}

void dfsIsland(vector<vector<char>>& grid, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') {
        return;
    }
    
    grid[i][j] = '0'; // Mark as visited
    
    // Check all 4 directions
    dfsIsland(grid, i + 1, j, rows, cols);
    dfsIsland(grid, i - 1, j, rays, cols);
    dfsIsland(grid, i, j + 1, rows, cols);
    dfsIsland(grid, i, j - 1, rows, cols);
}

// BFS version
int numIslandsBFS(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    
    int rows = grid.size();
    int cols = grid[0].size();
    int islands = 0;
    
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                islands++;
                
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    
                    for (auto [dx, dy] : directions) {
                        int nx = x + dx;
                        int ny = y + dy;
                        
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    
    return islands;
}
```

### Question 12: Word Ladder (Shortest Transformation Sequence)
**Answer:**
```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
    if (wordSet.find(endWord) == wordSet.end()) {
        return 0;
    }
    
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    
    while (!q.empty()) {
        auto [word, level] = q.front();
        q.pop();
        
        if (word == endWord) {
            return level;
        }
        
        for (int i = 0; i < word.length(); i++) {
            char original = word[i];
            
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                
                word[i] = c;
                
                if (wordSet.find(word) != wordSet.end()) {
                    q.push({word, level + 1});
                    wordSet.erase(word); // Remove to avoid revisiting
                }
            }
            
            word[i] = original; // Restore original character
        }
    }
    
    return 0;
}
```

## Key Interview Tips for TCS Digital:

1. **Always clarify graph representation**: Adjacency list vs matrix
2. **Handle edge cases**: Empty graph, single node, disconnected components
3. **Know time/space complexities**:
   - DFS/BFS: O(V + E)
   - Dijkstra: O((V + E) log V)
   - Floyd-Warshall: O(V³)
   - Kruskal: O(E log E)
   - Prim: O(E log V)

4. **Common follow-ups**:
   - "How would you handle negative weights?"
   - "What if the graph is very large?"
   - "Can you optimize space complexity?"

5. **Practice drawing graphs** while explaining algorithms

## Most Important Topics for TCS Digital:
1. **Graph Traversals** (DFS/BFS) - Almost guaranteed
2. **Shortest Path** (Dijkstra) - Very common
3. **Cycle Detection** - Frequently asked
4. **Connected Components** - Popular
5. **Topological Sort** - Common for dependency problems
6. **Number of Islands** - Popular 2D grid problem