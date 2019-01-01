#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string.h>
#define MAX 100005
using namespace std;

vector<int> v;
int L[MAX];

int LIS()
{
    int length = v.size();

    for(int i = 0; i < length; i++)
        L[i] = 1;       //initialize L[]
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(v[j] <= v[i]){
                L[j] = max(L[j], L[i] + 1);
            }
        }
    }

    int maxLength = 1;
    for(int i = 0; i < length; i++){
        maxLength = max(maxLength, L[i]);       //maximum length
    }

    return maxLength;
}
int main()
{
    int n, cases = 1;

    while(cin>>n){
        if(n == -1)
            break;
        v.clear();
        v.push_back(n);

        while(cin>>n){
            if(n == -1)
                break;
            v.push_back(n);
        }

        if(cases != 1)
            cout<<endl;

        int result = LIS();

        cout<<"Test #"<<cases++<<":"<<endl;
        cout<<"  maximum possible interceptions: "<<result<<endl;
    }

    return 0;
}
