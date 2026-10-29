class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int counter = 0, score =0;
        vector<int> ans;
        for(int i = 0 ; i<events.size(); i++){
            if(counter == 10) break;

            if(events[i] == "W") 
                counter++;
            else if(events[i] == "WD" || events[i] == "NB")
                score++;
            else{
                score += stoi(events[i]);
            }
        }
        ans.push_back(score);
        ans.push_back(counter);

        return ans;

        
    }
};
