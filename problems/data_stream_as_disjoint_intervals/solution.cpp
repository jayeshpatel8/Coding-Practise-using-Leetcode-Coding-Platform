class SummaryRanges {
public:
    map<int,vector<int>> m;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (m.count(val)) return;
        auto  higher = m.lower_bound(val);
        auto lower = higher == begin(m) ? end(m) : prev(higher);
        
        if (lower != end(m) && higher != end(m) && (lower->second.back())+1 == val && (higher->second.front())==val+1){
            lower->second.back() = higher->second.back();
            m.erase(higher);
        }
        else if (lower != end(m) && lower->second.back()+1 >= val){
            lower->second.back()=max(val,lower->second.back()) ;
        }
        else if (higher != end(m) && higher->second.front() == 1+val){
            m[val] ={val,higher->second.back()};
            m.erase(higher);
        }
        else
            m[val]={val,val};
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto & [a, b] : m)
            ans.push_back(b);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */