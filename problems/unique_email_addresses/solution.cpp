class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> set;
        for (auto s : emails){
            string n;

            for(auto c : s){
                if(c == '.' ) continue;
                if(c == '+' ||c == '@')
                    break;
                n +=c;
            }

            set.insert(n + s.substr(s.find('@')));
        }
        return set.size();
    }
};