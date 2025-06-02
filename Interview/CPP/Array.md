Here are the most commonly asked C++ array interview questions and answers for TCS Digital roles:

## **Basic Array Concepts**

**Q1: What is an array in C++? What are its characteristics?**
**Answer:** An array is a collection of elements of the same data type stored in contiguous memory locations. Key characteristics include:
- Fixed size determined at compile time
- Elements accessed using index (0-based)
- Homogeneous data type
- Contiguous memory allocation
- Random access with O(1) time complexity

**Q2: How do you declare and initialize arrays in C++?**
**Answer:**
```cpp
// Declaration
int arr[5];

// Declaration with initialization
int arr[] = {1, 2, 3, 4, 5};
int arr[5] = {1, 2, 3, 4, 5};
int arr[5] = {0}; // Initialize all elements to 0
```

## **Core Programming Questions**

**Q3: Find the largest and smallest element in an array**
**Answer:**
```cpp
void findMinMax(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    cout << "Min: " << min << ", Max: " << max;
}
```

**Q4: Reverse an array**
**Answer:**
```cpp
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
```

**Q5: Find duplicate elements in an array**
**Answer:**
```cpp
void findDuplicates(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                cout << arr[i] << " ";
                break;
            }
        }
    }
}
```

## **Searching and Sorting**

**Q6: Implement Binary Search**
**Answer:**
```cpp
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

**Q7: Rotate array by k positions**
**Answer:**
```cpp
void rotateArray(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, arr + n - k);
    reverse(arr + n - k, arr + n);
    reverse(arr, arr + n);
}
```

## **Advanced Problems**

**Q8: Find missing number in array of 1 to n**
**Answer:**
```cpp
int findMissing(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return total - sum;
}
```

**Q9: Merge two sorted arrays**
**Answer:**
```cpp
void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }
    while(i < n1) result[k++] = arr1[i++];
    while(j < n2) result[k++] = arr2[j++];
}
```

**Q10: Find subarray with given sum**
**Answer:**
```cpp
bool hasSubarraySum(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == target) return true;
        }
    }
    return false;
}
```

## **Memory and Pointer Questions**

**Q11: What's the difference between array and pointer?**
**Answer:**
- Array is a collection of elements; pointer stores memory address
- Array size is fixed; pointer can point to different memory locations
- Array name is constant pointer; pointer variable can be reassigned
- sizeof(array) gives total size; sizeof(pointer) gives pointer size

**Q12: How are 2D arrays stored in memory?**
**Answer:** 2D arrays are stored in row-major order in C++. For array `arr[m][n]`, element `arr[i][j]` is located at: `base_address + (i * n + j) * sizeof(datatype)`

## **Common Tricky Questions**

**Q13: What happens when you access array out of bounds?**
**Answer:** C++ doesn't perform bounds checking. Accessing out-of-bounds may lead to undefined behavior, garbage values, or program crashes.

**Q14: Can array size be variable in C++?**
**Answer:** Traditional arrays require compile-time constant size. Variable Length Arrays (VLA) are not standard C++, but dynamic arrays can be created using `new` operator or `std::vector`.

**Q15: Difference between array and std::vector?**
**Answer:**
- Array: Fixed size, stack allocation, no built-in functions
- Vector: Dynamic size, heap allocation, rich STL functions, automatic memory management

## **Time Complexity Questions**

**Q16: What are time complexities of common array operations?**
**Answer:**
- Access: O(1)
- Search (unsorted): O(n)
- Search (sorted): O(log n) with binary search
- Insertion at end: O(1)
- Insertion at beginning: O(n)
- Deletion: O(n)

These questions cover the fundamental to advanced array concepts typically asked in TCS Digital interviews. Practice implementing these solutions and understand their time/space complexities for better preparation.