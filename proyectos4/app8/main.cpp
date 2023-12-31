#include <iostream>
#include "preorder_traversal.h"

int main() {
    // Crear un árbol de ejemplo
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    // Llamar a la función de recorrido preorder
    std::cout << "Recorrido Preorder: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Liberar memoria (liberación del árbol)
    // ...

    return 0;
}
