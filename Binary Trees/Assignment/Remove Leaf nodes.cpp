/*Given a binary tree, remove all leaf nodes from it. 
Leaf nodes are those nodes, which don't have any children.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
8
3 10
6 14                    
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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
   if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    if(root->left){
   root->left=removeLeafNodes(root->left);
    }
    if(root->right){
   root->right=removeLeafNodes(root->right);
    }
    return root;
}