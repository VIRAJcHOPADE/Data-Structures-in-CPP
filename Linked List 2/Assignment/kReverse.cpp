/*Given a singly linked list of integers, reverse the nodes of the linked list 
'k' at a time and return its modified list.
 'k' is a positive integer and is less than or equal to the length of the 
 linked list. If the number of nodes is not a multiple
  of 'k,' then left-out nodes, in the end, should be reversed as well.
  Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10 
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
Node *reverse_linked_list_rec(Node *head)
{
    //write your recursive code here
  if(head==NULL || head ->next ==NULL)
      return head;
    
    Node* smallans=reverse_linked_list_rec(head->next);
    Node*tail= head->next;
    tail->next=head;
    head ->next =NULL;
    
    return smallans;
                                         
}
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
   Node * h1=head,*t1=head;
    int count=1;
    //move to kth node
    while(count<k && t1->next)
    {
        t1=t1->next;
        count++;
    }
    Node*h2=t1->next;
    t1->next=NULL;
    //break this part from LL 
    // and reverse it
    h1=reverse_linked_list_rec(h1);
    t1=h1;
    
    // iterate till next k nodes
    while(count>1)
    {
        t1=t1->next;
        count--;
    }
    
    // now call recuursion to kreverse remainng LL
    h2=kReverse(h2,k);
    
    //connect the LL
    t1->next=h2;
    
    return h1;
}