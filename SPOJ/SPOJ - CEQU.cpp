//Problem ID: SPOJ - CEQU (Crucial Equation)
//Programmer: IQBAL HOSSAIN     Description: Linear Diophantine Equation
//Date: 26/04/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

ll x1, x2, Y1, y2;

ll ext_gcd (int A, int B, ll &X, ll &Y){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2; Y = y2;
    return r2;
}


bool solve(int a, int b, int c)
{
    ll x, y, g;
    g = ext_gcd(a, b, x, y);
    //cout<<g<<endl;
    if(c % g){
        return false;
    }
    if(a == 0 && b == 0){
        if(c)
            return false;
        return true;
    }
    if(!a){
        if(c % b)
            return false;
        return true;
    }
    if(!b){
        if(c % a)
            return false;
        return true;
    }

    return true;
}

int main()
{
    int test, caseno = 1;
    int a, b, c;
    ll ans;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d %d", &a, &b, &c);
        //c *= -1;
        if(solve(a, b, c)){
            printf("Case %d: Yes\n", caseno++);
        }
        else{
            printf("Case %d: No\n", caseno++);
        }
    }

    return 0;
}
