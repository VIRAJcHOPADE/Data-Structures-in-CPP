/*Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Sample Input 1 :
2
1 2
Sample Output 1 :
false
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
*/

#include <iostream>
using namespace std;

bool helper(int* arr, int n, int start, int lsum, int rsum) 
{ 

    if (start == n) {
        return lsum == rsum; 
    }
    if (arr[start] % 5 == 0) {
        lsum += arr[start]; 
    }
    else if (arr[start] % 3 == 0){ 
        rsum += arr[start]; 
    }
    else{
        return helper(arr, n, start + 1, lsum + arr[start], rsum) 
           || helper(arr, n, start + 1, lsum, rsum + arr[start]); 
   }
    return helper(arr, n, start + 1, lsum, rsum); 
}
bool splitArray(int *input, int size) {
    return helper(input,size, 0, 0, 0); 
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}