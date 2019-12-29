//Problem ID: SPOJ - RENT (Rent your airplane and make money)
//Programmer: IQBAL HOSSAIN     Description: Dynamic Programming
//Date: 28/06/19
//Problem Link: https://www.spoj.com/problems/RENT/
#include <bits/stdc++.h>
#define MAX 10005
#define EPS 1e-8
using namespace std;

typedef long long ll;
int ans[MAX];

struct data
{
    int s, d, p;
    data(int a, int b, int c){
        s = a, d = b, p = c;
    }
};

bool compare(data A, data B)
{
    return A.d < B.d;
}

vector<data> v;

int solve()
{
    for(int i = 0; i < v.size(); i++){
        ans[i] = v[i].p;
    }
    for(int i = 1; i < v.size(); i++){
        for(int j = 0; j < i; j++){
            if(v[i].s >= v[j].d){
                if(ans[j] + v[i].p > ans[i]){
                    ans[i] = ans[j] + v[i].p;
                }
            }
        }
    }

    return *max_element(ans, ans + v.size());
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, n, a, b, c;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &a, &b, &c);
            v.push_back(data(a, a + b, c));
        }

        sort(v.begin(), v.end(), compare);

        int result = solve();

        printf("%d\n", result);
        v.clear();
    }

    return 0;
}