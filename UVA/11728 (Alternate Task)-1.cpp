#include <iostream>
#include <math.h>
using namespace std;

int dp[1010];

int sumDiv(int n)       //this function returns the summation of divisor
{
    int sqrtN=sqrt(n);

    int sum=0;
    for(int i=1; i<=sqrtN; i++){
        if(n%i==0){
            sum+=i;
            if(n/i!=i)
                sum+=(n/i);
        }
    }
    return sum;
}

int main()
{
    for(int i=0; i<1010; i++){
        dp[i]=-1;
    }

    for(int i=1; i<=1000; i++){
        int result=sumDiv(i);
        if(result<=1000){
            dp[result]=i;
        }
    }

    int n, cases=1;

    while(cin>>n && n!=0){
        cout<<"Case "<<cases++<<": "<<dp[n]<<endl;
    }

    return 0;
}
