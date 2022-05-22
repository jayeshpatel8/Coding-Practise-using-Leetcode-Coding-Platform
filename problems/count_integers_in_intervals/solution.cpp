class CountIntervals {
public:

    int min_=1e9+1 , max_=0 , cnt = 0;
    set<array<int,2>> st;
    //set<pair<int,int>>st;
    CountIntervals() {
        
    }
    void add(int left, int right) {
        if (left > max_ || right < min_){
            max_ = max(max_ , right);
            min_ = min(min_ , left);    
            cnt +=( right-left+1);
            st.insert({left,right});
        }
        else
        {
            auto it = st.upper_bound({left,INT_MIN});
            if (it != begin(st) && (*(--it))[1]<left)
                it++;
            
            while (it != end(st) && (*it)[0] <= right){
                cnt -= ((*it)[1] - (*it)[0] + 1);
                left = min(left, (*it)[0]);
                right = max(right, (*it)[1]);
                it = st.erase(it);
            }
            cnt +=( right-left+1);
            st.insert({left,right});
        }
        max_ = max(max_ , right);
        min_ = min(min_ , left);
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */