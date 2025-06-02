/*
 * ✅ Search Algorithms Summary Table:
 *    Search Type           Requires Sorted?    Time Complexity (Best/Avg/Worst)    Space Complexity    Best Use Cases
 *    ─────────────────────────────────────────────────────────────────────────────────────────────────────────────
 *    Linear Search         ❌ No              O(1)/O(n)/O(n)                      O(1)                Small arrays, unsorted data
 *    Binary Search         ✅ Yes             O(1)/O(log n)/O(log n)              O(1)                Large sorted arrays
 *    Jump Search           ✅ Yes             O(1)/O(√n)/O(√n)                    O(1)                Large sorted arrays, better than linear
 *    Exponential Search    ✅ Yes             O(1)/O(log n)/O(log n)              O(1)                Unbounded/infinite arrays
 *    Interpolation Search  ✅ Yes             O(1)/O(log log n)/O(n)              O(1)                Uniformly distributed sorted data
 *    Fibonacci Search      ✅ Yes             O(1)/O(log n)/O(log n)              O(1)                Large arrays, division-unfriendly systems
 *    Ternary Search        ✅ Yes             O(1)/O(log₃ n)/O(log₃ n)           O(log n)            Finding max/min in unimodal functions
 *    Hash Search           ❌ No              O(1)/O(1)/O(n)                      O(n)                Fast lookups with hash tables
 *    Peak Finding          ❌ No              O(1)/O(log n)/O(log n)              O(1)                Finding local maxima in arrays
 */

#include <bits/stdc++.h>
using namespace std;

class SearchAlgorithms {
public:
    // Utility functions
    void takeInput(int size, vector<int> &v) {
        cout << "Enter " << size << " elements: ";
        for(int i = 0; i < size; i++) {
            cin >> v[i];
        }
    }
    
    void display(const vector<int> &v, const string &title = "") {
        if(!title.empty()) {
            cout << title << ": ";
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    // 1. Linear Search - O(n) time, O(1) space
    int linearSearch(const vector<int> &v, int target) {
        cout << "\n--- Linear Search ---" << endl;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == target) {
                cout << "Element " << target << " found at index: " << i << endl;
                return i;
            }
        }
        cout << "Element " << target << " not found!" << endl;
        return -1;
    }
    
    // 2. Binary Search - O(log n) time, O(1) space
    int binarySearch(vector<int> v, int target) {
        cout << "\n--- Binary Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int left = 0, right = v.size() - 1;
        int comparisons = 0;
        
        while(left <= right) {
            comparisons++;
            int mid = left + (right - left) / 2;
            cout << "Comparing with index " << mid << " (value: " << v[mid] << ")" << endl;
            
            if(v[mid] == target) {
                cout << "Element " << target << " found at index: " << mid << " after " << comparisons << " comparisons" << endl;
                return mid;
            } else if(v[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << "Element " << target << " not found after " << comparisons << " comparisons!" << endl;
        return -1;
    }
    
    // 3. Jump Search - O(√n) time, O(1) space
    int jumpSearch(vector<int> v, int target) {
        cout << "\n--- Jump Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int n = v.size();
        int step = sqrt(n);
        int prev = 0;
        int jumps = 0;
        
        cout << "Jump step size: " << step << endl;
        
        // Jump until we find a block where target might exist
        while(v[min(step, n) - 1] < target) {
            jumps++;
            cout << "Jump " << jumps << ": Checking index " << min(step, n) - 1 << " (value: " << v[min(step, n) - 1] << ")" << endl;
            prev = step;
            step += sqrt(n);
            if(prev >= n) {
                cout << "Element " << target << " not found!" << endl;
                return -1;
            }
        }
        
        // Linear search in the identified block
        cout << "Linear search in block [" << prev << ", " << min(step, n) - 1 << "]" << endl;
        for(int i = prev; i < min(step, n); i++) {
            if(v[i] == target) {
                cout << "Element " << target << " found at index: " << i << " after " << jumps << " jumps" << endl;
                return i;
            }
        }
        cout << "Element " << target << " not found!" << endl;
        return -1;
    }
    
    // 4. Exponential Search - O(log n) time, O(1) space
    int exponentialSearch(vector<int> v, int target) {
        cout << "\n--- Exponential Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int n = v.size();
        if(v[0] == target) {
            cout << "Element " << target << " found at index: 0" << endl;
            return 0;
        }
        
        int i = 1;
        int exponentiations = 0;
        while(i < n && v[i] <= target) {
            exponentiations++;
            cout << "Exponential step " << exponentiations << ": Checking index " << i << " (value: " << v[i] << ")" << endl;
            i *= 2;
        }
        
        // Binary search in the identified range
        int left = i / 2;
        int right = min(i, n - 1);
        cout << "Binary search in range [" << left << ", " << right << "]" << endl;
        
        int comparisons = 0;
        while(left <= right) {
            comparisons++;
            int mid = left + (right - left) / 2;
            if(v[mid] == target) {
                cout << "Element " << target << " found at index: " << mid << " after " << exponentiations << " exponential steps and " << comparisons << " binary comparisons" << endl;
                return mid;
            } else if(v[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << "Element " << target << " not found!" << endl;
        return -1;
    }
    
    // 5. Interpolation Search - O(log log n) average, O(n) worst case
    int interpolationSearch(vector<int> v, int target) {
        cout << "\n--- Interpolation Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int left = 0, right = v.size() - 1;
        int probes = 0;
        
        while(left <= right && target >= v[left] && target <= v[right]) {
            probes++;
            if(left == right) {
                if(v[left] == target) {
                    cout << "Element " << target << " found at index: " << left << " after " << probes << " probes" << endl;
                    return left;
                }
                break;
            }
            
            // Interpolation formula
            int pos = left + ((double)(target - v[left]) / (v[right] - v[left])) * (right - left);
            cout << "Probe " << probes << ": Checking interpolated position " << pos << " (value: " << v[pos] << ")" << endl;
            
            if(v[pos] == target) {
                cout << "Element " << target << " found at index: " << pos << " after " << probes << " probes" << endl;
                return pos;
            }
            
            if(v[pos] < target) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
        }
        cout << "Element " << target << " not found after " << probes << " probes!" << endl;
        return -1;
    }
    
    // 6. Fibonacci Search - O(log n) time, O(1) space
    int fibonacciSearch(vector<int> v, int target) {
        cout << "\n--- Fibonacci Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int n = v.size();
        int fib2 = 0; // (m-2)'th Fibonacci number
        int fib1 = 1; // (m-1)'th Fibonacci number
        int fibM = fib2 + fib1; // m'th Fibonacci number
        
        // Find smallest Fibonacci number >= n
        while(fibM < n) {
            fib2 = fib1;
            fib1 = fibM;
            fibM = fib2 + fib1;
        }
        
        int offset = -1;
        int comparisons = 0;
        
        while(fibM > 1) {
            comparisons++;
            int i = min(offset + fib2, n - 1);
            cout << "Comparison " << comparisons << ": Checking index " << i << " (value: " << v[i] << ")" << endl;
            
            if(v[i] < target) {
                fibM = fib1;
                fib1 = fib2;
                fib2 = fibM - fib1;
                offset = i;
            } else if(v[i] > target) {
                fibM = fib2;
                fib1 = fib1 - fib2;
                fib2 = fibM - fib1;
            } else {
                cout << "Element " << target << " found at index: " << i << " after " << comparisons << " comparisons" << endl;
                return i;
            }
        }
        
        if(fib1 && offset + 1 < n && v[offset + 1] == target) {
            cout << "Element " << target << " found at index: " << offset + 1 << " after " << comparisons + 1 << " comparisons" << endl;
            return offset + 1;
        }
        
        cout << "Element " << target << " not found after " << comparisons << " comparisons!" << endl;
        return -1;
    }
    
    // 7. Ternary Search - O(log₃ n) time, O(log n) space
    int ternarySearch(vector<int> v, int target, int left, int right) {
        if(right >= left) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            cout << "Checking positions " << mid1 << " and " << mid2 << " (values: " << v[mid1] << ", " << v[mid2] << ")" << endl;
            
            if(v[mid1] == target) return mid1;
            if(v[mid2] == target) return mid2;
            
            if(target < v[mid1]) {
                return ternarySearch(v, target, left, mid1 - 1);
            } else if(target > v[mid2]) {
                return ternarySearch(v, target, mid2 + 1, right);
            } else {
                return ternarySearch(v, target, mid1 + 1, mid2 - 1);
            }
        }
        return -1;
    }
    
    int ternarySearch(vector<int> v, int target) {
        cout << "\n--- Ternary Search ---" << endl;
        sort(v.begin(), v.end());
        cout << "Sorted array: ";
        display(v);
        
        int result = ternarySearch(v, target, 0, v.size() - 1);
        if(result != -1) {
            cout << "Element " << target << " found at index: " << result << endl;
        } else {
            cout << "Element " << target << " not found!" << endl;
        }
        return result;
    }
    
    // 8. Hash-based Search (using unordered_map) - O(1) average time
    int hashSearch(const vector<int> &v, int target) {
        cout << "\n--- Hash Search ---" << endl;
        unordered_map<int, vector<int>> hashMap;
        
        // Build hash table
        for(int i = 0; i < v.size(); i++) {
            hashMap[v[i]].push_back(i);
        }
        
        cout << "Hash table built with " << hashMap.size() << " unique elements" << endl;
        
        if(hashMap.find(target) != hashMap.end()) {
            cout << "Element " << target << " found at indices: ";
            for(int idx : hashMap[target]) {
                cout << idx << " ";
            }
            cout << endl;
            return hashMap[target][0]; // Return first occurrence
        } else {
            cout << "Element " << target << " not found!" << endl;
            return -1;
        }
    }
    
    // 9. Peak Finding - O(log n) time, O(1) space
    int peakElement(const vector<int> &v) {
        cout << "\n--- Peak Element Finding ---" << endl;
        int left = 0, right = v.size() - 1;
        int comparisons = 0;
        
        while(left < right) {
            comparisons++;
            int mid = left + (right - left) / 2;
            cout << "Comparison " << comparisons << ": Checking index " << mid << " (value: " << v[mid] << ") vs " << mid + 1 << " (value: " << v[mid + 1] << ")" << endl;
            
            if(v[mid] > v[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << "Peak Element found at index: " << left << " -> " << v[left] << " after " << comparisons << " comparisons" << endl;
        return left;
    }
    
    // Performance testing function
    void testSearchPerformance(vector<int> original, int target) {
        cout << "\n=== SEARCH PERFORMANCE TEST ===\n";
        cout << "Searching for element: " << target << endl;
        
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        // Test each search algorithm
        vector<pair<string, function<int()>>> algorithms = {
            {"Linear Search", [&]() { return linearSearch(original, target); }},
            {"Binary Search", [&]() { return binarySearch(original, target); }},
            {"Jump Search", [&]() { return jumpSearch(original, target); }},
            {"Exponential Search", [&]() { return exponentialSearch(original, target); }},
            {"Interpolation Search", [&]() { return interpolationSearch(original, target); }},
            {"Fibonacci Search", [&]() { return fibonacciSearch(original, target); }},
            {"Ternary Search", [&]() { return ternarySearch(original, target); }},
            {"Hash Search", [&]() { return hashSearch(original, target); }}
        };
        
        cout << "\nPerformance Results:" << endl;
        cout << "─────────────────────────────" << endl;
        
        for(auto& algo : algorithms) {
            start = chrono::high_resolution_clock::now();
            int result = algo.second();
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::microseconds>(end - start);
            
            cout << algo.first << " - Time: " << duration.count() << " μs, Result: " << (result != -1 ? "Found" : "Not Found") << endl;
        }
    }
    
    // Interactive menu system
    void showMenu() {
        cout << "\n=== SEARCH ALGORITHMS MENU ===" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Jump Search" << endl;
        cout << "4. Exponential Search" << endl;
        cout << "5. Interpolation Search" << endl;
        cout << "6. Fibonacci Search" << endl;
        cout << "7. Ternary Search" << endl;
        cout << "8. Hash Search" << endl;
        cout << "9. Peak Element Finding" << endl;
        cout << "10. Performance Test (All Algorithms)" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
    }
};

int main() {
    SearchAlgorithms searcher;
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> v(n);
    searcher.takeInput(n, v);
    
    cout << "\nOriginal array: ";
    searcher.display(v);
    
    int choice, target;
    
    do {
        searcher.showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.linearSearch(v, target);
                break;
            case 2:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.binarySearch(v, target);
                break;
            case 3:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.jumpSearch(v, target);
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.exponentialSearch(v, target);
                break;
            case 5:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.interpolationSearch(v, target);
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.fibonacciSearch(v, target);
                break;
            case 7:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.ternarySearch(v, target);
                break;
            case 8:
                cout << "Enter element to search: ";
                cin >> target;
                searcher.hashSearch(v, target);
                break;
            case 9:
                searcher.peakElement(v);
                break;
            case 10:
                cout << "Enter element to search for performance test: ";
                cin >> target;
                searcher.testSearchPerformance(v, target);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 0);
    
    return 0;
}