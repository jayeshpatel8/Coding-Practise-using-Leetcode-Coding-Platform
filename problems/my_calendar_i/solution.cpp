class MyCalendar {
public:
    set<pair<int,int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = s.lower_bound({start, end});
        if (it != s.end()) {
            if (end > it->first) {
                return false;
            }
        }
        if (it != s.begin()) {
            if ((--it)->second > start) {
                return false;
            }
        }       
        s.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */