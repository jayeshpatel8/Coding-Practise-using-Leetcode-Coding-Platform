class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        for (int i = 0; i<arr.size(); i++){
            int cnt=1;
            //for ( int j=i+m; j<arr.size(); j++)
            {                                
                int l=0;
                for (int j1=i+m; j1<arr.size(); l++,j1++){
                    if (l==m) cnt++, l=0;                    
                    if (arr[i+l] != arr[j1]) {
                        break;
                    }
                }
                if ((cnt + (l==m)) >= k ) return true;                
            }
        }
        return false;
    }
};