class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> map;
        for (int i=0; i<target.size(); i++) map[target[i]]=i;
        
        vector<int> stack;
        for (auto i : arr){            
            auto it2 = map.find(i);
            if ( it2 == end(map)) continue;
            auto e = it2->second;
            if (stack.empty() ||stack.back()< e)
                stack.push_back(e);
            else
                *lower_bound(begin(stack),end(stack),e) = e;                
        }
        return target.size()- stack.size();
    }
};