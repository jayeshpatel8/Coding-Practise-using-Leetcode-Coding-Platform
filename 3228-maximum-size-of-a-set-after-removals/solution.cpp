class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(begin(nums1),end(nums1)) ,s2(begin(nums2),end(nums2));
        int same=0;
        for (auto &i : s1){
            auto it = s2.find(i);
            if ( it != end(s2)){
          //      s2.erase(it);
            //    s1.erase(i);
                same++;
            }
        }
        
        int n1= nums1.size(), n2=nums2.size(), ans= 0 ;
        int sz1= s1.size()-same,sz2=s2.size()-same;
        if (sz1 >= n1/2 ) ans =n1/2;
        else{
            int rem = min<int>(n1/2 - sz1,same);
            ans = sz1 + rem;
            same -=rem;            
        }
        if (sz2 >= n2/2 ) ans +=n2/2;
        else{
            int rem = min<int>(n2/2 - sz2,same);
            ans += sz2 + rem;
        }
        return ans;
    }
};
