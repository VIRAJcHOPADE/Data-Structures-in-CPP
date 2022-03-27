/*A thief is robbing a store and can carry a maximal weight of W into his knapsack.
 There are N items and ith item weighs wi and is of value vi. Considering the constraints
  of maximum weight that knapsack can carry, you have to find and return
 the maximum value that thief can generate by stealing items.
 Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*/

using namespace std;
              //DP BOTTOM UP APPROCH

int knapsack(int* wt, int* values, int n, int W) {
    int output[n+1][W+1];
      for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0){
                output[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]<=j){
                output[i][j]=max(values[i-1]+output[i-1][j-wt[i-1]],
                                output[i-1][j]);
            }
            else{
                output[i][j]=output[i-1][j];
            }
        }
    }
    return output[n][W];
}

              //MEMOZISATION
// int helper(int* wt,int* values,int n,int W,int** output){
//     if(W==0 || n==0){
//         return 0;
//     }
//     if(output[n][W]!=-1){
//         return output[n][W];
//     }
//     if(wt[n-1]<=W){
//         return output[n][W]=max(values[n-1]+helper(wt,values,n-1,W-wt[n-1],output),
//                                helper(wt,values,n-1,W,output));
//     }
//     else{
//         return output[n][W]=helper(wt,values,n-1,W,output);
//     }
// }
    
    
// int knapsack(int* wt, int* values, int n, int W) {
// 	int **output = new int*[n + 1];
//     for (int i = 0; i <= n; i++){
//         output[i] = new int[W + 1];
//         for (int j = 0; j <= W; j++){
//             output[i][j] = -1;
//         }
//     }
//     int ans = helper(wt, values, n, W, output);
//     for (int i = 0; i <= n; i++){
//         delete []output[i];
//     }
//     delete []output;
//     return ans;
// }