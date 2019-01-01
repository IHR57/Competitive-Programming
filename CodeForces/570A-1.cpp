#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, data[110][110], count[110], index;
    int position[110] = {0};

    cin>>n>>m;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>data[i][j];
        }
    }

    for(int i = 1; i <= m; i++){
        int Max = -1;
        for(int j = 1; j <= n; j++){
            if(data[i][j] > Max){
                Max = data[i][j];
                index = j;
            }
        }
        position[index]++;
    }

    int mx = -1;
    for(int i = 1; i < 110; i++){
        //cout<<"Position "<<i<<": "<<position[i]<<endl;
        if(position[i] > mx){
            mx = position[i];
            index = i;
        }
    }

    cout<<index<<endl;

    return 0;
}
