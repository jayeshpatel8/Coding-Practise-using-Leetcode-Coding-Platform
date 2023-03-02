class Solution {
public:
    int compress(vector<char>& chars) {
        char prev= chars[0];
        int ans = 0, rep = 0 ,  i=0 , j = 0;
        string s;
        while (i < chars.size()){
            if (chars[i] != chars[j]) {
                s +=chars[j];
                if (rep > 1)
                    s += to_string(rep);
                rep = 0;
                j = i;
            }
            rep++;
            i++;
        }
        if (rep > 0){
                s +=chars[j];
                string s2;
                if (rep > 1)
                    s += to_string(rep);
        }
        ans = s.size();
        for (int i=0; i< ans; i++) chars[i]=s[i];
        return ans;
    }
};