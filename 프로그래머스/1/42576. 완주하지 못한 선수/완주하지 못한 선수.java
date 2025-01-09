import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        // 참가자들을 담을 map 선언
        Map<String, Integer> map = new HashMap<>();
        
        // 참가자 배열을 돌면서 map에 참가자 이름과 수를 담음
        for(String parti : participant) {
            map.put(parti ,map.getOrDefault(parti, 0)+1);
        }
        
        // 완주한 사람은 제거 (value 값을 -1) 
        for(String compl : completion) {
            map.put(compl, map.get(compl)-1);
        }
        
        // participant를 돌면서 value 값이 0보다 크면 그게 답
        for(String parti : participant) {
            if(map.get(parti) > 0) {
                answer = parti;
                break;
            }
        }
        
        return answer;
    }
}