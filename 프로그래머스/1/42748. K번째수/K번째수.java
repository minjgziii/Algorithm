import java.util.*;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        
        for(int i=0; i<commands.length; i++) {
            List<Integer> a = new ArrayList<>();
            
            int start = commands[i][0];
            int end = commands[i][1];
            int idx = commands[i][2];
            
            for(int j=start-1; j<=end-1; j++) {
                a.add(array[j]);
            }
            
            Collections.sort(a);
            
            answer.add(a.get(idx-1));
        }
        
        return answer;
    }
}