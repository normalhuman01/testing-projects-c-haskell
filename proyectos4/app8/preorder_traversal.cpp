#include "preorder_traversal.h"
#include <iostream>

// Implementación de la función preorderTraversal
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Visitar el nodo actual
    std::cout << root->data << " ";
    
    // Recorrer la rama izquierda
    preorderTraversal(root->left);
    
    // Recorrer la rama derecha
    preorderTraversal(root->right);
}
