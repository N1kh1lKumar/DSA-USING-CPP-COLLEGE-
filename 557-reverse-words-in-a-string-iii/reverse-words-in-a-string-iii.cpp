class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            
            int start = i;
           
            while (i < n && s[i] != ' ') i++;
            int end = i - 1;

            while (start < end) {
                swap(s[start++], s[end--]);
            }
        }
        
        return s;
    }
};
