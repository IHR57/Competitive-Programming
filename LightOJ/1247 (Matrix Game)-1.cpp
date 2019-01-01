#include <iostream>
using namespace std;

int main()
{
    int test, row, column, value, sum, result, cases = 1;

    cin>>test;

    while(test--){
        cin>>row>>column;

        result = 0;
        for(int i=0; i<row; i++){
            sum = 0;
            for(int j=0; j<column; j++){
                cin>>value;
                sum+= value;
            }
            result = result^sum;
        }

        if(result){
            cout<<"Case "<<cases++<<": Alice"<<endl;
        }
        else
            cout<<"Case "<<cases++<<": Bob"<<endl;
    }

    return 0;
}
