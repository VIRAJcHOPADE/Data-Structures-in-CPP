/*Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values.
 Non zero values lie in the range: [1, 9]. Cells with zero value indicate 
 that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku 
board can be solved, then print true, otherwise print false.

Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/

using namespace std;
bool find_empty(int board[][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool check_row(int board[][9],int i,int j,int num){
    for(int row=0;row<9;row++){
        if(board[row][j]==num){
            return false;
        }
    }
    return true;
}

bool check_col(int board[][9],int i,int j,int num){
    for(int col=0;col<9;col++){
        if(board[i][col]==num){
            return false;
        }
    }
    return true;
}

bool check_block(int board[][9],int i,int j,int num){
    int checki=0;
    if(i>=0 && i<3){
        checki=0;
    }else{
        if(i>=3 && i<6){
            checki=3;
        }else{ checki = 6;}
    }
    
    int checkj=0;
    if(j>=0 && j<3){
        checkj=0;
    }else{
        if(j>=3 && j<6){
            checkj=3;
        }else{ checkj = 6;}
    }
    for(int row=checki;row<checki+3;row++){
        for(int col=checkj;col<checkj+3;col++){
            if(board[row][col]==num){
                return false;
            }
        }
    }
    return true;
    // int rowFactor = i-(i%3);
    // int colFactor = j-(j%3);
    // for(int i=0;i<3;i++){
    //     for(int j=0;i<3;j++){
    //         if(board[i+rowFactor][j+colFactor] == num){
    //             return false;
    //         }
    //     }
    // }
    // return true;
}

bool solve_sudoku(int board[][9]){
    int row,col;
    bool found=find_empty(board,row,col);
    if(found){
        // go from 1 to 9 and
        for(int i=0;i<=9;i++){
            bool rowcheck=check_row(board,row,col,i);
            bool colcheck=check_col(board,row,col,i);
            bool blockcheck=check_block(board,row,col,i);
            if(rowcheck&&colcheck&&blockcheck){
                board[row][col]=i;
                bool findifvalid=solve_sudoku(board);
                if(findifvalid){
                    return true;
                }
                board[row][col]=0;
            }
        }
        // check row
        // check col
        // check block
        // fill that row,col and call solve_sudoku again
        // if returned true - return true
        // if returned false - try for another num
    }else{
        // no empty means sudoku is filled or solved
        return true;
    }
    return false;
}

bool sudokuSolver(int board[][9]){

    return solve_sudoku(board);

}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}