/*For a given a string expression containing only round brackets or parentheses,
 check if they are balanced or not. Brackets
 are said to be balanced if the bracket which opens last, closes first.
 Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
*/
#include<iostream>
bool isBalanced(string exp) 
{
    // Write your code here
    
	stack <char> s;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='[' || exp[i]=='(' || exp[i]=='{' )
            s.push(exp[i]);
        if(s.empty() && (exp[i]==']' || exp[i]==')' || exp[i]=='}') )
            return false;
   
        
        if(exp[i]==']')
        {	if(s.top()=='[')
                  s.pop();
            else 
                return false;
        }
        
        if(exp[i]==')')
        {      if(s.top()=='(')
                    s.pop();
        		else 
                    return false;
        }
        
        if(exp[i]=='}') 
        {	if(s.top()=='{')
            	s.pop();
        else	
            return false;
        }
      

    }
    if(s.empty())
        return true ;
        else
            return false;
}