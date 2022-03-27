/*For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths 
where the sum of all the node data along the path is equal to K.
Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
 Sample Output 1:
2 3 4 4 
2 3 8
Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
 Sample Output 2:
5 6 2
5 7 1
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

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,vector<int> path)
{
    if(root==NULL)
        return;
    
    path.push_back(root->data);
    k=k- root->data;
    
    if(!root->left && !root->right) // leaf node
    {
        if(k==0)
        {
            for(int i : path)
            {
                cout<< i<<" ";
            }
            cout<<endl;
        }
      path.pop_back();
      return;
    }
    rootToLeafPathsSumToK(root->left,k,path);    
    rootToLeafPathsSumToK(root->right,k,path);
    path.pop_back();
    
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> v;
    rootToLeafPathsSumToK(root,k,v);
    return;
}