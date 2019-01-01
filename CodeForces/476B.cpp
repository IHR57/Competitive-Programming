// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

int countSetBit(int n)
{
    int cnt = 0;
    while(n){
        n &= (n-1);
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2;
    int pos = 0, neg = 0, total1 = 0, total2 = 0, n = 0, cnt = 0;

    cin>>str1;
    cin>>str2;

    int len = str1.length();

    for(int i = 0; i < len; i++){
        if(str1[i] == '+')
            total1++;
        else
            total1--;
    }

    for(int i = 0; i < len; i++){
        if(str2[i] == '+')
            total2++;
        else if(str2[i] == '-')
            total2--;
        else
            n++;
    }

    for(int i = 0; i < (1<<n); i++){
        int k = countSetBit(i) - (n - countSetBit(i));
        if(total2 + k == total1)
            cnt++;
    }

    double probability = (double) cnt / (double) (1<<n);

    cout<<setiosflags(ios::fixed)<<setprecision(12);
    cout<<probability<<endl;

    return 0;
}
