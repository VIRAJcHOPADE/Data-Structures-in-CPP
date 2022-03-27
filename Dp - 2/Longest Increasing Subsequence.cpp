/*Given an array with N elements, you need to find the length of the longest
 subsequence in the given array such that all elements of the subsequence
 are sorted in strictly increasing order.
 Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
*/
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
  int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int best=0;
    for(int i=0;i<n;i++){
        if(dp[i]>best){
            best=dp[i];
        }
    }
    delete[] dp;
    return best;
}