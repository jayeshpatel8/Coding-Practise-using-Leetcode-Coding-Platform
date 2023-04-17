class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m= *max_element(begin(candies),end(candies));
        vector<bool> ans;
        for (auto c : candies){
            ans.push_back(c + extraCandies >= m);
        }
        return ans;
    }
};