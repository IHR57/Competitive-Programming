#include <bits//stdc++.h>
using namespace std;

int main()
{
    int test, row, col, important, non_important, Max, MaxCount, cases = 1;
    char str[50][50];
    int digit[100];

    cin>>test;

    while(test--){
        cin>>row>>col>>important>>non_important;

        memset(digit, 0, sizeof(digit));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin>>str[i][j];
                digit[str[i][j]]++;
            }
        }

        Max = INT_MIN;

        for(int i = 65; i <= 90; i++){
            if(digit[i] > Max)
                Max = digit[i];
        }

        MaxCount = 0;

        for(int i = 65; i <= 90; i++){
            if(digit[i] == Max)
            {
                MaxCount++;
            }
        }

        int total = MaxCount * Max;
        int remain = (row * col) - total;

        int result = (total * important) + (remain * non_important);

        cout<<"Case "<<cases++<<": "<<result<<endl;
    }

    return 0;
}
