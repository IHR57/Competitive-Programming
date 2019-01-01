#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#define MAX 1000005
using namespace std;

int pi[MAX];

void prefix_function(string str)
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

int matching(string str, string patt)
{
    int Max = 0;
    int len = (int) str.length();
    int j = 0;
    for(int i = 0; i < len; i++){
        while(j > 0 && patt[i] != str[j])
            j = pi[j-1];
        if(patt[i] == str[j])
            j++;
        if(j > Max)
            Max = j;
    }

    //return j;
    return Max;
}

int main()
{
    int test;
    string str;

    cin>>test;

    while(test--){
        cin>>str;
        string rev = str;
        reverse(rev.begin(), rev.end());
        prefix_function(str);
        int match = matching(str, rev);
        for(int i = match - 1; i >= 0; i--)
            cout<<str[i];
        cout<<endl;
    }

    return 0;
}
