#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode    *newNode(int x)
{
    TreeNode *node = new TreeNode(x);
    return (node);
}

 TreeNode   *invertTree( TreeNode *root)
 {
    if (root == NULL)
        return (root);
    TreeNode *rootNode = root;
    TreeNode *tmp = root->left;
    root->left = root->right; 
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return (rootNode);
 }

int main( void )
{
    TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    TreeNode *ret = invertTree(root);
    cout << ret->val << endl;
    cout << ret->left->val << endl;
}