#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#define MAX 1000005
using namespace std;
 
typedef long long lint;
 
lint data[MAX];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    lint temp = 0;
 
    cin>>n;
 
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin>>data[i];
        temp += data[i];
        if(data[i] % 2 == 0)
            cnt++;
    }
 
    (cnt == n) ? cout<<"Second"<<endl : cout<<"First"<<endl;
 
    return 0;
}