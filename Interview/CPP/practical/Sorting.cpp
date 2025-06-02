/*
 * ✅ Sorting Algorithms Summary Table:
 *    Sorting Type        Stable    Time Complexity (Best/Avg/Worst)    Space Complexity    Best Use Cases
 *    ─────────────────────────────────────────────────────────────────────────────────────────────────────
 *    Bubble Sort         Yes       O(n)/O(n²)/O(n²)                   O(1)                Educational, small datasets
 *    Selection Sort      No        O(n²)/O(n²)/O(n²)                  O(1)                Memory constrained, small datasets
 *    Insertion Sort      Yes       O(n)/O(n²)/O(n²)                   O(1)                Small/nearly sorted arrays
 *    Merge Sort          Yes       O(n log n)/O(n log n)/O(n log n)    O(n)                Large datasets, stable sorting needed
 *    Quick Sort          No        O(n log n)/O(n log n)/O(n²)         O(log n)            General purpose, average case
 *    Heap Sort           No        O(n log n)/O(n log n)/O(n log n)    O(1)                Guaranteed O(n log n), memory constrained
 *    Counting Sort       Yes       O(n+k)/O(n+k)/O(n+k)               O(k)                Small range integers
 *    Radix Sort          Yes       O(d(n+k))/O(d(n+k))/O(d(n+k))      O(n+k)              Non-negative integers
 */

#include <bits/stdc++.h>
using namespace std;

class SortingAlgorithms {
public:
    // Utility functions
    void takeInput(int size, vector<int> &v) {
        // cout << "Enter " << size << " elements: ";
        for(int i = 0; i < size; i++) {
            cin >> v[i];
        }
    }
    
    void display(const vector<int> &v, const string &sortType = "") {
        if(!sortType.empty()) {
            cout << sortType << ": ";
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    // 1. Bubble Sort - O(n²) time, O(1) space
    void bubbleSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n-1; i++) {
            bool swapped = false;
            for(int j = 0; j < n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if(!swapped) break; // Optimization for best case O(n)
        }
    }
    
    // 2. Selection Sort - O(n²) time, O(1) space
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 0; i < n-1; i++) {
            int minIdx = i;
            for(int j = i+1; j < n; j++) {
                if(arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if(minIdx != i) {
                swap(arr[i], arr[minIdx]);
            }
        }
    }
    
    // 3. Insertion Sort - O(n²) time, O(1) space
    void insertionSort(vector<int> &arr) {
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    // 4. Merge Sort - O(n log n) time, O(n) space
    void merge(vector<int> &arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArr(n1), rightArr(n2);
        
        for(int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for(int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while(i < n1 && j < n2) {
            if(leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        while(i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        while(j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int> &arr, int left, int right) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    void mergeSort(vector<int> &arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }
    
    // 5. Quick Sort - O(n log n) average, O(n²) worst case time, O(log n) space
    int partition(vector<int> &arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for(int j = low; j < high; j++) {
            if(arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(vector<int> &arr, int low, int high) {
        if(low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    void quickSort(vector<int> &arr) {
        quickSort(arr, 0, arr.size() - 1);
    }
    
    // 6. Heap Sort - O(n log n) time, O(1) space
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
        
        if(right < n && arr[right] > arr[largest])
            largest = right;
        
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void heapSort(vector<int> &arr) {
        int n = arr.size();
        
        // Build max heap
        for(int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        
        // Extract elements from heap one by one
        for(int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    
    // 7. Counting Sort - O(n+k) time, O(k) space (k = range of input)
    void countingSort(vector<int> &arr) {
        if(arr.empty()) return;
        
        int maxVal = *max_element(arr.begin(), arr.end());
        int minVal = *min_element(arr.begin(), arr.end());
        int range = maxVal - minVal + 1;
        
        vector<int> count(range, 0);
        vector<int> output(arr.size());
        
        // Count occurrences
        for(int i = 0; i < arr.size(); i++)
            count[arr[i] - minVal]++;
        
        // Cumulative count
        for(int i = 1; i < range; i++)
            count[i] += count[i - 1];
        
        // Build output array
        for(int i = arr.size() - 1; i >= 0; i--) {
            output[count[arr[i] - minVal] - 1] = arr[i];
            count[arr[i] - minVal]--;
        }
        
        // Copy output array to original array
        for(int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
    
    // 8. Radix Sort - O(d(n+k)) time, O(n+k) space (d = digits, k = range)
    void countingSortForRadix(vector<int> &arr, int exp) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        
        for(int i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;
        
        for(int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        for(int i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
    
    void radixSort(vector<int> &arr) {
        if(arr.empty()) return;
        
        int maxVal = *max_element(arr.begin(), arr.end());
        
        for(int exp = 1; maxVal / exp > 0; exp *= 10)
            countingSortForRadix(arr, exp);
    }
    
    // Performance testing function
    void testSortingPerformance(vector<int> original) {
        cout << "\n=== SORTING PERFORMANCE TEST ===\n";
        
        vector<int> arr;
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        // Test each sorting algorithm
        vector<pair<string, function<void(vector<int>&)>>> algorithms = {
            {"Bubble Sort", [this](vector<int>& v) { bubbleSort(v); }},
            {"Selection Sort", [this](vector<int>& v) { selectionSort(v); }},
            {"Insertion Sort", [this](vector<int>& v) { insertionSort(v); }},
            {"Merge Sort", [this](vector<int>& v) { mergeSort(v); }},
            {"Quick Sort", [this](vector<int>& v) { quickSort(v); }},
            {"Heap Sort", [this](vector<int>& v) { heapSort(v); }},
            {"Counting Sort", [this](vector<int>& v) { countingSort(v); }},
            {"Radix Sort", [this](vector<int>& v) { radixSort(v); }}
        };
        
        for(auto& algo : algorithms) {
            arr = original;
            start = chrono::high_resolution_clock::now();
            algo.second(arr);
            end = chrono::high_resolution_clock::now();
            duration = chrono::duration_cast<chrono::microseconds>(end - start);
            
            cout << algo.first << " took: " << duration.count() << " microseconds\n";
        }
    }
};

int main() {
    SortingAlgorithms sorter;
    int n;
    
    // cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> original(n);
    sorter.takeInput(n, original);
    
    cout << "\nOriginal array: ";
    sorter.display(original);
    
    // Demonstrate each sorting algorithm
    vector<int> arr;
    
    cout << "\n=== SORTING DEMONSTRATIONS ===\n";
    
    arr = original; sorter.bubbleSort(arr);
    sorter.display(arr, "Bubble Sort");
    
    arr = original; sorter.selectionSort(arr);
    sorter.display(arr, "Selection Sort");
    
    arr = original; sorter.insertionSort(arr);
    sorter.display(arr, "Insertion Sort");
    
    arr = original; sorter.mergeSort(arr);
    sorter.display(arr, "Merge Sort");
    
    arr = original; sorter.quickSort(arr);
    sorter.display(arr, "Quick Sort");
    
    arr = original; sorter.heapSort(arr);
    sorter.display(arr, "Heap Sort");
    
    arr = original; sorter.countingSort(arr);
    sorter.display(arr, "Counting Sort");
    
    arr = original; sorter.radixSort(arr);
    sorter.display(arr, "Radix Sort");
    
    // Performance test (uncomment for larger datasets)
    // sorter.testSortingPerformance(original);
    
    return 0;
}