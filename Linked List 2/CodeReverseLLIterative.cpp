/*Given a singly linked list of integers, reverse 
it iteratively and return the head to the modified list.
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10 
*/
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    // Node *curr=head;
    // Node *prev=NULL;
    // Node *nex;
    // while(curr){
    //     nex=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=nex;
    //     nex=nex->next;
    // }
    // return prev;
    Node *p=head,*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    
    return q;
}