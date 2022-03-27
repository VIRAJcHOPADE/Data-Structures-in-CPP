/*You have been given a head to a singly linked list of integers. Write a 
function check to whether the list given is a 'Palindrome' or not.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
*/
// *****************************************************************

int length(Node *head) {
   
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

Node *reverse(Node*head2)
{
    Node *p=head2,*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head2=q;
    return q;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    if(head==NULL){
        return true;
    }
    Node *p=head;
    int x=length(head)/2;
    
    for(int i=1;i<x;i++)
    {
        p=p->next;
    }
    Node *head2=p->next;
    p->next=NULL;
   head2= reverse(head2);
   
    while(head&&head2)
    {
        if(head->data!=head2->data)
            return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}