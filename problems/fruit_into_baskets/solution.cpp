class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> type;
        int j=0, ans=0;
        for (int i=0; i<tree.size(); i++){
            ++type[tree[i]];
             if(type.size()>2){
                 if(--type[tree[j]]==0) type.erase(tree[j]);
                 j++;                 
             }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};