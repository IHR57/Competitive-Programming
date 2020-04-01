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
#define MAX 100005
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
    int test, n;
    string str;

    cin>>test;

    while(test--){
        cin>>n;
        cin>>str;

        string a = "" , b = "";
        a += "1", b += "1";
        bool found = false;
        for(int i = 1; i < n; i++){
            if(found){
                a += "0";
                b += str[i];
                continue;
            }
            if(str[i] == '1' && !found){
                a += "1";
                b += "0";
                found = true;
            }
            else{
                int rem = (str[i] - 48) / 2;
                a += (rem + 48);
                b += (rem + 48);
            }
        }

        cout<<a<<endl;
        cout<<b<<endl;
    }

    return 0;
}
