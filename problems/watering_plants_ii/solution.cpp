class Solution {
public:
    int minimumRefill(vector<int>& plants, int cA, int cB) {
        int i=0, j = plants.size()-1,  A =   cA, B=cB,  ans = 0;
        while ( i < j){
            if (plants[i] > A) A=cA , ans++;
            A -= plants[i++];
            if (plants[j] > B) B=cB , ans++;
            B -= plants[j--];            
        }
        if (i==j)
            if (plants[i] > max(A,B)) ans++;
        return ans;
    }
};