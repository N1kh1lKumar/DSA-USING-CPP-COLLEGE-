class Solution {
public:
    int maximumLengthSubstring(string s) {
        int arr[26] = {0};

        int start = 0, end =0;
        int maxLength = 0;
        for( ; end < s.size() ; end++){
            arr[s[end] - 'a']++;

            while(arr[s[end] - 'a'] > 2){
                arr[s[start] - 'a']--;
                start++;
            }

            maxLength = max( maxLength , end -start+1);

        }
        return maxLength;
    }
};
