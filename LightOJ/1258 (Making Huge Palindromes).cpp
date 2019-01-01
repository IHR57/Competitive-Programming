#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 1000005
using namespace std;

int pi[MAX];

int prefix_function(string str)
{
    memset(pi, 0, sizeof(pi));

    int len = (int) str.length();
    for(int i = 1; i < len; i++){
        int j = pi[i-1];
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            j++;
        pi[i] = j;
    }
}

int matching(string str, string p)
{
    int len = (int) str.length(), j = 0;

    for(int i = 0; i < len; i++){
        while(j > 0 && str[i] != p[j])
            j = pi[j-1];
        j++;
    }

    return j;
}
int main()
{
    string str, p;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, caseNo = 1;

    cin>>test;

    while(test--){
        cin>>str;
        p = str;
        int len = (int) str.length();
        reverse(p.begin(), p.end());
        prefix_function(p);
        //cout<<match<<endl;
        int match = matching(str, p);
        cout<<"Case "<<caseNo++<<": "<<(2 * len) - match<<endl;
    }

    return 0;
}
