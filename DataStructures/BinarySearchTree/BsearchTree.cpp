#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("f.in");


template <typename T>
class binarySearchTree
{
	private:
		struct Node
		{
			T key;
			Node *left, *right;

			Node()
			{
				left=right=NULL;
			}
		};

		Node *root;

		//inserting a key in the tree recursively, with params as key and root of tree
		Node * insert(Node* node, T& newKey)
		{
			if(node == NULL)
			{
				node = new Node;
				node->key = newKey;
				return node;
			}
			if(newKey < node->key)
				node->left = insert(node->left,newKey);
			if(newKey > node->key)
				node->right = insert(node->right,newKey);

			return node;

		}

		//searching for a key recursively in a tree, with params as key and root of tree
		bool search(Node*node, T& key)
		{
			if (node == NULL)
				return false;
			if(node -> key == key)
				return true;
			else
			{
				if(key < node->key)
					return search(node->left,key);
				else
					return search(node->right,key);
			}
		}

		//erase node from a tree searching for it recursively, with params as key and root of node
		Node * erase (Node* node, T& key)
		{
			if (node == NULL)
				return NULL;
			if(node->key == key)
			{
				Node* p;
				if(node->left == NULL || node->right == NULL)
				{
					p = (node->left==NULL ? node->right : node->left);
					delete node;
					return p;
				}

				for(p = node->left; p->right != NULL; p = p->right);

				node->key = p->key;
				node->left = erase(node->left,node->key);

			}
			else
			{
				if(key < node->key)
					node->left = erase(node->left,key);
				else node->right = erase(node->right, key);
			}
			return node;
		}

	public:
		binarySearchTree()
		{
			root = NULL;
		}

		//insert node with a specified key
		void insert(T newKey)
		{
			root = insert(root,newKey);
		}

		//search for a node with a specified key
		bool search(T key)
		{
			return search(root,key);
		}

		//erase node with a specified key
		void erase(T key)
		{
			root = erase(root,key);
		}
};

//testing my brand new binary search tree class
int main()
{
	int n, x, val;
	binarySearchTree<int>bst;
	fin>>n;
	fin>>val;
	for(;n;n--)
	{
		fin>>x;
		bst.insert(x);
	}
	cout<<bst.search(val)<<' ';
	bst.erase(val);
	cout<<bst.search(val-1)<<'\n';
	fin.close();
	return 0;
}

