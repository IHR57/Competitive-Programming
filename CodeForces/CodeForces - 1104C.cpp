//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int visited[10][10];
bool temp1 = true, temp2 = true;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string str;

    cin>>str;

    int len = (int) str.length();

    for(int x = 0; x < len; x++){
        if(str[x] == '1'){
            if(temp1){
                cout<<1<<" "<<1<<endl;
            }
            else{
                cout<<1<<" "<<3<<endl;
            }
            temp1 ^= 1;
        }
        if(str[x] == '0'){
            if(temp2){
                cout<<3<<" "<<4<<endl;
            }
            else{
                cout<<1<<" "<<4<<endl;
            }
            temp2 ^= 1;
        }

//        if(visited[3][2] == 1){
//            for(int i = 1; i <= 4; i++){
//                for(int j = 1; j <= 2; j++){
//                    visited[i][j] = 0;
//                }
//            }
//        }
//
//        if(visited[4][3] == 1){
//            for(int i = 1; i <= 4; i++){
//                for(int j = 3; j <= 4; j++){
//                    visited[i][j] = 0;
//                }
//            }
//        }

    }

    return 0;
}
