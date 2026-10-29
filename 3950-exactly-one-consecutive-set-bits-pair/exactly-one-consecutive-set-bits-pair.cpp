class Solution {
public:
    bool consecutiveSetBits(int n) { 
        int count  =0;
        vector<int> binary;
        while(n > 0){
            int rem = n%2;
            binary.push_back(rem);
            n /= 2;
        }

        for(int i=1; i<binary.size(); i++){
            if(binary[i] == 1 && binary[i-1] == 1){
                count ++;
            }
        }
        if(count == 1) return true;
        else return false;
    }
};
