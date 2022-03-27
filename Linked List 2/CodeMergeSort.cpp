 /*Given a singly linked list of integers, sort it using 'Merge Sort.'
 Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Output 2 :
2
-1
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

int length(Node *head) {
   
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}
Node* mergeTwoLLs(Node *head1, Node *head2) {
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return NULL;
    }
    Node *p=NULL,*q=NULL;
    if(head1->data<head2->data)
    {
        p=head1;
        q=head1;
        head1=head1->next;
        
        
    }
    else if(head1->data>=head2->data)
    {
        p=head2;
        q=head2;
        head2=head2->next;
       
        
    }
    while(head1&&head2)
    {
       if(head1->data<head2->data)
       {
           q->next=head1;
           q=head1;
           head1=head1->next;
           q->next=NULL;
       }
    else if(head1->data>=head2->data)
       {
           q->next=head2;
           q=head2;
           head2=head2->next;
           q->next=NULL;
       }
    }
    if(head1)
        q->next=head1;
    if(head2)
        q->next=head2;
    
    
    return p;
}

Node* mergeSort(Node *head) {
    //write your code here
   if(head==NULL|| head->next==NULL)
        {return head;}
     
     //breaking node into two half  
    Node *p=head;
    int n=length(head);
    for(int i=1;i<n/2;i++)
    {
        p=p->next;
    }
    Node *head1=p->next;
    p->next=NULL;
   /* Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *head1=head;
    Node *head2=slow->next;
    slow->next=NULL;*/
    
  head=mergeSort(head);
  head1=mergeSort(head1);
    
    return mergeTwoLLs(head,head1);
    
}