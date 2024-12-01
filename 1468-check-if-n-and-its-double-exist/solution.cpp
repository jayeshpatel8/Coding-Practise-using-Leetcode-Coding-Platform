class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_set<int> s;
        for (auto i : arr){
            if (s.count(i * 2)) return 1;
            if ( (i &1)==0  && s.count(i/2)) return 1;
            s.insert(i);
        }
        return 0;
    }
};
