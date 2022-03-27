/*Given a singly linked list of integers and an integer n, find and return the index 
for the first occurrence of 'n' in the linked list. -1 otherwise.
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
100
Sample Output 1 :
-1
Sample Input 2 :
2
10 20010 30 400 600 -1
20010
100 200 300 400 9000 -34 -1
-34
Sample Output 2 :
1
5
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

int findNodeRec(Node *head, int n)
{
	//Write your code here
    if(head==NULL)
        return -1;
    if(head->data==n)
        return 0;
    
    int x=findNodeRec(head->next,n);
    if(x==-1)
    {return x;}
    else
        return x+1;
    
}