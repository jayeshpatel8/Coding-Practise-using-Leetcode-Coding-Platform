class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int s ,e;
        vector<int> v(2,-1);
        s=0,e=nums.size()-1;
         while(s <= e){
             int m = s + (e-s)/2;
             if (nums[m] == t) v[0]=m, e = m-1;
             else if (nums[m]<t)s=m+1;
             else e=m-1;
         }
        e=nums.size()-1;
         while(s <= e){
             int m = s + (e-s)/2;
             if (nums[m] == t) v[1]=m, s = m+1;
             else if (nums[m]<t)s=m+1;
             else e=m-1;
         }
        return v;
    }
};