/*You are given an array of integers and a target K. 
You have to find the count of subsets of the given array that sum up to K.
Sample Input 1:
1
5 6
2 4 4 3 1
Sample Output 1:
3
Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]  
Sample Input 2:
2
8 8
1 4 1 3 1 1 2 3 
8 2
4 1 4 4 2 4 1 1
Sample Output 2:
30
4
*/

using namespace std;
int countSubsetSum(int *arr,int n,int index,int k){
    if(index==n){
        if(k==0){
            return 1;
        }
        return 0;
    }
    int count=0;
    if(k-arr[index]>=0){
        count+=countSubsetSum(arr,n,index+1,k-arr[index]); //first taking the value of array
    }
    
       count+=countSubsetSum(arr,n,index+1,k);// second skiping it to find the output 
    
    return count;
}
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << countSubsetSum(arr, n, 0, k) << endl;
        delete[] arr;
    }
    return 0;
    return 0;
}