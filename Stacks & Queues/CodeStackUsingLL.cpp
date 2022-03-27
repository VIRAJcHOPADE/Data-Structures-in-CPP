/*Implement a Stack Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
3. pop() :
It pops the element from the top of the stack and in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.
4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
5. size() :
It returns the size of the stack at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.
Sample Input 1:
6
1 13
1 47
4
5
2
3
Sample Output 1:
2
false
47
13
Sample Input 2:
4
5
2
1 10
5
Sample Output 2:
true
-1
false
*/
/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Stack {
	// Define the data members
    Node* head;
    int size;
   public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        size=0;
        
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        if(head==NULL){
            head=new Node(element);
            size++;
        }
        else{Node* newnode=new Node(element);
        newnode->next=head;
        head=newnode;
        size++;}
    }

    int pop() {
        // Implement the pop() function
        if(size==0){
            return -1;
        }
        Node* temp=head;
        int ans =temp->data;
        head=head->next;
        size--;
        delete temp;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(size==0){
            return -1;
        }
        return head->data;
    }
};