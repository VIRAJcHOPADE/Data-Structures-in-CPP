/*Given a tree and an integer x, find and return 
the number of nodes which contains data greater than x.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5
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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    // Write your code here
    int sum =0;
    
     if(root->data > x)
      sum++;
       
    
    for(int i=0;i<root->children.size();i++)
    {
        int smallsum=getLargeNodeCount(root->children[i], x) ;
        sum+=smallsum;
    }
    
    
    return sum;
}