/*For a given a Binary Tree of type integer, print it in a 
level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in
 a linear fashion and a single space will separate them.
 Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
Sample Output 1:
10 
20 30 
40 50 60 
Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 
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

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
        return;
    
    queue<BinaryTreeNode<int> *> pn;
    
    pn.push(root);
    pn.push(NULL);
    
    while(pn.size()!=0)
    { 
        BinaryTreeNode<int> *front=pn.front();
        pn.pop();
        
       if(front==NULL)
       {  if(pn.size()==0)
           break;
        else{
         cout<<endl;
        }
          pn.push(NULL);
       }
        
     else
     { cout<<front->data<<" ";
     if(front->left){
        pn.push(front->left);
     }
        if(front->right)
         pn.push(front->right);
     }
    }
}