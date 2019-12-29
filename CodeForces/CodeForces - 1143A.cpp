//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;
int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, zero = 0, one = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        if(arr[i] == 0)
            zero++;
        else
            one++;
    }

    int tzero = 0, tone = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            tzero++;
        }
        else{
            tone++;
        }
        if(tone == one || tzero == zero){
            cout<<i+1<<endl;
            return 0;
        }
    }

    return 0;
}
