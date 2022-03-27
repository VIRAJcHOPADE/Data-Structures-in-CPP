/*You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return 
the element which occurs in the array first.
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
3
1 4 5
Sample Output 2 :
1
*/

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> frek;
    int key=0;
    int value=0;
    for(int i=0;i<n;i++){
        frek[arr[i]]++;
        }
    for(int i=0;i<n;i++){
        if(frek[arr[i]]>value){
            key=arr[i];
            value=frek[arr[i]];
        }
    }
    return key;
    
}