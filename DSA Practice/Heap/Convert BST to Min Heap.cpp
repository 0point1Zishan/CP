#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inOrder(BinaryTreeNode* root, vector<int>& v){
	if(root == NULL) return;
	inOrder(root->left, v);
	v.push_back(root->data);
	inOrder(root->right, v);
}

void preOrder(BinaryTreeNode* root, vector<int>& v, int& i){
	if(root == NULL) return;
	root->data = v[i++];
	preOrder(root->left, v, i);
	preOrder(root->right, v, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> v;
	inOrder(root, v);
	
	int i = 0;
	preOrder(root, v, i);
	return root;
}