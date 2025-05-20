class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N =nums.size();
        vector<int> psum(N+1);
        for (auto &i : queries){
            psum[i[0]]++;
            psum[i[1]+1]--;
        }

        for (int i=0,sum=0; i<N; i++){
            sum += psum[i];
            if (nums[i] > sum) return false;
        }
        return true;
    }
};
