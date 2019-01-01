#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[MAX], fraction[MAX], temp[MAX];
    int counter = 0, idx = -1;

    cin>>str;

    int len = strlen(str);

    for(int i = 0; i < len; i++){
        if(str[i] == '.'){
            idx = i;
             break;
        }
        else{
            if(str[i] != '-')
                counter++;
        }
    }

    fraction[0] = '0', fraction[1] = '0';
    int k = 0;
    int cnt = 0;
    if(idx != -1){
        for(int i = idx + 1; i < idx + 3 && i < len; i++){
            cnt++;
        }
    }

    if(cnt == 0)    fraction[0] = '0', fraction[1] = '0';
    else if(cnt == 1)   fraction[0] = str[idx+1], fraction[1] = '0';
    else if(cnt == 2)   fraction[0] = str[idx+1], fraction[1] = str[idx+2];

    int extra = counter % 3;
    if(idx == -1) idx = len;

    k = 0;
   // cout<<counter<<endl;
    if(counter / 3 >= 1 && extra >= 1){
        if(str[0] == '-'){
            for(int i = 1; i <= extra; i++){
                if(i != extra)
                    temp[k++] = str[i];
                else{
                    temp[k++] = str[i];
                    temp[k++] = ',';
                }
            }
        }
        else{
            for(int i = 0; i < extra; i++){
                if(i != extra - 1)
                    temp[k++] = str[i];
                else{
                    temp[k++] = str[i];
                    temp[k++] = ',';
                }
            }
        }
        for(int i = (str[0] == '-') ? extra + 1 : extra, j = 0; i < idx; i++, j++){
            if(j / 3 >= 1 && j % 3 == 0){
                temp[k++] = ',';
                temp[k++] = str[i];
            }
            else{
                temp[k++] = str[i];
            }
        }
    }
    else if(counter / 3 >= 1 && extra == 0){
        for(int i = (str[0] == '-') ? extra + 1 : extra, j = 0; i < idx; i++, j++){
            if(j / 3 >= 1 && j % 3 == 0){
                temp[k++] = ',';
                temp[k++] = str[i];
            }
            else{
                temp[k++] = str[i];
            }
        }
    }
    else{
        for(int i = (str[0] == '-') ? 1 : 0; i < idx; i++){
            temp[k++] = str[i];
        }
    }
    if(str[0] == '-'){
        cout<<"("<<"$"<<temp<<"."<<fraction<<")"<<endl;
    }
    else{
        cout<<"$"<<temp<<"."<<fraction<<endl;
    }

    return 0;
}
