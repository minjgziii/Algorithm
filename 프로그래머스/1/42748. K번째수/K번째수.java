import java.util.*;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        int[] answer = {};
        
        List<Integer> ans = new ArrayList<Integer>();
        
        for(int i=0; i<commands.length; i++) {
            List<Integer> list = new ArrayList<Integer>();
            
            int s = commands[i][0];
            int e = commands[i][1];
            int idx = commands[i][2];
            
            for(int j=s; j<=e; j++) {
                list.add(array[j-1]);
            }
            
            Collections.sort(list);
            ans.add(list.get(idx-1));
        }
        
        return ans;
    }
}