#include <iostream>

struct Node
{
	int data;
	struct Node* next;
};

void display(struct Node *p)
{
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void rDisplay(struct Node *p)
{
	printf("%d ", p->data);

	if (p->next != NULL)
		rDisplay(p->next);
}

int count(struct Node *p)
{
	int count = 0;

	while (p != NULL)
	{
		count++;
		p = p->next;
	}

	return count;
}

int rCount(struct Node *p)
{
	if (p == NULL)
		return 0;

	return rCount(p->next) + 1;
}

int sum(struct Node *p)
{
	int sum = 0;

	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}

	return sum;
}

int rSum(struct Node *p)
{
	if (p == NULL)
		return 0;

	return rSum(p->next) + p->data;
}

int max(struct Node *p)
{
	int max = p->data;
	p = p->next;

	while (p != NULL)
	{
		if (p->data > max)
			max = p->data;

		p = p->next;
	}

	return max;
}

int rMax(struct Node* p)
{
	int x = 0;

	if (p == NULL)
		return INT_MIN;

	x = rMax(p->next);

	if (p->data > x)
		return p->data;
	return (p-> data > x) ? p->data : x;
}

Node *search(struct Node *p, int key)
{
	Node *q = NULL;

	while (p != NULL)
	{
		if (p->data = key)
		{


			return p;
		}

		q = p;
		p = p->next;
	}

	return NULL;
}

Node *rSearch(Node *p, int key)
{
	if (p == NULL)
		return NULL;

	return (p->data == key) ? p : rSearch(p->next, key);
}

void moveToFront(Node **head)
{
	Node *secondLast = NULL;
	Node *last = *head;

	while (last->next != NULL)
	{
		secondLast = last;
		last = last->next;
	}

	secondLast->next = NULL;
	last->next = *head;
	*head = last;
}

void moveToFront1(Node** head, Node* key)
{
	Node *secondLast = NULL;
	Node *last = *head;

	while (last != key)
	{
		secondLast = last;
		last = last->next;
	}

	secondLast->next = last->next;
	last->next = *head;
	*head = last;
}

void add(Node** head, Node* key, int data)
{
	Node* step = *head;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;

	if (*head == key)
	{
		n->next = *head;
		*head = n;
		return;
	}

	n->next = key->next;
	key->next = n;
}

void sortedInsert(Node** head, int data)
{
	Node* p = *head;
	Node* n = new Node;
	n->data = data;
	n->next = NULL;

	if (*head == NULL)
	{
		*head = n;
		return;
	}

	if (data < (*head)->data)
	{
		n->next = *head;
		*head = n;
		return;
	}

	while (p->next != NULL && p->next->data < data)
		p = p->next;

	n->next = p->next;
	p->next = n;
}

void deleteNode(Node** head, Node* key)
{
	Node* p = *head;
	Node* q = NULL;

	if (*head == key)
	{
		//*head = p->next;
		//free(p);
		//std::cout << "???";
		//return;

		Node* second = (*head)->next;
		free(*head);
		*head = second;
		return;
	}

	while (p != key && p->next != NULL)
	{
		q = p;
		p = p->next;
	}

	if (p != key)
		return;

	q->next = p->next;
	free(key);
}

bool isSorted(Node* head)
{
	Node* p = head;
	
	while (p->next != NULL)
	{
		if (p->data > p->next->data)
			return false;

		p = p->next;
	}

	return true;
}

bool rIsSorted(Node* head)
{
	if (head->next == NULL)
		return true;

	return head->data < head->next->data && rIsSorted(head->next);
}

void removeDuplicates(Node* head)
{
	Node* p = head;
	Node* q = head->next;

	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
}

void reverse(Node** head)
{
	Node *current = *head, *previous = NULL, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	*head = previous;
}

void reverseElements(Node* head)
{
	Node* p = head;
	int count = 0;

	while (p != NULL)
	{
		p = p->next;
		count++;
	}

	p = head;
	int *A = (int*)malloc(count * sizeof(int));

	for (int i = 0; i < count; i++)
	{
		A[i] = p->data;
		p = p->next;
	}

	p = head;

	for (int i = count - 1; i >= 0; i--)
	{
		p->data = A[i];
		p = p->next;
	}
}

void concat(Node* p, Node* q)
{
	while (p->next != NULL)
		p = p->next;

	p->next = q;
}

void merge(Node** main, Node* merging)
{
	Node* p = *main;
	Node* q = merging;
	Node* temp = NULL;

	if (q->data < p->data)
	{
		temp = q->next;
		q->next = p;
		*main = q;
		q = temp;
		p = *main;
	}

	while (p->next != NULL && q != NULL)
	{
		if (p->next->data > q->data)
		{
			temp = q->next;
			q->next = p->next;
			p->next = q;
			q = temp;
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}

	if (q != NULL)
		p->next = q;
}

bool checkLoop(Node *head)
{
	Node* p = head;
	Node* q = p->next;

	while (q != NULL)
	{
		if (p == q)
			return true;

		p = p->next;

		q = q->next;

		if (q != NULL)
			q = q->next;
	}

	return false;
}

void displayCircular(Node* head)
{
	Node* p = head;

	do
	{
		printf("%d ", p->data);
		p = p->next;
	}while (p != head && p != NULL);
}

void addToFrontCircular(Node** head, Node *n)
{
	Node* p = *head;

	while (p->next != *head)
		p = p->next;

	p->next = n;
	n->next = *head;
	*head = n;
}

void addCircular(Node* head, int data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	Node* p = head;
	n->data = data;
	n->next = NULL;

	while (p->next != head)
		p = p->next;

	p->next = n;
	n->next = head;
}

void deleteCircular(Node** head, Node* key)
{
	Node *p = *head;

	if (p == key)
	{
		while (p->next != *head)
			p = p->next;

		Node* temp = *head;
		p->next = (*head)->next;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		while (p->next != key)
		{
			if (p->next == *head)
			{
				return;
			}

			p = p->next;
		}

		Node* temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
}

struct dllNode
{
	int data;
	dllNode* prev;
	dllNode* next;
};

void dllDisplay(dllNode* head)
{
	dllNode* p = head;

	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

void dllInsert(dllNode** head, dllNode* key, int data)
{
	dllNode* p = *head;
	dllNode* n = (dllNode*)malloc(sizeof(dllNode));
	n->data = data;
	n->prev = NULL;
	n->next = NULL;

	if (p == key)
	{
		n->next = p;
		p->prev = n;
		*head = n;
	}
	else
	{
		while (p != key)
		{
			if (p->next == NULL)
				return;

			p = p->next;
		}

		n->next = p;
		n->prev = p->prev;
		p->prev = n;
		n->prev->next = n;
	}
}

void dllDelete(dllNode** head, dllNode* key)
{
	dllNode* p = *head;

	if (p == key)
	{
		*head = p->next;
		free(p);

		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		while (p != key)
		{
			if (p->next == NULL)
				return;

			p = p->next;
		}

		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

void dllReverse(dllNode** head)
{
	//dllNode* prev = NULL;
	//dllNode* curr = *head;
	//dllNode* next = curr->next;

	//while (curr != NULL)
	//{
	//	curr->next = prev;
	//	curr->prev = next;
	//	prev = curr;
	//	curr = next;

	//	if (next)
	//		next = next->next;
	//}

	//*head = prev;

	dllNode* p = *head;
	dllNode* temp = NULL;

	if (p == NULL || p->next == NULL)
		return;

	while (p->next)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
	}

	temp = p->next;
	p->next = p->prev;
	p->prev = temp;
	*head = p;
}

int middleElement()
{

}

int main()
{
	//struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	//head->data = 0;
	//head->next = NULL;

	struct dllNode* first = (struct dllNode*)malloc(sizeof(struct dllNode));
	struct dllNode* second = (struct dllNode*)malloc(sizeof(struct dllNode));
	struct dllNode* third = (struct dllNode*)malloc(sizeof(struct dllNode));
	struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
	struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
	struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));
	struct Node* seventh = (struct Node*)malloc(sizeof(struct Node));
	struct Node* eighth = (struct Node*)malloc(sizeof(struct Node));
	struct Node* a = (struct Node*)malloc(sizeof(struct Node));
	struct Node* b = (struct Node*)malloc(sizeof(struct Node));
	struct dllNode* c = (struct dllNode*)malloc(sizeof(struct dllNode));


	first->data = 2;
	first->prev = NULL;
	first->next = second;
	second->data = 4;
	second->prev = first;
	second->next = third;
	third->data = 7;
	third->prev = second;
	third->next = c;
	c->data = 8;
	c->prev = third;
	c->next = NULL;
	a->data = 8;
	a->next = b;
	b->data = 8;
	b->next = seventh;
	fourth->data = 0;
	fourth->next = fifth;
	fifth->data = 1;
	fifth->next = sixth;
	sixth->data = 3;
	sixth->next = a;
	seventh->data = 9;
	seventh->next = eighth;
	eighth->data = 9;
	eighth->next = fourth;

	dllReverse(&first);
	dllDisplay(first);

	return 0;
}