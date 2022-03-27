/*A thief robbing a store can carry a maximal weight of W into his knapsack. 
There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
 What would be the maximum value V, that the thief can steal?
 Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
*/
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    if(maxWeight==0 || n==0){
        return 0;
    }
    if(weights[n-1]<=maxWeight)
    {
    return max(values[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]),
               knapsack(weights,values,n-1,maxWeight));
    }
    else
    {
       return knapsack(weights,values,n-1,maxWeight); 
    }
}