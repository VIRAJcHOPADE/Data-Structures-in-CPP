/*You are given with an integer k and an array of integers that contain
 numbers in random order. Write a program to find k smallest numbers from 
 given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output 1 :
1 2 3 5 
*/

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    vector<int> ans;
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);  
    }
    for(int i=k;i<n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}