/*You have been given a singly linked list of integers along with two integers, 'i,' and 'j.'
 Swap the nodes that are present at the 'i-th' and 'j-th' positions.
 Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
     Node *p=head;
     Node *q=head;
    
    for(int index=0;index<i;index++)
    {
        p=p->next;
    }
     for(int index=0;index<j;index++)
    {
        q=q->next;
    }
    
    int x=p->data;
    p->data=q->data;
    q->data=x;
    
    return head;
}