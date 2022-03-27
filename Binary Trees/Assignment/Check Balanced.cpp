/*Given a binary tree, check if it is balanced.
 Return true if given binary tree is balanced, false otherwise.
 Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
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
int height(BinaryTreeNode<int> *root)
{   if(root==NULL)
       return 0;
 
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
     if (root == NULL) 
        return 1; 
    int l=height(root->left);
	int r=height(root->right);	
   
     if ( ( abs(l- r) ==0 ) && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
   return 0;
}
