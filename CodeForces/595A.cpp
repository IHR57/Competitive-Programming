#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int floor, flat, windows[210][210];

    cin>>floor>>flat;

    for(int i = 0; i < floor; i++){
        for(int j = 0; j < 2*flat; j++){
            cin>>windows[i][j];
        }
    }

    int count = 0;

    for(int i = 0; i < floor; i++){
        for(int j = 0; j < 2*flat; j += 2){
            if(windows[i][j] == 1 || windows[i][j+1] == 1){
                count++;
            }
        }
    }

    cout<<count<<endl;

    return 0;
}
