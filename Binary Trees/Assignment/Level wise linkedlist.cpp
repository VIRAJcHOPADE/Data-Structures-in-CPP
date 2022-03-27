/*Given a binary tree, write code to create a separate linked list for each level.
 You need to return the array which contains head of each level linked list.
 Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/
/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> v;
    if(root==NULL){
        v.push_back(NULL);
        return v;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    while(q.size()!=0){
        BinaryTreeNode<int> * front = q.front();
        Node<int> * temp = new Node<int>(front -> data);
		q.pop();
        
        if(head == NULL && tail == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = tail -> next;
        }
		        
		if(front -> left != NULL){
			q.push(front -> left);
		}
        
		if(front -> right != NULL){
			q.push(front -> right);
		}
        
         if(q.front() == NULL){
            v.push_back(head);
            q.pop(); 
             head = NULL;
             tail = NULL;
            if(q.size()!=0){
                q.push(NULL);
             }
        }
        
    }
    return v;
}