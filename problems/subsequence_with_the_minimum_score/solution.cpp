class Solution {
public:
    void makeprefix(vector<int>& left,vector<int>& right,string &s,string &t){
        for(int i = 0,j = 0; i<s.size() && j<t.size();++i){
            if(s[i]==t[j]){
                left[j] = i; j++;
            }
        }
        for(int i = s.size()-1,j = t.size()-1;i>=0 && j>=0;--i){
            if(s[i]==t[j]){
                right[j] = i; j--;
            }
        }
    }
    bool find(vector<int>& left,vector<int>& right,int m,int n){
        if(m==n) return 1;
        if(right[m]!=-1 || left[n-m-1]!=-1) return 1;
        for(int i = 0,j = m+1; j<n ;++i,++j){
            if(left[i]!=-1 && right[j]!=-1 && left[i]<right[j]) return 1;
        }
        return 0;
    }
    int minimumScore(string s, string t) {
        vector<int> left(t.size(),-1),right(t.size(),-1);
        makeprefix(left,right,s,t);
        int l = 0,h = t.size(),re = -1;
        while(l<=h){
            int m = (l+h)/2;
            if(find(left,right,m,t.size())) { re = m; h = m-1; }
            else l = m+1;
        }
        return re;
    }
};