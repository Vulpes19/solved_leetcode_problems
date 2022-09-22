 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    size_t getSize(ListNode *list)
    {
        size_t len = 0;
        while (list)
        {
            len++;
            list = list->next;
        }
        return (len);
    }

    ListNode* rotateRight(ListNode* head, int k) {
        size_t size = getSize(head);
        if (size <= 1 || k % size == 0)
            return (head);
        if (size == 2)
        {
            if (k % size == 0)
                return (head);
            else
            {
                ListNode *node = head->next;
                node->next = head;
                node->next->next = NULL;
                return (node);
            }
        }
        ListNode *list = head;
        k %= size;
        k = size - k - 1;
        while (k--)
            list = list->next;
        ListNode *prev_head = head;
        ListNode *new_head = list->next;
        head = list->next;
        list->next = NULL;
        while (new_head->next)
            new_head = new_head->next;
        new_head->next = prev_head;
        return (head);
    }
};