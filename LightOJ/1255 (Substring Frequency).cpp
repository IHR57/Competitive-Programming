#include <bits/stdc++.h>
#define MAX 2000005
using namespace std;

int pi[MAX];

void prefix_function(string str)
{
    int len = (int)str.length();

    for(int i = 1; i < len; i++){
        int j = pi[i-1];
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            j++;
        pi[i] = j;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test, caseNo = 1;
    string strA, strB;

    cin>>test;

    while(test--){
        cin>>strA;
        cin>>strB;

        int l1 = (int) strB.length();

        strB += "#";
        strB += strA;

        memset(pi, 0, sizeof(pi));

        prefix_function(strB);

        int l2 = (int) strB.length();

        int count = 0;
        for(int i = l1; i < l2; i++){
            if(pi[i] == l1)
                count++;
        }

        cout<<"Case "<<caseNo++<<": "<<count<<endl;
    }

    return 0;
}
