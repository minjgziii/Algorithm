import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        int size = citations.length;
        
        List<Integer> list = new ArrayList<>();
        
        for(int i=0; i<=size; i++) {
            int cnt = 0; // i번 이상 인용된 논문의 개수
            int cnt_not = 0; // i번 이하 인용된 논문의 개수
            
            for(int j=0; j<size; j++) {
                if(citations[j] >= i) {
                    cnt++;
                }
                else {
                    cnt_not++;
                }
            }
            
            if(cnt >= i) {
                list.add(i);
            }
        }
        
        Collections.sort(list, Collections.reverseOrder());
        
        answer = list.get(0);
        
        return answer;
    }
}