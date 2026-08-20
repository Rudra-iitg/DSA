<div align="center">

# 🧠 Data Structures & Algorithms in C++

### A structured, topic-wise DSA repository — built while preparing for competitive programming and SWE internship interviews.

![C++](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=flat-square&logo=cplusplus)
![Progress](https://img.shields.io/badge/Sheet-Striver%20A2Z-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-In%20Progress-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)

</div>

---

## 📖 About This Repository

This repo is my personal DSA workspace — every problem I solve, every pattern I learn, and every "aha" moment gets logged here in a structured, revisitable form. It follows **Striver's A2Z DSA Sheet** as the backbone, supplemented with problems from **LeetCode** and **Codeforces**, and is organized so that anyone (including future-me) can jump into any topic and understand *what it is, when to use it, and how it's implemented* — not just see raw code.

The goal isn't just "solve and forget." Each topic folder is meant to build genuine pattern recognition — the kind needed for competitive programming rounds and technical interviews alike.

> 💡 **Philosophy:** Understand the *why* before optimizing the *how*. Brute force → Better → Optimal, always shown in that order.

---

## 📌 Table of Contents

1. [Repository Structure](#-repository-structure)
2. [How to Use This Repo](#-how-to-use-this-repo)
3. [Progress Tracker](#-progress-tracker)
4. [Topics Covered](#-topics-covered)
   - [1. Basic Math & Recursion Foundations](#1-basic-math--recursion-foundations)
   - [2. Arrays](#2-arrays)
   - [3. Searching & Sorting](#3-searching--sorting)
   - [4. Strings](#4-strings)
   - [5. Hashing](#5-hashing)
   - [6. Two Pointers & Sliding Window](#6-two-pointers--sliding-window)
   - [7. Recursion & Backtracking](#7-recursion--backtracking)
   - [8. Linked List](#8-linked-list)
   - [9. Stacks & Queues](#9-stacks--queues)
   - [10. Binary Trees](#10-binary-trees)
   - [11. Binary Search Trees](#11-binary-search-trees)
   - [12. Heaps & Priority Queues](#12-heaps--priority-queues)
   - [13. Greedy Algorithms](#13-greedy-algorithms)
   - [14. Graphs](#14-graphs)
   - [15. Dynamic Programming](#15-dynamic-programming)
   - [16. Trie](#16-trie)
   - [17. Bit Manipulation](#17-bit-manipulation)
5. [Complexity Cheat Sheet](#-complexity-cheat-sheet)
6. [Resources](#-resources)
7. [Connect With Me](#-connect-with-me)

---

## 🗂 Repository Structure

```
DSA/
├── 01-Basic-Math-Recursion/
├── 02-Arrays/
│   ├── easy/
│   ├── medium/
│   └── hard/
├── 03-Searching-Sorting/
├── 04-Strings/
├── 05-Hashing/
├── 06-Two-Pointers-Sliding-Window/
├── 07-Recursion-Backtracking/
├── 08-Linked-List/
├── 09-Stacks-Queues/
├── 10-Binary-Trees/
├── 11-Binary-Search-Trees/
├── 12-Heaps/
├── 13-Greedy/
├── 14-Graphs/
├── 15-Dynamic-Programming/
├── 16-Trie/
├── 17-Bit-Manipulation/
└── README.md
```

Each topic folder follows the same internal convention:

```
Topic/
├── notes.md          # Concept explanation, patterns, edge cases
├── problem_name.cpp   # Solution with comments (brute → optimal)
└── complexity.md      # Time/space breakdown for each approach
```

---

## 🚀 How to Use This Repo

1. Every `.cpp` file is self-contained — it compiles and runs independently.
2. Each solution file has three sections in comments: **Approach**, **Intuition**, **Complexity**.
3. `notes.md` inside each folder is the "textbook" for that topic — read it before diving into problems.
4. Problems are tagged by difficulty (`easy` / `medium` / `hard`) and by pattern (e.g. `#sliding-window`, `#two-pointer`).

---

## 📊 Progress Tracker

| Topic | Status | Problems Solved |
|---|---|---|
| Basic Math & Recursion | ✅ Done | 20+ |
| Arrays | 🟡 In Progress | 40+ |
| Searching & Sorting | 🟡 In Progress | 25+ |
| Strings | 🟡 In Progress | 15+ |
| Hashing | 🟡 In Progress | 20+ |
| Two Pointers & Sliding Window | ⬜ Upcoming | - |
| Recursion & Backtracking | ⬜ Upcoming | - |
| Linked List | ⬜ Upcoming | - |
| Stacks & Queues | ⬜ Upcoming | - |
| Trees | ⬜ Upcoming | - |
| Graphs | ⬜ Upcoming | - |
| Dynamic Programming | ⬜ Upcoming | - |
| Greedy | ⬜ Upcoming | - |
| Trie | ⬜ Upcoming | - |
| Bit Manipulation | ⬜ Upcoming | - |

> Update this table as you go — it's the fastest way to see your own momentum.

---

## 🧩 Topics Covered

### 1. Basic Math & Recursion Foundations

**What it is:** The building blocks — number theory basics (primes, GCD/LCM, digit manipulation) and the mental model of recursion (a function that calls itself on a smaller sub-problem until it hits a base case).

**Why it matters:** Recursion underlies backtracking, tree/graph traversal, divide-and-conquer, and DP. If recursion isn't intuitive, nothing built on top of it will be either.

**Key patterns:**
- Base case → Recursive case → Combine results
- Recursion tree visualization to spot repeated sub-problems (the seed of DP)
- Tail recursion vs. non-tail recursion (stack usage implications)

**Illustration — Factorial recursion tree:**
```
factorial(4)
 └── 4 * factorial(3)
      └── 3 * factorial(2)
           └── 2 * factorial(1)
                └── 1 * factorial(0)
                     └── returns 1   (base case)
```

**Core problems:** Reverse a number, check palindrome, GCD (Euclidean algorithm), power(x, n) using fast exponentiation, print 1 to N without loops, sum of first N numbers recursively.

```cpp
// Fast exponentiation — O(log n) instead of O(n)
long long power(long long x, long long n) {
    if (n == 0) return 1;
    long long half = power(x, n / 2);
    long long result = half * half;
    return (n % 2 == 0) ? result : result * x;
}
```

---

### 2. Arrays

**What it is:** A contiguous block of memory holding elements of the same type, accessible in O(1) via index. The most fundamental data structure — most other structures are built on top of it.

**Why it matters:** Arrays are where pattern recognition starts — prefix sums, Kadane's algorithm, two pointers, and sorting-based tricks all begin here.

**Key patterns:**
- **Prefix sum** — precompute cumulative sums to answer range-sum queries in O(1)
- **Kadane's Algorithm** — maximum subarray sum in O(n)
- **Boyer-Moore Voting** — majority element in O(n) time, O(1) space
- **Dutch National Flag** — 3-way partitioning (sort array of 0s, 1s, 2s in one pass)
- **Cyclic sort** — placing numbers at their correct index when range is known

**Illustration — Kadane's Algorithm:**
```
Array:      [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Running:     -2  1  -2  4   3  5  6   1  5
Max so far:  -2  1   1  4   4  5  6   6  6
                                   ↑
                        Max subarray sum = 6 → [4, -1, 2, 1]
```

**Core problems:** Second largest element, rotate array, move zeroes, find missing number, Kadane's max subarray, merge intervals, next permutation, majority element (>n/2 and >n/3), Dutch National Flag sort.

```cpp
// Kadane's Algorithm — Maximum Subarray Sum
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
```

**Complexity:** Access O(1) · Search O(n) · Insertion/Deletion O(n) (due to shifting)

---

### 3. Searching & Sorting

**What it is:** Techniques to locate elements (search) or arrange them in order (sort) efficiently.

**Why it matters:** Binary search alone unlocks an entire category of "search on answer" problems that look nothing like classic searching at first glance. Sorting algorithms teach divide-and-conquer and in-place manipulation.

**Key patterns:**
- **Binary Search** — O(log n) search on a sorted (or monotonic) space
- **Binary Search on Answer** — when the answer itself is monotonic (e.g. "minimum days to make M bouquets")
- **Merge Sort** — divide & conquer, stable, O(n log n) guaranteed
- **Quick Sort** — partition-based, average O(n log n), in-place

**Illustration — Binary Search:**
```
Array: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
Target: 23

low=0, high=9, mid=4 → arr[4]=16 < 23 → search right
low=5, high=9, mid=7 → arr[7]=56 > 23 → search left
low=5, high=6, mid=5 → arr[5]=23 == 23 → FOUND at index 5 ✅
```

**Core problems:** Lower/upper bound, search in rotated sorted array, find peak element, aggressive cows (binary search on answer), median of two sorted arrays, merge sort, quick sort implementation from scratch.

```cpp
// Binary Search — iterative, avoids overflow
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

**Complexity table:**

| Algorithm | Best | Average | Worst | Space | Stable |
|---|---|---|---|---|---|
| Binary Search | O(1) | O(log n) | O(log n) | O(1) | — |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ |

---

### 4. Strings

**What it is:** Arrays of characters with specialized operations — pattern matching, palindrome checks, and manipulation problems that combine hashing, two pointers, and DP.

**Key patterns:**
- Frequency counting via hash maps / fixed-size arrays (26 lowercase letters)
- Two-pointer palindrome checks
- Pattern matching (brute force, KMP for O(n+m))
- Anagram grouping via sorted-string or frequency-signature keys

**Illustration — Palindrome check via two pointers:**
```
String: "madam"
 m  a  d  a  m
 ↑              ↑
left=0        right=4   → s[0]==s[4] ('m'=='m') ✅ move inward
    ↑        ↑
  left=1   right=3     → s[1]==s[3] ('a'=='a') ✅ move inward
       ↑ ↑
    left=2==right=2    → pointers met → PALINDROME ✅
```

**Core problems:** Reverse words in a string, check anagram, longest palindromic substring, valid parentheses, string compression, Rabin-Karp / KMP pattern matching, Z-function basics.

```cpp
// Check if two strings are anagrams — O(n)
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;
    for (int f : freq) if (f != 0) return false;
    return true;
}
```

---

### 5. Hashing

**What it is:** A technique to achieve average O(1) lookup, insertion, and deletion by mapping keys to array indices via a hash function.

**Why it matters:** Hashing turns O(n) or O(n²) brute-force searches into O(n) or O(1) lookups. It's the single highest-leverage topic for quickly optimizing brute-force solutions.

**Key patterns:**
- Frequency counting (`unordered_map<int,int>`)
- Existence checking (`unordered_set`) — e.g. "have I seen this before?"
- Prefix-sum + hash map for subarray-sum problems
- Two Sum pattern — store `value → index` while scanning once

**Illustration — Two Sum via hashing:**
```
nums = [2, 7, 11, 15], target = 9

i=0: num=2,  need=7  → map empty, not found → store {2:0}
i=1: num=7,  need=2  → 2 IS in map at index 0 → FOUND! return [0,1] ✅
```

**Core problems:** Two Sum, longest consecutive sequence, subarray sum equals K, count distinct elements in every window, group anagrams, majority element via hashing.

```cpp
// Two Sum — O(n) time, O(n) space
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

---

### 6. Two Pointers & Sliding Window

**What it is:** Two-pointer uses a pair of indices moving toward/away from each other; sliding window maintains a "window" of elements that expands/shrinks based on a condition. Both avoid the nested-loop O(n²) trap.

**Key patterns:**
- **Fixed-size window** — e.g. max sum of subarray of size K
- **Variable-size window** — expand right pointer, shrink left pointer when a constraint breaks
- **Fast & slow pointers** — cycle detection, finding the middle of a linked list

**Illustration — Variable sliding window (longest substring without repeating characters):**
```
s = "abcabcbb"

right→ a  b  c  a  b  c  b  b
left=0 window="a"        len=1
left=0 window="ab"       len=2
left=0 window="abc"      len=3
left=0 window="abca" → duplicate 'a' → shrink: left moves to 1
left=1 window="bca"      len=3
... continues, max length found = 3 ("abc")
```

**Core problems:** Max sum subarray of size K, longest substring without repeating chars, minimum window substring, longest repeating character replacement, fruit into baskets.

```cpp
// Longest substring without repeating characters — O(n)
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> lastSeen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left)
            left = lastSeen[s[right]] + 1;
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

---

### 7. Recursion & Backtracking

**What it is:** Backtracking is recursion with "undo" — try a choice, recurse, and if it doesn't lead to a valid solution, undo it and try the next choice. It systematically explores a decision tree while pruning invalid branches early.

**Key patterns:**
- Decision tree: at each step, either **include** or **exclude** the current element (subsets pattern)
- Constraint checking before recursing (pruning) to avoid wasted exploration
- Mark → Recurse → Unmark (the core backtracking template)

**Illustration — Subsets of `[1, 2]` (include/exclude tree):**
```
                    []
              /            \
          include 1      exclude 1
            [1]              []
           /    \           /    \
      incl 2   excl 2   incl 2  excl 2
     [1,2]      [1]       [2]     []

Final subsets: [], [1], [2], [1,2]
```

**Core problems:** Subsets, permutations, combination sum, N-Queens, Sudoku solver, rat in a maze, palindrome partitioning, word search.

```cpp
// Generate all subsets — O(2^n)
void backtrack(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res) {
    if (idx == nums.size()) {
        res.push_back(curr);
        return;
    }
    // exclude nums[idx]
    backtrack(idx + 1, nums, curr, res);
    // include nums[idx]
    curr.push_back(nums[idx]);
    backtrack(idx + 1, nums, curr, res);
    curr.pop_back(); // undo (backtrack)
}
```

---

### 8. Linked List

**What it is:** A chain of nodes where each node stores data and a pointer to the next (and optionally previous) node. Unlike arrays, insertion/deletion is O(1) once you have a reference to the node — no shifting required.

**Key patterns:**
- **Fast & slow pointers** — cycle detection (Floyd's), finding the middle
- **Dummy node** — simplifies edge cases in insertion/deletion at the head
- **In-place reversal** — reverse pointers iteratively without extra space

**Illustration — Floyd's Cycle Detection ("Tortoise and Hare"):**
```
1 → 2 → 3 → 4 → 5
        ↑         ↓
        8 ← 7 ← 6

slow moves 1 step, fast moves 2 steps per iteration.
If a cycle exists, fast eventually "laps" slow and they meet
inside the loop — proving a cycle exists in O(n) time, O(1) space.
```

**Core problems:** Reverse a linked list (iterative + recursive), detect & remove cycle, merge two sorted lists, find middle node, remove Nth node from end, add two numbers as linked lists, LRU cache design.

```cpp
// Reverse a singly linked list — O(n) time, O(1) space
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
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

### 9. Stacks & Queues

**What it is:** Stack = LIFO (Last In, First Out) — think a stack of plates. Queue = FIFO (First In, First Out) — think a checkout line. Both are typically built on arrays or linked lists.

**Why it matters:** Stacks power expression evaluation, backtracking's "undo" mechanism (implicitly, via the call stack), and the **monotonic stack** pattern for "next greater/smaller element" problems.

**Key patterns:**
- **Monotonic stack** — maintain elements in increasing/decreasing order to answer next-greater/smaller queries in O(n)
- **Two stacks → Queue** (and vice versa)
- Balanced parentheses via stack matching

**Illustration — Monotonic stack for "Next Greater Element":**
```
Array: [4, 5, 2, 25]

i=0: push 4          → stack=[4]
i=1: 5>4 → pop 4, NGE(4)=5 → push 5   → stack=[5]
i=2: 2<5 → push 2                     → stack=[5,2]
i=3: 25>2 → pop 2, NGE(2)=25
     25>5 → pop 5, NGE(5)=25 → push 25 → stack=[25]

Result: NGE(4)=5, NGE(5)=25, NGE(2)=25, NGE(25)=-1
```

**Core problems:** Valid parentheses, next greater/smaller element, min stack (O(1) getMin), implement queue using stacks, largest rectangle in histogram, sliding window maximum (using deque).

```cpp
// Next Greater Element — O(n) using monotonic stack
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // stores indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

---

### 10. Binary Trees

**What it is:** A hierarchical structure where each node has at most two children (left, right). The foundation for BSTs, heaps, and tries.

**Key patterns:**
- **DFS traversals** — Inorder (left-root-right), Preorder (root-left-right), Postorder (left-right-root)
- **BFS / Level-order traversal** — using a queue, processes the tree level by level
- **Recursive height/diameter/balance checks** — most tree problems reduce to "compute something for left and right subtree, then combine at the root"

**Illustration — Tree traversals:**
```
         1
        / \
       2   3
      / \
     4   5

Preorder  (root→left→right): 1 2 4 5 3
Inorder   (left→root→right): 4 2 5 1 3
Postorder (left→right→root): 4 5 2 3 1
Level-order (BFS):           1 2 3 4 5
```

**Core problems:** All four traversals (+ iterative versions), height of tree, diameter of tree, check balanced tree, lowest common ancestor (LCA), zig-zag traversal, serialize/deserialize tree, maximum path sum, boundary traversal.

```cpp
// Height of a binary tree — O(n), classic "combine left & right" pattern
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

### 11. Binary Search Trees

**What it is:** A binary tree with an ordering invariant: for every node, all values in the left subtree are smaller and all values in the right subtree are larger. This invariant makes search, insert, and delete O(log n) on average (O(h) where h is tree height).

**Key patterns:**
- Exploit the ordering to prune half the tree at each step (like binary search, but on a tree)
- **Inorder traversal of a BST always yields sorted order** — a hugely useful property
- Deletion has 3 cases: leaf node, one child, two children (replace with inorder successor/predecessor)

**Illustration — BST search for value 5:**
```
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \
         5   7

Search 5: 8 > 5 → go left → 3 < 5 → go right → 6 > 5 → go left → 5 == 5 ✅
Only 4 comparisons instead of checking all 7 nodes.
```

**Core problems:** Search/insert/delete in BST, validate BST, kth smallest element (via inorder), LCA in BST, floor/ceil in BST, convert sorted array to balanced BST, BST iterator.

```cpp
// Validate BST — O(n), pass down valid (min, max) bounds
bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}
```

---

### 12. Heaps & Priority Queues

**What it is:** A complete binary tree stored as an array, satisfying the heap property: in a **min-heap**, every parent ≤ its children (root = minimum); in a **max-heap**, every parent ≥ its children (root = maximum). Gives O(log n) insert/delete and O(1) access to the min/max.

**Key patterns:**
- "Top K" problems — maintain a heap of size K
- Merge K sorted lists using a min-heap of size K
- Two-heap technique for running median (max-heap for lower half, min-heap for upper half)

**Illustration — Min-heap as an array:**
```
Tree view:            Array view:
       2
     /   \             [2, 4, 5, 8, 9, 7]
    4     5              0  1  2  3  4  5
   / \   /
  8   9 7

Parent of index i  → (i-1)/2
Left child of i    → 2i + 1
Right child of i   → 2i + 2
```

**Core problems:** Kth largest element in a stream, top K frequent elements, merge K sorted lists, find median from data stream, task scheduler, implement heap from scratch (heapify).

```cpp
// Kth largest element in an array using a min-heap of size K — O(n log k)
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}
```

---

### 13. Greedy Algorithms

**What it is:** Making the locally optimal choice at every step, hoping (and, when provably correct, guaranteeing) it leads to the globally optimal solution. Greedy works only when the problem has the **greedy-choice property** and **optimal substructure** — recognizing when it applies is the real skill.

**Key patterns:**
- Sort first, then make greedy choices in that order (e.g. by end time, by ratio, by deadline)
- Exchange argument — the standard way to *prove* a greedy strategy is correct
- Interval scheduling — sort by end time, always pick the interval that finishes earliest

**Illustration — Activity Selection (interval scheduling):**
```
Activities (start, end): (1,4) (3,5) (0,6) (5,7) (3,9) (5,9) (6,10) (8,11) (8,12) (2,14) (12,16)

Sort by END time, then greedily pick any activity whose
start ≥ end of last picked activity:

Picked: (1,4) → (5,7) → (8,11) → (12,16)   = 4 activities, maximum possible
```

**Core problems:** Activity selection, fractional knapsack, job sequencing with deadlines, minimum platforms, Huffman encoding, gas station, jump game.

```cpp
// Fractional Knapsack — O(n log n), greedy by value/weight ratio
double fractionalKnapsack(vector<pair<int,int>>& items, int capacity) {
    // items = {value, weight}
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });
    double totalValue = 0.0;
    for (auto& [value, weight] : items) {
        if (capacity >= weight) {
            capacity -= weight;
            totalValue += value;
        } else {
            totalValue += value * ((double)capacity / weight);
            break;
        }
    }
    return totalValue;
}
```

---

### 14. Graphs

**What it is:** A collection of nodes (vertices) connected by edges — the most general-purpose data structure, modeling everything from social networks to road maps to dependency chains.

**Key patterns:**
- **BFS** — shortest path in unweighted graphs, level-by-level exploration
- **DFS** — connectivity, cycle detection, topological sort
- **Union-Find (Disjoint Set Union)** — efficiently track connected components, detect cycles in O(α(n)) ~ O(1)
- **Dijkstra's Algorithm** — shortest path in weighted graphs with non-negative weights (min-heap based)
- **Topological Sort** — valid ordering of nodes in a DAG (used for task scheduling / dependency resolution)

**Illustration — BFS vs DFS traversal order:**
```
Graph:        1
             / \
            2   3
           /     \
          4       5

BFS from 1: 1 → 2 → 3 → 4 → 5   (level by level, using a queue)
DFS from 1: 1 → 2 → 4 → 3 → 5   (goes deep first, using recursion/stack)
```

**Core problems:** Number of islands, course schedule (cycle detection + topo sort), Dijkstra's shortest path, Kruskal's/Prim's MST, clone graph, word ladder, flood fill, rotten oranges (multi-source BFS).

```cpp
// BFS traversal — O(V + E)
void bfs(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

### 15. Dynamic Programming

**What it is:** An optimization technique for problems with **overlapping sub-problems** and **optimal substructure** — instead of recomputing the same sub-problem repeatedly (like naive recursion does), DP stores results and reuses them.

**Why it matters:** This is where recursion "grows up." Recognizing that a recursion tree has repeated branches (and can be collapsed into a DAG of sub-problems) is the single biggest unlock in DSA prep.

**Key patterns:**
- **Memoization (top-down)** — recursion + a cache (`dp[]` array or hash map)
- **Tabulation (bottom-up)** — build the answer iteratively from base cases upward
- **Space optimization** — most 2D DP problems reduce to O(n) or O(1) space once you notice you only need the previous row/state
- Classic families: 0/1 Knapsack, Unbounded Knapsack, Longest Common Subsequence (LCS), Longest Increasing Subsequence (LIS), Matrix Chain Multiplication, DP on grids, DP on trees

**Illustration — Fibonacci: naive recursion vs. memoized DP:**
```
Naive recursion tree for fib(5) — note the REPEATED sub-calls:

                    fib(5)
                 /          \
            fib(4)          fib(3)
           /      \         /    \
       fib(3)   fib(2)  fib(2)  fib(1)
       /   \      ...     ...
   fib(2) fib(1)
   
fib(3) and fib(2) are computed multiple times → wasted work → O(2^n)

With memoization: each fib(k) is computed ONCE and cached → O(n)
dp[] = [0, 1, 1, 2, 3, 5]
```

**Core problems:** Climbing stairs, 0/1 knapsack, coin change, LCS, LIS, edit distance, matrix chain multiplication, house robber, partition equal subset sum, unique paths, maximum path sum in grid.

```cpp
// 0/1 Knapsack — O(n * capacity) time & space (tabulation)
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i-1][w]; // don't take item i
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
        }
    }
    return dp[n][capacity];
}
```

---

### 16. Trie

**What it is:** A tree-like structure specialized for storing strings, where each path from root to a node represents a prefix. Enables O(L) prefix/word lookups regardless of how many words are stored (L = word length).

**Key patterns:**
- Each node holds an array/map of children (one per possible character) + an `isEndOfWord` flag
- Prefix search: walk the trie character by character; if you fall off the trie, the prefix doesn't exist
- Common uses: autocomplete, spell-checkers, IP routing (longest prefix match)

**Illustration — Trie storing "cat", "car", "dog":**
```
              (root)
             /      \
            c        d
            |        |
            a        o
           / \        \
          t   r        g
          •   •        •
      ("cat") ("car") ("dog")   • = end of word marker
```

**Core problems:** Implement Trie (insert/search/startsWith), word search II (trie + backtracking), longest word with all prefixes, maximum XOR of two numbers (binary trie).

```cpp
// Trie implementation
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }
};
```

---

### 17. Bit Manipulation

**What it is:** Directly operating on the binary representation of numbers using bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`). Often the difference between an O(n) space solution and an O(1) space one.

**Key patterns:**
- `n & (n-1)` clears the lowest set bit — used to count set bits, check power of 2
- `n & -n` isolates the lowest set bit
- XOR trick — `a ^ a = 0` and `a ^ 0 = a`, so XOR-ing all elements cancels out pairs, leaving the unpaired one (single number problem)
- Bitmasking for subsets — representing a subset of `n` elements as an `n`-bit integer, iterating `0` to `2^n - 1`

**Illustration — Finding the single non-duplicate number via XOR:**
```
Array: [4, 1, 2, 1, 2]

4 ^ 1 = 0101
0101 ^ 2 = 0111
0111 ^ 1 = 0110
0110 ^ 2 = 0100  = 4  ✅ (the number that appears once)

Every number that appears twice cancels itself out (a^a=0),
leaving only the unpaired number — O(n) time, O(1) space.
```

**Core problems:** Single number, count set bits (Brian Kernighan's algorithm), check power of 2, subsets using bitmasking, XOR of numbers in a range, swap two numbers without a temp variable.

```cpp
// Count set bits — O(number of set bits), Brian Kernighan's algorithm
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); // clears the lowest set bit
        count++;
    }
    return count;
}
```

---

## ⏱ Complexity Cheat Sheet

| Data Structure | Access | Search | Insertion | Deletion |
|---|---|---|---|---|
| Array | O(1) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1)* | O(1)* |
| Stack / Queue | O(n) | O(n) | O(1) | O(1) |
| Hash Table | — | O(1) avg | O(1) avg | O(1) avg |
| Binary Search Tree (balanced) | O(log n) | O(log n) | O(log n) | O(log n) |
| Heap | O(1) top | O(n) | O(log n) | O(log n) |
| Trie | — | O(L) | O(L) | O(L) |

<sub>*O(1) once you have a reference to the node.</sub>

| Sorting Algorithm | Time (avg) | Space |
|---|---|---|
| Merge Sort | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(log n) |
| Heap Sort | O(n log n) | O(1) |
| Counting Sort | O(n + k) | O(k) |

---

## 📚 Resources

- [Striver's A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/) — primary structured sheet followed in this repo
- [LeetCode](https://leetcode.com/) — problem practice
- [Codeforces](https://codeforces.com/) — competitive programming rounds
- [CP-Algorithms](https://cp-algorithms.com/) — deep dives into advanced algorithms

---

## 🤝 Connect With Me

**Rudra**
B.S. Data Science & AI, IIT Guwahati

- 🌐 Portfolio: [rudra-iitg.github.io/rudrajha](https://rudra-iitg.github.io/rudrajha)
- 💼 GitHub: [@Rudra-iitg](https://github.com/Rudra-iitg)
- 🔗 LinkedIn: [rudra-jha-iitg](https://linkedin.com/in/rudra-jha-iitg)

---

<div align="center">

**⭐ If you find this repo useful for your own DSA journey, consider giving it a star!**

</div>
