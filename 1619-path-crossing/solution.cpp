class Solution {
public:
    bool isPathCrossing(string path) {
        int  up = 0 , left=0;
        set<pair<int,int>> st;
        st.insert({0,0});
        for (auto c : path){
            switch(c){
                case 'N' : up++;break;
                case 'S' : up--;break;
                case 'W' : left++;break;
                case 'E' : left--;break;
            }
            if (st.find({up,left}) != st.end()) return true;
            st.insert({up,left});
        }
        return false;
    }
};
