class UndergroundSystem {
public:
    unordered_map<int,pair<string, int>> ids;
    unordered_map<string,array<int,2>> avg;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ids[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [s,t1] = ids[id];
        string s1 = s+" "+stationName;
        auto &a = avg[s1];
        a[0] += t-t1;
        a[1]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto s = startStation +" "+ endStation;
        auto &a  =  avg[s];
        return (double) a[0] / a[1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */