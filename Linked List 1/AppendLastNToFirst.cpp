/*You have been given a singly linked list of integers along with an integer 'N'.
 Write a function to append the last 'N' nodes towards the 
front of the singly linked list and returns the new head to the list.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100 -1
4
Sample Output 2 :
90 61 67 100 10 6 77 
*/
#include <iostream>

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

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
/******************************************************************/
int length(Node *head) {
    
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    
    // important edge case in every LL question
    if(head == NULL)
        return NULL;
    
     Node *p=head;
    Node *q=head;
    int len = length(head);
    for(int i=1;i<len-n;i++)
    {
        p=p->next;
    }
    for(int i=1;i<len;i++)
    {
        q=q->next;
    }
    q->next=head;  //circular LL
    head=p->next;
    p->next=NULL; //breaking that circular LL
    
    return head;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}