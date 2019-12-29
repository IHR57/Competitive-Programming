//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 200005
using namespace std;

string str1, str2;
int arr[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k;

    cin>>k;
    cin>>str1;
    cin>>str2;

    for(int i = k - 1; i >= 0; i--){
        arr[i] += (str1[i] - 'a') + (str2[i] - 'a');
        if(i && arr[i] >= 26){
            arr[i-1]++;
            arr[i] -= 26;
        }
    }

    for(int i = 0; i < k; i++){
        cout<<char('a' + (arr[i]) / 2);
        if(arr[i] % 2 == 1){
            arr[i+1] += 26;
        }
    }

    cout<<endl;

    return 0;
}

