class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int N= arr.size();
        
        for (int i=N-2; i>=0; i--){
            int m[N+1];m[0]=10000;
            for (int j=0; j<N; j++)   m[j+1] = min(m[j],arr[i+1][j]);
            m[N]=10000;
            for (int j=N-1; j>=0; j--){
                arr[i][j] +=min(m[j],m[j+1]);
                m[j] =min(m[j+1] ,arr[i+1][j]);
            }
        }
        
        return *min_element(begin(arr[0]),end(arr[0]));
    }
};