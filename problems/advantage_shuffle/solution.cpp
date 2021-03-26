class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        set<pair<int,int>> s;
        for (int i=0, j=0; i<A.size(); i++) s.insert({B[i],i});
        
        int  end =  A.size()-1, beg=0;
        vector<int> ans (end+1);
        for (auto it = s.rbegin(); it != s.rend(); it++)  
        {
            int num = it->first, j = it->second; 
            if(A[end]<=num)  
                ans[j]=A[beg++]; 
            else
                ans[j] = A[end--];        
        }
        return  ans;
    }
};