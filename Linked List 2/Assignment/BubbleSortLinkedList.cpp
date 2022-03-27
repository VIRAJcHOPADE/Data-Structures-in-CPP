/*Given a singly linked list of integers, sort it using 'Bubble Sort.'
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90 
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
int len(Node *head){
    Node *temp=head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
Node *bubbleSort(Node *head)
{
	// Write your code here
     if(head==NULL || head->next==NULL)
        return head;
    
   // node *curr=head;
    //node *prev=NULL;
    //node *n=head->next;
    for(int i=0;i<len(head);i++){
        Node *curr=head;
        Node *prev=NULL;
          // node *n=head->next;
        
        while(curr->next!=NULL) // traverse though LL
        {
            if(curr->data > curr->next->data)  // if nodes are to be swapped
            {
				if(prev)   //check if previous of the current node exist , u cant point on a garbage value
                {
                    // swapping using those 4 steps
                    Node* t=curr->next->next;
                    curr->next->next= curr;
                    prev->next=curr->next;
                    curr->next=t;
                    prev=prev->next;
                }
                else  //is it doent exist it would be head node 
                {
                    head= curr->next;
                    curr->next=head->next;
                    head->next=curr;
                    prev=head;
                }
                
            }
            else    // else you simply move to next node
            {
                prev=curr;
                curr=curr->next;
            }
        }
    }

  
    return head;
    
}