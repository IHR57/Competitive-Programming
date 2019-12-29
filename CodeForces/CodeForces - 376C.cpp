//Problem Link: https://codeforces.com/contest/376
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

string strA, strB;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>strA;

    int p[] = { 1689, 1698, 1869, 1896, 1968, 1986,
            6189, 6198, 6819, 6891, 6918, 6981,
            8169, 8196, 8619, 8691, 8916, 8961,
            9168, 9186, 9618, 9681, 9816, 9861 };

    int numberofZero = 0;
    int len = strA.length();

    int cnt[20] = {0};
    for(int i = 0; i < len; i++){
        if(strA[i] == '0')
            numberofZero++;
        else{
            if(strA[i] == '1' || strA[i] == '6' || strA[i] == '8' || strA[i] == '9'){
                cnt[strA[i] - 48]++;
                if(cnt[strA[i]-48] > 1)
                    strB += strA[i];
            }
            else{
                strB  += strA[i];
            }
        }
    }

    len = strB.length();

    int rem = 0;
    for(int i = 0; i < len; i++){
        int val = (rem * 10 + (strB[i] - 48));
        rem = val % 7;
    }

    int idx;
    for(int i = 0; i < 24; i++){
        if(((rem * 10000) + p[i]) % 7 == 0){
            idx = i;
            break;
        }
    }

//    for(int i = 0; i < 24; i++){
//        cout<<p[i] % 7<<" ";
//    }
//    cout<<endl;

    cout<<strB<<p[idx];
    for(int i = 0; i < numberofZero; i++){
        cout<<"0";
    }
    cout<<endl;

    return 0;
}
