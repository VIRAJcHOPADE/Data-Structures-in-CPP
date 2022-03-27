/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10
*/
#include <iostream>
using namespace std;

int findUnique(int *arr, int n) {
    // Write your code here
    // int count=0;
    // for(int i=0;i<n-1;i++){
    //     count=0;
    //     for(int j=0;j<n;j++){
    //         if(arr[i]==arr[j]){
    //             count++;
    //         }
    //     }
    //     if(count==1){
    //         return arr[i];
    //     }
    // }
    // int count[10000];
    // for(int i=0;i<n;i++){
    //     count[arr[i]]++;
    // }
    // for(int i=0;i<10000;i++){
    //     if(count[i]==1){
    //         return i;
    //     }
    // }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            i++;
            continue;
        }
        else{
            return arr[i];
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}