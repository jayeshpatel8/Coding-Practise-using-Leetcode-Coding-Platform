
using ll  = long long;
class Solution {
public:

    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        ll toswap=0, maxF = 0, maxFv  , ans = 0;
        // just follow hint section for implementation 
        for (int i=0; i<nums1.size(); i++)
        {
            if (nums1[i] != nums2[i]) continue;
            freq[nums1[i]]++;
            toswap++;
            if (maxF < freq[nums1[i]]){
                maxF = freq[nums1[i]];
                maxFv = nums1[i];
            }
            ans +=i;
        }
        if (maxF > toswap/2){
            for (int i=0; i<nums1.size() && maxF > toswap/2; i++){
                if ( nums1[i] != nums2[i] 
                    && nums1[i] != maxFv && nums2[i] != maxFv){
                        toswap++;
                        ans +=i;
                    }
            }
        }
        return maxF > toswap/2 ? -1 : ans;
    }
};