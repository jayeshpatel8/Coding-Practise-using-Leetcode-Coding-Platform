class Solution {
public:
    int  N;
    unordered_map<int,int> freq;
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> m;
        for (auto i : nums)  m[i]++;
        
        for(auto  i : m) freq[i.second]++;
        N = quantity.size();
        //sort(begin(freq), end(freq),greater<int>());
        sort(begin(quantity), end(quantity),greater<int>());
        return dfs(0,quantity);
    }
    int dfs(int i, vector<int>& qua){
        if(i== N) return true;
        
        for ( auto j :  freq){
            if (j.second >0 && j.first >= qua[i]){
                freq[j.first]--, freq[j.first -  qua[i]]++;
                if (dfs(i+1,qua)) return true;
                freq[j.first]++, freq[j.first -  qua[i]]--;
            }
        }
        return false;
    }
};