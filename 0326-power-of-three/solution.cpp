class Solution { public: bool isPowerOfThree(int n) { //max possible int 3^n => 3^19=> 1162261467 // as 3 is prime , (3^19) %n ==0 
return n > 0 && 1162261467 % n == 0; } };
