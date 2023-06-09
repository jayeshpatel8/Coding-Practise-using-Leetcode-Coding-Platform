
class Solution {
public:
string Less20[21] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string Less100[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string above1000[4] = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i=0;
        string ans;
        while (num > 0){
            if (num %1000){
                ans = parseDig(num %1000) + above1000[i] + " " + ans;
            }
            num/=1000;
            i++;
        }
        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
    string parseDig(int num){
        if (!num) return "";
        //123
        else if (num < 20){
            return Less20[num]+ " ";
        }
        else if (num < 100){
            return Less100[num/10] + " " + parseDig(num%10);
        }
        else{
            return Less20[num/100] + " Hundred " + parseDig(num%100);
        }
    }
};