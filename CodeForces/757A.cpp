#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    int index[150] = {0};

    cin>>str;

    int len = str.size();

    for(int i = 0; i < len; i++){
        index[str[i]] += 1;
    }

    //int j = min(index[66], index[108], index[98], index[114], index[115]);
    int j = min(index[66], index[108]);
    int m = min(j, index[98]);
    int n = min(m, index[114]);
    int p = min(n, index[115]);

    int k = min(index[97], index[117]);

    //printf("%c %c %c %c %c %c %c\n", 66, 108, 98, 114, 115, 117, 97);
    int flag = 0;
    for(int i = p; i >= 1; i--){
        if(k >= 2*i){
            cout<<i<<endl;
            flag = 1;
            break;
        }
    }

    if(!flag)
        cout<<0<<endl;

    return 0;
}


