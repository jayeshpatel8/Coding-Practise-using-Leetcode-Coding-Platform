class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        vector<int> res;
        int l=-1,r=-1;
        if (!end ) {
            if (target == nums[0]){
                l=0;r=0;}
            res.push_back(l);                
            res.push_back(r);            
            return res;}
        
        while(start <= end ){
            int m = start + (end -start)/2;
            if (nums[m] == target)
            {
                l=m,r=m;
                while( l>=0 && (nums[l]==target))
                    l--;
                while( r<nums.size() && (nums[r]==target))
                    r++;
                res.push_back(++l);                
                res.push_back(--r);
                return res;
            }
            else if (nums[m]< target)
                start=m+1;
            else
                end=m-1;
        }
        res.push_back(l);                
        res.push_back(r);        
        return res;
    }
};