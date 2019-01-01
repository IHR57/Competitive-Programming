#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#define MAX 100005
using namespace std;

const int INF = 1 << 28;

int main()
{
    int len1, len2;     //length of two string
    char strA[1005], strB[1005];

    cin>>len1>>len2;
    cin>>strA;
    cin>>strB;

    int n = len2 - len1 + 1;

    vector<int> index;
    int m = INF, count;

    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = i, k = 0; k < len1; j++, k++){
            if(strA[k] != strB[j]){
                count++;
            }
        }
        if(count < m){
            index.clear();
            for(int j = i, k = 0; k < len1; j++,  k++){
                if(strA[k] != strB[j]){
                    index.push_back(k + 1);
                }
            }
            m = count;
        }
    }

    cout<<m<<endl;
    for(int i = 0; i < index.size(); i++)
        cout<<index[i]<<" ";
    cout<<endl;

    return 0;
}
