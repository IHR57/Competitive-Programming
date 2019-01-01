#include <bits//stdc++.h>
using namespace std;

int main()
{
    int data[105][105], row, col, temp[105], maxSum;

    while(cin>>row>>col){
        maxSum = INT_MIN;
        if(!row && !col)        //if both input are zero
            break;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin>>data[i][j];
                if(data[i][j]==0)
                    data[i][j]=1;
                else if(data[i][j]==1)
                    data[i][j]=0;
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(data[i][j] == 1){
                    data[i][j] = data[i-1][j] + 1;
                }
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int count = data[i][j];
                for(int k = j + 1; k < col && data[i][j] <= data[i][k]; k++){
                    count += data[i][j];
                }
                for(int k = j - 1; k >= 0 && data[i][j] <= data[i][k]; k--){
                    count += data[i][j];
                }

                if(count > maxSum){
                    maxSum = count;
                }
            }
        }
        cout<<maxSum<<endl;
    }

    return 0;
}
