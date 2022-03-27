/*Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, you need to convert the
string into corresponding integer and return the answer.

Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/

#include <iostream>
using namespace std;


int stringToNumber(char input[]) {
    // Write your code here
    int l=0;
    while(input[l]!= '\0'){
        l++;
    }
    
    int b=input[0];
    b=b-48;
    if(l==1){
        return b;
    }
    
    int ans=stringToNumber(input+1);
    
    return (b* pow(10,l-1)+ans);
    
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}