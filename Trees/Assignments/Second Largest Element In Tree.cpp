/*Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
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
class Pair{
    public:
    TreeNode<int>* largest;
    TreeNode<int>* secondLargest;
};
void helper(TreeNode<int>* root, Pair& ans){
   if(ans.secondLargest == NULL && ans.largest == NULL){
       ans.largest = root;
       ans.secondLargest = NULL;
   }
    else{
        if (ans.secondLargest == NULL){
            if (ans.largest -> data > root -> data){
                ans.secondLargest = root;
            }
            else if (ans.largest -> data == root -> data){
                // Nothing to so ans largest -> data == root -> data
            }
            else{
                ans.secondLargest = ans.largest;
                ans.largest = root;
            }
        }
        else{
            if (ans.secondLargest -> data < root -> data && ans.largest -> data > root -> data){
                ans.secondLargest = root;
            }
            else if (ans.largest -> data < root -> data){
                ans.secondLargest = ans.largest;
                ans.largest = root;
            }
        }
    }
    for (int i = 0; i < root -> children.size(); i++){
        helper(root -> children[i], ans);
    }
} 
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
  Pair ans;
    ans.largest = NULL;
	ans.secondLargest = NULL;
    helper(root, ans);
    return ans.secondLargest; 
}