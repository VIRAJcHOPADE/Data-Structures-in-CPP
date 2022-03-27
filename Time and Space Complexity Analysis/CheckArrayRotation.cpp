/*You have been given an integer array/list(ARR) of size N.
 It has been sorted(in increasing order) and then rotated by
  some number 'K' in the right hand direction.
Your task is to write a function that returns the value of 'K',
 that means, the index from which the array/list has been rotated.
 Sample Input 1:
1
6
5 6 1 2 3 4
Sample Output 1:
2
Sample Input 2:
2
5
3 6 8 9 10
4
10 20 30 1
Sample Output 2:
0
3
*/
#include <iostream>
using namespace std;

int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    if(size==0){
        return 0;
    }
    if(input[size-1]<input[size-2]){
        return size-1;
    }
    
   int start=0;
    int end=size-1;
    while(start<end){
        int mid=(start+end)/2;
        if(input[mid]<=input[mid-1] && input[mid]<=input[mid+1]){
            return mid;
        }
        else if(input[mid]>input[end]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}