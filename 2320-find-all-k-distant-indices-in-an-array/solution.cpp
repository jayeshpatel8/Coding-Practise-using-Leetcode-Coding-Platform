class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == key){
                for (int j = max(0,i-k); j<= min<int>(nums.size()-1,i+k); j++){
                    st.insert(j);
                }
            }
        }
        return vector<int>(begin(st),end(st));
    }
};
