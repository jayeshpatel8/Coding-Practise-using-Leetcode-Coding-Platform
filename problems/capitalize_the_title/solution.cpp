class Solution {
public:
    string capitalizeTitle(string title) {
        string ans;
        for (int i=0; i<title.size(); i++){
            if (title[i] == ' ') {ans.push_back(' ');continue;}
            string t;
            while( title[i] != ' ' && i < title.size()){
                t.push_back(title[i++]);
            }
            i--;
            if (t.size() <=2){
                for (auto c : t) ans.push_back(tolower(c));
            }
            else{
                for (auto &c : t) c = (tolower(c));
                t[0] = toupper(t[0]);
                ans += t;
            }
        }
        return ans;
    }
};