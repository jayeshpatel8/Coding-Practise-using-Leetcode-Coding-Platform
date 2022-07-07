class Solution {
public:
    int maxSatisfied(vector<int>& A, vector<int>& G, int minutes) {
        int ans = 0, save=0,maxsave = 0;
        for (int i=0, j=0; i<A.size(); i++){
            if (G[i])
                save += A[i]; 
            else
                ans +=A[i];
            if (i-j+1 > minutes){
                if (G[j])
                    save -=A[j]; 
                j++;
            }
            maxsave = max(maxsave, save);
        }

        return ans +  maxsave;
    }
};