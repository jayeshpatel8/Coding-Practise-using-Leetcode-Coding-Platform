class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& R) {
        int minx,miny,maxx,maxy;
        minx = miny = 1e5 + 1;
        maxx = maxy = -(1e5 +1);
        
        int mod=1e9 +7;
        
        //cout << minx << " " << miny << " " <<maxx << " " <<maxy<<endl;
         long  cal=0;
        set<pair<int,int>>set;
        for (auto a : R){
            minx= min(minx, a[0]);
            miny= min(miny, a[1]);
            maxx= max(maxx, a[2]);
            maxy= max(maxy, a[3]);
            
             long  side1 = a[2]-a[0];
             long  side2 = a[3]-a[1];
             long area = (side1  * side2)%mod;
            if (set.count({a[0],a[3]})) set.erase({a[0],a[3]});
            else
                set.insert({a[0],a[3]});
            if (set.count({a[0],a[1]})) set.erase({a[0],a[1]});
            else set.insert({a[0],a[1]});
            if (set.count({a[2],a[1]})) set.erase({a[2],a[1]});
            else set.insert({a[2],a[1]});
            if (set.count({a[2],a[3]})) set.erase({a[2],a[3]});
            else set.insert({a[2],a[3]});
            cal= (cal +area)%mod;
        }
   //     cout << area << " " <<cal <<endl;
        if (set.size()!=4 || !set.count({minx,miny}) || !set.count({minx,maxy}) || !set.count({maxx,miny}) || !set.count({maxx,miny})) return false;
         long side1 = maxx-minx , side2 = maxy-miny;
         long area = (side1 * side2)%mod;
        return cal == area;
    }
};