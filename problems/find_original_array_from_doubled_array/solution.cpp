class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() & 1) return {};
        sort(begin(changed), end(changed));
        int j=changed.size()-1;
        vector<int> ans;
        int freq[100001]={};        
        while(j>=0){
            int id = changed[j] * 2;
            if ( id<= 100001 && freq[id]){ 
                ans.push_back(changed[j]);
                freq[id]--;
            }
            else
                freq[changed[j]]++;
            j--;
        }
        if (ans.size() * 2 != changed.size()) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};