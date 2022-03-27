/*You are given with an array of integers and an integer K. 
You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int>mp;
    int pair_count=0;
    for(int i=0;i<n;i++){
        int count=arr[i]+k;
        pair_count+=mp[count];
        if(k!=0){
            count=arr[i]-k;
            pair_count+=mp[count];
        }
        mp[arr[i]]++;
    }
    return pair_count;
}
// arr[i]*(arr[i]-k)  + arr[i]*(arr[i]+k)
//cnt[5]*cnt[3]