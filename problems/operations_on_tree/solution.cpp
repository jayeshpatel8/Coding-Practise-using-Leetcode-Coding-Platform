class LockingTree {
public:
    unordered_map<int,int> M;
    vector<int> des[2000],par;
    LockingTree(vector<int>& parent) {
        for (int i=1; i< parent.size(); i++){
            des[parent[i]].push_back(i);
        }
        par = parent;
    }
    
    bool lock(int num, int user) {
        if (M.count(num)){
            if (M[num] != -1) return false;
        }
        M[num]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
       if (M.count(num)){
            if (M[num] == user) {
                M[num]=-1;
                return true;        
            }
        }
        return false;
    }
    bool isLocked(int num){
        if (M.count(num) && M[num] != -1 ) return true;
        return false;
    }
    bool upgrade(int num, int user) {
        if (isLocked(num) ) return false;
        // ansc unlocked
        int n  = num;
        while(n > 0){
            if (isLocked(par[n])) return false;
            n = par[n];
        }
        if( dfs(num)){
            M[num]=user;
            return true;
        }
        return false;
    }
    bool dfs(int num){
        int res=0;
        if (isLocked(num)) M[num]=-1, res = 1;
        for (auto i : des[num]){            
            res |= dfs(i);
        }
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */