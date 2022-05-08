class Solution {
public:
    string largestGoodInteger(string nums) {
        int ans [256] = {};
        for (int i=2; i<nums.size(); i++){
            if ((nums[i] ==nums[i-1]) && (nums[i] ==nums[i-2])){
                ans[nums[i]]=1;
                
            }
        }
        for (int i='9'; i>='0'; i--){
            if (ans[i]){
                return string(3,i);
            }
        }
        return "";
    }
};