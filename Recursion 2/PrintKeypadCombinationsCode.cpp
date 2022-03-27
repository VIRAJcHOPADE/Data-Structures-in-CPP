/*Given an integer n, using phone keypad find out and 
print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. 
Just print different strings in new lines.
Input Format :
Integer n
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

string key[]={" ", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printKeypad(int num,string str=""){
    
    if(num==0){
        cout<<str<<endl;
        return;
    }
    int x=num%10;
    for(int i=0;i<key[x].size();i++){
        printKeypad(num/10,key[x][i]+str);
    }
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}