class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        map<int,int> map;      
        
        for (int i=0, j =0;i <nums.size(); i++){
            map[nums[i]]++;
            while (!map.empty() && rbegin(map)->first-begin(map)->first >2){
                if (1==map[nums[j]]--) map.erase(nums[j]);
                j++;
            }
            ans  += i-j+1;
        }
        return ans;
    }
};