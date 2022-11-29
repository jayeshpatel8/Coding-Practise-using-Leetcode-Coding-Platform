class RandomizedSet {
public:
vector<int> A;
unordered_map<int,int> map;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (map.count(val)) return false;
        map[val] = A.size();
        A.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (map.count(val)==0) return false;
        int i = map[val];
        map.erase(val);
        if (i < A.size()-1){
            A[i] = A[A.size()-1];
            map[A[i]]=i;
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