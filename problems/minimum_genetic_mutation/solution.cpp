class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> banks, seen;
        for (auto &s : bank) banks.insert(s);
        queue<string> q;
        q.push(start);
        seen.insert(start);
        int steps=0;
        string s2 = "ACGT";
        while (!q.empty()){
            int sz = q.size();
            while (sz-- > 0){                
                auto s  = q.front(); q.pop();
                if(s == end) return steps;
                for (int i=0; i<s.size(); i++){
                    auto t = s[i];
                    for (auto c : s2){
                        if (c == t) continue;
                        s[i]=c;
                        if (seen.count(s) || banks.count(s)==0) continue;
                        seen.insert(s);
                        q.push(s);
                    }
                    s[i]=t;
                }
            }
            steps++;
        }
        return -1;
    }
};