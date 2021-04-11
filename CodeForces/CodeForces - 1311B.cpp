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
#define MAX 1005
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int arr[MAX], pos[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int test, m, n;

    cin>>test;

    while(test--){
        cin>>m>>n;

        for(int i = 0; i < m; i++){
            cin>>arr[i];
        }

        for(int i = 0; i < n; i++){
            cin>>pos[i];
        }

        sort(pos, pos + n);

        int first = pos[0], last = first + 1;
        for(int i = 1; i < n; i++){
            if(pos[i] == pos[i-1] + 1){
                last = pos[i] + 1;
            }
            else{
                sort(arr + first - 1, arr + last);
                first = pos[i];
                last = pos[i] + 1;
            }
        }

        sort(arr + first - 1, arr + last);

        bool flag = true;
        for(int i = 1; i < m; i++){
            if(arr[i] < arr[i-1]){
                flag = false;
                break;
            }
        }
        (flag) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}
