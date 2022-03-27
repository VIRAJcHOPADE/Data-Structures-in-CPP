/*Given a generic tree, find and return the node with maximum data.
 You need to return the node which is having maximum data.
Return null if tree is empty.
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
*/
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

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    
     if(root==NULL){
        return NULL;
    }
    TreeNode<int>*max = root;
    for(int i=0;i<root->children.size();i++){
      TreeNode<int>* small = maxDataNode(root->children[i]);
        if(small->data > max->data){
            max=small;
        }
    }
    return max;
}