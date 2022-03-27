/*You have been given two stacks that can store integers as the data. 
Out of the two given stacks, one is populated and the other one is empty. 
You are required to write a function that reverses the populated stack using the one which is empty.
Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.
Sample Input 2:
5
2 8 15 1 10
Sample Output 2:
2 8 15 1 10
*/
#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    int x;
    while(!input.empty()){
        x=input.top();
        extra.push(x);
        input.pop();
    }
    input=extra;
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}