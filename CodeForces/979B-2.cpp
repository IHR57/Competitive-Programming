// BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;

const int inf = 1<<28;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2, str3;
    int counter[3][150] = {0}, n;

    cin>>n;

    cin>>str1;
    cin>>str2;
    cin>>str3;

    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();
    int max1 = -inf, max2 = -inf, max3 = -inf;

    for(int i = 0; i < len1; i++){
        counter[0][str1[i]-65]++;
        if(counter[0][str1[i]-65] > max1)
            max1 = counter[0][str1[i]-65];
    }
    for(int i = 0; i < len2; i++){
        counter[1][str2[i]-65]++;
        if(counter[1][str2[i]-65] > max2)
            max2 = counter[1][str2[i]-65];
    }
    for(int i = 0; i < len3; i++){
        counter[2][str3[i]-65]++;
        if(counter[2][str3[i]-65] > max3)
            max3 = counter[2][str3[i]-65];
    }

    len1 -= max1, len2 -= max2, len3 -= max3;
    //cout<<len1<<" "<<len2<<" "<<len3<<endl;

    int Min = min(len1, min(len2, len3));

    if(n > Min){
        cout<<"Draw"<<endl;
    }
    else{
        if(len1 == Min){
            if(len2 == Min || len3 == Min)
                cout<<"Draw"<<endl;
            else
                cout<<"Kuro"<<endl;
            return 0;
        }
        if(len2 == Min){
            if(len1 == Min || len3 == Min)
                cout<<"Draw"<<endl;
            else
                cout<<"Shiro"<<endl;
            return 0;
        }
        if(len3 == Min){
            if(len1 == Min || len2 == Min)
                cout<<"Draw"<<endl;
            else
                cout<<"Katie"<<endl;
            return 0;
        }
    }
    return 0;
}
