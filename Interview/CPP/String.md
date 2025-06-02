Here are the most commonly asked C++ string interview questions and answers for TCS Digital roles:

## **Basic String Concepts**

**Q1: What is a string in C++? What are the different ways to represent strings?**
**Answer:** A string is a sequence of characters. C++ provides multiple ways:
- C-style strings: `char str[] = "hello";`
- C++ string class: `string str = "hello";`
- String literals: `"hello world"`
- Character arrays: `char str[10];`

**Q2: What's the difference between C-style strings and C++ string class?**
**Answer:**
- C-style strings are null-terminated character arrays
- C++ strings are objects with built-in methods
- C++ strings handle memory automatically
- C++ strings are safer and more feature-rich

```cpp
// C-style
char cstr[] = "Hello";
// C++ style
string cppstr = "Hello";
```

## **String Operations and Manipulation**

**Q3: Reverse a string**
**Answer:**
```cpp
// Method 1: Using built-in function
string reverseString1(string str) {
    reverse(str.begin(), str.end());
    return str;
}

// Method 2: Manual reversal
string reverseString2(string str) {
    int n = str.length();
    for(int i = 0; i < n/2; i++) {
        swap(str[i], str[n-1-i]);
    }
    return str;
}

// Method 3: Two pointers
void reverseString3(string& str) {
    int left = 0, right = str.length() - 1;
    while(left < right) {
        swap(str[left++], str[right--]);
    }
}
```

**Q4: Check if a string is palindrome**
**Answer:**
```cpp
bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Case-insensitive palindrome
bool isPalindromeIgnoreCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return isPalindrome(str);
}
```

**Q5: Check if two strings are anagrams**
**Answer:**
```cpp
bool areAnagrams(string str1, string str2) {
    if(str1.length() != str2.length()) return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return str1 == str2;
}

// Using frequency count
bool areAnagramsFreq(string str1, string str2) {
    if(str1.length() != str2.length()) return false;
    
    int freq[256] = {0};
    
    for(int i = 0; i < str1.length(); i++) {
        freq[str1[i]]++;
        freq[str2[i]]--;
    }
    
    for(int i = 0; i < 256; i++) {
        if(freq[i] != 0) return false;
    }
    return true;
}
```

## **Pattern Matching and Searching**

**Q6: Find first occurrence of substring**
**Answer:**
```cpp
int findSubstring(string str, string pattern) {
    return str.find(pattern);
}

// Manual implementation
int findSubstringManual(string str, string pattern) {
    int n = str.length();
    int m = pattern.length();
    
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) {
            if(str[i + j] != pattern[j]) break;
        }
        if(j == m) return i;
    }
    return -1;
}
```

**Q7: Count occurrences of a character in string**
**Answer:**
```cpp
int countChar(string str, char ch) {
    int count = 0;
    for(char c : str) {
        if(c == ch) count++;
    }
    return count;
}

// Using built-in function
int countCharBuiltIn(string str, char ch) {
    return count(str.begin(), str.end(), ch);
}
```

**Q8: Find all permutations of a string**
**Answer:**
```cpp
void findPermutations(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while(next_permutation(str.begin(), str.end()));
}

// Recursive approach
void permuteRecursive(string str, int left, int right) {
    if(left == right) {
        cout << str << endl;
        return;
    }
    for(int i = left; i <= right; i++) {
        swap(str[left], str[i]);
        permuteRecursive(str, left + 1, right);
        swap(str[left], str[i]); // backtrack
    }
}
```

## **String Formatting and Conversion**

**Q9: Convert string to integer (atoi implementation)**
**Answer:**
```cpp
int stringToInt(string str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    // Handle whitespace
    while(i < str.length() && str[i] == ' ') i++;
    
    // Handle sign
    if(i < str.length() && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert digits
    while(i < str.length() && isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;
}
```

**Q10: Remove duplicates from string**
**Answer:**
```cpp
string removeDuplicates(string str) {
    unordered_set<char> seen;
    string result = "";
    
    for(char c : str) {
        if(seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

// Maintain order, remove all duplicates
string removeDuplicatesKeepFirst(string str) {
    string result = "";
    bool visited[256] = {false};
    
    for(char c : str) {
        if(!visited[c]) {
            visited[c] = true;
            result += c;
        }
    }
    return result;
}
```

## **Advanced String Problems**

**Q11: Longest Common Subsequence**
**Answer:**
```cpp
int longestCommonSubsequence(string str1, string str2) {
    int m = str1.length(), n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
```

**Q12: Longest Palindromic Substring**
**Answer:**
```cpp
string longestPalindrome(string str) {
    int n = str.length();
    if(n == 0) return "";
    
    int start = 0, maxLen = 1;
    
    // Check for odd length palindromes
    for(int i = 0; i < n; i++) {
        int left = i, right = i;
        while(left >= 0 && right < n && str[left] == str[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    // Check for even length palindromes
    for(int i = 0; i < n - 1; i++) {
        int left = i, right = i + 1;
        while(left >= 0 && right < n && str[left] == str[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    return str.substr(start, maxLen);
}
```

**Q13: String compression (run-length encoding)**
**Answer:**
```cpp
string compressString(string str) {
    if(str.empty()) return str;
    
    string compressed = "";
    int count = 1;
    
    for(int i = 1; i < str.length(); i++) {
        if(str[i] == str[i-1]) {
            count++;
        } else {
            compressed += str[i-1] + to_string(count);
            count = 1;
        }
    }
    compressed += str.back() + to_string(count);
    
    return compressed.length() < str.length() ? compressed : str;
}
```

## **String Tokenization and Parsing**

**Q14: Split string by delimiter**
**Answer:**
```cpp
vector<string> splitString(string str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    
    while(getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Manual implementation
vector<string> splitStringManual(string str, char delimiter) {
    vector<string> tokens;
    string current = "";
    
    for(char c : str) {
        if(c == delimiter) {
            if(!current.empty()) {
                tokens.push_back(current);
                current = "";
            }
        } else {
            current += c;
        }
    }
    if(!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}
```

**Q15: Remove extra spaces from string**
**Answer:**
```cpp
string removeExtraSpaces(string str) {
    string result = "";
    bool spaceFound = false;
    
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ' ') {
            result += str[i];
            spaceFound = false;
        } else if(!spaceFound) {
            result += ' ';
            spaceFound = true;
        }
    }
    
    // Remove trailing space
    if(!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    
    return result;
}
```

## **Memory and Performance Questions**

**Q16: What's the time complexity of string concatenation?**
**Answer:**
- Using `+` operator: O(n) for each operation
- Using `+=` operator: Amortized O(1)
- For multiple concatenations, use `stringstream` or reserve space

**Q17: How does string memory allocation work?**
**Answer:**
- C++ strings use dynamic memory allocation
- Small String Optimization (SSO) for short strings
- Capacity grows exponentially to avoid frequent reallocations
- Use `reserve()` for known size requirements

**Q18: What's the difference between `size()` and `length()` in strings?**
**Answer:** Both are identical in C++ strings. They return the number of characters. `size()` is preferred for consistency with other STL containers.

## **Common Tricky Questions**

**Q19: How to check if string contains only digits?**
**Answer:**
```cpp
bool isNumeric(string str) {
    for(char c : str) {
        if(!isdigit(c)) return false;
    }
    return !str.empty();
}

// Using built-in function
bool isNumericBuiltIn(string str) {
    return !str.empty() && all_of(str.begin(), str.end(), ::isdigit);
}
```

**Q20: Case-insensitive string comparison**
**Answer:**
```cpp
bool compareIgnoreCase(string str1, string str2) {
    if(str1.length() != str2.length()) return false;
    
    for(int i = 0; i < str1.length(); i++) {
        if(tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}

// Using transform
bool compareIgnoreCaseTransform(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}
```

These questions cover fundamental to advanced string concepts commonly asked in TCS Digital interviews. Practice implementing these solutions and understand their time/space complexities for comprehensive preparation.