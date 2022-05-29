class Solution {
public:
    int maxProduct(vector<string>& words) {
        size_t N = words.size(), ans = 0;
        vector<size_t> bv(N) ,l(N);
        for (int i=0; i < N; i++){
            int bits=0, l1=0;
            for (auto c : words[i]){
                bits |= 1 << (c-'a');
                l1++;
            }
            bv[i]=bits;
            l[i] = l1;
        }
        for (int i=0; i<N; i++){
            unsigned int l1=l[i];
            for (int j =i+1; j<N; j++){
                if (i == j) continue;
                if (bv[i] & bv[j]) continue;
                ans = max(ans, l1 *  l[j]);
            }
        }
        return ans;
    }
};