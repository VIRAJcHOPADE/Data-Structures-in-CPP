/*Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
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

int helper(BinaryTreeNode<int> *root, vector<int> &a){
    if(root==NULL){
        return NULL;
    }
    a.push_back(root->data);
    helper(root->left,a);
    helper(root->right,a);
    
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> output;
    helper(root,output);
    sort(output.begin(),output.end());
    int i=0,j=output.size()-1;
    while(i<j){
        if(output[i]+output[j]==sum){
        cout<<output[i]<<" "<<output[j]<<"\n";
        i++;
        j--;          
        }
        else if(output[i]+output[j]<sum){
            i++;
        }
        else if(output[i]+output[j]>sum){
            j--;
        }
    }
  
}