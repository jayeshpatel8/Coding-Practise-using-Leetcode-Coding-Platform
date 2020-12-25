class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (auto i: arr){
            int k = 2 *i;
            if (s.find(k) != s.end() || (i%2==0 && s.find(i/2) != s.end())) return true;
            s.insert(i);
        }
        return false;
    }
};