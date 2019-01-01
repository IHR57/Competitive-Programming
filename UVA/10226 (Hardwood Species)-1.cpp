#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

/*int node[MAX][53], isWord[MAX];
int root, nodeNo;

void init()
{
    root = 0;
    nodeNo = 0;

    for(int i = 0; i < 53; i++){
        node[root][i] = -1;
    }

    for(int i = 0; i < MAX; i++)
        isWord[i] = 0;
}

int insertWord(string st, int check)
{
    int len = st.size(), id;
    int current = root;

    for(int i = 0; i < len; i++){
        if(st[i] > 'Z')    id = st[i] - 'a' + 26;
        else if(st[i] == ' ') id = 52;
        else    id = st[i] - 'A';

        if(node[current][id] == -1){        //if it is empty
            if(check == 1){
                current = -1;
                break;
            }
            node[current][id] = ++nodeNo;
            for(int j = 0; j < 53; j++){
                node[nodeNo][j] = -1;
            }
        }
        current = node[current][id];
    }

    return current;
}*/

int main()
{
    int test, totalTree, line = 0;

    scanf("%d", &test);
    getchar();
    getchar();

    while(test--){
        //getline(cin, s);
        totalTree = 0;
        map<string, int> myMap;
        string s;

        while(getline(cin, s)){
            if(s.compare("") == 0)
                break;
            myMap[s]++;
            totalTree++;
        }

        if(line)    printf("\n");       //printing blank line between two consecutive test cases
        line = 1;

        map<string, int> :: iterator it;

        for(it = myMap.begin(); it != myMap.end(); it++){
            cout<<it->first<<" "<<fixed << setprecision(4)<<it->second * 100.0 / totalTree<<endl;
        }
    }

    return 0;
}
