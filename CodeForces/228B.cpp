#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string first[MAX], second[MAX];
    int na, ma, nb, mb;

    cin>>na>>ma;

    for(int i = 0; i < na; i++)
        cin>>first[i];

    cin>>nb>>mb;

    for(int i = 0; i < nb; i++)
        cin>>second[i];

    int r = (na > nb) ? na : nb;
    int w = (ma > mb) ? ma : mb;

    int sum = 0, idx1, idx2, Max = -1;

    for(int x = -r; x <= r; x++){
        for(int y = -w; y <= w; y++){
            sum = 0;
            for(int i = 0; i < na; i++){
                for(int j = 0; j < ma; j++){
                    if((i + x) >= 0 && (i + x) < nb && (j + y) >= 0 && (j + y) < mb && first[i][j] == '1' && second[i+x][j+y] == '1'){
                        sum++;
                    }
                }
            }
            if(sum > Max){
                Max = sum;
                idx1 = x, idx2 = y;
            }
        }
    }

    cout<<idx1<<" "<<idx2<<endl;

    return 0;

}
