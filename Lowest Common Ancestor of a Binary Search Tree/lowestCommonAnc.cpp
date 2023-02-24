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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if ( root == nullptr )
		return ( nullptr );
	if ( root->val == p->val || root->val == q->val )
		return ( root );
	TreeNode *lca_left = lowestCommonAncestor( root->left, p, q );
	TreeNode *lca_right = lowestCommonAncestor( root->right, p, q );
	if ( lca_left && lca_right )
		return ( root );
	return (lca_left == nullptr ) ? lca_right : lca_left;
}

int  main( void )
{
	// TreeNode *root = newNode(2);
    // root->right = newNode(1);
	TreeNode *root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    TreeNode *ret = lowestCommonAncestor(root, root->left->left, root->right->left);
    if (ret != nullptr)
	cout << ret->val << endl;
}
