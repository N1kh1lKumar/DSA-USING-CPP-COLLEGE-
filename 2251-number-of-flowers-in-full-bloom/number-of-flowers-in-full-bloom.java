class Solution {
    public int[] fullBloomFlowers(int[][] flower, int[] people) {
       TreeMap<Integer , Integer> days = new TreeMap<>();

       for(int i =0; i< flower.length ; i++){
        int startTime = flower[i][0];
        int endTime = flower[i][1];

        days.put(startTime , days.getOrDefault(startTime , 0) + 1);
        days.put(endTime+1 , days.getOrDefault(endTime+1 , 0) - 1);        
       }    

       int fullBloom = 0;

       for(Map.Entry<Integer, Integer> entry : days.entrySet()){
        fullBloom += entry.getValue();
        days.put(entry.getKey() , fullBloom);
       }

       int[] answer = new int[people.length];
       for(int i = 0; i<people.length ; i++){
        Integer nearestday =  days.floorKey(people[i]);
        if(nearestday != null){
            answer[i] = days.get(nearestday);
        }
       }
        return answer;
    }
}
