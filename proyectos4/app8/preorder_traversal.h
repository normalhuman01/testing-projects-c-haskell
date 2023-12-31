#ifndef PREORDER_TRAVERSAL_H
#define PREORDER_TRAVERSAL_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Declaración de la función preorderTraversal
void preorderTraversal(TreeNode* root);

#endif
