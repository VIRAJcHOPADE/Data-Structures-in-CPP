/*You have been given a singly linked list of integers. Write a function to
 print the list in a reverse order.
To explain it further, you need to start printing the data from the tail 
and move towards the head of the list,
 printing the head data at the end.
 Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1
Sample Output 2 :
3 2 1
50 40 30 20 10
*/
void printReverse(Node *head)
{
    //Write your code here
    if(head==NULL){
        return;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
}