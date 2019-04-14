//Problem ID: CodeForces - 1101C (Division and Union)
//Programmer: IQBAL HOSSAIN     Description: Sorting
//Date: 08/04/19
#include <bits/stdc++.h>
#define MAX 200005
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> pii;

vector<pii> v;
int result[MAX];

bool compare(pii A, pii B)
{
    if(A.first.second != B.first.second){
        return A.first.second < B.first.second;
    }
    if(A.first.first != B.first.first)
        return A.first.first < B.first.first;
    return A.second < B.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, n, l, r;

    cin>>q;

    while(q--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>l>>r;
            v.pb(mp(mp(l, r), i));
        }

        sort(v.begin(), v.end(), compare);

        bool flag = false;
        int idx = v[n-1].first.first;
        for(int i = n - 2; i >= 0; i--){
            if(v[i].first.second < idx){
                for(int j = i; j >= 0; j--){
                    result[v[j].second] = 1;
                }
                for(int j = i + 1; j < v.size(); j++)
                    result[v[j].second] = 2;
                flag = true;
                break;
            }
            idx = min(idx, v[i].first.first);
        }

        v.clear();
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }

    return 0;

}
