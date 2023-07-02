class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i <nums.size(); i++){
            int cnt=0;
            int freq[1003]={};
            freq[nums[i]]++;
            for (int j=i+1; j<nums.size(); j++){
                int n = nums[j];
                freq[n]++;
                if (freq[n] == 1)
                    cnt+= 1-(freq[n+1]!=0) - (freq[n-1]!=0);
                ans += cnt;
            }
            
        }
        return ans;
    }
};