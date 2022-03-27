/*For the given infinite supply of coins of each of denominations, 
D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total 
number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
Sample Input 1 :
3
1 2 3
4
Sample Output 1 :
4
Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
Sample Input 2 :
6
1 2 3 4 5 6
250
Sample Output 2 :
13868903
*/


using namespace std;
int countWaysToMakeChange(int S[], int m, int n){
	int i, j, x, y; 
  
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 

}