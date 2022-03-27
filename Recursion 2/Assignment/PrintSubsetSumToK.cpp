/*Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/
#include <iostream>
using namespace std;

void helper(int input[],int size, int k,int output[],int m){
    //base case
    if(size==0){
        if(k==0){

            for(int i=0;i<m;i++){
                cout<<output[i]<<" ";

            }
            cout<<endl;

            return ;

        }
        else {
            return ;
        }
    }
    //recursion call
    helper(input+1,size-1,k,output,m);
    //calculation part
    // int newarr[10000];
    // for(int i=0;i<m;i++){
    //     newarr[i]=output[i];
    // }
    // newarr[m]=input[0];
    helper(input+1,size-1,k-input[0],output,m+1);

}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here

    int output[10000];
    helper(input,size,k,output,0);

}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}