class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st, pri;
     
        for (auto i : nums){
            int k=i;
            for (int j=2; j<= sqrt(i); j++){
                if (k%j == 0){
                    st.insert(j);
                    while (k%j == 0) k/=j;
                }
                
            }
            if (k>1)st.insert(k);

        }
   
        return st.size();
    }
};