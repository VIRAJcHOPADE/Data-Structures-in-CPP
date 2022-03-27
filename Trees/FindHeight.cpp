/*Given a generic tree, find and return the height of given tree.
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3*/
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int getHeight(TreeNode<int>* root) {
    // Write your code here 
    int h =1;
    
    if(root->children.size()==0)
        return h;	
    
    int arr[root->children.size()];
    for(int i=0;i<root->children.size();i++)
    {
        arr[i]=getHeight(root->children[i]);
        
    }
    sort(arr,arr+root->children.size(),greater<int>());
	h+=arr[0];
    
    return h;
}