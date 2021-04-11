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

int arr[MAX], ans[MAX];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, n;

    cin>>test;

    while(test--){
        cin>>n;
        int Max = 0, Min = 2e9;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            Min = min(Min, arr[i]);
            Max = max(Max, arr[i]);
        }

        if(Min == Max){
            cout<<1<<endl;
            for(int i = 0; i < n; i++){
                cout<<"1 ";
            }
            cout<<endl;
            continue;
        }

        if(n % 2 == 0){
            cout<<2<<endl;
            for(int i = 0; i < n; i++){
                cout<<(i % 2) + 1<<" ";
            }
            cout<<endl;
            continue;
        }

        bool flag = false;
        for(int i = 0; i < n; i++){
            if(arr[i] == arr[(i + 1) % n]){
                cout<<2<<endl;
                for(int j = 0, k = i + 1; k < n; j++, k++){
                    ans[k] = (j % 2) + 1;
                }
                for(int j = 0, k = i; k >= 0; j++, k--){
                    ans[k] = (j % 2) + 1;
                }
                for(int i = 0; i < n; i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                flag = true;
                break;
            }
        }

        if(!flag){
            cout<<3<<endl;
            for(int i = 0; i < n - 1; i++){
                ((i & 1)) ? cout<<2<<" " : cout<<1<<" ";
            }
            cout<<3<<endl;
        }
    }
    return 0;
}
