#include "nary_tree.h"
#include <stdio.h>
#include <stdlib.h>
/************************ PREDEFINED FUNCTIONS (DO NOT CHANGE)*******************************/
/*
Print the binary tree according to the preorder traversal
*/
void print_preorder(binarynode* root) {
	printf("%d ", root->key);
	if (root->leftchild != NULL) print_preorder(root->leftchild);
	if (root->rightchild != NULL) print_preorder(root->rightchild);
}

/*
Print the binary treee according to the inorder traversal
*/
void print_inorder(binarynode* root) {
	if (root->leftchild != NULL) print_inorder(root->leftchild);
	printf("%d ", root->key);
	if (root->rightchild != NULL) print_inorder(root->rightchild);
}

/*
Print error message
*/
void print_error() {
	printf("Error\n");
}
/***************************************************************************************/

/*
Create and return a tree with single root node whose key value is key.
All the children are initialized to NULL
If root already exists, return root
*/
nary_node* createtree(nary_node* root, int key) {
//implement your code
	if (root == NULL)
	{
		root = (nary_node*)malloc(sizeof(nary_node));
		root->key = key;
		for (int i = 0; i < n; i++)
		{
			root->children[i] = NULL;
		}
	}
	return root;
}

/*
Return a node with corresponding key value
If such node doesn't exist, return NULL
*/
nary_node* key_node(nary_node* root, int key) {
//implement your code
	if (root->key == key)
	{
		return root;
	}
	nary_node* search = NULL;
	for (int i = 0; i < n; i++)
	{
		if (root->children[i] != NULL)
		{
			search = key_node(root->children[i], key);
			if (search != NULL)
			{
				return search;
			}
		}
	}

	return NULL;
}

/*
Insert a node with the key value
as the i-th child of the node whose key value is parent_key
If such (parent) node doesn't exist, tree is already full, or index (i) exceeds the degree, call error function and return root
*/
nary_node* add_i_child(nary_node* root, int parent_key, int i, int key) {
//implement your code
	nary_node* search = key_node(root, parent_key);
	if (search == NULL || (search->children[i] != NULL && search->children[n-1] != NULL) || i>=n)
	{
		print_error();
	}
	else
	{
		if (search->children[i] != NULL)
		{
			for (int j = n-1; j > i; j--)
			{
				search->children[j] = search->children[j - 1];
			}
		}
		nary_node* temp = NULL;
		temp = createtree(temp, key);
		search->children[i] = temp;
	}
	return root;
}

/*
Delete the i-th child of the node with parent_key (with all its descendants) and deallocating memory, by make it as NULL
If the node doesn't exist or index is out of range, call error function and return root
*/
nary_node* delete_i_child(nary_node* root, int parent_key, int i) {
//implement your code
	nary_node* search = key_node(root, parent_key);
	if (search == NULL || i >= n)
	{
		print_error();
	}
	else
	{
		int count = -1;
		for (int j = 0; j < n; j++)
		{
			if (search->children[j] != NULL)
			{
				count += 1;
				if (count == i)
				{
					break;
				}
			}
		}
		if (i>count)
		{
			print_error();
			return root;
		}
		free(search->children[count]);
		search->children[count] = NULL;
	}
	return root;
}

/*
Return the height of the node whose key value is node_value
If the node doesn't exist, call error function and return -1
*/
int height_node(nary_node* root, int node_value) {
//implement your code
	int height = 0;
	if (key_node(root, node_value) == NULL)
	{
		print_error();
		return -1;
	}
	nary_node* here = key_node(root, node_value);
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		if (here->children[i] != NULL)
		{
			temp = height_node(here->children[i], here->children[i]->key) + 1;
			if (temp > height)
			{
				height = temp;
			}
		}
	}
	return height;
}

/*
Return the height of a tree 
*/
int height_tree(nary_node* root) {
//implement your code
	int num = 0;
	int chk = 0;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		if (root->children[i] != NULL)
		{
			chk = 1;
			temp = height_tree(root->children[i]) + 1;
			if (temp > num)
			{
				num = temp;
			}
		}
	}
	if (chk != 0)
	{
		return num;
	}
	else
	{
		return 0;
	}
}

/*
Calculate the depth of the node whose key value is node_value
If the node doesn't exist, call error function and return -1
*/
int depth_node(nary_node* root, int node_value) {
//implement your code
	static int chk = 0;
	chk++;
	if (key_node(root, node_value) == NULL)
	{
		if (chk == 1)
		{
			print_error();
		}
		return -1;
	}
	if (root->key == node_value)
	{
		chk = 0;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (root->children[i] != NULL)
		{
			if (depth_node(root->children[i], node_value) != -1)
			{
				return depth_node(root->children[i], node_value) + 1;
			}
		}
	}

	print_error();
	return -1;
}

/*
Calculate the depth of a tree
*/
int depth_tree(nary_node* root) {
//implement your code
	return height_tree(root);
}

/*
Return the child rank of the node whose key value is node_value
If the node doesn't exist, call error function and return -1
*/
int child_rank(nary_node* root, int node_value) {
//implement your code
	if (key_node(root, node_value) == NULL)
	{
		print_error();
		return -1;
	}
	if (root->key == node_value)
	{
		return -1;
	}
	int rank = 0;
	struct queue {
		int num;
		nary_node* rem;
		struct queue* next;
	};
	struct queue* child_queue = NULL;
	struct queue* save_queue = NULL;
	nary_node* search = NULL;
	search = root;
	child_queue = (struct queue*)malloc(sizeof(struct queue));
	child_queue->num = root->key;
	child_queue->rem = root;
	child_queue->next = NULL;
	save_queue = child_queue;
	while(search != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			if (search->children[i] != NULL)
			{
				if (search->children[i]->key == node_value)
				{
					int count = 0;
					for (int j = 0; j < i; j++)
					{
						if (search->children[j] != NULL)
						{
							count++;
						}

					}
					return count;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (search->children[i] != NULL)
			{
				
				struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
				temp->num = search->children[i]->key;
				temp->next = NULL;
				temp->rem = search->children[i];
				child_queue->next = temp;
				child_queue = child_queue->next;
			}
		}
		save_queue = save_queue->next;
		search = save_queue->rem;
	}

	return -1;
}

/*
Return the i-th child of the node whose key value is parent_key
If the node doesn't exist, call error function and return -1
*/
int child_select(nary_node* root, int parent_key, int i) {
//implement your code
	if (key_node(root, parent_key) == NULL)
	{
		print_error();
		return -1;
	}
	nary_node* search = key_node(root, parent_key);
	int count = 0;
	for (int j = 0; j < n; j++)
	{
		if (search->children[j] != NULL)
		{
			if (count == i)
			{
				return search->children[j]->key;
			}
			else
			{
				count++;
			}
		}
	}
	print_error();
	return -1;
}

/*
Print the tree according to the preorder traversal
*/
void preorder(nary_node* root) {
//implement your code
	printf("%d ", root->key);
	for (int i = 0; i < n; i++)
	{
		if (root->children[i] != NULL)
		{
			preorder(root->children[i]);
		}
	}
}

/*
Convert the nary tree to the binary tree by lcps (last child previous sibling)
*/
binarynode* lcps(nary_node* root) {
	//implement your code4
	int idx = -1;
	binarynode* binary_root = (binarynode*)malloc(sizeof(binarynode));
	binarynode* temp = NULL;
	binary_root->leftchild = NULL;
	binary_root->rightchild = NULL;
	
	for (int i = n - 1; i >= 0; i--)
	{
		if (root->children[i] != NULL)
		{
			idx = i;
			break;
		}
	}
	if (idx == -1)
	{
		return NULL;
	}
	else
	{
		binary_root->key = root->children[idx]->key;
	}
	temp = binary_root;

	for (int i = idx - 1; i >= 0; i--)
	{
		if (root->children[i] != NULL)
		{
			binarynode* temp_right = (binarynode*)malloc(sizeof(binarynode));
			temp_right->key = root->children[i]->key;
			temp_right->leftchild = lcps(root->children[i]);
			temp_right->rightchild = NULL;
			temp->rightchild = temp_right;
			temp = temp_right;
		}
	}

	binary_root->leftchild = lcps(root->children[idx]);
	
	return binary_root;

}
