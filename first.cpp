#include<stack>
#include<bits/stdc++.h>
#include <iostream>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void topviewUtil(struct node* root,int hd,set<int>&hash)
{
	if(!root)
	{
		return;
	}
	if(hash.find(hd)==hash.end())
	{
		std::cout<<root->data<<" ";
		hash.insert(hd);
	}
	topviewUtil(root->left,hd-1,hash);
	topviewUtil(root->right,hd+1,hash);
}

void topview(struct node* root)
{
	if(!root)
	{
		return;
	}
	set<int>hash;
	topviewUtil(root,0,hash);
}

int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left=newNode(4);
    root->left->right = newNode(5); 
    root->right->left=newNode(6);
    root->right->right=newNode(7); 
    cout<<"top view :\n";  
    topview(root); 
    return 0; 
} 
