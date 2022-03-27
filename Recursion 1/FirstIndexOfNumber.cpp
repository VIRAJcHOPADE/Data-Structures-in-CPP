/*Given an array of length N and an integer x, you need to find and return the 
first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Sample Input :
4
9 8 10 8
8
Sample Output :
1 */
#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
  
  if(size==0){
      return -1;
  }
    if(x==input[0]){
        return 0; 
    }
    int ans=-1;
     ans= firstIndex(input+1,size-1,x);
    if(ans==-1){
        return -1;
    }
    else{
        return ans+1;
    }
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}
