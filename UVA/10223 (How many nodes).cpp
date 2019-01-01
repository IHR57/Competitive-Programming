#include <iostream>
using namespace std;

int main()
{
    long int catalan[]={1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845,
                        35357670, 129644790, 477638700, 1767263190};
    long int n;
    int index;

    while(cin>>n){
        for(int i=0; i<19; i++){
            if(n==catalan[i]){
                index=i;
                break;
            }
        }
        cout<<index+1<<endl;
    }

    return 0;
}
