class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        unordered_map<int,int> odd,even;
        int o1,o2,e1,e2 , i1,i2,i3,i4, N=  nums.size(), ans=0;
        o1 = o2 = e1 = e2 = 0;
        if (N==1) return 0;
        for (int i=0; i<N; i++){
            if (i&1){
                int v = ++odd[nums[i]];
                if (v > o1){
                    o1 = v;
                    i1=i;
                }
            }
            else{
                int v = ++even[nums[i]];
                if (v > e1){
                    e1 = v; 
                    i3=i;
                }
               
            }
        }
        if (nums[i1] != nums[i3]){
            ans  =  (N+1)/2 - o1 + (N/2) - e1;
        }
        else{
            odd.erase(nums[i1]);
            even.erase(nums[i3]);
            for (auto &[k,v] : odd){
                if (v > o2) o2=v,i2=k;
            }
            for (auto &[k,v] : even){
                if (v > e2) e2=v,i4=k;
            }
            ans = min( (N+1)/2 - o1 + (N/2) - e2, (N+1)/2 - o2 + (N/2) - e1);
        }
        return ans;
    }
};
