class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int l =0,N=nums.size()-1,  r = N;
        if (nums[0] >t ) return 0;
        if (nums[N] <t) return N+1;
        while(l<r){
           int m =( l+r )/2;
           
           if (nums[m] == t){
               return m;
           }
           else if (  nums[m] > t){
               r = m ;
            }
           else 
               l = m + 1;
       }
        return l;
    }
};