class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(begin(nums),end(nums));
        
        int ans=0;
        for (auto i : set){
           
            if (set.find(i-1) == end(set)){                
                int j=i+1;
                while ( set.find(j) != end(set) )
                    j++;
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};