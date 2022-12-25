class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> fb;
        for (auto & s:positive_feedback) fb[s] =3;
        for (auto & s:negative_feedback) fb[s] =-1;
        vector<int> po(student_id.size()),idx(student_id.size());
        for (int i=0; i< student_id.size(); i++){
            string w = "";
            int p=0;
            for (auto c : report[i]){
                if (c==' '){
                    if (w.empty()) continue;
                    if (fb.count(w)){
                        p+=fb[w];
                        
                    }
                    w="";
                }
                else w+=c;
            }
            if (fb.count(w)){
                        p+=fb[w];
                        
            }            
            po[i]=p;
        }
        for (auto p : po) cout << " " << p ;
        cout<<endl;
        iota(begin (idx),end(idx),0);
        sort(begin (idx),end(idx),[&](auto &a, auto &b){ return (po[a] >po[b]) || (po[a] == po[b] && student_id[a]<student_id[b]);});
        vector<int> ans(k);
        for (int i=0; i<k; i++)
            ans[i] = student_id[idx[i]];
        return ans;
    }
};