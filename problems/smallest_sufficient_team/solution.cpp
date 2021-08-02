class Solution {
public:
        
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int> skillid;
        int i=0;
        for (auto &s : req_skills) 
            skillid[s]=i++;            

        int n = req_skills.size();
        unordered_map<int,vector<int>> skill;
        skill.reserve(1 << n); 
        skill[0]={};
        
        for (int i=0; i<people.size(); i++){
            int cur_skill = 0;
            for ( auto &s : people[i])
                cur_skill |=1<<skillid[s];            
            for ( auto & s : skill){
                int comb = cur_skill | s.first;
                if (skill.count(comb) ==0 || skill[comb].size() > s.second.size()+1 ){
                    skill[comb] = s.second;
                    skill[comb].push_back(i);
                }
            }
        }
        return skill[(1 << n )- 1];
    }    
    /*
    int dp[62][1<<16], req_skill=0, best=INT_MAX;
    uint64_t ans=0;
    unordered_map<string,int> skillid;
    vector<int> peopleid ;    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        peopleid.resize(people.size());
        int i=0;
        for (auto &s : req_skills) 
            skillid[s]=i++;            
        
        req_skill = (1 << req_skills.size() )- 1;
        //sort(begin(people), end(people), [&](auto &a , auto &b){ return a.size() <  b.size(); });
        
        i=0;
        for ( auto &p : people){   
            for ( auto &s : p)
                peopleid[i] |=1<<skillid[s];
            i++;
        }

        memset(dp,-1,sizeof(dp));
        int val=find(0,0,0);
        vector<int>  ret;
        int mask=0;
        for (int i=0; i<req_skill; i++){
            for(int person=0;person<people.size();++person){
                cout << dp[person][i] << " ";
            }
            cout << endl;
        }
        for(int person=0;person<people.size();++person)
        {
            if(dp[person][mask]>val)
            {
                mask=mask|peopleid[person-1];
                ret.push_back(person-1);
                val--;
            }
            if(person==people.size()-1){
                if(mask!=req_skill&&mask|peopleid[person]==req_skill)
                    ret.push_back(person);
            }
            if(val==0)
                break;
        }
        return ret;
    }
    uint64_t find(int  i, uint64_t rsmask, uint64_t mask){
        if (req_skill == rsmask ){  
            return 0;
        }
        if (i>= peopleid.size() ) return INT_MAX;
        if (dp[i][rsmask] != -1) return dp[i][rsmask];

        return dp[i][rsmask] = min(find(i+1,rsmask, mask),1 + find(i+1,rsmask | peopleid[i]  , mask|1UL<<i)) ;
    }

    */
};