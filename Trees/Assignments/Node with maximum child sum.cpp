/*Given a generic tree, find and return the node for which sum of its
 data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
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
int sumdadson(TreeNode<int>* root)
{
    int x=0;
    if(root==NULL)
        return x;
    
    for(int i=0;i<root->children.size();i++)
    {
        x=x+root->children[i]->data;
    }
    
    return x+root->data;
}
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL || root->children.size()==0)
        return root;
    
    TreeNode<int>* curr=NULL;
    TreeNode<int>* max=NULL;
    int maxi=0;
    int curri=0;
    for(int i=0;i<root->children.size();i++)
    {
        curr=maxSumNode(root->children[i]);
        if(max==NULL)
        {
            max=curr;
            maxi=sumdadson(max);
        }
        else
        {
            int curri=sumdadson(curr);
            if(curri>maxi)
            {
                max=curr;
                maxi=curri;
            }
        }
    }
    
    int a=sumdadson(root);
    
    if(a>maxi)
    {
        return root;
    }
    else
        return max;
}