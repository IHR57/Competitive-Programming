/*
Template for vjudge.net

	Author: Iqbal Hossain Rasel
	CodeForces: Psychedelic
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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    int l;
    string str;

    cin>>l;
    cin>>str;

    int n = str.size();
    if(l > n){
        cout<<"1";
        for(int i = 1; i < l; i++)
            cout<<"0";
        cout<<endl;
        return 0;
    }

    if(n % l != 0){
        int t = n / l + 1;
        for(int i = 0; i < t; i++){
            cout<<"1";
            for(int j = 1; j < l; j++)
                cout<<"0";
        }
        cout<<endl;
        return 0;
    }

    bool found = false;
    if(l != n){
        for(int i = 0; i < l; i++){
            for(int j = l + i; j < n; j += l){
                if(str[i] > str[j]){
                    for(int x = 0; x < n / l; x++){
                        for(int y = 0; y < l; y++){
                            cout<<str[y];
                        }
                    }
                    cout<<endl;
                    return 0;
                }
                else if(str[i] < str[j]){
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
    }
    found = false;
    for(int i = l - 1; i >= 0; i--){
        if(str[i] != '9'){
            found = true;
            str[i] = str[i] + 1;
            for(int j = i + 1; j < l; j++)
                str[j] = '0';
            break;
        }
    }

    if(!found){
        int t = n / l + 1;
        for(int i = 0; i < t; i++){
            cout<<"1";
            for(int j = 1; j < l; j++)
                cout<<"0";
        }
        cout<<endl;
        return 0;
    }

    for(int i = 0; i < n / l; i++){
        for(int j = 0; j < l; j++){
            cout<<str[j];
        }
    }

    cout<<endl;

    return 0;
}
