/*Given k different arrays, which are sorted individually (in ascending order).
 You need to merge all the given arrays such that output array should be sorted
  (in ascending order).
Hint : Use Heaps.
Sample Input 1:
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1:
0 1 2 5 6 9 45 78 90 100 234
*/

using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int> ans;
    
    priority_queue<int, vector<int>,greater<int>> pq;
    
    for(auto v : input){
       for(auto i: *v){
           pq.push(i);
       }
    }
    int n=pq.size();
    for(int i=0;i<n;i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}