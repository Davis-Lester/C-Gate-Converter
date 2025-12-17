// File name : GateConverter.cpp
// Last edited : 11/27/2025
// Author : Davis Lester
// Description : Creating Functions to convert binary logic trees to include only NAND gates and NOT gates that are logically equivilant

// Standard Includes
#include <iostream>

// Local Includes
#include "TreeNode.hpp"

using namespace std;

//╭━━━╮╱╱╭╮╱╱╱╭━━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮
//┃╭━╮┃╱╭╯╰╮╱╱┃╭━╮┃╱╱╱╱╱╱╱╱╱╱╱╱╭╯╰╮
//┃┃╱╰╋━┻╮╭╋━━┫┃╱╰╋━━┳━╮╭╮╭┳━━┳┻╮╭╋━━┳━┳━━┳━━┳━━╮
//┃┃╭━┫╭╮┃┃┃┃━┫┃╱╭┫╭╮┃╭╮┫╰╯┃┃━┫╭┫┃┃┃━┫╭┫╭━┫╭╮┃╭╮┃
//┃╰┻━┃╭╮┃╰┫┃━┫╰━╯┃╰╯┃┃┃┣╮╭┫┃━┫┃┃╰┫┃━┫┣┫╰━┫╰╯┃╰╯┃
//╰━━━┻╯╰┻━┻━━┻━━━┻━━┻╯╰╯╰╯╰━━┻╯╰━┻━━┻┻┻━━┫╭━┫╭━╯
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃╱┃┃
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯╱╰╯

// ───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
//   OR Gate                                ║║    NAND Equivalent
//                                          ║║                       |‾‾‾‾‾‾\                                           
//               \‾‾‾‾‾‾\                   ║║       A ────────┬─────|       \                                         
//     A──────────\      \                  ║║                 |     | NAND   |o───────┐                                      
//                 |  OR  |─────── Output   ║║                 └─────|       /         |                      
//     B──────────/      /                  ║║                       |______/          |                               
//               /______/                   ║║                                         |     |‾‾‾‾‾‾\                  
//                                          ║║                                         └─────|       \               
//                                          ║║                                               | NAND   |o──────── Output  
//                                          ║║                                         ┌─────|       /                 
//                                          ║║                       |‾‾‾‾‾‾\          |     |______/                  
//                                          ║║       B ────────┬─────|       \         |                               
//                                          ║║                 |     | NAND   |o───────┘                               
//                                          ║║                 └─────|       /                                      
//                                          ║║                       |______/ 
//                                          ║║
// ───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────

/**
 * @brief Converts a logic tree rooted at 'root' into a NAND-NOT tree
 * @param root a pointer to a TreeNode structure containing the start of a tree composed of logic gates
 */
TreeNode* toNandNot(TreeNode* root) {

    // Naming Convention is to add INV for NOT gates

    // Inputs do not need to be changed
    if (!root || root->operation == "IN") return root;

    // Post-order traversal
    if (root->left) root->left = toNandNot(root->left);
    if (root->right) root->right = toNandNot(root->right);

    // Convert AND to NAND and NOT
    if (root->operation == "AND") {
        // AND(A, B) -> NOT( NAND(A, B) )
        root->operation = "NAND";
        root->name += "_NAND";
        return new TreeNode("NOT", "INV_" + root->name, root, nullptr);
    }

    // Convert OR to NANDS
    else if (root->operation == "OR") {
        // OR(A, B) -> NAND( NOT(A), NOT(B) )
        // NO OPTIMIZATION: Always add NOTs. This preserves patterns for MinCost.
        // Previously, removed instances of double NOT gates, but this caused errors in MinCost calculation
        root->operation = "NAND";
        root->name += "_NAND";
        
        root->left = new TreeNode("NOT", "INV_L", root->left, nullptr);
        root->right = new TreeNode("NOT", "INV_R", root->right, nullptr);
        
        return root;
    }
    
    return root;
}