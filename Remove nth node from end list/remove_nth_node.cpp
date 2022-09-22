
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
    int getSize(ListNode *list)
    {
        int len = 0;
        while (list)
        {
            len++;
            list = list->next;
        }
        return (len);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        ListNode *res = head;
        if (size == n)
        {
            res = head->next;
            delete (head);
            return (res);
        }
        size -= n;
        int i = 0;
        ListNode *prev = NULL;

        while (head)
        {
            if (i == size)
            {
                prev->next = head->next;
                delete (head);
                break ;
            }
            i++;
            prev = head;
            head = head->next;
        }
        return (res);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head;
        while (n--)
            current = current->next;
        ListNode *prev = NULL;
        while (current) {
            current = current->next;
            prev = prev ? prev->next : head;
        }
        if (prev == NULL)
        {
            current = head->next;
            delete head;
            return current;
        }
        current = prev->next->next;
        delete prev->next;
        prev->next = current;
        return head;
        
    }
};