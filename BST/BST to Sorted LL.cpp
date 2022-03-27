/*Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/
/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

class Pair{
  public:
    Node <int>*head;
    Node <int>*tail;
};

Pair BST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair ans ;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;

    }
    
	Node<int> *node= new Node<int> (root->data);
    
    Pair leftans=BST(root->left);
    Pair rightans=BST(root->right);
    
    
    Pair ans;
    
    if(leftans.head==NULL && rightans.head==NULL)
    {
        
        ans.head=node;
        ans.tail=node;
       
    }
    
   else if(!leftans.head && rightans.head  )
   		 { ans.head=node;
           node->next=rightans.head;
   		     
        	ans.tail=rightans.tail;
  		  }
  else if(leftans.head && rightans.head==NULL)
  		  { ans.head=leftans.head;
      			leftans.tail->next=node;
  		        ans.tail=node;
               
  		  }
    else
    {
        ans.head=leftans.head;
        leftans.tail->next=node;
        node->next=rightans.head;
        ans.tail=rightans.tail;
    }
    
    
    
     return ans;
     
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
   return BST(root).head;
    
}