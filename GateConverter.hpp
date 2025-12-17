#pragma once

// File name : GateConverter.cpp
// Last edited : 11/27/2025
// Author : Davis Lester
// Description : Creating Functions to convert binary logic trees to include only NAND gates and NOT gates that are logically equivilant

// Local Includes
#include "TreeNode.hpp"

//╭━━━╮╱╱╭╮╱╱╱╭━━━╮╱╱╱╱╱╱╱╱╱╱╱╱╱╭╮╱╱╱╱╱╭╮
//┃╭━╮┃╱╭╯╰╮╱╱┃╭━╮┃╱╱╱╱╱╱╱╱╱╱╱╱╭╯╰╮╱╱╱╱┃┃
//┃┃╱╰╋━┻╮╭╋━━┫┃╱╰╋━━┳━╮╭╮╭┳━━┳┻╮╭╋━━┳━┫╰━┳━━┳━━╮
//┃┃╭━┫╭╮┃┃┃┃━┫┃╱╭┫╭╮┃╭╮┫╰╯┃┃━┫╭┫┃┃┃━┫╭┫╭╮┃╭╮┃╭╮┃
//┃╰┻━┃╭╮┃╰┫┃━┫╰━╯┃╰╯┃┃┃┣╮╭┫┃━┫┃┃╰┫┃━┫┣┫┃┃┃╰╯┃╰╯┃
//╰━━━┻╯╰┻━┻━━┻━━━┻━━┻╯╰╯╰╯╰━━┻╯╰━┻━━┻┻┻╯╰┫╭━┫╭━╯
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱┃┃╱┃┃
//╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╱╰╯╱╰╯

/**
 * @brief Converts a logic tree rooted at 'root' into a NAND-NOT tree
 * @param root a pointer to a TreeNode structure containing the start of a tree composed of logic gates
 */
TreeNode* toNandNot(TreeNode* root);