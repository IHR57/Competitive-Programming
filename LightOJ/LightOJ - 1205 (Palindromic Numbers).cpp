//Problem ID: LightOJ - 1205 (Palindromic Numbers)
//Programmer; IQBAL HOSSAIN     Description: Dynamic Programming (Digit-DP)
//Date: 15/01/19
#include <bits/stdc++.h>
#define MAX 20
using namespace std;

typedef long long ll;

int visited[MAX][MAX][2][2], lim, cnt, temp[MAX];
vector<int> digit;
ll dp[MAX][MAX][2][2];

ll solve(int pos, int lastD, int isStart, int isSmall)
{
    if(pos == lim){
        if(lastD == temp[0]){
//             for(int i = 0; i < pos; i++){
//                 cout<<temp[i]<<" ";
//             }
//             cout<<endl;
            return 1;
        }
        return 0;
    }

    ll &ret = dp[pos][lastD][isStart][isSmall];
    int &v = visited[pos][lastD][isStart][isSmall];

    if(v == cnt)
        return ret;
    v = cnt;
    int last = (isSmall) ? 9 : digit[pos];

    ret = 0;
    if(!isStart){
        for(int i = 0; i <= last; i++){
            temp[pos] = i;
            if(pos < (lim / 2)){
                ret += solve(pos + 1, temp[pos], 0, isSmall | i < digit[pos]);
            }
            else{
                if(i == temp[lim-pos-1]){
                    ret += solve(pos + 1, i, 0, isSmall | i < digit[pos]);
                }
            }
        }
    }
    else{
        for(int i = 1; i <= last; i++){
            temp[pos] = i;
            if(pos < (lim / 2)){
                ret += solve(pos + 1, temp[pos], 0, isSmall | i < digit[pos]);
            }
            else{
                if(i == temp[lim-pos-1]){
                    ret += solve(pos + 1, i, 0, isSmall | i < digit[pos]);
                }
            }
        }
    }

    return ret;
}

ll cal(ll x)
{
    if(x <= 9){
        return x;
    }
    digit.clear();
    while(x){
        digit.push_back(x % 10);
        x /= 10;
    }

    lim = digit.size();
    reverse(digit.begin(), digit.end());
    cnt++;

    return solve(0, 0, 1, 0);
}

int main()
{
    int test, caseno = 1;
    ll a, b;

    scanf("%d", &test);

    while(test--){
        scanf("%lld %lld", &a, &b);
        if(a > b)
            swap(a, b);
        ll tempa = 0, tempb = 0;
        ll result1 = cal(b);
        ll result2 = cal(a - 1);
        while(tempb < b){
            tempb = tempb * 10 + 9;
            if(tempb < b)
                result1 += cal(tempb);
        }

        while(tempa < (a -1)){
            tempa = tempa * 10 + 9;
            if(tempa < (a -1))
                result2 += cal(tempa);
        }

        ll result = result1 - result2;

        printf("Case %d: %lld\n", caseno++, result);
    }

    return 0;
}
