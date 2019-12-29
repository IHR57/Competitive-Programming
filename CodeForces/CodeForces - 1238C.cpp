//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int n, arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, h;

    cin>>test;

    while(test--){
        cin>>h>>n;
        set<int> s;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }

        s.insert(0);
        int diff, curr = h, res = 0;
        for(int i = 0; i < n; i++){
            diff = curr - arr[i];
            if(diff == 1){
                if(!s.count(curr - 2)){
                    res++;
                }
                curr -= 2;
            }
            else if(diff >= 2){
                int x = curr - arr[i] - 1;
                curr = curr - x;
                if(curr == 0)
                    break;
                if(curr - 2 == 0){
                    break;
                }
                if(!s.count(curr - 2)){
                    res++;
                }
                curr -= 2;
            }
            if(curr == 0)
                break;
        }
        cout<<res<<endl;
    }
    return 0;
}
