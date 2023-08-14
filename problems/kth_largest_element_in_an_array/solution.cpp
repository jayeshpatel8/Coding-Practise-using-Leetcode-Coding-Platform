class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int min_ = *min_element(begin(nums),end(nums)),max_ = *max_element(begin(nums),end(nums)), m  = max_ - min_ + 1;
        vector<int> freq(m);
        for (auto i : nums) freq[i - min_]++;
        for (int i=m-1; i>=0; i--){
            k-=freq[i];
            if (k<=0) return i + min_;
        }
        return -1;
    }
};