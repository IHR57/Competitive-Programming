#include <bits/stdc++.h>
using namespace std;


bool isPossible(int applicants[], int totalDivisions) {
    if(totalDivisions == 1 && applicants[0] > 1) {
        return false;       // not possible two id's must be adjacent
    }

    int maxApplicantDivisionId, maxApplicants = 0;
    for(int i = 0; i < totalDivisions; i++) {       // finding the division id which has most applicants
        if(applicants[i] > maxApplicants) {
            maxApplicants = applicants[i];
            maxApplicantDivisionId = i;
        }
    }

    int sum = 0;
    for(int i = 0; i < totalDivisions; i++) {       // sum of other division's applicants
        if(i != maxApplicantDivisionId)
            sum += applicants[i];
    }

    // not possible according to pigeon-hole principle.
    // at lease two id's must be adjacent in maxApplicantDivisionId
    if(maxApplicants > sum) {
        return false;
    }

    /*
    otherwise we can distribute id's following way
    1. select the topmost from queue
    2. match the division id with previously taken division id
    3. if match found (i.e previous and current are same) then pop the top element and take the second element, otherwise assign id for current division
    4. assign id and push again if applicants count is not zero
    5. at the end no adjacent id belongs to same division
    */

    priority_queue<pair<int, int> > applicantsQueue;
    for(int i = 0; i < totalDivisions; i++) {
        applicantsQueue.push(make_pair(applicants[i], i));          // key-value pair: total_applicants and division_id
    }

    int prevDivisionId = -1;        // will track last taken division-id
    int currId = 1;
    while(!applicantsQueue.empty()) {
        pair<int, int> currDivision = applicantsQueue.top();
        applicantsQueue.pop();
        if(currDivision.second == prevDivisionId) {
            pair<int, int> nextDivision = applicantsQueue.top();
            applicantsQueue.pop();
            nextDivision.first--;
            prevDivisionId = nextDivision.second;
            if(nextDivision.first > 0)
                applicantsQueue.push(nextDivision);
            applicantsQueue.push(currDivision);
            cout<<"Division: "<<nextDivision.second<<" ID: "<<(currId++)<<endl;       // print id that belongs to a division

        }
        else {
            currDivision.first--;
            prevDivisionId = currDivision.second;
            if(currDivision.first > 0) {
                applicantsQueue.push(currDivision);
            }
            cout<<"Division: "<<currDivision.second<<" ID: "<<(currId++)<<endl;
        }
    }


    return true;
}

int main() {


    int arr[3] = {1, 1, 2};

    isPossible(arr, 3);

    return 0;
}
