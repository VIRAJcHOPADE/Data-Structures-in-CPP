/*Given an NxM matrix that contains only 0s and 1s, find out the
 size of the maximum square sub-matrix with all 0s. 
You need to return the size of the square matrix with all 0s.
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/

using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    for (int i=0;i<row;i++)
        
    { 
        for (int j=0;j<col;j++)
        
       if (arr[i][j]==1)
           arr[i][j]=0; 
          else arr[i][j]=1;
       }
    int max=0;
    for (int i=1;i<row;i++)
    {  for (int j=1;j<col;j++)
         {    if (arr[i][j]==0) continue;
             arr[i][j]=min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
              if (max<arr[i][j]) max=arr[i][j];
         }
      
    }
    
   return max; 
}