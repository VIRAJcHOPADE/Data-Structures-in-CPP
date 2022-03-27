/*For a given expression in the form of a string, find the minimum
 number of brackets that can be reversed in order to make the expression 
 balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

int countBracketReversals(string input) {
	// Write your code here
     int n=input.length();
    stack<char> s;
    int count=0;
    if(n==0){
        return 0;
    }
    if(n%2!=0){
        return -1;
    }
    for(int i=0;i<n;i++){
     if(input[i]=='{'){
        s.push(input[i]);
    }
    else if(input[i]=='}'){
        if(!s.empty() && s.top()=='{'){
            s.pop();
        }
        else if(s.empty()){
            s.push(input[i]);
        }
        else if(!s.empty() && s.top()=='}'){
            s.push(input[i]);
        }
      }
    }
    while(!s.empty()){
        char ch1 = s.top();
        s.pop();
        char ch2 = s.top();
        s.pop();
        if(ch1==ch2){
            count++;
        }
        else if(ch1!=ch2){
            count+=2;
        }
    }
    return count;
}