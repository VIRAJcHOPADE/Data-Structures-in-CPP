/*You have been given a random integer array/list(ARR) and a number X. 
Find and return the triplet(s) in the array/list which sum to X.
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5
*/
#include <iostream>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	
    int cnt=0;
	sort(arr,arr+n);
    for(int k=0; k<n; k++){
        
        int sum=num-arr[k];
        if(sum<0)break;
        
        int i=k+1, j=n-1;
        
        while(i<j){
            if(arr[i]+arr[j]==sum){
                if(arr[i]==arr[j]){
                    int len=j-i+1;
                    cnt+=(len)*(len-1)/2;
                    break;
                }
                int a=0,b=0;
                int x=arr[i],y=arr[j];
                while(arr[i]==x){
                    a++,i++;
                }
                while(arr[j]==y){
                    b++,j--;
                }
                cnt+=a*b;
            }
            else if(arr[i]+arr[j]>sum)
                j--;
            else i++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}