/*An integer matrix of size (M x N) has been given. 
Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/

using namespace std;
// DP bottom UP approch
int minCostPath(int **input, int m, int n)
{
    int **output = new int*[m];
    for (int i = 0; i < n; i++){
        output[i] = new int[n];
    }
    output[m - 1][n - 1] = input[m - 1][n - 1];

    for (int j = n - 2; j >= 0; j--){
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    for (int j = m - 2; j>= 0; j--){
        output[j][n - 1] = output[j + 1][n - 1] + input[j][n - 1];
    }

    for (int i = m - 2; i >= 0; i--){
        for (int j = n - 2; j >=0; j--){
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1])) + input[i][j];
        }
    }

    int ans = output[0][0];
    for (int i = 0; i < m; i++){
        delete []output[i];
    }
    delete []output;
    return ans;
}
//MEMOZISATION
int helper(int **input, int m, int n, int row, int col, int **output){
    if (row >= m || col >= n){
        return INT_MAX;
    }

    if (row == m - 1 && col == n - 1){
        return input[row][col];
    }

    if (output[row][col] != -1){
        return output[row][col];
    }

    int x = helper(input, m, n, row + 1, col, output);
    int y = helper(input, m, n, row, col + 1, output);
    int z = helper(input, m, n, row + 1, col + 1, output);

    output[row][col] = input[row][col] + min(x, min(y, z));

    return output[row][col];    
}

int minCostPath(int **input, int m, int n)
{
    int **output = new int*[m];
    for (int i = 0; i < n; i++){
        output[i] = new int[n];
        for (int j = 0; j < n; j++){
            output[i][j] = -1;
        }
    }
    int ans = helper(input, m, n, 0, 0, output);

    for (int i = 0; i < m; i++){
        delete []output[i];
    }
    delete []output;
    return ans;
}
// RECuRSIVE CodE
int helper(int **input, int m, int n, int row, int col)
{
    if (row == m - 1 && col == n - 1)
    {
        return input[row][col];
    }
    int side = INT_MAX, down = INT_MAX, diagonal = INT_MAX;
    if (row + 1 < m)
    {
        side = helper(input, m, n, row + 1, col);
    }
    if (col + 1 < n)
    {
        down = helper(input, m, n, row, col + 1);
    }
    if (row + 1 < m && col + 1 < n)
    {
        diagonal = helper(input, m, n, row + 1, col + 1);
    }

    return input[row][col] + min(side, min(down, diagonal));
}

int minCostPath(int **input, int m, int n)
{
    return helper(input, m, n, 0, 0);
}