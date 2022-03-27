/*For a given Binary Tree of type integer, print all the nodes without any siblings
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9    
Sample Input 2:
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
6 7  
*/
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    
    // Write your code here
    if(root->left && !root->right){
        cout<<root->left->data<<" ";
        printNodesWithoutSibling(root->left);
    }
    else if(!root->left && root->right){
        cout<<root->right->data<<" ";
        printNodesWithoutSibling(root->right);
    }
    else{
        printNodesWithoutSibling(root->left);
        printNodesWithoutSibling(root->right);
    }
    
}