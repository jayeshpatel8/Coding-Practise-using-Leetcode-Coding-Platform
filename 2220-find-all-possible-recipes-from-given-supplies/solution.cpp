
class Solution {
public:
    unordered_map<string,int> m ,rec;
    bool vis[101]={};
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ing, vector<string>& sup) {
        
        vector<string> ans;
        for (auto &s : sup) m[s]=1;
        for ( int i=0; i<recipes.size(); i++) rec[recipes[i]]=i;
        for ( int i=0; i<recipes.size(); i++){
            if (check(ing, i))
                ans.push_back(recipes[i]), m[recipes[i]]=1;
        }
        return ans;
    }
    bool check(vector<vector<string>>& ing, int i){
        for (auto & in : ing[i]){
            if (m[in] == 0 ){
                if (!rec.count(in)) return false;
                if (vis[rec[in]]) return false;
                vis[rec[in]]=1;
                if (!check(ing, rec[in])) return false;
                else
                    m[in]=true;
                vis[rec[in]]=0;
            }   
            
        }
        return true;
    }
};
