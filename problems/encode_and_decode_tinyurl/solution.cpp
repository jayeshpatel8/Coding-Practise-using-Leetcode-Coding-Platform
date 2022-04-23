class Solution {
public:
    int i=1;
    unordered_map<string,string> m;
    //unordered_map<string,string> encm;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        //auto it = encm.find(longUrl);
          //  if (encm.end() != it)
           //     return encm[longUrl];
           // else{
            //    encm[longUrl]=to_string(i);
        auto enc=to_string(i++);
                 m[enc] = longUrl;      
                return enc;
           // }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));