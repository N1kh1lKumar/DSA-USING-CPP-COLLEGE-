class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size() , m = t.size();
        if(n != m) return false;

        int arr[26] = {0};

        for( int i =0; i<s.size();i++ ){

            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for(int i =0; i<s.size(); i++){
            if(arr[s[i] - 'a'] != 0){
                return false;
            }
        }

        return true;
    }
};