/*Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.
The data members should be private.
You need to implement the following public functions :
1. Constructor:
It initialises the data members as required.
2. enqueue(data) :
This function should take one argument of type integer. It enqueues the element into the queue and returns nothing.
3. dequeue() :
It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.
4. front() :
It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.
5. getSize() :
It returns the size of the queue at any given instance of time.
6. isEmpty() :
It returns a boolean value indicating whether the queue is empty or not.
Sample Input 1:
7
1 17
1 23
1 11
2
2
2
2
Sample Output 1:
17
23
11
-1
Sample Input 2:
3
2
1 10
4
Sample Output 2:
-1 
1
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


class Queue {
    
    Node *head,*last;
    int size;
    
    
    public :
    
    
    Queue() {
       last=head=NULL;
        size=0;
        
    }
    
    void enqueue(int data) {
        Node *newnode= new Node(data);
        if(head==NULL)
        {
            head=last=newnode;
            size++;
        }
        else
        {
            last->next=newnode;
            last=newnode;
            size++;
        }
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
       if(size==0){
           return true;
       }
        else{
            return false;
        }
    }
    
    int dequeue() {
        // Return 0 if queue is empty
        if(size==0)
            return -1;
        int ans=head->data;
        Node *p=head;
        head=head->next;
        delete p;
        size--;
        return ans;
    }
    
    int front()  {
          if(size==0){
            return -1; 
        }
        // Return 0 if queue is empty
        return head->data;
    }
};    