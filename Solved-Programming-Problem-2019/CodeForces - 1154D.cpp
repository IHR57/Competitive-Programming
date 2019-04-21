//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

int s[MAX];

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n>>b>>a;

    for(int i = 1; i <= n; i++){
        cin>>s[i];
    }
    int tempa = a;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 1){
            if(a == tempa){
                a--, cnt++;
            }
            else if(b > 0){
                b--; a++; cnt++;
            }
            else if(a > 0 && a < tempa)
                a--, cnt++;
            else{
                break;
            }
        }
        else if(s[i] == 0){
            if(a > 0)
                a--, cnt++;
            else if(b > 0)
                b--, cnt++;
            else{
                break;
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}

