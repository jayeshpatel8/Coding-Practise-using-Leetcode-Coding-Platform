class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int ans = 0;
        if (date1 > date2) swap(date1, date2);
        int start = stoi(date1.substr(0,4)), end = stoi(date2.substr(0,4)), sameyear = start==end;
        int ms = stoi(date1.substr(5,2)), me = stoi(date2.substr(5,2)), samemonth = ms==me;
        int ds = stoi(date1.substr(8,2)), de = stoi(date2.substr(8,2)), samedate = ds==de;
       
        int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  
        if (sameyear == 0){
            int i=start;
            while(++i < end){
                ans += 365;
                ans += ((i%4 == 0) && (i%100 != 0 || i%400 == 0));
                //start++;
            }
            
            
                ans += month[ms]-ds + de;  
               
                i = ms;
                ans += (start%4 == 0 && (start%100 != 0  || start%400 == 0) && ms<=2);
                while(++i <= 12){
                    ans+=month[i];                    
                }
                i=0;
               
                ans += (end%4 == 0 && (end%100 != 0  || end%400 == 0) && me>=3);
                while(++i < me){
                    ans+=month[i];                    
                }
               
            
   
            
        }
        else{
            if (samemonth == 0){
                ans += month[ms]-ds + de;  
                int i = ms;
                ans += (start%4 == 0 && (start%100 != 0  || start%400 == 0) && ms<=2&& me>2);
                while(++i < me){
                    ans+=month[i];                    
                }
            }            
            else{
                ans +=de-ds;
            }            
        }
        return ans;
    }
};