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
    void    check( TreeNode* p, TreeNode* q, bool &isSame )
    {
        if ( p == nullptr && q == nullptr )
        {
            isSame = true;
            return;
        }
        if ( p == nullptr || q == nullptr )
        {
            isSame = false;
            return;
        }
        if ( p->val != q->val )
        {
            isSame = false;
            return;
        }
        check(p->left, q->left, isSame);
        if ( isSame == false )
            return ;
        check(p->right, q->right, isSame);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ret = false;
        check(p, q, ret);
        return (ret);
    }
};