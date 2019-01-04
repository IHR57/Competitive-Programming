#include <iostream>
#include <vector>
#include <fstream>
#define read (freopen("input.txt", "r", stdin))
#define write (freopen("output.txt", "w", stdout))
using namespace std;

vector<int> v;

int main()
{
   // freopen("output.txt", "w", stdout);
    
    cout<<"Hello is anybody in there?"<<endl;

    for(int i = 1; i <= 100; i++){
        if(i % 7 == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    return 0;
}