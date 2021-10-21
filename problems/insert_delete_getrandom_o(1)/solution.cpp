class RandomizedSet {
public:
    unordered_map<int,int> M;
    vector<int> A;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (M.count(val)) return false;
        M[val] = A.size();
        A.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (M.count(val)==0) return false;
        int i = M[val];
        M.erase(val);
        if (i < A.size()-1){
            A[i] = A[A.size()-1];                
            M[A[i]]=i;
        }
        
        A.pop_back();
        return true;        
    }
    
    int getRandom() {
        return A[rand()%A.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */