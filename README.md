<div align="center">

# Logic Gate Converter
### *Binary Logic Tree Transformation & Universal Gate Synthesis*

![C++17](https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=flat&logo=cplusplus&logoColor=white)
![UF Engineering](https://img.shields.io/badge/University%20of%20Florida-EE-FA4616?style=flat&logo=university-of-florida&logoColor=white)
![Status](https://img.shields.io/badge/Project-Digital%20Logic-blueviolet?style=flat)

**Developed by Davis Lester**
*Sophomore Electrical Engineering Student & Peer Advisor @ University of Florida*

---

### 🚀 Overview
The **GateConverter** is a specialized C++ utility designed to transform standard binary logic trees (AND, OR, NOT) into functionally equivalent trees composed exclusively of **NAND** and **NOT** gates. This transformation is fundamental in hardware design, where NAND gates are often preferred due to their status as **Universal Gates**.

</div>

---

### 🧬 Universal Gate Logic
In digital logic design, any Boolean function can be implemented using only NAND gates. This library automates the structural conversion of logic trees to prepare them for cost optimization and physical synthesis.




#### **Implemented Transformations**
1. **AND(A, B)** $\rightarrow$ `NOT(NAND(A, B))`
2. **OR(A, B)** $\rightarrow$ `NAND(NOT(A), NOT(B))`
3. **Inputs (IN)** $\rightarrow$ Remain unchanged as tree leaves.

---

### 🛠️ Technical Implementation
The converter utilizes a **Post-Order Traversal** algorithm to ensure that all child nodes are converted before their parent gates are processed, maintaining logical integrity throughout the recursion.

* **Recursion Strategy**: The `toNandNot` function recursively visits left and right children before applying transformation rules to the current `root`.
* **Name Normalization**: Automatically updates node names (e.g., adding `INV_` or `_NAND` suffixes) to track the transformation history of each gate.
* **MinCost Compatibility**: The conversion logic intentionally avoids premature optimization (like removing double-NOT gates) to preserve structural patterns required for downstream Minimum Cost calculation algorithms.

---

### 📦 Integration
Include the converter in your logic synthesis projects:

```cpp
#include "GateConverter.cpp"
#include "TreeNode.hpp"

// Example Usage
TreeNode* myLogicTree = buildSampleTree(); 
TreeNode* nandTree = toNandNot(myLogicTree);
```

<div align="center">

</div>