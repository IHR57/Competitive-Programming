//Problem ID: CodeForces - 746D (Green and Black Tea)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 26/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int n, k;

void solve(int a, int b, char ch1, char ch2)
{
    if(b == 0){
        if(a > k){
            cout<<"NO"<<endl;
            return;
        }
        else{
            for(int i = 0; i < a; i++){
                cout<<ch1;
            }
            cout<<endl;
            return;
        }
    }
    if(a <= k){
        for(int i = 0; i < a; i++){
            cout<<ch1;
        }
        for(int i = 0; i < b; i++)
            cout<<ch2;
        cout<<endl;
        return;
    }

    int x = (a / k);
    if(a % k == 0)
        x--;
    if(b < x){
        cout<<"NO"<<endl;
        return;
    }

    while(b > x * k){
        cout<<ch2;
        b--;
    }

    int t1 = b / x, t2 = t1 + 1, rem = (b % x);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < k; j++){
            cout<<ch1;
            a--;
        }
        if(rem){
            for(int j = 0; j < t2; j++)
                cout<<ch2;
            rem--;
        }
        else{
            for(int j = 0; j < t1; j++)
                cout<<ch2;
        }
    }
    for(int i = 0; i < a; i++)
        cout<<ch1;
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;

    cin>>n>>k>>a>>b;

    (a >= b) ? solve(a, b, 'G', 'B') : solve(b, a, 'B', 'G');

    return 0;

}
