#include <iostream>
#include <string>
using namespace std;

int main()
{
    int index[105];
    string str;

    index['1'] = 1, index['0'] = 0;
    index['A'] = index['B'] = index['C'] = 2;
    index['D'] = index['E'] = index['F'] = 3;
    index['G'] = index['H'] = index['I'] = 4;
    index['J'] = index['K'] = index['L'] = 5;
    index['M'] = index['N'] = index['O'] = 6;
    index['P'] = index['Q'] = index['R'] =  index['S'] = 7;
    index['T'] = index['U'] = index['V'] = 8;
    index['W'] = index['X'] = index['Y'] = index['Z'] = 9;

    while(cin>>str){
        int len = str.size();

        for(int i = 0; i < len; i++){
            if(str[i] == '-'){
                cout<<str[i];
            }
            else{
                cout<<index[str[i]];
            }
        }
        cout<<endl;
    }

    return 0;
}
