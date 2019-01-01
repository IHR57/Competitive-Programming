#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int visited[2 * MAX] = {0}, n, m, source, destination, l[MAX], r[MAX], t[MAX];

    cin>>n>>m>>source>>destination;

    for(int i = 0; i < m; i++){
        cin>>t[i]>>l[i]>>r[i];
        if(t[i] <= 100000)
            visited[t[i]] = 1;
    }

    vector<char> v;

    int i = 1, j = 0;
    while(source != destination){
        if(!visited[i]){
            if(source < destination)
                v.push_back('R'), source++;
            else if(source > destination)
                v.push_back('L'), source--;
        }
        else{
            if(source >= l[j] && source <= r[j]){
                v.push_back('X');
            }
            else if(source < l[j] && source < destination){
                if(source + 1 < l[j])
                    v.push_back('R'), source++;
                else{
                    v.push_back('X');
                }
            }
            else if(source < l[j] && source > destination){
                v.push_back('L'), source--;
            }
            else if(source > r[j] && source > destination){
                if(source - 1 > r[j])
                    v.push_back('L'), source--;
                else
                    v.push_back('X');
            }
            else if(source > r[j] && source < destination)
                v.push_back('R'), source++;
            j++;
        }
        i++;
    }

    for(int i = 0; i < v.size(); i++){
        cout<<v[i];
    }
    cout<<endl;

    return 0;
}
