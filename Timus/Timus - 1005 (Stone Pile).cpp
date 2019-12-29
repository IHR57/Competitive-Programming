//Problem ID: TIMUS - 1005 (Stone Pile)
//Programmer: IQBAL HOSSAIN     Description: BitMask
//Date: 14/07/19
//Problem Link: http://acm.timus.ru/problem.aspx?space=1&num=1005
#include <bits/stdc++.h>
#define MAX 2000005
using namespace std;

typedef long long ll;

int arr[25], possible[MAX];
bool check(int mask, int pos){return (bool)(mask & (1<<pos));}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt",  "w", stdout);
    #endif
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    
    for(int i = 0; i < (1<<20); i++){
        int s = 0;
        for(int j = 0; j < n; j++){
            if(check(i, j)){
                s += arr[j];
            }
        }
        possible[s] = 1;
    }

    for(int i = sum / 2; i >= 0; i--){
        if(possible[i]){
            cout<<(sum - i) - i<<endl;
            return 0;
        }
    }

    return 0;
}