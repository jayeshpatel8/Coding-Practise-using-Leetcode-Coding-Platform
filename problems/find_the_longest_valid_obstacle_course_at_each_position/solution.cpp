class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> ans, lis;
        ans.push_back(1);
        lis.push_back(obs[0]);
        for (int i=1; i<obs.size(); i++){
            auto it = upper_bound(begin(lis) , end(lis) , obs[i]);
            if (it == end(lis))              
                ans.push_back(lis.size()+1), lis.push_back(obs[i]);   
            else { 
                ans.push_back(it - begin(lis) +1);
                *it = obs[i];
            }
        }
        return ans;
    }
};