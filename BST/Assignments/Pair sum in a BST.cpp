/*Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. 
You can use extra space of the order of O(log n).
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7
*/
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

int helper(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
        return NULL;
    }
    ans.push_back(root->data);
    helper(root->left,ans);
    helper(root->right,ans);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
     vector<int> ans;
    helper(root,ans);
    sort(ans.begin(),ans.end());
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==s){
            cout<<ans[i]<<" "<<ans[j];
            i++;
            j--;
        }
        else if(ans[i] + ans[j] > s){
            j--;
        }
        else if(ans[i] + ans[j] < s){
            i++;
        }
        cout<<endl;
    }
}