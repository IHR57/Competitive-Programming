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
#define MAX 400005
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

int main()
{
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test, n;
    string str;

    cin>>test;

    while(test--) {
        cin>>n>>str;
        int l = 0, g = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '<')
                l++;
            else
                g++;
        }
        (str[n-2] == '<') ? l++ : g++;
        vector<int> minLIS, maxLIS;

        char prev = str[0];
        int cnt = 1;
        int tl = l , tg = l + g;


        for(int i = 1; i < n - 1; i++) {
            if(str[i] ==  prev) {
                cnt++;
            }
            else {
                if(prev == '<') {
                    int r = tl - cnt + 1;
                    for(int i = r; i <= tl; i++) {
                        minLIS.pb(i);
                    }
                    tl -= cnt;
                }
                else if(prev == '>') {
                    int r = tg - cnt;
                    for(int i = tg; i >= r + 1; i--) {
                        minLIS.pb(i);
                    }
                    tg -= cnt;
                }
                cnt = 1;
            }
            prev = str[i];
        }
        if(prev == '<') {
            int r = tl - cnt + 1;
            if(str[n-2] == '<')
                r--;
            for(int i = r; i <= tl; i++) {
                minLIS.pb(i);
            }
        }
        else if(prev == '>') {
            int r = tg - cnt - 1;
            for(int i = tg; i >= r + 1; i--) {
                minLIS.pb(i);
            }
        }

        for(int i = 0; i < minLIS.size(); i++) {
            cout<<minLIS[i]<<" ";
        }
        cout<<endl;

        tl = l, tg = l + g;
        prev = str[0];
        cnt = 1;
        int st = 1;

        for(int i = 1; i < n - 1; i++) {
            if(str[i] ==  prev) {
                cnt++;
            }
            else {
                if(prev == '<') {
                    for(int i = st; i < st + cnt; i++) {
                        maxLIS.pb(i);
                    }
                    st = st + cnt;
                }
                else if(prev == '>') {
                    int r = tg - cnt;
                    for(int i = tg; i >= r + 1; i--) {
                        maxLIS.pb(i);
                    }
                    tg -= cnt;
                }
                cnt = 1;
            }
            prev = str[i];
        }
        if(prev == '<') {
            for(int i = st; i <= st + cnt; i++) {
                maxLIS.pb(i);
            }
        }
        else if(prev == '>') {
            int r = tg - cnt;
            if(str[n-2] == '>')
                r--;
            for(int i = tg; i >= r + 1; i--) {
                maxLIS.pb(i);
            }
        }

        for(int i = 0; i < minLIS.size(); i++) {
            cout<<maxLIS[i]<<" ";
        }
        cout<<endl;
    }


    return 0;
}