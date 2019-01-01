#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 100005
using namespace std;

struct info
{
	int weight, iq, index;
};

bool compare(info A, info B)
{
	if(A.iq != B.iq){
        return A.iq > B.iq;
	}
}

vector<info> v;
int I[MAX], L[MAX], lisSequence[MAX];
const int INF = 1 << 28;

int LIS()
{
    int length = v.size();

    for(int i = 0; i < length; i++)
        L[i] = 1;

    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(v[j].weight > v[i].weight){
                L[j] = max(L[j], L[i] + 1);
            }
        }
    }

    int maxLength = 0;

    for(int i = 0; i < length; i++){
        if(L[i] > maxLength)
            maxLength = L[i];
    }

    return maxLength;
}

void findSequence(int maxLength)
{
    int i = 0;
    int length = v.size();

    for(int j = 1; j < length; j++){
        if(L[j] > L[i])
            i = j;
    }

    int top = L[i] - 1;
    lisSequence[top] = v[i].index;
    top--;

    for(int j = i - 1; j >= 0; j--){
        if(v[j].weight < v[i].weight && L[j] == L[i] - 1){
            i = j;
            lisSequence[top] = v[i].index;
            top--;
        }
    }

    for(i = 0; i < maxLength; i++)
        cout<<lisSequence[i]<<endl;
}

int main()
{
	int u, w, idx = 0;

	while(cin>>u>>w){
		idx++;
		info data;			//create a object of info type
		data.weight = u;		//assigning value in the created object
		data.iq = w;
		data.index = idx;
		v.push_back(data);
	}
	sort(v.begin(), v.end(), compare);		//sorting in decreasing order of IQ

	/*int length = v.size();

	for(int i = 0; i < length; i++){
        cout<<v[i].index<<" "<<v[i].weight<<" "<<v[i].iq<<endl;
	}*/

	int maxLength = LIS();
	cout<<maxLength<<endl;
	findSequence(maxLength);

	return 0;
}
