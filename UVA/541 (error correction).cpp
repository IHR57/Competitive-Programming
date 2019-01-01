#include <iostream>
using namespace std;

namespace global
{
    bool parity;
    char grid[102][102];
    int input;
    int column;
    int row;
}
void initialize();
void check_parity();

int main()
{
    int i, j;
    using namespace global;
    while(cin>>input && input!=0){
        initialize();
        for(i=0; i<input; i++){
            for(j=0; j<input; j++){
                cin>>grid[i][j];
            }
        }
        check_parity();
        if(parity){
            cout<<"OK"<<endl;
            continue;
        }

        if(grid[row][column]=='0')
            grid[row][column]='1';
        else
            grid[row][column]='0';

        check_parity();
        if(parity){
            cout<<"Change bit ("<<++row<<","<<++column<<")"<<endl;
        }
        else
            cout<<"Corrupt"<<endl;
    }

    return 0;
}

using namespace global;
void initialize()
{
    int i, j;
    parity=true;
    for(i=0; i<102; i++){
        for(j=0; j<102; j++){
            grid[i][j]='0';
        }
    }
}

void check_parity()
{
    int i, j;
    parity=true;
    int result=0;
    for(i=0; i<input; i++){
        for(j=0; j<input; j++){
            result+=grid[i][j]-48;
        }
        if(result%2!=0){
            row=i;
            parity=false;
            break;
        }
    }

    result=0;
    for(i=0; i<input; i++){
        for(j=0; j<input; j++){
            result+=grid[j][i]-48;
        }

        if(result%2!=0){
            column=i;
            parity=false;
            break;
        }
    }
}
