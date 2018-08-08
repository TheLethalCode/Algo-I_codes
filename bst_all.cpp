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
	{
		root->right=insert(root->right, val, root);
	}
	else if(val<root->val)
	{
		root->left=insert(root->left,val,root);

	}
	return root;
}

void inorder(node *root)
{
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void preorder(node *root)
{
	if(root==NULL)return;
	preorder(root->left);
	preorder(root->right);
	cout<<root->val<<" ";
}

void postorder(node *root)
{
	if(root==NULL)return;
	cout<<root->val<<" ";
	postorder(root->left);
	postorder(root->right);
}

node * search(node *root, int val)
{
	if(root==NULL || root->val == val) return root;
	if(root->val <  val) return search(root->right,val);
	else if(root->val >  val) return search(root->left,val);
}

node * reach_left(node *root)
{
	node *cur=root;
	while(cur->left != NULL)cur=cur->left;
	return cur;
}

node * in_succ(node *cur)
{
	if(cur->right == NULL)
	{
		if(cur->parent == NULL)return NULL;
		while(cur->parent->right==cur)
		{
			cur=cur->parent;
			if(cur->parent == NULL)return NULL;
		}
		cur=cur->parent;
		return cur;
	}
	else return reach_left(cur->right);
}

node * del(node *root, int data)
{
  if (root == NULL)
  {
     return NULL;
  }
  if (data < root->val)
  { 
      root->left = del(root->left, data);
  } 
  else if (data > root->val) 
  { 
      root->right = del(root->right, data);
  } 
  else 
  {
     // case 1
     if (root->left == NULL && root->right == NULL) 
     {
        delete(root); 
        root = NULL;
     }
     // case 2 && case 3
     else if (root->left == NULL) 
     {
        node *temp = root; 
        root = root->right;
        delete temp;
     }
     else if (root->right == NULL) 
     {
        node *temp = root; 
        root = root->left;
        delete temp;
     }
     //case 4
     else 
     {
        node *temp = reach_left(root->right); 
        root->val = temp->val;
        root->right = del(root->right, temp->val); 
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
	//inorder(root);
	//cout<<endl;
	//preorder(root);
	//cout<<endl;
	//postorder(root);
	// int a=0;
	// cin>>a;
	// node *re = search(root,a);	
	del(root,5);
	inorder(root);
	return 0;
}
