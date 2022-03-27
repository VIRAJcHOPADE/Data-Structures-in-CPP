/*Given an integer h, find the possible number of balanced
 binary trees of height h. You just need to return the count of
  possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/
using namespace std;
const long long m = 1e9 + 7;

int balancedBTs(int n) {

    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 3;
    }
    int a = balancedBTs(n - 1);
    int b = balancedBTs(n - 2);
    int temp1 = (int)(((long long)(a) * a) % m);
    int temp2 = (int)((2 * (long long)(a) * b) % m);
    int ans = (int)(((long long)temp1 + temp2) % m);
    return ans;
}