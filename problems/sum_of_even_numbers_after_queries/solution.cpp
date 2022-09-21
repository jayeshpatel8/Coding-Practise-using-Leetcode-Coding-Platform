class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even = 0;
        vector<int> ans;
        for (auto i : nums) if (i %2 == 0) even +=i;
        for (auto &i : queries){
            if ( (nums[i[1]] & 1)  == 0)
                even -= nums[i[1]];
            nums[i[1]] += i[0];
            if ( (nums[i[1]] & 1)  == 0)
                even += nums[i[1]]; 
            ans.push_back(even);
        }
        return ans;
    }
    vector<int> sumEvenAfterQueries2(vector<int>& nums, vector<vector<int>>& queries) {
        int even = 0;
        vector<int> ans;
        for (auto i : nums) if (i %2 == 0) even +=i;
        for (auto &i : queries){
            int new_num = nums[i[1]] + i[0];
            if ( nums[i[1]] & 1){
                if (new_num %2  == 0) 
                    even +=new_num;                
            }
            else{
                if (new_num %2  == 0) 
                    even += i[0];
                else
                    even -= nums[i[1]];
            }
            nums[i[1]] += i[0];
            ans.push_back(even);
        }
        return ans;
    }
};