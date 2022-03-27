/*You have been given a singly linked list of integers. Write a function that returns the 
index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.
Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
Sample Output 1 :
2
-1
 Explanation for Sample Output 1:
In test case 1, 'N' = 5 appears at position 2 (0-based indexing) in the given linked list.

In test case 2, we can see that 'N' = 6 is not present in the given linked list.
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

int findNode(Node *head, int n){
    // Write your code here.
    
    Node *temp=head;
    
    int i=0;
    
    while(temp){
        if(temp->data==n){
            return i;
        }
        temp=temp->next;
        i++;
    }
    return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}