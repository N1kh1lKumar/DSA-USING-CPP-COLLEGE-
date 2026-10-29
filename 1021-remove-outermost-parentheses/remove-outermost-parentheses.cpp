class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int countOfBracket =0;
        for(auto ch : s){

            if(ch == '('){ 
            if(countOfBracket > 0){
                ans += ch;
            }
            countOfBracket++;
            }
            else{
                 countOfBracket--;
                if(countOfBracket >0){
                    ans += ch;
                }
               
            }
        }

        return ans;
    }
};
