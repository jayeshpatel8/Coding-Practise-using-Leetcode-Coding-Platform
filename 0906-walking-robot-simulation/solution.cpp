class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> st;
            static const int MULTIPLIER = 60001;
        for (auto &i : obstacles){
            st.insert( i[0] + MULTIPLIER * i[1]);
        }
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x=0, y=0;
        int dir=0;
        int ans = 0;
        for (auto &c : commands){
            if ( c == -1){
                dir = (dir +  1) % 4;
            }
            else if ( c== -2) dir = (dir +  3) % 4;
            else{
                auto d  =  dirs[dir];
                for (int step=0; step<c; step++){
                    int x1 = x + d[0];
                    int y1 = y + d[1];
                    if (st.count(x1 + MULTIPLIER * y1)){
                        break;
                    }
                    x = x1; y  = y1;
                }
            }
            ans = max(ans, x*x + y*y);
        }
        return ans;
    }
};
