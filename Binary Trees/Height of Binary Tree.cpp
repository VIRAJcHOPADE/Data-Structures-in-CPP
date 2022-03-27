/*For a given Binary Tree of integers, find and return the height of the tree.
Sample Input 1:
10 20 30 40 50 -1 -1 -1 -1 -1 -1
Sample Output 1:
3
Sample Input 2:
3 -1 -1
Sample Output 2:
1
*/
/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    int h=0;
    if(root==NULL){
        return 0;
    }
    int lefth=height(root->left);
    int righth=height(root->right);
    
    if(lefth>righth){
        return 1+lefth;
    }
    else{
        return 1+righth;
    }
}