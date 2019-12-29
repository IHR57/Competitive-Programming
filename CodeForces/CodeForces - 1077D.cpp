//Problem ID: CodeForces - 1077D (Cutting Out)
//Programmer: IQBAL HOSSAIN     Description: Sorting/Binary Search
//Date: 13/04/19
#include <bits/stdc++.h>
#define MAX 200005
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int s[MAX], counter[MAX];
int ans[MAX], freq[MAX], visited[MAX];

vector<pii> v;

bool compare(pii A, pii B)
{
    return A.second > B.second;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>s[i];
        counter[s[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(!visited[s[i]]){
            v.pb(mp(s[i], counter[s[i]]));
            visited[s[i]] = 1;
        }
    }

    sort(v.begin(), v.end(), compare);

    int low = 1, high = 2e5, mid, res;

    while(low <= high){
        mid = (low + high + 1) >> 1;
        int cnt = 0;
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < v.size(); i++){
            int temp = v[i].second / mid;
            freq[v[i].first] = temp;
            cnt += temp;
        }
        if(cnt >= k){
            res = mid;
            for(int i = 0; i < v.size(); i++){
                ans[v[i].first] = freq[v[i].first];
            }
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(ans[v[i].first] > 0){
            for(int j = 0; j < ans[v[i].first]; j++){
                cout<<v[i].first<<" ";
                cnt++;
                if(cnt >= k){
                    cout<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
