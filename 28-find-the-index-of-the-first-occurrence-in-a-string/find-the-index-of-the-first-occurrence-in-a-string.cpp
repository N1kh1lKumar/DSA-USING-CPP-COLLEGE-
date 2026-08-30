class Solution {
public:
    int strStr(string haystack, string needle) {
       size_t found = haystack.find(needle);
       return (found != string::npos) ? found : -1;        
    }
};