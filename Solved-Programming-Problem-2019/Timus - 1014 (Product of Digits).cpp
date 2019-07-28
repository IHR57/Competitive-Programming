//Problem ID: TIMUS - 1014 (Product of Digits)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 19/07/19
//Problem Link: http://acm.timus.ru/problem.aspx?space=1&num=1014
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
string str;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif

    int n;

    cin>>n;
    if(n == 1){
        cout<<"1"<<endl;
        return 0;
    }
    else if(n == 0){
        cout<<"10"<<endl;
        return 0;
    }
    while(true){
        bool flag = false;
        for(int i = 9; i >= 2; i--){
            if(n % i == 0){
                str += (i + 48);
                n /= i;
                flag = true;
                break;
            }
        }
        if(n == 1)
            break;
        if(!flag){
            cout<<-1<<endl;
            return 0;
        }
    }

    sort(str.begin(), str.end());

    cout<<str<<endl;

    return 0;
}
