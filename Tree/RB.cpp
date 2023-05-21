#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;

struct Node
{
  	int data;
  	Node *parent;
  	Node *left;
  	Node *right;
  	int color; 
};

class RedBlackTree 
{
   	private:
  	Node* root;
  	Node* TNULL;
	
  	void createNULLNode(Node* node, Node* parent) 
  	{
    		node->data = 0;
    		node->parent = parent;
    		node->left = nullptr;
    		node->right = nullptr;
    		node->color = 0;
  	}
  	
  	void insertFix(Node* k)
  	{
    		Node* u;
    		while (k->parent->color == 1)
    		{
      			if (k->parent == k->parent->parent->right) 
      			{
        			u = k->parent->parent->left;
        			if (u->color == 1) 
        			{
          				u->color = 0;
          				k->parent->color = 0;
          				k->parent->parent->color = 1;
          				k = k->parent->parent;
        			} 
        			else 
        			{
          				if (k == k->parent->left)	
          				{
            					k = k->parent;
            					rightRotate(k);
          				}
          				k->parent->color = 0;
          				k->parent->parent->color = 1;
          				leftRotate(k->parent->parent);
        			}
      			} 
      			else 
      			{
        			u = k->parent->parent->right;
        			if (u->color == 1)
        			{
          				u->color = 0;
          				k->parent->color = 0;
          				k->parent->parent->color = 1;
          				k = k->parent->parent;
        			} 
        			else 
        			{
          				if (k == k->parent->right) 
          				{
            					k = k->parent;
            					leftRotate(k);
          				}
          				k->parent->color = 0;
          				k->parent->parent->color = 1;
          				rightRotate(k->parent->parent);
        			}
      			}
      			if (k == root) break;
     		}
    		root->color = 0;
  	}
public:
  	RedBlackTree() 
  	{
    		TNULL = new Node;
    		TNULL->color = 0;
    		TNULL->left = nullptr;
    		TNULL->right = nullptr;
    		root = TNULL;
  	}

	void leftRotate(Node* x) 
	{
    		Node* y = x->right;
    		x->right = y->left;
    		if (y->left != TNULL) y->left->parent = x;
    		y->parent = x->parent;
    		if (x->parent == nullptr) this->root = y;
   		else if (x == x->parent->left) x->parent->left = y;
    		else x->parent->right = y;
    		y->left = x;
		x->parent = y;
  	}

  	void rightRotate(Node* x) 
  	{
    		Node* y = x->left;
    		x->left = y->right;
    		if (y->right != TNULL) y->right->parent = x;
    		y->parent = x->parent;
    		if (x->parent == nullptr) this->root = y;
    		else if (x == x->parent->right) x->parent->right = y;
    		else x->parent->left = y;
		y->right = x;
		x->parent = y;
  	}

	void insert(int key) 
	{
		Node* node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;
		Node* y = nullptr;
		Node* x = this->root;
		while (x != TNULL) 
    		{
      			y = x;
     	 		if (node->data < x->data) x = x->left;
			else x = x->right;
    		}
		node->parent = y;
		if (y == nullptr) root = node;
		else if (node->data < y->data) y->left = node;
		else y->right = node;
		if (node->parent == nullptr) 
		{
			node->color = 0;
			return;
		}
		if (node->parent->parent == nullptr) return;
		insertFix(node);
  	}

  	Node* getRoot()
  	{
  		return this->root;
	}

  	int getHeight(Node* node) 
  	{
		if (node == TNULL) return 0;
		else
		{
			int leftHeight = getHeight(node->left);
			int rightHeight = getHeight(node->right);
			return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
		}
	}
};

int main() 
{
  	freopen("data.txt","r",stdin);
  	vector<int> data(MAX);
  	for (int i = 0; i < 10; ++i)
  	{
  		RedBlackTree tree;
  		for (int j = 0; j < MAX; ++j)
  		{
  			cin>>data[j];
  			tree.insert(data[j]);
  		}
  		cout<<tree.getHeight(tree.getRoot())<<endl;
  	}
}
