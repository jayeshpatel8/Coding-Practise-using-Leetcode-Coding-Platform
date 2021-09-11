class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(begin(p),end(p),[](auto&a, auto&b){return a[0]==b[0]? a[1]>b[1]:a[0]<b[0];});

        int N = p.size(), ans = 0, high = p[N-1][1];

        for(int i=N-2; i>=0; i--){
            if (p[i][1]<high)  ans++ ;   
            
            high = max(high, p[i][1]);
        }
        return ans;
    }
};