class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int start = Integer.MAX_VALUE;
        int end = 0;

        for (List<Integer> num : nums) {
            start = Math.min(start, num.get(0));
            end = Math.max(end, num.get(1));
        }

        int[] carparking = new int[end+2];

        for (List<Integer> num : nums) {
            carparking[num.get(0)]++;
            carparking[num.get(1) + 1]--;
        }

        int sum = 0 , ans= 0;
        for( int i = 0 ; i < carparking.length ; i++){
            sum += carparking[i];

            if(sum > 0){
                ans++;
            }
        }


        return ans;

    }
}
