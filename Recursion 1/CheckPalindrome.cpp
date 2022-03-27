/*Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include <iostream>
using namespace std;

bool checkPalindrome(char input[]) {
    int i=0,l=0;
    while(input[i]!=0){
        i++;
        l++;
    }
    if(l==0||l==1)
        return true;
    if(input[0]!=input[l-1])
        return false;
    else
        input[l-1]='\0';
    return checkPalindrome(input +1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
