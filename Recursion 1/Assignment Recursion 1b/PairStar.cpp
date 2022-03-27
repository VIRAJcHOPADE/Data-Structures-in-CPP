/*Given a string S, compute recursively a new string where identical chars 
that are adjacent in the original string
 are separated from each other by a "*".

Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

#include <iostream>
using namespace std;

void pairStar(char input[]) {
    // Write your code here
    int l=0;
    while(input[l]!='\0'){
        l++;
    }
    
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==input[1]){
        for(int i=l;i>=1;i--){
            input[i+1]=input[i];
        }
        input[1]='*';
        pairStar(input);
    }
    pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}