Since you're appearing for the **TCS Digital role** (a premium role at TCS) and already working as an **Associate Developer Intern at Tech Mahindra**, the interview panel will likely assess you on **core CS concepts**, **problem-solving skills**, **project understanding**, and **real-world development exposure**.

Here’s a categorized list of **likely questions and sample answers**:

---

### 🔹 **1. Tell me about yourself**

**Q:** Tell me about yourself.
**A:**
Good Morning Sir,

My name is Raushan Kumar, and I am from Motihari, Bihar. I completed my schooling under the State Board and am currently pursuing a Bachelor of Technology in Computer Science and Engineering from Lovely Professional University.

I am also working as an Associate Developer Intern at Tech Mahindra, where I collaborate on designing responsive websites with a focus on frontend development.

I have hands-on experience in building full-stack applications using the MERN stack. Some of the projects I have worked on include *InPic AI*, an image generation platform using AI APIs, and *ExploreEase*, a travel booking website. I am proficient in C++ and JavaScript.

I am passionate about creating user-centric applications that solve real-world problems and am always eager to learn new technologies and contribute to innovative projects.


---

### 🔹 **2. Questions on Your Internship**

**Q:** What are you working on at Tech Mahindra?
**A:**
I’m working as an Associate Developer Intern, mainly focusing on frontend development using HTML, CSS, JavaScript, and React. I collaborate with the team to design responsive UI components and ensure a good user experience. I’ve also participated in integrating frontend with APIs and basic debugging.

**Q:** What challenges have you faced and how did you solve them?
**A:**
One challenge was optimizing a page with too many re-renders in React. I used `React.memo`, proper key usage in lists, and optimized component hierarchy, which significantly improved performance.

---

### 🔹 **3. Technical Concepts**

**Q:** Explain the difference between REST and GraphQL.
**A:**
REST is an architectural style where each resource is accessed via a unique URL, and CRUD operations are mapped to HTTP methods. GraphQL is a query language that allows clients to request exactly the data they need, reducing over-fetching and under-fetching.

**Q:** What is the Virtual DOM in React?
**A:**
The Virtual DOM is a lightweight JavaScript representation of the real DOM. React updates the Virtual DOM first and then performs a diff to update only the changed parts in the actual DOM, improving performance.

---

### 🔹 **4. Data Structures & Algorithms**

**Q:** Find the second highest salary from an employee table.
**A:**

```sql
SELECT MAX(salary) 
FROM employees 
WHERE salary < (SELECT MAX(salary) FROM employees);
```

**Q:** Write a function to reverse a linked list.
**A:**

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
```

---

### 🔹 **5. Project-Based Questions**

**Q:** Explain the architecture of your InPic AI project.
**A:**
InPic AI is built using MERN. The frontend is in React, with Tailwind for styling. The backend is in Node.js and Express, where I handle routing and connect to OpenAI’s API for image generation. MongoDB stores user and image metadata. I also integrated file uploads using Multer and Cloudinary.

**Q:** How did you handle authentication in ExploreEase?
**A:**
I used JWT for token-based authentication. Tokens are stored in HTTP-only cookies for security. Role-based access control is implemented to protect admin routes.

---

### 🔹 **6. HR Questions**

**Q:** Why do you want to leave Tech Mahindra and join TCS?
**A:**
I’m grateful for the learning at Tech Mahindra, but TCS Digital offers more challenging roles and exposure to advanced technologies. It’s a step forward in my career to work in a company with global impact and structured growth.

**Q:** Are you willing to relocate or work in any domain?
**A:**
Yes, I’m flexible with both location and domain. I see each opportunity as a learning experience.

---

### 🔹 **7. Coding / Aptitude Problem**

**Q:** Write a function to check if a string is a palindrome.
**A:**

```cpp
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i++] != s[j--]) return false;
    }
    return true;
}
```

---

### 🔹 **8. OOPs Concepts**

**Q:** What is the difference between abstraction and encapsulation?
**A:**

* **Abstraction** hides complex logic and shows only relevant details (e.g., interface).
* **Encapsulation** binds data and methods together and restricts access using access modifiers (e.g., private, public).

---

Would you like me to prepare:

* A **custom resume-based mock interview**?
* A **PDF with Q\&A** for offline practice?
* A **DSA-focused cheat sheet** for TCS Digital?

Let me know!
