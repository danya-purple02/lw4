#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;


int main()
{
	int D, start = 1;

	root = NULL;
	printf("-1 - ��������� ���������� ������\n");






	while (start)
	{
		printf("������� �����: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("���������� ������ ��������\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);

	scanf_s("%d", &D);
	return 0;
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
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}


struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("������ ��������� ������");
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
