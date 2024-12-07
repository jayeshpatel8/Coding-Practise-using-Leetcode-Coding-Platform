class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1, r=1e9;

        while (l <r ){
            int m = (l+r)/2, c=0;
            for (auto i : nums) c += (i-1)/m;
            if (c > maxOperations) l=m+1;
            else r=m;
        }
        return l;
    }
};
