#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long int lint;

lint p[2000005];

int main()
{
    lint i, n;

    while(cin>>n){
        if(n==0)
            break;
        for(i=0; i<n; i++){
            cin>>p[i];
        }
        sort(p, p+n);
        for(i=0; i<n-1; i++){
            cout<<p[i]<<" ";
        }
        cout<<p[n-1]<<endl;
    }

    return 0;
}
