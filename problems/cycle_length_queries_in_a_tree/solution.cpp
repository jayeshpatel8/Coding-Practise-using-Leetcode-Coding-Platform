class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> ret;

        for (auto &q : queries){
            int c = 1;
            while (q[0] != q[1]){
                if (q[0]>q[1]) 
                    q[0]/=2;
                else 
                    q[1]/=2;
                c++;
            }
            ret.push_back(c);
        }
        return ret;
    }
};