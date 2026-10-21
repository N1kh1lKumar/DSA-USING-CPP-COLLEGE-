
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int queryLength = queries.length;

        int[] result = new int[queryLength];
        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

        int[][] sortedQueries = new int[queryLength][2];

        for(int i = 0; i < queryLength; i++){
            sortedQueries[i][0] = queries[i];
            sortedQueries[i][1] = i;
        }

        Arrays.sort(sortedQueries, (a, b) -> Integer.compare(a[0], b[0]));

        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int start = 0, end = 0;

        for(int i = 0; i < queryLength; i++){
            int time = sortedQueries[i][0];
            int index = sortedQueries[i][1];
            int startTime = time - x;

            while(end < logs.length && logs[end][1] <= time){
                int serverId = logs[end][0];
                freqMap.put(serverId, freqMap.getOrDefault(serverId, 0) + 1);
                end++;
            }

            while(start < end && logs[start][1] < startTime){
                int serverId = logs[start][0];
                freqMap.put(serverId, freqMap.get(serverId) - 1);

                if(freqMap.get(serverId) == 0){
                    freqMap.remove(serverId);
                }

                start++;
            }

            result[index] = n - freqMap.size();
        }

        return result;
    }
}
