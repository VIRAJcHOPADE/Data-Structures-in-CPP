/*Given a positive integer 'n', find and return the minimum number
 of steps that 'n' has to take to get reduced to 1.
 You can perform any one of the following 3 steps:
 1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
*/

using namespace std;
int countStepsTo1(int n){ // USING DP
	
    int a[n+1];
     
    a[1]=0; a[2]=a[3]=1;
   int b,c;
    for(int i=4 ;i<n+1;i++)
    {   
        b=c=n;
     
       if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
     
      a[i]=1+ min(a[i-1] ,min(b,c));
    }
return a[n];
}
int countHelp(int n,int ans[]){ // USING MEMOIZATION
    if(n<=1){
        return 0;
    }    
    if(ans[n]!=-1){
        return ans[n];
    }
    int x=countHelp(n-1,ans);
    int y=INT_MAX;
    int z=INT_MAX;
    if(n%2==0){
        y=countHelp(n/2,ans);
    }
    if(n%3==0){
        z=countHelp(n/3,ans);
    }
    int output=1+min(x,min(y,z));
    ans[n]=output;
    return output;
}

int countStepsToOne(int n)
{
	//Write your code here
    int ans[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return countHelp(n,ans);
}