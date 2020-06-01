class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> t(34,1);
        
        for (int i=0; i<=rowIndex; i++){            
            for (int j= i-1; j>0; j--)
                t[j] +=t[j-1]; 
        }
        
        vector<int>  res(t.begin(),t.begin()+rowIndex+1);
        return res;        
    }
};