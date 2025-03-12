class Solution {
public:
int p=0,n=0;
    int maximumCount(vector<int>& nums) {
        for (auto i : nums){
            if (i < 0) n++;
            else if ( i > 0) p++;
        }
        return max(n,p);
    }
};
