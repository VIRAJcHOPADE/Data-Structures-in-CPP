/*Gary has two string S and V. Now, Gary wants to know the length shortest
 subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/



using namespace std;
int solve(string s,string v)
{
	int m =s.size();
	int n =v.size();

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[m][i] = n-i;
	}

	for (int i = 0; i < m+1; ++i)
	{
		dp[i][n] = m-i;
	}

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			int k = j;
			
			while(k<v.size())
			{
				if(v[k]==s[i])
				{
					break;
				}
				k++;
			}
			if (k==v.size())
			{
				dp[i][j] = 1;
				//return 1;
			}

			int c1 = 1+dp[i+1][k+1];
			int c2 = dp[i+1][j];

			dp[i][j] = min(c1, c2);
		}
	}

	return dp[0][0];


}