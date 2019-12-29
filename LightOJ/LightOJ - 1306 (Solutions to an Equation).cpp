//Problem ID: LightOJ - 1306
//Programmer: IQBAL HOSSAIN     Description: Extended Euclid
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

bool linearDiophantine(int A, int B, int C, ll &x, ll &y, ll &g)
{
    g = ext_gcd(A, B, x, y);
    if(C % g)
        return false;;
    //ext_gcd(a, b, x, y);
    x *= -C / g, y *= -C / g;
    return true;
}

ll solve(int a, int b, int c)
{
    ll x, y, g;
    if(!linearDiophantine(a, b, c, x, y, g)){
        return 0;
    }
//    cout<<x<<" "<<y<<endl;
    a /= g;
    b /= g;

    double l = (x1 - x) / (double) b, r = (x2 - x) / (double) b;
    if(l > r)   swap(l, r);
    //cout<<l<<" "<<r<<endl;
    ll t1 = (ll) ceil(l), t2 = (ll) floor(r);

    l = (y - Y1) / (double) a, r = (y - y2) / (double) a;
    if(l > r)   swap(l, r);
    //cout<<l<<" "<<r<<endl;
    ll t3 = (ll) ceil(l), t4 = (ll) floor(r);

    t1 = max(t1, t3), t2 = min(t2, t4);
    if(t2 < t1)
        return 0;
    return (t2 - t1 + 1);
}

int main()
{
    int test, caseno = 1;
    int a, b, c;
    ll ans;

    scanf("%d",  &test);

    while(test--){
        scanf("%d %d %d %lld %lld %lld %lld", &a, &b, &c, &x1, &x2, &Y1, &y2);
        //c *= -1;
        if(a == 0 && b == 0){
            if(c)
                printf("Case %d: 0\n", caseno++);
            else
                printf("Case %d: %lld\n", caseno++, (x2 - x1 + 1) * 1LL * (y2 - Y1 + 1));
        }
        else if(a == 0){
            if(c % b){
                printf("Case %d: 0\n", caseno++);
            }
            else if((-c / b) >= Y1 && (-c / b) <= y2){
                printf("Case %d: %lld\n", caseno++, x2 - x1 + 1);
            }
            else{
                printf("Case %d: 0\n", caseno++);
            }
        }
        else if(b == 0){
            if(c % a){
                printf("Case %d: 0\n", caseno++);
            }
            else if((-c / a) >= x1 && (-c / a) <= x2){
                printf("Case %d: %lld\n", caseno++, y2 - Y1 + 1);
            }
            else{
                printf("Case %d: 0\n", caseno++);
            }
        }
        else{
            ans = solve(a, b, c);
            printf("Case %d: %lld\n", caseno++, ans);
        }
    }

    return 0;
}
