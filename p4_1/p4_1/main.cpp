#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void print_tree(struct Node* r, int l);
struct Node* CreateTree(struct Node* root, struct Node* r, int data);
//int CheckAmount(struct Node* t, int data, int r);
struct Node* SearchElement(struct Node* t, int data);

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* root,* res;

int main()
{
	int D, choise = 0, start = 1, search_value = 0;
	//int res = 0;
	root = NULL;
	res = NULL;
	while (1) 
	{
		cout << "choose action:" << endl;
		cout << "1 - create binary tree" << endl << "2 - search element" << endl << "3 - print tree" << endl << "4 - exit program" << endl;
		cin >> choise;
		switch (choise) 
		{
			case 1: 
			{
				if (root != NULL) 
				{
					cout << "tree already exists" << endl << endl;
					continue;
				}
				cout << "to stop enter -1" << endl;
				while (start)
				{
					cout << "type number: ";
					cin >> D;
					if (D == -1)
					{
						cout << "construction is done" << endl << endl;
						start = 0;
					}
					else 
					{
						root = CreateTree(root, root, D);
					}
				}
				continue;
			}
			case 2: 
			{
				cout << "enter search value: ";
				cin >> search_value;
				res = SearchElement(root, search_value);
				if (!res)
				{
					continue;
				}
				cout << "element exists" << endl << endl;
				continue;
			}
			case 3: 
			{
				print_tree(root, 0);
				cout << endl << endl;
				continue;
			}
			case 4: 
			{
				return 0;
			}
			default: 
			{ 
				cout << "must type 1 - 4" << endl;
				continue;
			}
		}
	}
	
}


void print_tree(struct Node* r, int l)
{
	if (r == NULL)
	{
		return;
	}
	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf("	");
	}
	cout << r->data;
	cout << endl;
	print_tree(r->left, l + 1);
}


struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			cout << "malloc error";
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}
	if (data == r->data) 
	{
		cout << "element already exist" << endl;
		return root;
	}
	if (data > r->data) 
	{
		CreateTree(r, r->left, data);
	}
	else
	{
		CreateTree(r, r->right, data);
	}
	return root;
}

struct Node* SearchElement(struct Node* t, int data)
{
	if (t == NULL)
	{
		cout << "element does not exist" << endl;
		return 0;
	}

	if (data > t->data)
	{
		t = t->left;
		SearchElement(t, data);
	}
	else if (data < t->data)
	{
		t = t->right;
		SearchElement(t, data);
	}
	else if (data == t->data)
	{
		return t;
	}
}

/*
int CheckAmount(struct Node* t, int data, int r)
{
	if (t == NULL) 
	{
		cout << "element does not exist" << endl << endl;
		return 0;
	}

	if (data > t->data)
	{
		t = t->left;
		CheckAmount(t, data, r);
	}
	else if (data < t->data)
	{
		t = t->right;
		CheckAmount(t, data, r);
	}
	else if (data == t->data)
	{
		r++;
		if (t->right != NULL) 
		{
			t = t->right;
			CheckAmount(t, data, r);
		}
		else 
		{
			return r;
		}
	}
}
*/