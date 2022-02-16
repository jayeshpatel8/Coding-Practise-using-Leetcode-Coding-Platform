class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        vector<int> pos;
        pos.push_back(0);
        for (int i=1; i<s.size(); i++){
            if (s[i] == ' ')  pos.push_back(i+1);
        }
        int N = s.size();
        while (1){
            string a;
            bool f=false;
            for (auto &i : pos){
                if (i < N && s[i] != ' ')
                    a.push_back(s[i++]), f=true;
                else
                    a += ' ';
            }
            int size = a.size();

            if (f){
                for (int c = size-1; c>=0; c--)
                {
                    if (a[c] == ' ') size--;
                    else break;
                }                
                ans.push_back(a.substr(0,size));
            }
            else break;
        }
        return ans;
    }
};