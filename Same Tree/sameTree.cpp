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
class Solution {
public:
    void    check( TreeNode* p, TreeNode* q, bool &test )
    {
        if ( p == nullptr && q == nullptr )
        {
            test = true;
            return;
        }
        if ( p == nullptr || q == nullptr )
        {
            test = false;
            return;
        }
        if ( p->val != q->val )
        {
            test = false;
            return;
        }
        check(p->left, q->left, test);
        if ( test == false )
            return ;
        check(p->right, q->right, test);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ret = false;
        check(p, q, ret);
        return (ret);
    }
};