class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int ans = 0, max_n=0;
        for (int i=0; i<arr.size(); i++){
            max_n = max(max_n , arr[i]);

            if (max_n == i) ans++;
        }

        return ans;
    }
};
