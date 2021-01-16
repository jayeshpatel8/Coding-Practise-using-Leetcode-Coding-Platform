class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i=0, j=people.size()-1;
        int res=0;
        while (i<=j){
            if (people[j] + people[i] <= limit) i++;                
            j--;
            res++;
        }
        return res;
    }
};

