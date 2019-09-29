/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: The_Silent_Man
	AtCoder   : IHR57
	TopCoder  : IHR57

*/
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
#define MAX 100005
using namespace std;

typedef long long ll;

int Set(int mask, int pos){return mask = mask | (1<<pos);}
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

string str1, str2;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    int n;

    cin>>n;

    stack<string> st;

    for(int i = 0; i < n; i++){
        cin>>str1;
        if(str1 == "Sleep"){
            cin>>str2;
            st.push(str2);
        }
        else if(str1 == "Kick"){
            if(!st.empty())
                st.pop();
        }
        else{
            if(st.empty()){
                cout<<"Not in a dream"<<endl;
            }
            else
                cout<<st.top()<<endl;
        }
    }

    return 0;
}
