/*Given an array consisting of positive and negative integers,
 find the length of the longest subarray whose sum is zero.
 ample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
*/
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    int pre[n+1]={};
    for(int i=1; i<=n; i++){
        pre[i]=pre[i-1]+arr[i-1];
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(pre[j]-pre[i-1]==0)
                ans=max(ans,j-i+1);
        }
    }
    return ans;
}
