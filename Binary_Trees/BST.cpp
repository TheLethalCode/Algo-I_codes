#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *left, *right, *parent;
};

node * insert(node *root, int val, node *par){
	if(root == NULL)
	{
		root = new node;
		root->parent = par;
		root->left = NULL;
		root->right = NULL;
		root->val=val;
		return root;
	}
	if(val>root->val)
		root->right=insert(root->right, val, root);
	else if(val<root->val)
		root->left=insert(root->left,val,root);

	return root;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void preorder(node *root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	preorder(root->right);
	cout<<root->val<<" ";
}

void postorder(node *root)
{
	if(root==NULL)
		return;
	cout<<root->val<<" ";
	postorder(root->left);
	postorder(root->right);
}

node * search(node *root, int val)
{
	if(root==NULL || root->val == val) 
		return root;
	if(root->val <  val) 
		return search(root->right,val);
	return search(root->left,val);
}

// Smallest element of the sub-tree
node * reach_left(node *root)
{
	node *cur=root;
	while(cur->left != NULL)
		cur=cur->left;
	return cur;
}

// Inorder Successor
node * in_succ(node *cur)
{
	if(cur->right == NULL)
	{
		if(cur->parent == NULL)
			return NULL;
		while(cur->parent->right==cur)
		{
			cur=cur->parent;
			if(cur->parent == NULL)
				return NULL;
		}
		cur=cur->parent;
		return cur;
	}
	else 
		return reach_left(cur->right);
}

node * del(node *root, node *z)
{
	if(z->left == NULL && z->right == NULL)
	{
		if(z->parent==NULL)
			root = NULL;
		else if(z->parent->right == z) 
			z->parent->right = NULL;
		else 
			z->parent->left = NULL;
		delete(z);
	}
	else if(z->left == NULL)
	{
		if(z->parent==NULL)
			root = z->right;
		else if(z->parent->right == z) 
			z->parent->right = z->right;
		else 
			z->parent->left = z->right;
		z->right->parent=z->parent;
		delete(z);
	}
	else if(z->right == NULL)
	{
		if(z->parent==NULL)
			root = z->left;
		else if(z->parent->right == z)
			 z->parent->right = z->left;
		else 
			z->parent->left = z->left;
		z->left->parent=z->parent;
		delete(z);
	}
	else
	{
		node *y = reach_left(z->right);
		if(y==z->right)
		{
			y->parent=z->parent;
			if(z->parent == NULL)
				root=y;
			else if(z->parent->right == z) 
				z->parent->right = y;
			else 
				z->parent->left = y;
			y->left=z->left;
			if(z->left!=NULL)
				z->left->parent=y;
			delete(z);
		}
		else
		{
			y->parent->left = y->right;
			if(y->right != NULL) 
				y->right->parent=y->parent;
			y->parent=z->parent;
			
			if(z->parent == NULL)
				root=y;
			else if(z->parent->right == z) 
				z->parent->right = y;
			else
				 z->parent->left = y;
			
			y->left=z->left;
			if(z->left != NULL) 
				z->left->parent=y;	
			
			y->right=z->right;
			if(z->right != NULL) 
				z->right->parent=y;
			delete(z);
		}
	}
	return root; 
}

int main(int argc, char **argv)
{
	int n;
	cin>>n;
	vector<int> v(n);
	node *root = NULL;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		root = insert(root,v[i],NULL);
	}
	inorder(root);
	return 0;
}
