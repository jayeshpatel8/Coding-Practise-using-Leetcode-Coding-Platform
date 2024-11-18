class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> ans(N);
        if (k==0) return ans;

        for (int i=0; i<N; i++){
            int sum = 0;
            if (k > 0){
                for (int j=1; j<=k; j++){
                    sum += code[(i + j + N) % N];
                }
            }
            else{
                for (int j=-1; j>=k; j--){
                    sum += code[(i + j + N) % N];
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};
