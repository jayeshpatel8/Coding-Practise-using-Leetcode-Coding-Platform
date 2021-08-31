class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        auto compare = [&](auto &s1, auto &s2){
                                                      return (s1.size() == s2.size()? s1 > s2 : s1.size() > s2.size());
                                                  };
        priority_queue<string,vector<string>,decltype(compare)> pq(compare);
        int i=0;
        for (auto &s : nums){
           pq.push(s);
            if (i++ >= k) pq.pop();
            
        }
        return pq.top();
    }
};