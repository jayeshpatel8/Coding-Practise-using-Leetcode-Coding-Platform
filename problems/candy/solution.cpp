class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> L(ratings.size(),0);
        vector<int> R(ratings.size(),0);
        for ( int i=1; i< ratings.size(); i++){
            if (ratings[i] > ratings[i-1]) {
                L[i] = L[i-1]+1;
            }
        }
        long ans=max(L[ratings.size()-1],R[ratings.size()-1]);
        for (int i=ratings.size()-2; i>=0; i--){
            if (ratings[i]>ratings[i+1])
                R[i] = R[i+1] +1;
            ans+=max(L[i],R[i]);
        }
        return ans + ratings.size();
    }
};