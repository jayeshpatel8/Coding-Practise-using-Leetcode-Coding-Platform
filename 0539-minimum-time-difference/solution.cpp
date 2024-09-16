class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> m;
        for (auto &s : timePoints){
            m.push_back(stoi(s.substr(0,2)) *60 + stoi(s.substr(3,2)));
        }   
        sort(begin(m),end(m));

        int ans = INT_MAX;
        for (int i=1;i<m.size(); i++){
            ans = min(ans, m[i]- m[i-1]);
        }
        return min(ans, 24 * 60 - m[m.size()-1] + m[0]);
    }
};
