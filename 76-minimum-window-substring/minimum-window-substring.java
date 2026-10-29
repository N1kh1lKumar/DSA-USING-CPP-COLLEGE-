class Solution {
    public String minWindow(String s, String t) {
         int wStart = 0, wEnd = 0, startIndex = -1, matched = 0 , length =Integer.MAX_VALUE;
        HashMap<Character , Integer>tMap = new HashMap<>();

        for(int index =0; index < t.length(); index++){
            char currChar = t.charAt(index);
            tMap.put(currChar , tMap.getOrDefault(currChar , 0)+1);
        }

        for( ; wEnd < s.length(); wEnd++){
            char currChar = s.charAt(wEnd);
            if(tMap.containsKey(currChar)){
                tMap.put(currChar , tMap.get(currChar) -1);

                if(tMap.get(currChar) >= 0){
                    matched++;
                }
            }

            while(matched == t.length()){
                if(length > (wEnd - wStart +1)){
                    length = (wEnd - wStart + 1);
                     startIndex = wStart;
                }


                char startChar = s.charAt(wStart++);
                if(tMap.containsKey(startChar)){
                    if(tMap.get(startChar) == 0){
                        matched -= 1;
                    }

                    tMap.put(startChar , tMap.getOrDefault(startChar , 0)+1);
                }
            }
        }
        if(startIndex == -1) return "";
        return s.substring(startIndex , startIndex+length);
    }
}
