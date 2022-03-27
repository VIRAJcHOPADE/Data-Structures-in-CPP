/*Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor)
 of the given two nodes in the binary tree.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 10
Sample Output 1:
10
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
12 78
Sample Output 3:
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

int getLCA(BinaryTreeNode <int>* root , int val1, int val2) {
    // Write your code here
    if(root==NULL)
        return -1;
    if(root->data == val1 || root->data== val2)
        return root->data;
    
    int left= getLCA(root->left,val1,val2);
    int right= getLCA(root->right,val1,val2);
    
    if(left== -1 && right == -1)
       return -1;
    else if( left!=-1 &&right ==-1)
        return left;
     else if( left==-1 &&right !=-1)
        return right;
     else
         return root->data;
}