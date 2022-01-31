class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size() , sum = accumulate(begin(nums), end(nums),0) ,zero=0, one=0 ,ma=sum;
        vector<int> ans = {0};
        for (int i=0; i < nums.size(); i++){
            if (nums[i]) one++;
            else zero++;
            int score = zero + sum - one;
            if (score > ma){
                ma= score;
                ans = {i+1};
            }
            else if (score == ma)  ans.push_back(i+1);
        }
       
        return ans;
    }
};