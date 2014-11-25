#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* get_node(ListNode* node, int n)
{
	while (n > 0 && node != NULL)
	{
		n--;
		node = node->next;
	}
	return node;
}

bool check_node(ListNode* node, int i, int len)
{
	return (node != NULL && i < len);
}

ListNode* next_node(ListNode* node, int& i)
{
	i++;
	return node->next;
}

ListNode* add_node(ListNode* result, ListNode* node)
{
	if (result == NULL) return node;

	result->next = node;
	return result->next;
}

ListNode* merge_sort(ListNode* left, int len)
{
	ListNode* right = get_node(left, len);
	if (right == NULL) return right;

	ListNode* result = NULL;
	
	int left_count = 0;
	int right_count = 0;

	while(check_node(left, left_count, len) && 
		  check_node(right, right_count, len))
	{
		if (left->val <= right->val)
		{
			result = add_node(result, left);
			left = next_node(left, left_count);
		}
		else
		{
			result = add_node(result, right);
			right = next_node(right, right_count);
		}
	}

	while (check_node(left, left_count, len))
	{
		result = add_node(result, left);
		left = next_node(left, left_count);
	}

	while (check_node(right, right_count, len))
	{
		result = add_node(result, right);
		right = next_node(right, right_count);
	}

	return result;
}

int list_len(List* head)
{
	int count = 0;
	while (head != NULL)
	{		
		count++;
		head = head->next;
	}

	return count;
}


ListNode* merge_sort(List* head)
{
	int len = list_len(head);
	int merge_len = 1;
	while (merge_len < len)
	{
		ListNode* first = head;
		while (first != NULL) 
		{
			first = merge_sort(first, len);
		}

		len *= 2;
	}

	return head;
}

ListNode* partition(ListNode* pBegin, ListNode* pEnd)
{
	int key = pBegin->val;  
	ListNode* p = pBegin;  
	ListNode* q = p->next;  
  
	while(q != pEnd)  
	{  
		if(q->val < key)  
		{  
			p = p->next;  
			swap(p->val,q->val);  
		}  
  
		q = q->next;  
	} 
	
	swap(p->val,pBegin->val);
	return p;  
}

void quick_sort(ListNode* pBeign, ListNode* pEnd)
{
	if(pBeign != pEnd)  
	{  
		ListNode* partion = partition(pBeign,pEnd);  
		quick_sort(pBeign,partion);
		quick_sort(partion->next,pEnd);
	}
}


ListNode *sortList(ListNode *head) {
	if (head == NULL) return NULL;
	quick_sort(head, NULL);
	return head;
}


int main(int n, char* args[])
{

	return 0;
}

