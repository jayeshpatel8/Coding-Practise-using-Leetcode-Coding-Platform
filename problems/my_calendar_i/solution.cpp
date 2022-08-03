class MyCalendar {
public:
map<int,int> map; 
    MyCalendar() {
        map[-1]=-1;
    }
    
    bool book(int start, int end) {
       
        auto it = map.upper_bound(start);
        if (it == map.end() || end <= it->second){
            map[end]=start;
            return true;
        }
        else
            return false;        
    }
    /*
set<array<int,2>> st; 
    MyCalendar() {
        st.insert({-1,-1});
    }
    
    bool book(int start, int end) {
       
        auto it = st.upper_bound({start,end});
        if (it == st.end()){
            st.insert({end,start});
            return true;
        }
        else{
            if (end <= (*it)[1]){
                st.insert({end,start});
                return true;
            }
            else
                return false;
        }
    }
    */
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */