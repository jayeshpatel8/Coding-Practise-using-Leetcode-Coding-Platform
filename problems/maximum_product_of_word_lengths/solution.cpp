class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bits(n);
        
        for (int  w=0; w < n; w++){
            int i=0;
            for (auto c : words[w])
                i  |=  (1 << (c - 'a'));
            bits[w]=i;
        }
        int ans=0;
        for (int i=0; i<n; i++){    
            for (int j=i+1; j<n; j++){                
                    if ((bits[i] & bits[j]) == 0)
                       ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};