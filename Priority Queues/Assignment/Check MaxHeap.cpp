/*Given an array of integers, check whether it represents max-heap or not.
 Return true if the given array represents max-heap, else return false.
 Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
*/
bool isMaxHeap(int arr[], int n) {
    // Write your code here
   int p = 0;
    int l = 2*p+1;
    int r = 2*p+2;
    while(l<n){
        if(arr[p] > arr[l] && arr[p] > arr[r]){
            p = p + 1;
            l = 2 * p + 1;
            r = 2 * p + 2;
        }
        if(arr[p] < arr[l] && arr[p] < arr[r]){
            return false;
            break;
        }
    }
    
}