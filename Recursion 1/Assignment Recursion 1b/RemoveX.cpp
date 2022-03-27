Given a string, compute recursively a new 
string where all 'x' chars have been removed.
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

#include <iostream>
using namespace std;

void removeX(char input[]) {
    // Write your code here
    int l=0;
    while(input[l]!='\0'){
        
        l++;
    }
    if(input[0] == '\0'){
        return;
    }
    if(input[0]=='x'){
        for(int i=0;i<l;i++){
            input[i]=input[i+1];
        }
       removeX(input);
    }
    removeX(input+1);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}