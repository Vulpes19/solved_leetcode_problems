#include <iostream>
#include<vector>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
    //   ListNode() : val(0), next(nullptr) {}
    //   ListNode(int x) : val(x), next(nullptr) {}
    //   ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void    initList(struct ListNode *head, int val)
{
    head->val = val;
    head->next = NULL;
}

void display(struct ListNode *head) {
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
            node->next = newNode;
            return ;
        }
        node = node->next;
    }
}

int     getListSize(struct ListNode *head)
{
    int len;

    len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return (len);
}
bool    isPalindrome(struct ListNode *head)
{
    int listSize;
    int size;
    int i;

    i = 0;
    listSize = getListSize(head);
    if (listSize % 2 == 0)
        size = listSize / 2;
    else
        size = (listSize - 1) / 2;
    vector<int> front(listSize);
    vector<int> back(listSize);
    while (head)
    {
        front[i] == head->val;
        i++;
        if (i + 1 == listSize)
        {
            cout << "hello" << endl;
            if (listSize % 2 != 0)
                head = head->next;
            while (head)
                back[i] = head->val;
                head = head->next;
                i--;
        }
        head = head->next ;
    }
    i = 0;
    while (front[i] && back[i])
    {
        cout << front[i] << back[i] << endl;
        if (front[i] != back[i])
        {
            cout << "false" << endl;
            return (false);
        }
        i++;
    }
    cout << "truee" << endl;
    return (true);
}

int main()
{
    struct ListNode *head;
    initList(head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 1);
    printf("%d\n", isPalindrome(head));
    // cout << isPalindrome(head) << endl;
//    display(head);
}