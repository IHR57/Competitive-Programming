//Date: 24/09/19
#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define PI acos(-1)
#define pi 3.1415926535897932384
#define INF 2147483647
#define EPS 1e-8
#define MOD 1000000007
#define MAX 1000005
using namespace std;
 
typedef unsigned long long ll;
typedef pair<int, int> ii;
 
int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int test;
    string str;

    cin>>test;

    while(test--){
        cin>>str;
        stack<char> st;
        int n = str.size();
        for(int i = 0; i < n; i++){
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
                st.push(str[i]);
            }
            else if(str[i] == ')'){
                cout<<st.top();
                st.pop();
            }
            else if(str[i] >= 'a' && str[i] <= 'z')
                cout<<str[i];
        }
        cout<<endl;
    }

    return 0;
}