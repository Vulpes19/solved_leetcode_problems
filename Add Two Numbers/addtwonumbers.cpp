/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int			left = 0;
		ListNode	*head = NULL;
		ListNode	*last = NULL;

		while (l1 || l2)
		{
			int v_l1 = l1 ? l1->val : 0;
			int v_l2 = l2 ? l2->val : 0;
			int sum = v_l1 + v_l2 + left;
			ListNode *new_node = new ListNode(sum % 10, NULL);
			left = sum / 10;
			if (head == NULL)
				head = new_node;
			else
				last->next = new_node;
			last = new_node;
			if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
		}
		if (left != 0)
			last->next = new ListNode(left, NULL);
		return head;
        
    }
};

