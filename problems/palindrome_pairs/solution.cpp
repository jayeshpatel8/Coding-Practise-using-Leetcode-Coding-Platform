class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> rev;
        for (int i=0; i< words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            rev[s]=i;
        }
        vector<vector<int>> ans;
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<=words[i].size(); j++){
                string pre = words[i].substr(0,j);
                string suf = words[i].substr(j);
                
                //case 1 prefix rev is in map
                if (rev.count(pre) && rev[pre] != i && isPal(suf) )
                    ans.push_back({i,rev[pre]});
                //case 2 suffix rev is in map
                if (pre.size() && rev.count(suf)&& rev[suf] != i && isPal(pre) )
                    ans.push_back({rev[suf], i});                
            }
        }
        return ans;
    }
bool isPal(string &st)
{
    int s = 0, e = st.size()-1;
	while(s<e)
	{
		if(st[s++]!=st[e--])
			return false;
    }
	return true;
}
};