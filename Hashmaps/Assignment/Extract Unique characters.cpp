/*Given a string S, you need to remove all the duplicates. 
That means, the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> frek;
    string str2;
    int n=str.size();
    for(int i=0; i<n;i++){
        if(frek[str[i]]==0){
            str2.push_back(str[i]);
            frek[str[i]]++;
        }
    }
    
    return str2;
}