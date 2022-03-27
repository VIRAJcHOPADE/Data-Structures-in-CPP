/*Given an integer n, using phone keypad find out all the 
possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you.
 You just have to populate the output array and return the 
 count of elements populated in the output array.

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
    
int keypad(int num, string output[]){
   int x=num%10;
    if(x==0 || x==1){
        output[0]="";
        return 1;
    }
    int sizeofsmall=keypad(num/10,output);
    for(int i=1;i<key[x].size();i++){
        for(int j=0;j<sizeofsmall;j++){
            output[sizeofsmall*i+j]=output[j];
        }
    }
    for(int i=0;i<key[x].size();i++){
        for(int j=0;j<sizeofsmall;j++){
            output[sizeofsmall*i+j]=output[sizeofsmall*i+j]+key[x][i];
        }
    }
    return sizeofsmall*key[x].size();
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}