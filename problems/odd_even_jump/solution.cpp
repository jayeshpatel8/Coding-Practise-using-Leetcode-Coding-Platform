class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
       int n  = A.size(), res = 1;
         vector<int>oddjump(n,0);
         vector<int>evejump(n,0);
        oddjump[n-1]=evejump[n-1]=1;
        map<int,int>map;
        map[A[n-1]]=n-1;
        for (int i=n-2; i>=0; i--){
            auto nextgreater = map.lower_bound(A[i]);
            auto nextsmaller = map.upper_bound(A[i]);
            if (nextgreater != map.end())
                oddjump[i] = evejump[nextgreater->second];
            if (nextsmaller != map.begin())
                evejump[i] = oddjump[(--nextsmaller)->second]; 
            if (oddjump[i])
                res++;
            map[A[i]]=i;
        }

        return res;        
    }
};