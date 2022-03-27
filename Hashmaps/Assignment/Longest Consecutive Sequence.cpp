/*You are given an array of unique integers that contain numbers in random order.
 You have to find the longest possible sequence of
 consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element.
 If the length of the longest possible sequence is one, then the output array must
  contain only single element.
  Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
*/

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    unordered_map<int ,int> mp;
    
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    int max=0;
    int k=0;
    for(int i=0;i<n;i++){
        int va=arr[i];
        //to avoid checking element multiple times
        if(va>=k and va<k+max)continue;
        int j=0;
        while(mp.count(va)>0){
            va++;
            j++;
        }
        if(j>max){
            max=j;
            k=arr[i];
        }
    }
    
        ans.push_back(k);
        ans.push_back(k+max-1);
    return ans;
}