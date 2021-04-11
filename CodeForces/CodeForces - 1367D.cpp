//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mem(a, b) (memset(a, b, sizeof(a)))
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define INF 2147483647
#define MOD 1000000007
#define MAX 200005
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int setBit(int mask, int pos){return mask = mask | (1<<pos);}
bool checkBit(int mask, int pos){return (bool)(mask & (1<<pos));}

int b[MAX];

int main()
{
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, m;
    string str;

    cin>>test;

    while(test--) {
        cin>>str;
        cin>>m;

        vector<int> cnta(26, 0), cntb(1230, 0), mark(55, 0);
        vector<int> res(m + 1);

        for(int i = 0; i < str.size(); i++) {
            cnta[str[i]-'a']++;
        }
        for(int i = 0; i < m; i++) {
            cin>>b[i];
            cntb[b[i]]++;
        }
        vector<int> idx;

        int k = 25;
        for(int i = 25; i >= 0; i--) {
            if(cnta[i] >= cntb[0]) {
                for(int j = 0; j < m; j++) {
                    if(b[j] == 0) {
                        res[j] = i;
                        idx.pb(j);
                        mark[j] = 1;

                    }
                }
                k = i;
                break;
            }
        }

        for(int i = k - 1; i >= 0; i--) {
            int cnt = 0;
            vector<int> tIdx;
            for(int j = 0; j < m; j++) {
                if(!mark[j]) {
                    int sum = 0;
                    for(int x = 0; x < idx.size(); x++) {
                        sum += abs(j - idx[x]);
                    }
                    if(sum == b[j]) {
                        cnt++;
                        tIdx.pb(j);
                    }
                }
            }
            if(cnta[i] >= cnt) {
                for(int j = 0; j < tIdx.size(); j++) {
                    res[tIdx[j]] = i;
                    idx.pb(tIdx[j]);
                    mark[tIdx[j]] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++) {
            cout<<char(res[i] + 97);
        }
        cout<<endl;

    }

    return 0;
}