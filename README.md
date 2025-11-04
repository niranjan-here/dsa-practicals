# 🧠 SPPU DSA Practicals – IT Department (Second Year, 2024 Pattern)

This repository contains the **Data Structures and Algorithms (DSA)** practical programs as per the **Savitribai Phule Pune University (SPPU)** syllabus for **Second Year Information Technology (2024 Pattern)**.

---

## 📘 Subject Details

- **Subject Name:** Data Structures and Algorithms (DSA)  
- **Department:** Information Technology  
- **Year:** Second Year (SE IT)  
- **Pattern:** 2024  
- **University:** Savitribai Phule Pune University (SPPU)

---

## 📘 PART A – Using C++

### 🔹 Practical 1 – Searching and Sorting *(CO1, CO2)*  
**Problem Statement:**  
Design a program to maintain a **student database** that performs the following tasks:  
1. Add and store student details (**ID, Name, CGPA**) using dynamically allocated memory.  
2. Expand the student list using `realloc()` as new entries are added.  
3. Implement **Linear Search** and **Binary Search** to find student records by ID.  
4. Implement at least **two sorting algorithms** (Bubble, Selection, or Insertion Sort) to sort records by:  
   - Name (Alphabetically)  
   - CGPA (Ascending/Descending)  
5. Analyze and compare search performance **before and after sorting**.

---

### 🔹 Practical 2 – Stack *(CO1, CO2)*  
Implement **Stack as an Abstract Data Type (ADT)** using a **singly linked list** and use this ADT to:  
- Convert **Infix Expression → Postfix / Prefix** form.  

---

### 🔹 Practical 3 – Circular Queue *(CO1, CO2)*  
Implement **Circular Queue** using **Array**. Perform the following operations:  
- Enqueue (Insertion)  
- Dequeue (Deletion)  
- Display queue contents  

> Handle “Queue Full” condition using a fixed-size array.

---

## 🐍 PART B – Using Python

### 🔹 Practical 4 – Binary Search Tree *(CO1, CO2, CO3)*  
Implement a **Binary Search Tree (BST)** and perform the following operations:  
a) Insert (handle duplicates)  
b) Delete  
c) Search  
d) Display Tree (Traversal)  
e) Display Depth of Tree  
f) Display Mirror Image  
g) Create a Copy  
h) Display Parent Nodes with Children  
i) Display Leaf Nodes  
j) Display Level-wise Tree  

---

### 🔹 Practical 5 – Graph: Minimum Spanning Tree *(CO1, CO2, CO3)*  
Represent a **graph of your college campus** using adjacency list or adjacency matrix.  
- Nodes → Departments/Institutes  
- Edges → Distances between them  
Implement **Minimum Spanning Tree (MST)** using:  
a) **Kruskal’s Algorithm**  
b) **Prim’s Algorithm**

---

### 🔹 Practical 6 – Heap Sort *(CO1, CO2, CO4)*  
Design and implement **Heap Sort** to efficiently sort an array of integers in ascending order.  
Demonstrate the working of **min-heap or max-heap**, and analyze time and space complexity.

---

### 🔹 Practical 7 – Divide and Conquer (Merge Sort) *(CO1, CO2, CO5)*  
**Problem Statement:**  
You are given a list of online orders with estimated delivery times (in minutes).  
Use **Merge Sort** to sort the orders by **delivery time**, so that quicker deliveries are prioritized.  

---

### 🔹 Practical 8 – Greedy Algorithm (Fractional Knapsack) *(CO1, CO2, CO5)*  
**Problem Statement:**  
You run a shipping company and must load a truck with parcels of various weights and profits.  
The truck has a limited weight capacity.  
Use the **Fractional Knapsack Algorithm** to **maximize profit** — partial selection of parcels is allowed.

---

### 🔹 Practical 9 – String Processing: Naïve String Matching *(CO1, CO2, CO4)*  
**Objective:**  
Given:  
- A text string `text` of length `n`  
- A pattern string `pattern` of length `m`  

Find all starting indices `i` such that `text[i:i+m] == pattern`, using the **Naïve String Matching Algorithm**.

Constraints:  
- `0 ≤ m ≤ n`  
- Text and pattern may contain any valid characters (a–z, A–Z, digits, symbols, etc.)

---

## 🧩 Summary of Practicals

| No. | Practical Title | Language | Major Concepts |
|-----|------------------|-----------|----------------|
| 1 | Searching and Sorting | C++ | Linear Search, Binary Search, Sorting, Dynamic Memory |
| 2 | Stack ADT | C++ | Linked List, Infix → Postfix/Prefix |
| 3 | Circular Queue | C++ | Array, Queue Operations |
| 4 | Binary Search Tree | Python | Tree Operations, Traversals, Recursion |
| 5 | Graph – MST | Python | Kruskal’s, Prim’s, Graph Representation |
| 6 | Heap Sort | Python | Heap Structure, Sorting |
| 7 | Merge Sort | Python | Divide and Conquer |
| 8 | Fractional Knapsack | Python | Greedy Algorithm |
| 9 | String Matching | Python | Pattern Searching |

---

## 🛠️ Tools and Technologies

- **C++** (Part A)  
  - Compiler: GCC / g++  
  - IDE: Code::Blocks / VS Code  
- **Python 3.x** (Part B)  
  - IDE: VS Code / PyCharm / Jupyter Notebook  
- **OS:** Windows / Linux / macOS  

---

## 🚀 How to Run

### For C++ Programs
```
g++ practical1.cpp -o practical1  ---> TO COMPILE THE CODE
./practical1                      ---> TO RUN COMPILED FILE
```

### For Python Programs
```
python3 practical4.py
```
