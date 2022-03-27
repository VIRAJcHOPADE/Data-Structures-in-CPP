/*You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list 
is also sorted(in ascending order) and return the new head to the list.
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12 
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
     if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node *finalh=NULL;
     Node *tail=NULL;
    if(head1->data <= head2->data){
        finalh=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        finalh=head2;
        tail=head2;
        head2=head2->next;
    }
   
    while(head1 && head2){
        if(head1->data <= head2->data){
            
            tail->next=head1;
            tail=head1;
            head1=head1->next;
            
        }
        else if(head1->data >head2->data){
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }
    if(head1){
        tail->next=head1;
    }
    if(head2){
        tail->next=head2;
    }
    return finalh;
}