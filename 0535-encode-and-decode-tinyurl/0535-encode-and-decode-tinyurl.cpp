class Solution {
public:
    map<string,string> mpp;
    int num=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++;
        string ans="https://tinyurl.com/";
        ans+=to_string(num);
        mpp[ans]=longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));