/*Afzal has been working with an organization called 'Money Traders' for the past few years.
 The organization is into the money trading business. 
 His manager assigned him a task. For a given array/list of 
 stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number 
of consecutive days(starting from today and going backwards) for which 
the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], 
then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
Sample Input 1:
4
10 10 10 10
Sample Output 1:
1 1 1 1 
Sample Input 2:
8
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
*/
#include <iostream>
using namespace std;


int* stockSpan(int *price, int size)  {
    
	int *span = new int[size];
    stack<int> s;
    int n = size;
    s.push(0);
    span[0]=1;
    for(int i=1;i<n;i++){
        while(!s.empty() && price[s.top()]<price[i]){
            s.pop();
        }
         if(s.empty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-s.top();
        }
        s.push(i);
    }
    return span;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}