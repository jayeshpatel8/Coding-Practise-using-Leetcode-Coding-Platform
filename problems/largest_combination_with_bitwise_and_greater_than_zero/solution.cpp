class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        int b[25]={};
        for (auto &c : candidates){
            for (int i=24; i>=0; i--){
                if ( c & (1<<i)){
                    b[i]++;    
                }
            }
        }
        
        return *max_element(begin(b),end(b));
    }
};