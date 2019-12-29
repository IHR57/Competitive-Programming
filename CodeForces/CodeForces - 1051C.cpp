//Problem ID: CodeForces - 1051C (Vasya and Multisets)
//Programmer: IQBAL HOSSAIN     Description: Brute Force
//Date: 17/03/19
#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int visited[MAX] = {0}, cnt[MAX] = {0}, n, arr[MAX];
    int cnt1 = 0, cnt2 = 0, cnt3 =  0;
    char str[MAX];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        cnt[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(!visited[arr[i]]){
            visited[arr[i]] = 1;
            if(cnt[arr[i]] == 1)
                cnt1++;
            else if(cnt[arr[i]] == 2)
                cnt2++;
            else
                cnt3++;
        }
    }

    if(cnt1 == 0){
        for(int i = 0; i < n; i++)
            str[i] = 'A';
    }
    else if(cnt1 % 2 != 0){
        if(cnt3 == 0){
            cout<<"NO"<<endl;
            return 0;
        }
        else{
            int temp = (cnt1 + 1) / 2;
            int flag = 0, c = 0;
            for(int i = 0; i < n; i++){
                if(!flag && cnt[arr[i]] >= 3){
                    str[i] = 'B';
                    flag = 1;
                }
                else if(cnt[arr[i]] == 1){
                    c++;
                    if(c <= temp)
                        str[i] = 'A';
                    else
                        str[i] = 'B';
                }
                else
                    str[i] = 'A';
            }
        }
    }
    else{
        int temp = cnt1 / 2;
        int c = 0;
        for(int i = 0; i < n; i++){
            if(cnt[arr[i]] == 1){
                c++;
                if(c <= temp)
                    str[i] = 'A';
                else
                    str[i] = 'B';
            }
            else
                str[i] = 'A';
        }
    }

    cout<<"YES"<<endl;
    for(int i = 0; i < n; i++){
        cout<<str[i];
    }
    cout<<endl;

    return 0;

}
