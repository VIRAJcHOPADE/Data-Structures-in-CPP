/*Given a BST and an integer k. Find if the integer k 
is present in given BST or not. You have to return true, 
if node with data k is present, return false otherwise.
Note: Assume that BST contains all unique elements.
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true
Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
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

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root==NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }
    if(root->data > k){
        searchInBST(root->left,k);
    }
    else{
        searchInBST(root->right,k);
    }
}