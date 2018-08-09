#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	char col;
	node *left, *right, *parent;
}*nil;

void inorder(node *root)
{
        if(root==nil)return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
}

void preorder(node *root)
{
        if(root==nil)return;
        preorder(root->left);
        preorder(root->right);
        cout<<root->val<<" ";
}

void postorder(node *root)
{
        if(root==nil)return;
        cout<<root->val<<" ";
        postorder(root->left);
        postorder(root->right);
}

node * search(node *root, int val)
{
        if(root==nil || root->val == val) return root;
        if(root->val <  val) return search(root->right,val);
        else if(root->val >  val) return search(root->left,val);
}


node * left_r(node *root, node *x)
{
	node *y = x->right;
	x->right=y->left;
	if(y->left != nil) y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == nil) root = y;
	else if(x->parent->right == x) y->parent->right =x;
	else y->parent->left=x;
	y->left=x;
	x->parent=y;
	return root;
}

node * right_r(node *root, node *y)
{
	node *x = y->left;
	y->left=x->right;
	if(y->left != nil) y->left->parent = y;
	x->parent = y->parent;
	if(y->parent == nil) root = x;
	else if(y->parent->right == y) y->parent->right =x;
	else y->parent->left=x;
	x->right=y;
	y->parent=x;
	return root;
}

node * ins_fix(node *root, node *z)
{
	while(z->parent->col == 'R')
	{
		if(z->parent == z->parent->parent->left)
		{
			node *y = z->parent->parent->right;
			if(y->col == 'R')
			{
				z->parent->col='B';
				y->col='B';
				z=z->parent->parent;
				z->col='R';
			}
			else
			{
				if(z->parent->right == z)
				{
					z=z->parent;
					root = left_r(root,z);
				}
				z->parent->col = 'B';
				z->parent->parent->col = 'R';
				root = right_r(root,z->parent->parent);
			}
		}
		else
		{
			node *y = z->parent->parent->left;
			if(y->col == 'R')
			{
				z->parent->col='B';
				y->col='B';
				z=z->parent->parent;
				z->col='R';
			}
			else
			{
				if(z->parent->left == z)
				{
					z=z->parent;
					root = right_r(root,z);
				}
				z->parent->col = 'B';
				z->parent->parent->col = 'R';
				root = left_r(root,z->parent->parent);
			}
		}
	}
	root->col='B';
	return root;
}

node * insert(node *root, int k)
{
	node *z = new node;
	z->val = k;
	node *y = nil;
	node *cur = root;
	while(cur!=nil)
	{
		y=cur;
		if(z->val > cur->val)cur=cur->right;
		else cur=cur->left;
	}
	z->parent=y;
	if(y == nil) root = z;
	else if(z->val < y->val) y->left=z;
	else y->right = z;
	z->left = nil;
	z->right = nil;
	z->col = 'R';
	root = ins_fix(root,z);
	return root;
}

int main(int argc, char **argv)
{
	nil = new node;
	nil->col='B';
	int n;
        cin>>n;
        vector<int> v(n);
        node *root = nil;
        for(int i=0;i<n;i++)
        {
                cin>>v[i];
                root = insert(root,v[i]);
        }
        inorder(root);
        return 0;
}
