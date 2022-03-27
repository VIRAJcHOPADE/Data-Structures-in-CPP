/*You have been given an integer array/list(ARR) and a number 'num'. 
Find and return the total number of pairs in the array/list which sum to 'num'.
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2
*/

#include <iostream>
using namespace std;


int pairSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr,arr+n);
   
   //  int count=0;
   // for(int i=0;i<n;i++){
   //     for(int j=i+1;j<n;j++){
   //         if(arr[i]+arr[j]==num){
   //             count++;
   //         }
   //     }
   // }
   //  return count;
    unordered_map<int,int>m;
    
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    
    int count_twice=0;
    
    for(int i=0;i<n;i++){
        count_twice +=m[num-arr[i]];
    
         if(arr[i]==(num-arr[i])){
            count_twice--;
          }
       }
    return count_twice/2;  // as each pair is counted twice
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}