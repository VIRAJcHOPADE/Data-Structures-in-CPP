/*Write a program to find x to the power n (i.e. x^n). 
 Take x and n from the user. You need to return the answer.


 Sample Input 1 :
 3 4
 Sample Output 1 :
 81
 Sample Input 2 :
 2 5
 Sample Output 2 :
 32

 code:*/
#include<iostream>
using namespace std;
int power(int x, int n) {
    // cout<<n<<endl;
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    int final_power=power(x,n-1);
    
    int output=x*final_power;
    
    return output;
}

int main(){
    int x, n;
    cin >> x >> n;
  
    cout << power(x, n) << endl;
}
