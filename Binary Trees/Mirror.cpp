/*For a given Binary Tree of type integer, update it with its corresponding mirror image.
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9
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

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(!root){
        return;
    }
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}