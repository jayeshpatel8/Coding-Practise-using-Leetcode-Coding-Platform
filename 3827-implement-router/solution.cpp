
class Router {
public:
    set<vector<int>> st;
    int N=0;
    queue<vector<int>>q;
    unordered_map<int,vector<int>> dest;
    unordered_map<int,int> idx;
    Router(int memoryLimit) {
        N = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
            vector<int> p{source, destination, timestamp};
        if (st.count(p)) return false;
        if (st.size() == N){
            auto i = q.front(); q.pop();
            st.erase(i);
            idx[i[1]]++;
            
        }
        st.insert(p);
        q.push(p);
        dest[p[1]].push_back(p[2]);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto i = q.front(); q.pop();
        //dest[i[1]].pop();
        idx[i[1]]++;
        st.erase(i);
        return i;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (dest.count(destination) == 0) return 0;
        auto &t = dest[destination];
        auto start = lower_bound(begin(t)+idx[destination], end(t), startTime);
        auto en  = upper_bound(begin(t)+idx[destination], end(t), endTime);
        return en-start;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
 
