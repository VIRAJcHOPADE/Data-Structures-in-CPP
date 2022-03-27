/*Given an undirected graph G(V, E) and two vertices v1 and v2 
(as integers), check if there exists any path between them or not. 
Print true if the path exists and false otherwise.
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/

using namespace std;

bool haspathDFS(int** edges,int n ,int start, int end , bool* visited){
    if(edges[start][end]==1){
        return true;
    }
    visited[start]=true;
    for(int i = 0 ; i < n ; i++){
      if(!visited[i] && edges[start][i]==1 & i!=start)  {
          if(haspathDFS(edges,n,i,end,visited))  return true;
          //return true;
      }
    }
    return false;
}


int main() {
    // Write your code here
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v,e;
    cin>>v>>e;
     int **edges=new int*[v];
    for(int i = 0 ; i < v ; i++ ){
        edges[i] = new int[v];
        for(int j = 0 ; j < v ; j++){
            edges[i][j]=0;
        }
    }
    for(int i = 0 ; i < e ; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool[v];
    memset(visited,false,sizeof(visited));
    int start,end;
    cin>>start>>end;
    bool ans = haspathDFS(edges,v,start,end,visited);
     ans?cout<<"true":cout<<"false";
    for(int i=0;i<v;i++){
        delete [] edges[i];
    }
    delete[] edges;
    delete[] visited;
}