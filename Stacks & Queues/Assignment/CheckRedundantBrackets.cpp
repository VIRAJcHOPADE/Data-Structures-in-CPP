/*For a given expression in the form of a string,
 find if there exist any redundant brackets or not.
  It is given that the expression contains only rounded 
  brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression 
is surrounded by unnecessary or needless brackets.
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false
*/


bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack <char> s;
    int count;
    int i=0;
    // int len =0;
    // while(expression[len]!='\0'){
    //     len++;
    // }
    int len=expression.size();
    while(i<len)
    {  
        if(expression[i]==')'){
            int cnt=0;
            while(!s.empty() and s.top()!='('){
                s.pop();
                cnt++;
            }
            s.pop();
            if(cnt==0 or cnt==1 )return 1;
        }
        else{
            s.push(expression[i]);
        }
        i++;
    }
    return false;
}