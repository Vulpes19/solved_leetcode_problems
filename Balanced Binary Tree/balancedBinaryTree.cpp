#include <iostream>

using namespace std;

struct TreeNode
{
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

int   countLen( TreeNode *node, int len )
{
      if ( node == NULL ) return (len);
      len += countLen(node, len);
      return (len);
}

bool	isBalanced(TreeNode *root)
{
      int len1, len2;

      len1 = countLen(root->right, 1);
      len2 = countLen(root->left, 1);

      if ( len1 == len2 )
            return (true);
      else
            return (false);
}

int main( void )
{
    TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
//     root->left->left = newNode(1);
//     root->left->right = newNode(3);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    cout << isBalanced(root) << endl;
}