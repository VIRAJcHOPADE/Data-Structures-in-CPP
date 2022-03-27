/*Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers),
 find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
*/

using namespace std;

void getpathBFS(bool **edges, int n , int start, int end , unordered_map<int,bool> visited){
    queue<int> q;
    unordered_map < int , int > mp;
    bool path_exist=false;
    q.push(start);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t==end){
            //visited[end]=true;
            path_exist=true;
            break;
        }
        for(int i = 0; i < n ; i++){
            if(edges[t][i]==1 && !visited[i] && i!=start){
                q.push(i);
                visited[i]=true;
                mp[i]=t;
            }
        }
    }
if(!path_exist){
    return;
}
int k = end;
cout<<end<<" ";
while(k!=start){
    cout<<mp[k]<<" ";
    k=mp[k];
}
}

int main() {
    // Write your code here
      int n,e;  //n->vertices,e->edges
    cin>>n>>e;
    bool **edges=new bool*[n];  //edges array(2D)
    for(int i=0;i<n;i++){
        edges[i]=new bool[n];
        for(int j=0;j<n;j++){
            edges[i][j]=false;
        }
    }
    //taking input of edges
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    //visited map
  unordered_map<int,bool> visitedMap;
    for(int i=0;i<n;i++){
        visitedMap[i]=false;
    }
    //call your working function below
    int start,end;
    cin>>start>>end;
    getpathBFS(edges,n,start,end,visitedMap);
    for(int  i = 0 ; i < n ; i++ ){
        delete [] edges[i];
    }
    delete [] edges;
    
}