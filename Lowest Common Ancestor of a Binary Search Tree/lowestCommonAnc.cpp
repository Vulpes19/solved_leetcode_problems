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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	TreeNode *head = root;
	TreeNode	*anc = nullptr;
	bool ifp = false;
	bool ifq = false;
	if (root == nullptr)
		return (nullptr);
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* node = st.top();
		st.pop();
		// if ( node->val == 0 )
		// 	exit(1);
		// cout << node->val << " "; // process current node
		if (node->right != nullptr) {
			st.push(node->right); // push right child onto stack
		}
		if ( node->right != nullptr && node->right->val == q->val)
		{
			cout << "hello q\n";
			anc = newNode(node->val);
			ifq = true;
		}
		if (node->left != nullptr)
			st.push(node->left); // push left child onto stack
		if ( node->left != nullptr && node->left->val == p->val && anc && anc->val == node->val )
		{
			std::cout << "hello p\n";
			ifp = true;
		}
		if ( ifq && ifp )
			return ( node );
	}
	return (nullptr);
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
    TreeNode *ret = lowestCommonAncestor(root, root->left, root->left->right);
    if (ret != nullptr)
	cout << ret->val << endl;
}
