//Problem ID: CodeForces - 71C (Round Table Knights)
//Programmer: IQBAL HOSSAIN     Description: Number Theory
//Date: 26/01/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

bool mark[MAX];
int n;

bool solve(int x)
{
    if((n / x) <= 2)
        return false;

    for(int i = 0; i < x; i++){
        int j;
        for(j = i; j < n; j += x){
            if(!mark[j]){
                break;
            }
        }
        if(j >= n)
            return true;
    }
    return false;
}
int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &mark[i]);
    }

    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            if(solve(i) || solve(n / i)){
                printf("YES\n");
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
