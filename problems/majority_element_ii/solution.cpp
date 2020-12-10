class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() < 2) return nums;
        int n1=INT_MIN,n2=INT_MIN,c1=0,c2=0;
        for (int i=0 ; i< nums.size(); i++){
            if (n1 == nums[i]) c1++;
            else if (n2 == nums[i]) c2++;
            else if (c2 == 0) {c2 = 1, n2=nums[i];           } 
            else if (c1 == 0) {c1=1,n1=nums[i];}
            else {c1--,c2--;}            
        }
        
        c1=c2=0;
        for (auto i: nums){
            if (n1==i) c1++;
            else if (n2 == i) c2++;
        }
       
        vector<int> res;
        if (c1 > nums.size()/3)  res.push_back(n1);
        if (c2 > nums.size()/3)  res.push_back(n2);
        return res;
    }
};