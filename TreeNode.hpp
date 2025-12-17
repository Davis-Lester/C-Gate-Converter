#pragma once

// File name : TreeNode.hpp
// Last edited : 11/27/2025
// Author : Davis Lester
// Description : Creating a structure to hold valuable information in gate logic creation

#include <iostream>
#include <string>

using namespace std;

//╭━━━━╮╱╱╱╱╱╱╭━╮╱╭╮╱╱╱╱╭╮╱╱╱╭╮
//┃╭╮╭╮┃╱╱╱╱╱╱┃┃╰╮┃┃╱╱╱╱┃┃╱╱╱┃┃
//╰╯┃┃┣┻┳━━┳━━┫╭╮╰╯┣━━┳━╯┣━━╮┃╰━┳━━┳━━╮
//╱╱┃┃┃╭┫┃━┫┃━┫┃╰╮┃┃╭╮┃╭╮┃┃━┫┃╭╮┃╭╮┃╭╮┃
//╱╱┃┃┃┃┃┃━┫┃━┫┃╱┃┃┃╰╯┃╰╯┃┃━╋┫┃┃┃╰╯┃╰╯┃
//╱╱╰╯╰╯╰━━┻━━┻╯╱╰━┻━━┻━━┻━━┻┻╯╰┫╭━┫╭━╯
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃╱┃┃
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯╱╰╯

struct TreeNode {
    string operation; // Gate type ; IN, OR, NAND, NOT, AND, etc.
    string name;      // Gate Name (optional)
    TreeNode* left;   // Pointer to the left input
    TreeNode* right;  // Pointer to the right input

    // Custom Constructor
    TreeNode(string op, string n = "", TreeNode* l=nullptr, TreeNode* r=nullptr) : operation(op), name(n), left(l), right(r){ }
};