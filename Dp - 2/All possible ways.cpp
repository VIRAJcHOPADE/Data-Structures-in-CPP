/*Given two integers a and b. You need to find and return the count of possible 
ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 
2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2
*/

using namespace std;

int helper(int a, int b, int currNum, int currSum){
    int result = 0;
    int p = pow(currNum, b);
    while (p + currSum < a){
        result += helper(a, b, currNum + 1, currSum + p);
        currNum++;
        p = pow(currNum, b);
    }
    
    if (p + currSum == a){
        result++;
    }
    return result;
}

int getAllWays(int a, int b) {
    return helper(a, b, 1, 0);
}