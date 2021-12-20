class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size(), ans = n;
        for (int i=0; i<k; i++){
            vector<int> seq;
            for (int j = i; j<n; j+=k)
                seq.push_back(arr[j]);
            vector<int> lis;
            for (auto j : seq){
                auto it = upper_bound(begin(lis),end(lis),j);
                if (it == end(lis)) lis.push_back(j);
                else *it = j;
            }
            ans -= lis.size();
        }
        return ans;
    }
};