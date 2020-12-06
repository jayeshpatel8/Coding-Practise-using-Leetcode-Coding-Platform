class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {        
        vector<int> v;
        int l=0,r=num.size()-1;
        while (l<r){
            int s = num[r] + num[l];
            if (target > s) l++;
            else if (target < s) r--;            
            else{// 2 3 4 5 = 6
             return vector<int>{l+1,r+1};
            }
        }
        return v;
    }
};