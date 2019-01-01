#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, s;

    cin>>m>>s;

    if((s == 0 && m > 1) || s > m * 9){
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    int smallest[MAX];
    int largest[MAX];

    memset(smallest, 0, sizeof(smallest));
    for(int i = 0; i < m; i++)
        largest[i] = 9;

    smallest[0] = 1;

    int lrg = m * 9;

    for(int i = m - 1; i >= 0; i--){
        if(lrg - s > 9){
            largest[i] = 0;
        }
        else if(lrg - s >= 0 && lrg - s <= 9){
            largest[i] = 9 - (lrg - s);
        }
        lrg = 9 * i;
    }

    int temp = s - 1;
    for(int i = m - 1; i >= 0; i--){
        if(temp >= 9){
            smallest[i] = 9;
            temp -= 9;
        }
        else{
            smallest[i] = smallest[i] + temp;
            break;
        }
    }
    for(int i = 0; i < m; i++){
        cout<<smallest[i];
    }
    cout<<" ";
    for(int i = 0; i < m; i++){
        cout<<largest[i];
    }
    cout<<endl;

    return 0;
}
