//Problem ID: CodeForces - 1146C (Tree Diameter)
//Programmer: IQBAL HOSSAIN     Description: Graphs/Interactive
//Date: 22/05/19
#include <bits/stdc++.h>
#define MAX 105
#define mp make_pair
using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, x, test;

    cin>>test;

    while(test--){
        cin>>n;
        int Max = 0;
        for(int k = 1; k < n; k <<= 1){
            vector<int> v1, v2;
            int mark = 1;
            for(int i = 1; i <= n; ){
                for(int j = i; j <= i + k - 1; j++){
                    if(j > n)
                        break;
                    if(mark){
                        v1.push_back(j);
                    }
                    else
                        v2.push_back(j);
                }
                i += k;
                mark = 1 - mark;
            }
            cout<<v1.size()<<" "<<v2.size()<<" ";
            for(int i = 0; i < v1.size(); i++)
                cout<<v1[i]<<" ";
            for(int i =  0; i < v2.size(); i++){
                cout<<v2[i]<<" ";
            }
            cout<<endl;
            cout.flush();
            cin>>x;
            Max = max(Max, x);
        }
        cout<<-1<<" "<<Max<<endl;
    }

    return 0;
}