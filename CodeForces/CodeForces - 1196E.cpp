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
#define MAX 2750132
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<ii> vii;
typedef priority_queue<int,vector<int>,greater<int> > PQ;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int test, b, w;

    cin>>test;

    while(test--) {
        cin>>b>>w;
        int x = 300000, y = 299999;        // black cell
        if(w < b) {
            y += 1;     //moving to white cell
            swap(b, w);
        }
        if(b == 1 && w == 4) {
            cout<<"YES"<<endl;
            cout<<x<<" "<<y<<endl;
            cout<<x + 1<<" "<<y<<endl;
            cout<<x - 1<<" "<<y<<endl;
            cout<<x<<" "<<y + 1<<endl;
            cout<<x<<" "<<y - 1<<endl;

            continue;
        }

        if((w / b) >= 4 || ((w / b) == 3 && (w % b) > 1)) {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;

        if(w / b == 3) {
            int r = w % b;
            if(r == 1)
                cout<<x<<" "<<y - 1<<endl;

            for(int i = 0; i < b; i++) {
                cout<<x<<" "<<y<<endl;
                cout<<x - 1<<" "<<y<<endl;
                cout<<x + 1<<" "<<y<<endl;
                cout<<x<<" "<<y + 1<<endl;
                y += 2;
            }
        }
        else if(w / b == 2) {
            int r = (w % b);
            for(int i = 0; i < r; i++) {
                cout<<x<<" "<<y<<endl;
                cout<<x - 1<<" "<<y<<endl;
                cout<<x + 1<<" "<<y<<endl;
                cout<<x<<" "<<y + 1<<endl;
                y += 2;
            }
            for(int i = r; i < b; i++) {
                cout<<x<<" "<<y<<endl;
                cout<<x + 1<<" "<<y<<endl;
                cout<<x - 1<<" "<<y<<endl;
                x -= 1, y += 1;
            }
        }
        else if(w / b == 1) {
            int r = (w % b);
            for(int i = 0; i < r; i++) {
                cout<<x<<" "<<y<<endl;
                cout<<x - 1<<" "<<y<<endl;
                cout<<x + 1<<" "<<y<<endl;
                x -= 1, y += 1;
            }
            for(int i = r; i < b; i++) {
                cout<<x<<" "<<y<<endl;
                cout<<x - 1<<" "<<y<<endl;
                x -= 1, y += 1;
            }
        }

    }
    return 0;
}


