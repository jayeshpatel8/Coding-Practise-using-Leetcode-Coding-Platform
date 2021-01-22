class Solution {
public :
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        //nums = [2,4,3,3,5,4,9,6], k = 4
        int max_nums_to_delete = nums.size()-k;
        vector<int> s;
         
        for (int i= 0; i< nums.size(); i++){
           while(!s.empty() && nums[i] < s.back()   && max_nums_to_delete){
               max_nums_to_delete--;
               s.pop_back();
           }
            s.push_back(nums[i]);
        }
        s.resize(k);
        return s;
    }
};