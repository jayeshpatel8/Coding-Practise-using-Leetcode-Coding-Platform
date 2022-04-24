class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> cin;
    unordered_map<string,pair<int,int>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        cin[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &[s1,t1] = cin[id];
        auto &v = avg[s1+'-'+stationName];

        v.first += t-t1;
        v.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &v = avg[startStation+'-'+endStation];
        
        return (double)v.first/v.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */