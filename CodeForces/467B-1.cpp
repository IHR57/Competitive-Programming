//we have to determine how many 1 exist after comparing two numbers in binary representation
//we can compare it using XOR operation
//after XOR we have to count number of 1's exists in that number and we can find easily it by countSetBit() function
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int countSetBit(int n)
{
    int cnt = 0;
    while(n){
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k, army[MAX];

    cin>>n>>m>>k;

    for(int i = 0; i <= m; i++){
        cin>>army[i];
    }

    int count = 0;

    for(int i = 0; i < m; i++){
        int xr = army[m] ^ army[i];
        int diff = countSetBit(xr);
        if(diff <= k){
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
