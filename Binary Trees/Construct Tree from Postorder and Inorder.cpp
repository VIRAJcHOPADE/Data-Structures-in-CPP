/*For a given postorder and inorder traversal of a Binary Tree of type
 integer stored in an array/list, create the binary tree using the given two arrays/lists.
 You just need to construct the tree and return the root.
 Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
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
BinaryTreeNode<int>* tree(int *postorder, int *inorder,int ps,int pe, int is, int ie)
{
    if(ps>pe)
        return NULL;
    
    
     int k = 0; 
    for(int i = is; i <= ie; i++)
    { if(postorder[pe] == inorder[i])
        { k = i; break; } 
    }
    int lps=ps;    //left prestart
    int lis=is;  //left instart
    int  lie=k-1;   //left inend
    int lpe= lie-lis+lps; //left  pre end
    
    int rps=lpe+1; //right prestart
    int rpe=pe-1;//  right preend
    int ris=k+1;  //right instart
    int rie=ie;   //right inend
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[pe]);
    root->left=tree(postorder,inorder,lps,lpe,lis,lie);
    root->right=tree(postorder,inorder,rps,rpe,ris,rie);
    return root;   
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
     return tree (postorder,inorder,0,postLength-1,0,inLength-1);
}