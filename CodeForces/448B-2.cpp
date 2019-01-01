#include <bits/stdc++.h>
#define MAX 1005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str1, str2;
    int cnt1[MAX] = {0}, cnt2[MAX] = {0};

    cin>>str1;
    cin>>str2;

    for(int i = 0; i < str1.size(); i++){
        cnt1[str1[i]]++;
    }
    for(int i = 0; i < str2.size(); i++){
        cnt2[str2[i]]++;
    }

    if(str1.size() == str2.size()){         //if both string are equal size
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if(str1 == str2){
            cout<<"array"<<endl;
        }
        else{
            cout<<"need tree"<<endl;
        }
    }
    else{
        int count = 0;
        for(int i = 0; i < str2.size(); i++){
            if(cnt1[str2[i]] >= 1 && cnt1[str2[i]] >= cnt2[str2[i]]){       //if str2 exists in str1 as substring
                count++;
            }
        }
        //cout<<count<<endl;
        if(count == str2.size()){
            int idx = 0, c = 0;
            for(int i = 0; i < str2.size(); i++){
                for(int j = idx; j < str1.size(); j++){
                    if(str2[i] == str1[j]){
                        idx = j + 1;
                        c++;
                        break;
                    }
                }
            }
            if(c == str2.size()){
                cout<<"automaton"<<endl;
            }
            else{
                cout<<"both"<<endl;
            }
        }
        else{
            cout<<"need tree"<<endl;
        }
    }

    return 0;
}
