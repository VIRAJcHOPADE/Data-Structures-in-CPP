/*For a given singly linked list of integers, arrange the elements such 
that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40
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

Node *evenAfterOdd(Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
	//write your code here
    Node *even= new Node(0);
    Node *etail=even;
    
    Node *odd=new Node(0);
    Node *otail=odd;
    
   while(head)
    {
        if(head->data%2==0)
        {
            
            etail->next=head;
            etail=head;
            head=head->next;
            etail->next=NULL;
        }
        else
        {
            otail->next=head;
            otail=head;
            head=head->next;
            otail->next=NULL;
        }
    }
        otail->next=even->next;
        return odd->next;
}