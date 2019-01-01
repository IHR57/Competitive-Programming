#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 200005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2;
    int n, m, arr[MAX], values, mark[MAX];

    cin>>str1;
    cin>>str2;

    n = str1.length();
    m = str2.length();

    for(int i = 0; i < n; i++){
        cin>>values;
        values--;
        arr[i] = values;
    }

    int low = 0, high = n, mid;

    while(low < high){
        memset(mark, 0, sizeof(mark));
        mid = (low + high + 1) >> 1;
        for(int i = 0; i < mid; i++){
            mark[arr[i]] = 1;
        }

        bool possible = true;

        int i = 0, j = 0;
        while(i < n && j < m){
            while(i < n && mark[i])
                i++;
            if(i == n){         //str2 must be lesser than str1
                possible = false;
                break;
            }
            if(str1[i] == str2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j != m){
            possible = false;
        }

        if(possible) low = mid;
        else    high = mid - 1;
    }

    cout<<low<<endl;

    return 0;
}
