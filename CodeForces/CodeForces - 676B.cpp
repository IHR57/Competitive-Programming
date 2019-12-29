//Problem ID: CodeForces - 676B (Pyramid of Glasses)
//Programmer: IQBAL HOSSAIN     Description: Implementation
//Date: 31/03/19
#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

typedef long long ll;
typedef pair<double, double> pii;

int visited[MAX];
double temp[MAX];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    double t;

    cin>>n>>t;

    if(t == 0){
        cout<<0<<endl;
        return 0;
    }
    //memset(temp, 0, sizeof(temp));
    temp[1] = t;

    int cnt = 1;
    for(int i = 0; i < n - 1; i++){
        int flag = 0, c = 0;
        for(int j = (i * (i + 1)) / 2; c <= i; j++){
            int u = j + i + 2;
            int v = j + i + 3;
            double t = max((double) 0, temp[j+1] - 1);
            temp[u] += t * 0.5;
            temp[v] += t * 0.5;
            if(temp[u] + 1e-12 >= 1){
                if(!visited[u])
                    cnt++;
                flag = 1;
                visited[u] = 1;
            }
            if(temp[v] + 1e-12 >= 1){
                if(!visited[v]){
                    cnt++;
                }
                flag = 1;
                visited[v] = 1;
            }
            c++;
//            cout<<temp[u]<<" "<<temp[v]<<endl;
        }
//        cout<<endl;
        if(!flag){
            break;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
