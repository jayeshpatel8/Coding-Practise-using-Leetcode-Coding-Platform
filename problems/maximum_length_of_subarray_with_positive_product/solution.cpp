class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int cnt=0, ans = 0,n  = nums.size(), f=-1,s=-1, i1=-1, i =0;
        for ( ; i<n; i++){
            if (i1 < 0) i1 = i;
            if (nums[i]  == 0){
                if (cnt %2 == 0){
                    ans= max(ans, i-i1);
                }
                else{
                    ans = max({ans, f-i1, i-f-1});
                    if (cnt>2)
                        ans = max({ans, s-i1, i-s-1});
                }
                
                i1=-1;cnt=0,f=-1,s=-1;
            }
            else if ( nums[i] < 0){                
                cnt++;
                if (f==-1) f=i;
                s = i;
            }
        }
        if ((i1>=0)){
            if ( (cnt %2 == 0)){
                ans= max(ans, i-i1);
            }
            else{
                ans = max({ans, f-i1, i-f-1});
                if (cnt>2)
                    ans = max({ans, s-i1, i-s-1});
            }        
        }
        return ans;
    }
};