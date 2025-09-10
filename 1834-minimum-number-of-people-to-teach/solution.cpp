class Solution {
public:
    

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size(), min_user=INT_MAX;
        vector<bitset<512>> lmap(users);
        for (int u=0; u<users; u++ ){
            for (auto l : languages[u]) lmap[u][l]=1;
        }
        bitset<512> no_com;
        for (auto &f : friendships){
                int u =f[0]-1,v=f[1]-1;
            bool found=false;
            for (auto l : languages[u]){
                if (lmap[v][l]) {found = true; break;}
            }
            if (!found){
                no_com[u] = no_com[v] = 1;
            }
        }
        
        for (int lang=1; lang <=n; lang++){
            int cnt=0;
            for (int i=0; i<users; i++){
                if (no_com[i]){
                    cnt  += 1-lmap[i][lang];
                    if (cnt>=min_user)break;                    
                }                                
            }
            min_user = min(min_user,cnt);
        }
        return min_user;
    }

};
