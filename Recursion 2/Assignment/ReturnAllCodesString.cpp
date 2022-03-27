/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. Write a program to return the list of all possible codes
 that can be generated from the given string

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include <iostream>
using namespace std;

// #include <bits/stdc++.h>
// using namespace std;

// void help(string input,string out,vector<string> &str)
// {
//     if(input.size()==0)
//     {
//         str.push_back(out);
//         return;
//     } 
//     char c1=(input[0]-48)+96;
//     if(input[0]=='0')
//     {
//         return;
//     }
//     help(input.substr(1),out+c1,str);

//     if(input.size()>1){
//         int d=(input[0]-48)*10+(input[1]-48);
//         if(d>26){
//             return;
//         }
//         char c2=96+d;
//         help(input.substr(2),out+c2,str);
//     }
// }
// int getCodes(string input, string output[10000]) {
//     vector<int>str;
//     string out="";
//     help(input,out,str);
//     for(int i=0;i<str.size();i++){
//         output[i]=str[i];
//     }
//     int x=str.size();
//     return x;
// }


#include <string.h>
using namespace std;
int i=0;
void print(string input,string output[],string asf)
{
    if(input.size()==0)
    {
        output[i++]=asf;
        return;
    }
    int num = input[0]-'0';
    char pf = 'a' + num - 1;
    print(input.substr(1),output,asf+pf);
    int num2 = (input[0] - '0')*10+(input[1] - '0');
    if(10<=num2 && num2<=26)
    {
        char pf2 ='a'+num2-1;
        print(input.substr(2),output,asf+pf2);
    }
}
int getCodes(string input, string output[10000])
{
    string asf = "";
    print(input,output,asf);
    return 10000;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}