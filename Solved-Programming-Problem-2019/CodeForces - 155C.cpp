//Date: 06/02/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    string str, org;
    int k;

    cin>>str;

    cin>>k;

    int cnt = 0;
    for(int i = 0; i < k; i++){
        cin>>org;
        int l = 0, r = 0;
        for(int j = 0; j < (int) str.length(); j++){
            if(str[j] == org[0] || str[j] == org[1]){
                if(str[j] == org[0])
                    l++;
                if(str[j] == org[1])
                    r++;
            }
            else{
                cnt += min(l, r);
                l = r = 0;
            }
        }
        cnt += min(l, r);
        //cout<<str<<endl;
    }

    cout<<cnt<<endl;

    return 0;
}
