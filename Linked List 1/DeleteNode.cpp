/*You have been given a linked list of integers. Your task is to 
write a function that deletes a node from a given position, 'POS'.
Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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

Node *deleteNode(Node *head, int pos)
{
	if(head == NULL){
        return head;
    }
    
    // if(length(head) < pos){
    //     return head;
    // }
    
    // int i=0;
    if(pos==0){
        Node *temp = head -> next;
        delete head;
        return temp;
    }
    
    
   int i = 1;
	Node *q = head -> next;
    Node *p = head;
    
    while(q != NULL){
        
        if(i == pos){
            p -> next = q -> next;
            delete q;
            return head;
        }
        
        p = p -> next;
        q = q -> next;
        i++;
    }
    
    return head;
    
   // Node *temp=head;
   //  while(temp!=NULL && i<pos-1){
   //      temp=temp->next;
   //       i++;
   //  }    
   //  if(temp !=NULL){
   //  Node *a=temp->next;
   //  Node *b=a->next;
   //  temp->next=b;
   //      delete a;
   //  }
   //  return head;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}