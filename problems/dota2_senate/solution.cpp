class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        int N=0;
        for (auto c : senate)
            if (c=='R') q1.push(N++);
            else q2.push(N++);
        while (!q1.empty() && !q2.empty()){
            auto r = q1.front() ; q1.pop();
            auto d = q2.front() ; q2.pop();
            if (r<d)
                q1.push(r+N);
            else
                q2.push(d+N);
        }
        return q2.empty() ? "Radiant" : "Dire";
    }
};