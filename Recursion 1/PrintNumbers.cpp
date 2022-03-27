/*Given is the code to print numbers from 1 to n in increasing order recursively. 
But it contains few bugs that you need to rectify such that all the test cases pass.
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
Sample Input 2 :
 4
Sample Output 2 :
1 2 3 4  */

#include<iostream>
using namespace std;

int print(int n){
    if(n == 0){
        return 1;
    }
    
    print(n - 1);
    cout << n << " ";
}


int main(){
    int n;
    cin >> n;
  
    print(n);
}