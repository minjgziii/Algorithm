import java.util.*;

public class Solution {
    public List<Integer> solution(int []arr) {
        int[] answer = {};

        List<Integer> ls = new ArrayList<>();
        
        Deque<Integer> s = new ArrayDeque<>();
        
        for(int a : arr) {
            if(s.size()==0) {
                s.add(a);
            }
            else if(a != s.getLast()) {
                s.add(a);
            }
        }
        
        int size = s.size();
        
        for(int i=0; i<size; i++) {
            ls.add(s.getFirst());
            s.poll();
        }
        
        return ls;
    }
}