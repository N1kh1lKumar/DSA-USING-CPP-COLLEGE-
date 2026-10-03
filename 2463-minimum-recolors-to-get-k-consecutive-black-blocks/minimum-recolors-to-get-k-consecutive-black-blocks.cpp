class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start = 0, end = 0;
        int minimumWhite  = INT_MAX;
        int countOfWhite = 0;

        for( ; end<blocks.size(); end++){
            if(blocks[end] == 'W'){
                countOfWhite++;
            }

            if(end - start+1  == k){
                minimumWhite = min( minimumWhite, countOfWhite);

                if(blocks[start++] == 'W'){
                    countOfWhite--;
                }
            }

        }

        return minimumWhite;
    }
};