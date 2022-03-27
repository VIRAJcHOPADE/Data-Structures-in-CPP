/*Given a generic tree, count and return the number of leaf nodes present in the given tree.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4*/
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

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL){   
        return 0;    
    }                    
    // Write your code here
    if(root->children.size()==NULL){   
        return 1;
    }
    int ans=0;    
    for(int i=0;i<root->children.size();i++){
      ans = ans+getLeafNodeCount(root->children[i]);
    }
    return ans;
}