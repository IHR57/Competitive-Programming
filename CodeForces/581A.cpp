#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int red, blue, same, different;

    cin>>red>>blue;

    different = min(red, blue);
    same = (max(red, blue) - different) / 2;

    cout<<different<<" "<<same<<endl;

    return 0;
}
