class Solution {
public:
    int maxDistance(string moves) {
        int x2 = 0, y2=0,k=0;
        for( int i=0; i<moves.size(); i++){
            if(moves[i] == 'U'){
                y2++;
            }
            else if(moves[i] == 'D'){
                y2--;
            }
            else if(moves[i] == 'L'){
                x2--;
            }
            else if(moves[i] == 'R'){
                x2++;
            }
            else{
                k++;
            }
        }
        int ans = abs(0-x2) + abs(0 - y2) +k;
        return ans;
    }
};
