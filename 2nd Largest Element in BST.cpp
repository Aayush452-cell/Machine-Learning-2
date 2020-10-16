#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* newNode(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

Node* insert(Node* root,int data)
{
	if(root==NULL)
	   return newNode(data);
    if(root->data > data)
    root->left=insert(root->left,data);
    else if(root->data < data)
    root->right=insert(root->right,data); 
    return root;
}

void secondLargestElement(Node* root,int k)
{
	static int c=0;
	if(root==NULL || c>k)
	  return;
    secondLargestElement(root->right,k);
    c++;
    if(c==k)
    {
    	cout<<root->data;
    	return;
	}
	secondLargestElement(root->left,k);
}

int main()
{
	Node* root=NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	
    secondLargestElement(root,2);
	return 0;
}
