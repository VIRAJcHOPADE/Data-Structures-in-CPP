/*Given an integer h, find the possible number of balanced 
binary trees of height h. You just need to return the count 
of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

using namespace std;
const int m = 1e9 + 7;
int balancedBTs(int n) {
    // Write your code here
      if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 3;
    }

    int *dp = new int[n + 1];
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= n; i++)
    {
        int x = (int)(((long long)dp[i - 1] * dp[i - 1]) % m);
        int y = (int)((2 * (long long)dp[i - 1] * dp[i - 2]) % m);
        dp[i] = (int)(((long long)x + y) % m);
    }
    int result = dp[n];
    delete[] dp;
    return result;
}