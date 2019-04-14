//BISMILLAHIR RAHMANIR RAHIM
//Problem ID: CodeForces - 1070F (Debate)
//Programmer: IQBAL HOSSAIN     Description: Greedy
//Date: 14/04/19
#include <bits/stdc++.h>
#define MAX 400005
using namespace std;

vector<int> v[5];
int cs[5][MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        if(a == 10)
            v[2].push_back(b);
        else if(a == 11)
            v[3].push_back(b);
        else
            v[a].push_back(b);
    }

    for(int i = 0; i < 4; i++){
        sort(v[i].rbegin(), v[i].rend());
    }
    for(int i = 0; i < 4; i++){
        cs[i][0] = 0;
        for(int j = 0; j < v[i].size(); j++){
            cs[i][j+1] = cs[i][j] + v[i][j];
        }
    }

    int diff = v[3].size();
    int sum = 0, Max = -1, k = diff;

    if(v[0].size() > 0 && diff > 0){
        for(int i = 0; i <= diff; i++){
            k = diff - i;
            //cout<<k<<endl;
            sum = cs[3][v[3].size()];
            //cout<<sum<<endl;
            sum += cs[0][i];
            int Mn = min(v[1].size(), v[2].size());
            if(v[1].size() == Mn){
                sum += cs[1][v[1].size()];
                if(v[1].size() + k >= v[2].size()){
                    sum += cs[2][v[2].size()];
                }
                else{
                    if(!v[2].empty())
                        sum += cs[2][v[1].size() + k];
                }
            }
            else if(v[2].size() == Mn){
                sum += cs[2][v[2].size()];
                if(v[2].size() + k >= v[1].size()){
                    sum += cs[1][v[1].size()];
                }
                else{
                    if(!v[1].empty())
                        sum += cs[1][v[2].size()+k];
                }
            }
            //cout<<sum<<endl;
            Max = max(Max, sum);
        }

        cout<<Max<<endl;
    }
    else{
        sum = cs[3][v[3].size()];
        int Mn = min(v[1].size(), v[2].size());
        if(v[1].size() == Mn){
            sum += cs[1][v[1].size()];
            if(v[1].size() + diff >= v[2].size()){
                sum += cs[2][v[2].size()];
            }
            else{
                if(!v[2].empty())
                    sum += cs[2][v[1].size() + diff];
            }
        }
        else if(v[2].size() == Mn){
            sum += cs[2][v[2].size()];
            if(v[2].size() + diff >= v[1].size()){
                sum += cs[1][v[1].size()];
            }
            else{
                if(!v[1].empty())
                    sum += cs[1][v[2].size()+diff];
            }
        }
        cout<<sum<<endl;
    }


    return 0;
}
