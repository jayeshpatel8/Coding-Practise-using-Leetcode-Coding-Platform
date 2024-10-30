
class Solution {
public:
    
    int minimumMountainRemovals(vector<int>& arr) {
         int N = arr.size();
        vector<int>  lis;
        int inc[N], dec[N];
        for (int i=0; i<N-1; i++){
            auto it = lower_bound(begin(lis),end(lis),arr[i]);
            inc[i] =  it-begin(lis);
            if (it == end(lis)) lis.push_back(arr[i]);
            else *it = arr[i];
            
        }
        lis.clear();

        for (int i=N-1; i>0; i--){
            auto it = lower_bound(begin(lis),end(lis),arr[i]);
            dec[i] = it-begin(lis);
            if (it == end(lis)) lis.push_back(arr[i]);
            else *it = arr[i];
            
        }
        int ans=0;        
        for (int i =1 ; i<N-1; i++)
            if (inc[i] && dec[i]) ans = max(ans, (inc[i]+dec[i]));

        return N-1-ans;
    }

};
