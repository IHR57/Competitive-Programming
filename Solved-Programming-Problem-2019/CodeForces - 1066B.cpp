//Problem ID: CodeForces - 1066B (Heaters)
//Programmer: IQBAL HOSSIAN     Description: Greedy
//Date: 11/02/19
#include <bits/stdc++.h>
#define MAX 100005
#define MOD 1000000007
using namespace std;

typedef pair<int, int> pii;
vector<pii> v, result;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, r, val;

    cin>>n>>r;

    int lft, rht, x = 1, y = -1;
    for(int i = 1; i <= n; i++){
        cin>>val;
        if(val){
            lft = i - r + 1;
            rht = i + r - 1;
            if(lft <= 0)    lft = 1;
            if(rht > n)     rht = n;
            if(lft == 1){
                x = 1;
                y = max(y, rht);
            }
            v.push_back(make_pair(lft, rht));
        }
    }

    if(y == -1){
        cout<<-1<<endl;
        return 0;
    }
    result.push_back(make_pair(x, y));

    for(int i = 0; i < v.size(); i++){
        if(y == n)
            break;
        int flag = 0, tx, ty;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j].first <= (y+1)){
                flag = 1;
                tx = v[j].first;
                ty = v[j].second;
            }
        }
        if(!flag)
            break;
        result.push_back(make_pair(tx, ty));
        x = tx, y = ty;
    }


    if(result[result.size()-1].second != n){
        cout<<-1<<endl;
        return 0;
    }
    cout<<result.size()<<endl;

    return 0;
}
