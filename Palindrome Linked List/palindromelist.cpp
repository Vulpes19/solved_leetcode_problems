#include <iostream>
#include<vector>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
  };

ListNode    *initList(struct ListNode *head, int val)
{
    head = new ListNode;
    head->val = val;
    head->next = NULL;
    return (head);
}

void display(struct ListNode *head)
{
	struct ListNode *list = head;
	while(list) 
    {
		cout << list->val << endl;
		list = list->next;
	}
}

void    addNode(struct ListNode **head, int val)
{
    struct ListNode *newNode;
    struct ListNode *node;

    node = *head;
    newNode = new ListNode;
    newNode->val = val;
    newNode->next = NULL;
    while (node)
    {
        if (node->next == NULL)
        {
    // exit(1);
            node->next = newNode;
            return ;
        }
        node = node->next;
    }
}

int     getListSize(struct ListNode *head)
{
    int len;
    struct ListNode *tmp;

    tmp = head;
    len = 0;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    return (len);
}


ListNode *reverseList(struct ListNode *head) {
    struct ListNode *temp = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return (prev);
}

int *copyToArr(int *arr, struct ListNode *head, int n)
{
    struct ListNode *node;
    
    node = head;
    for(int i = 0; i < n; i++)
    {
        arr[i] = node->val;
        node = node->next;
    }
    return (arr);
}
bool    isPalindrome(struct ListNode *head)
{
    int listSize;
    struct ListNode *reversedList;
    int size;
    int i;
    int *arr;

    i = 0;
    listSize = getListSize(head);
    arr = new int[listSize/2];
    arr = copyToArr(arr, head, listSize/2);
    reversedList = reverseList(head);
    size = listSize / 2;
    while ( i < size)
    {
        if (arr[i] != reversedList->val)
            return (false);
        reversedList = reversedList->next;
        i++;
    }
    return (true);
}

int main()
{
    struct ListNode *head;
    /* you can edit the list here */
    head = initList(head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 2);
    addNode(&head, 1);
    /*add as many nodes as you want */
    cout << isPalindrome(head) << endl;
}