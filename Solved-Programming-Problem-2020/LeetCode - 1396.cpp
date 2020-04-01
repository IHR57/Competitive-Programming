class UndergroundSystem {
public:
    map<int, string> mp1;
    map<pair<string, string>, pair<int, int> > mp2;
    int checkInTime[1000005];
    
    UndergroundSystem() {
        memset(checkInTime, 0, sizeof(checkInTime));    
        mp1.clear();
        mp2.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id] = stationName;
        checkInTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mp1.count(id)){
            if(mp2.count(make_pair(mp1[id], stationName))){
                mp2[make_pair(mp1[id], stationName)] = make_pair(mp2[make_pair(mp1[id], stationName)].first + (t - checkInTime[id]), mp2[make_pair(mp1[id], stationName)].second + 1);
            }
            else{
                mp2[make_pair(mp1[id], stationName)] = make_pair(mp2[make_pair(mp1[id], stationName)].first + (t - checkInTime[id]), 1);
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans = mp2[make_pair(startStation, endStation)].first / (double) mp2[make_pair(startStation, endStation)].second;
        
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */