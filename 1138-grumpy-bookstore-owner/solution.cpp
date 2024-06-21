class Solution {
public:
    int maxSatisfied(vector<int>& cu, vector<int>& gr, int mi) {
        int ans = 0,ng=0, max_ng=0;
        for (int i=0,j=0; i<cu.size(); i++){
            
            if (gr[i]){
                ng+=cu[i];
            }
            else ans += cu[i];

            if (i>=mi-1){
                while ( i-j >= mi){
                    if (gr[j])ng-=cu[j];
                    j++;
                }
                max_ng = max(max_ng,ng);
            }
        }   
        max_ng = max(max_ng,ng);
        return ans + max_ng;
    }
};
