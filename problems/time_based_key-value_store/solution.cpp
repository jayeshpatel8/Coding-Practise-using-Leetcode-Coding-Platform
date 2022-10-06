class TimeMap {
public:
    unordered_map <string, set<pair<int,string>>> M;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        M[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &st = M[key];
        if (st.empty()) return {};

        auto it =  st.upper_bound({timestamp, ""});
        if (it->first == timestamp) return it->second;
        if (it == st.begin()) return {};
        
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */