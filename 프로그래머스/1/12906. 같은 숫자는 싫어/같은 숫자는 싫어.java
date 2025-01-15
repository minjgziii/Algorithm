import java.util.*;

public class Solution {
    public List<Integer> solution(int []arr) {
        List<Integer> ls = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int a : arr) {
            if(dq.size()==0 || a != dq.getLast()) {
                dq.add(a);
            }
        }
        
        int size = dq.size();
        
        for(int i=0; i<size; i++) {
            ls.add(dq.getFirst());
            dq.poll();
        }
        
        return ls;
    }
}