class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int eg = accumulate(begin(energy), end(energy),0)- initialEnergy + 1;
        int ex = initialExperience, extra=0;

        for (auto e : experience){
            if (ex <= e){
                extra += e-ex+1;
                ex += e-ex+1 ;
                
            }
            
            ex +=e;
        }

        return (eg <0? 0 : eg)+ extra;

    }
};