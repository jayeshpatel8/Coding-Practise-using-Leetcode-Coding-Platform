class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>  ans;

        for (int i=0;i<nums.size(); i++){
            int num = nums[i];

            while(ans.size() && gcd(ans.back(), num) > 1){                    
                num = lcm(ans.back(),num);
                ans.pop_back();
            }
            ans.push_back(num);
        }
        return ans;
    }

};
