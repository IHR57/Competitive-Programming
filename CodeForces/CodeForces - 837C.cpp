#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int A, B;

bool check(int a, int b, int c, int d)
{
    if(a + c <= A && max(b, d) <= B)
        return true;
    if(b + d <= B && max(a, c) <= A)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x, y;

    cin>>n>>A>>B;

    for(int i = 0; i < n; i++){
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }

    int Max = 0;

    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(check(v[i].first, v[i].second, v[j].first, v[j].second) || check(v[i].first, v[i].second, v[j].second, v[j].first) ||
            check(v[i].second, v[i].first, v[j].first, v[j].second) || check(v[i].second, v[i].first, v[j].second, v[j].first)){
                Max = max(Max, (v[i].first * v[i].second) + (v[j].first * v[j].second));
            }
        }
    }

    cout<<Max<<endl;

    return 0;

}
