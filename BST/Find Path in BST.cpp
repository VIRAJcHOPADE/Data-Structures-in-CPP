/*Given a BST and an integer k. Find and return the path 
from the node with data k and root (if a node with data 
k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8
*/
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

using namespace std;
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root==NULL)
    {
       return NULL;
    }
    
    if(root->data == data )
    {
        vector<int> *v = new vector <int> ();
        v->push_back(root->data);
        return v;
    }
    
    vector<int> *left=getPath(root->left, data);
     if(left)
    {
        left->push_back(root->data);
        return left;
    }
  
    vector<int> *right=getPath(root->right,data);

        if(right)
        {
            right->push_back(root->data);
            return right;
        }
    
     
        return NULL;   
}