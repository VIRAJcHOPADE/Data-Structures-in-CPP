/*Given a random integer array A of size N. 
Find and print the count of pair of elements in the array which sum up to 0.
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
*/

int pairSum(int *arr, int n) {
	// Write your code here
    int paircount=0;
    unordered_map<int,int>mp;
    
    for(int i=0;i<n;i++){
        int complement=-arr[i];
        if(mp.find(complement)!=mp.end()){
            paircount+=mp[complement];
        }
        ++mp[arr[i]];
    }
    return paircount;
}