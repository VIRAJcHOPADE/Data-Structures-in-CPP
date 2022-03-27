/*Given a binary tree with N number of nodes, check if that input 
tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.
Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true
Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

using namespace std;

class Pair{
    
   public:
  int minimum;
  int maximum;
  bool bst;
   
};

Pair BST(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
       Pair obj;
        obj.minimum =INT_MAX;
        obj.maximum = INT_MIN;
        obj.bst = true;
    return obj;
    }
    
    Pair left= BST(root->left);
    Pair right =BST(root->right);
    
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool  isBSTfinal=(root->data >left.maximum) && (root->data < right.minimum) && left.bst && right.bst;
   
    Pair obj;
    obj.minimum=minimum;
    obj.maximum=maximum;
    obj.bst=isBSTfinal;
    return obj;
        
    
    
}

bool isBST(BinaryTreeNode<int> *root){

    return BST(root).bst;
    
    
}