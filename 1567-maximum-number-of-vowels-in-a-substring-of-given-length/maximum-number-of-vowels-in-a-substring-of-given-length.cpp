class Solution {
public:
    int maxVowels(string s, int k) {
        int start = 0, end = 0 , currVowel = 0;
        int maxVowel = 0;

        for(; end < s.size(); end++){
            if(isVowel(s[end])){
                currVowel++;
            }

            if(end-start+1  == k){

                   maxVowel = max(maxVowel , currVowel);
                if(isVowel(s[start])){
                    currVowel--;
                }
                  start++;
            }  
        }
        return maxVowel;
    }


    bool isVowel(char c){
        return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};