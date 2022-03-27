/*Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/
  
#include <iostream>
#include <vector>

using namespace std;
void printDFS(int** graph ,int v,int s,bool* visited ,vector<int> &ans)
{ 
    
  ans.push_back(s);
    visited[s]= true;
    
    for(int i =0 ;i< v ;i++)
    {
        if(!visited[i]&& graph[s][i]==1)
    	printDFS( graph ,v, i ,visited,ans);
    }
    
}
void printDFS(int** graph ,int v,int s,bool* visited )
{
    vector<int >ans;
    printDFS( graph ,v, s,visited,ans);
    
    sort(ans.begin() , ans .end());
        
    for( auto i :ans )
        cout << i<<" ";
        
    
}
int main()
{
  int V, E;
  cin >> V >> E;
    int** graph = new int * [V];
    for(int i=0 ;i <V ;i++)
    {
        graph[i]=new int[V];
        for( int j=0 ;j<V ;j++)
            graph[i][j]=0; 
    }
    for(int i=0 ;i< E ;i++)
    {
        int x,y; 
        cin>>x>>y;
        graph[x][y]=1;
        graph[y][x]=1;
    }
    bool * visited=new bool[V];
    for(int i=0 ;i< V;i++)
        visited[V]= false;
    for(int i=0;i<V;i++)
    {
   		 if(!visited[i])
         { printDFS(graph,V , i,visited );
          cout<<endl;}
        
	}
    delete []  visited;
    for(int i = 0 ;i <V ;i++)
        delete [] graph[i];
    delete[] graph;
  return 0;
}