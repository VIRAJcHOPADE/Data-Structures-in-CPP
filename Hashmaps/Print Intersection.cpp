/*You have been given two integer arrays/lists (ARR1 and ARR2) of 
size N and M, respectively. You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists
 contain a particular value or to put it in other words,
 when there is a common value that exists in both the arrays/lists.
 Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2
*/

using namespace std;
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> map;
    
    for(int i=0;i<n;i++){
        map[arr1[i]]++;
    }
    
    for(int i=0;i<m;i++){
        if(map[arr2[i]]>0){
            
            cout<<arr2[i]<<endl;
            map[arr2[i]]--;
        }
    }
}