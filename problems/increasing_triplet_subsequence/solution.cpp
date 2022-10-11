class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int left = INT_MAX , mid = INT_MAX;
      for (auto n : nums){
          if ( n <= left) left = n;
          else if ( n    > mid) return true;
          else mid = n;
      }
      return false;
    }
};