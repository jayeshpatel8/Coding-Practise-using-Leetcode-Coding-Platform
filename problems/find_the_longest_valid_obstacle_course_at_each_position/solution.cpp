class Solution {
public:

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            vector<int> ans,lis;
            int len=0;
            for (auto i : obstacles){
                auto it =  upper_bound(begin(lis),end(lis),i);
                if (it == end(lis)){
                    lis.push_back(i);
                    ans.push_back(++len);
                }
                else{
                    ans.push_back(it-begin(lis)+1);
                    *it = i;
                }
            }
            return ans;
    }
};