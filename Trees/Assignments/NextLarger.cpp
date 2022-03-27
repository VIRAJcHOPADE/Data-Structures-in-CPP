/*Given a generic tree and an integer n. Find and return the node
 with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
21
Sample Output 2:
30
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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    int ans=0;
    if(root==NULL){
        return NULL;
    }
    TreeNode<int>* res=NULL;
   if(root->data>x){
        if(res==NULL||root->data<res->data){  
        res=root;
        }
    }
    for(int i=0;i<root->children.size();i++){
     // getNextLargerElement(root->children[i],x);  
        
        TreeNode<int> *childAns = getNextLargerElement(root->children[i],x); // 
        
        if(res==NULL||childAns->data<res->data){ //
        	res=childAns; //
        }//
    }
    
    return res;
}