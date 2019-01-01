#include <iostream>
using namespace std;

int main()
{
    int n, data[110], odd, even, odd_count = 0, even_count = 0;

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>data[i];

        if(data[i] % 2 == 0){
            even_count++;
            even = i;
            continue;
        }
        if(data[i] % 2 != 0){
            odd_count++;
            odd = i;
        }
    }

    if(even_count > odd_count){
        cout<<odd<<endl;
    }
    else{
        cout<<even<<endl;
    }

    return 0;
}
