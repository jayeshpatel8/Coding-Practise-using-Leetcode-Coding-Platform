class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        
        int total=0;
        int bucket[101]={};
        int max=0;
        for (auto i: nums) {total +=i; bucket[i]++;
                            if (max < i) max=i;
                          }

        vector<int> res;
        total/=2 ;
        int rem=0;
        for (int k=max; k>0 && rem <= total; k--) {
            int i =bucket[k];
            while (i && rem <= total){
                res.push_back(k);
                rem +=k;i--;
            }
        }
        
        return res;
    }
};