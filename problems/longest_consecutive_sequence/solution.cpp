class Solution {

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (!n)  return 0;
        if (n<2) return 1;
        
        unordered_set<int> s(nums.begin(), nums.end());
        int max=0;
        for (auto  i : s){
            if(s.find(i-1) == s.end()){
                int l=1;                
                while(s.find(++i)!= s.end()) l++;
                max = std::max(max,l);
            }
        }
        return max;
    }
};