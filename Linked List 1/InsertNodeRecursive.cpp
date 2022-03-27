/*You have been given a linked list of integers. Your task is to write a function
 that inserts a node at a given position, 'pos'.

 Sample Input 1:
1
3 4 5 2 6 1 9 -1
3 100
Sample Output 1:
3 4 5 100 2 6 1 9
Sample Input 2:
1 
3 4 5 2 6 1 9 -1
0 20
Sample Output 2:
20 3 4 5 2 6 1 9
*/
#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;


Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(i==0)
    {
        Node *p=new Node(data);
        p->next=head;
        
        return p;
    }
    
    if(head==NULL || i<0)
      return head;
    
   
    head->next=insertNode(head->next,i-1,data);
   
    return head;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}