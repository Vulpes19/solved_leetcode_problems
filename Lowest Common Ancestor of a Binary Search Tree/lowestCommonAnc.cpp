#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode    *newNode(int x)
{
    TreeNode *node = new TreeNode(x);
    return (node);
}

void dfs( TreeNode *root, vector<pair<int, int> > &depths )
{
     int depth = 0;
     stack<TreeNode *> s;

     s.push(root);
     while ( !s.empty() )
     {
          TreeNode *current = s.top();
          s.pop();
          if (current == NULL)     continue;
          depths.emplace_back(current->val, depth + 1);
          ++depth;
          s.push(root->left);
          s.push(root->right);

     }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
     vector<pair<int, int> > depths;
     TreeNode *head = root;
     dfs(root, depths);
     for (unsigned int i = 0; i < depths.size(); i++)
     {
          cout << depths[i].first << " " << depths[i].second << endl;
     }
     return (head);
}

int  main( void )
{
     TreeNode *root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    lowestCommonAncestor(root, root->left, root->right);
}
