class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> map;
        for (int i = 0 ; i< pieces.size(); i++){
            map[pieces[i][0]] = i;
        }
        for (int i = 0; i< arr.size(); i++){
            if (!map.count(arr[i])) return false;
            for ( auto j : pieces[map[arr[i]]]){
                if ( arr[i] != j) return false;
                i++;
            }
            i--;
        }
        return true;
    }
};