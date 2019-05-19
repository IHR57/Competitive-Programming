//Problem ID: CodeForces - 832B (Petya and Exam)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 16/05/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string good, bad, str, temp;
    int q;

    int mark[30] = {0};
    cin>>good;
    int n1 = good.size();
    for(int i = 0; i < n1; i++){
        mark[good[i]-'a'] = 1;
    }

    cin>>str;
    bool hasStar = false;
    int len = str.size();
    for(int i = 0; i < len; i++){
        if(str[i] == '*')
            hasStar = true;
    }

    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>temp;
        int tlen = temp.size();
        bool matched = true;
        if((tlen > len && !hasStar) || (tlen < len - 1) || (tlen == len - 1 && !hasStar)){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            int req = tlen - len + 1;
            int j = 0, k = 0;
            while(j < len){
                if(!matched)
                    break;
                if(k >= tlen || j >= len)
                    break;
                if(str[j] == '*' && tlen >= len){
                    for(int x = 0; x < req; x++){
                        if(mark[temp[k]-'a']){
                            matched = false;
                            break;
                        }
                        k++;
                    }
                    j++;
                }
                else if(str[j] == '*' && tlen < len){
                    j++;
                }
                else if(str[j] == '?'){
                    if(!mark[temp[k]-'a']){
                        matched = false;
                        break;
                    }
                    j++, k++;
                }
                else{
                    if(str[j] != temp[k]){
                        matched = false;
                        break;
                    }
                    j++, k++;
                }
            }
        }
        (matched) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }

    return 0;
}
