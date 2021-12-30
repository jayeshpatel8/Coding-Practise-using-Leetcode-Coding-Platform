class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        deque<int> q;
        int ans = INT_MIN;
        for (int j=0; j<p.size(); j++){
            auto &i = p[j];
            while(!q.empty() && i[0] - p[q.front()][0] > k)
                q.pop_front();
            if (!q.empty())
                ans  =  max(ans , i[1] + p[q.front()][1] + i[0] - p[q.front()][0]);
            while(!q.empty() && p[q.back()][1] - p[q.back()][0] < i[1] -i[0])
                q.pop_back();
            q.push_back(j);
        }
        return ans;
    }
};