class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> map;
        
        for(auto s : arr){
            map[s]++;
        }
        for(auto s : arr){
            if (map[s]==1)
                if (k--==1) return s;
        }
        return "";
    }
};
