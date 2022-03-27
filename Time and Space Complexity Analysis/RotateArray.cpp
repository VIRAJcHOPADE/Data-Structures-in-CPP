/*You have been given a random integer array/list(ARR) of size N. Write a function that 
rotates the given array/list by D elements(towards the left).
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/
#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
//     int z=d%n; ////important in case     d>size
//     int temp[z];
//     for(int i=0;i<z;i++)
//     {
        
//         temp[i]=input[i];
        
//     }
//     for(int i=0;i<n-z;i++)
//     {
        
//         input[i]=input[i+z];
        
//     }
//     for(int i=0;i<z;i++)
//     {
        
//         input[n-z+i]=temp[i];
        
//     }
    int ar[n];
    for(int i=0; i<n; i++)
        ar[i]=input[i];
    
    for(int i=0; i<n; i++){
        input[i]=ar[(i+d)%n];
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}