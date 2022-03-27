/*Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

void merge(int input[], int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a1[n1];
    int b1[n2];
    
    for(int i=0;i<n1;i++){
        a1[i]=input[i+l];
    }
    for(int i=0;i<n2;i++){
        b1[i]=input[i+mid+1];
    }
    int i=0,j=0,k=l;
    
    while(i<n1 && j<n2){
        if(a1[i]<=b1[j]){
            input[k]=a1[i];
            i++; k++;
        }
        else{
            input[k]=b1[j];
            k++;j++;
        }
    }
    while(i<n1){
        input[k]=a1[i];
        i++;k++;
    }
    while(j<n2){
        input[k]=b1[j];
        k++;
        j++;
    }
}
      
void mergesort1(int input[], int l,int r){
    int mid=(l+r)/2;
    if(l<r){
       mergesort1(input,l,mid);
       mergesort1(input,mid+1,r);
       merge(input,l,mid,r); 
    }
}
           
void mergeSort(int input[], int size){
	// Write your code here
  if(size<=0){
      return;
  }
    mergesort1(input,0,size-1);
    
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}