/*You are given an integer N and a binary 2D array of size N*N. 
The given binary matrix represents a maze and a rat starts from 
the top left cell and has to reach to the bottom right cell of the maze. 
The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies 
the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left 
cell to the bottom right cell of the given binary matrix.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
*/
/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/ 

using namespace std;
void print1(vector<vector<bool>> &visited){
    for(int i=0;i<visited.size();i++){
        for(int j=0;j<visited[i].size();j++){
            cout<<visited[i][j]<<" ";
        }
    }
    cout<<endl;
    return;
}
void helper(int **maze,int n,vector<vector<bool>> &visited,int i,int j){
    if(i>=n||i<0||j>=n||j<0||maze[i][j]==0||visited[i][j]==true)
        return;
    visited[i][j]=1;
    if(i==n-1&&j==n-1){
        print1(visited);
        visited[i][j]=false;
        return;
    }
    helper(maze,n,visited,i-1,j);
    helper(maze,n,visited,i+1,j);
    helper(maze,n,visited,i,j-1);
    helper(maze,n,visited,i,j+1);
    visited[i][j]=false;
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    int **maze=new int*[n];
    for(int i=0;i<n;i++){
        maze[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    }
   	vector<vector<bool>> visited(n,vector<bool>(n,false)); 
    helper(maze,n,visited,0,0);
    for(int i=0;i<n;i++)
        delete []maze[i];
    delete []maze;
	return 0;
}
 