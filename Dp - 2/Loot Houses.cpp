/*A thief wants to loot houses. He knows the amount of money in each house.
 He cannot loot two consecutive houses. 
Find the maximum amount of money he can loot.
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90*/
int maxMoneyLooted(int *arr, int n)
{
	//Write your code hereint 
    int loot[n+1];
    loot[0]=arr[0];
    loot[1]=max(arr[1],loot[0]);
    for(int i=2;i<n;i++){
        loot[i]=max((loot[i-2]+arr[i]),loot[i-1]);
    }
    return loot[n-1];
}