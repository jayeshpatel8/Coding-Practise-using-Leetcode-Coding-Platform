class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,two=nums.size()-1;
        for (int i = 0; i<=two;){
            if (nums[i] == 0 ){
                if (i == zero) zero++;
                else{
                    swap(nums[i], nums[zero++]);
                    continue;
                }
            }
            else if (nums[i] == 2){
                if (i == two) return;
                else{
                    swap(nums[i], nums[two--]);
                    continue;
                }
            }
            i++;
        }
        return ;
    }
};