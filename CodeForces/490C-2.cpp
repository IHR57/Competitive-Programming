#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

typedef long long ll;

string str, part1, part2;
ll a, b, len, ra[MAX], rb[MAX];

ll Power(ll a, ll b, ll M)
{
    if(b == 0)
        return 1;
    ll x = Power(a, b/2, M);
    x = (x * x) % M;
    if(b % 2 == 1){
        x = (x * a) % M;
    }

    return x;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>str;
    cin>>a>>b;

    len = (int) str.length();
    int idx, flag = 0;

    ll sum = 0;
    for(int i = 0; i < len - 1; i++){       //prefix
        sum = sum * 10 + (str[i] - 48) % 10;
        if(sum >= a){
            sum = sum % a;
        }
        ra[i] = sum;
    }
    ll k = 1;
    sum = 0;
    rb[len-1] = (str[len-1] - 48) % b;
    for(int i = len - 2; i >= 1; i--){      //suffix
        rb[i] = ((str[i] - 48) * Power(10, k, b) + rb[i+1]) % b;
        k++;
    }

    for(int i = 0; i < len - 1; i++){
        if(ra[i] == 0 && rb[i+1] == 0){
            flag = 1;
            idx = i;
            break;
        }
    }
    if(flag){
        k = idx + 1;
        for(int i = 0; i <= idx; i++){
            part1 += str[i];
        }
        for(int i = idx + 1; i < len; i++){
            if(str[i] != '0'){
                break;
            }
            else{
                part1 += str[i];
                k = i + 1;
            }
        }
        for(int i = k; i < len; i++){
            part2 += str[i];
        }

        if(part2.size() == 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<part1<<endl;
            cout<<part2<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
