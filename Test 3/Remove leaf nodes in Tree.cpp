/*Remove all leaf nodes from a given generic Tree. 
Leaf nodes are those nodes, which don't have any children.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
10
20
*/
// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>* children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
#include<vector>

TreeNode<int>* removeLeafNodes(TreeNode<int> *root){
	if(root == NULL || root -> numChildren() == 0)
        return NULL;

	vector<int> indexes;
	for(int i=0; i< root-> numChildren(); i++){
		TreeNode<int> *child = root -> getChild(i);
		if(child -> numChildren() == 0)
			indexes.push_back(i);
	}
    
	for(int i= indexes.size()-1; i>= 0; i--){
		int j= indexes[i];
		root -> removeChild(j);
	}
	
    for(int i=0; i< root-> numChildren(); i++){
		TreeNode<int> *child = removeLeafNodes(root -> getChild(i));
	}
	return root;
}

// TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
//     // Write your code here
//    if(root==NULL)return NULL;     //if root is NULL return NULL
//     if(root->children.size()==0){  //if root itself is leaf then return NULL
//         delete root;
//         return NULL;
//     }
//     for(int i=0;i<root->children.size();i++){//moving onto its children
//         TreeNode* child=root->children[i];
//         if(child->children.size()==0){       // if leaf then delete that node
//             delete child;
//             for(int j=i;j<root->children.size()-1;j++){// update the children vector as well
//                 root->children[j]=root->children[j+1];
//             }
//             root->children.pop_back();
//             i--;
//         }
//     }
//     for(int i=0;i<root->children.size();i++){  //recursive call
//         root->children[i]=removeLeafNodes(root->children[i]);
//     }
//     return root;

// }

