#include <iostream>
#include <vector>

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
		cout << list->val << ' ';
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

unsigned long long     getListSize(struct ListNode *head)
{
   unsigned long long len;
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

int *copyToArray(int *arr, struct ListNode *head, unsigned long long size)
{
	size -= 1;
	while (head && size >= 0)
	{
		arr[size] = head->val;
		head = head->next;
		size--;
	}
	return (arr);
}

unsigned long long	arrToNumber(int *arr, unsigned long long size)
{
	unsigned long long res;

	res = arr[0];
	if (size == 1)
		return (res);
	for (int i = 1; i < size; i++)
	{
		res *= 10;
		res += arr[i];
	}
	return (res);
}

int	getNbrSize(unsigned long long int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

ListNode *getResList(unsigned long long int nbr, unsigned long long int size)
{
	vector <int> res;
	struct ListNode *node;

	while (true)
	{
		res.insert(res.end(), nbr % 10);
		nbr /= 10;
		if (nbr == 0)
			break ;
	}
	node = initList(node, res[0]);
	for (int i = 1; i < size; i++)
	{
		addNode(&node, res[i]);
	}
	return (node);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	unsigned long long	size1;
	unsigned long long	size2;
	int	*nbr1;
	int *nbr2;
	unsigned long long int nbr_res1;
	unsigned long long int nbr_res2;
	unsigned long long int nbr_sum;
	struct ListNode *res;
	
	size1 = getListSize(l1);
	nbr1 = new int[size1];
	nbr1 = copyToArray(nbr1, l1, size1);
	size2 = getListSize(l2);
	nbr2 = new int[size2];
	nbr2 = copyToArray(nbr2, l2, size2);
	nbr_res1 = arrToNumber(nbr1, size1);
	cout << nbr_res1 << endl;
	nbr_res2 = arrToNumber(nbr2, size2);
	cout << nbr_res2 << endl;
	nbr_sum = nbr_res1 + nbr_res2;
	res = getResList(nbr_sum, getNbrSize(nbr_sum));
	return (res);
}

int main(void)
{
	struct ListNode *list1;
	struct ListNode *list2;
	struct ListNode *res;
	

    /* you can edit the list here */
	list1 = initList(list1, 1);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 0);
	addNode(&list1, 1);

	list2 = initList(list2, 5);
	addNode(&list2, 6);
	addNode(&list2, 4);

	display(addTwoNumbers(list1, list2));
}