import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int size = nums.length; // 폰켓못의 개수
        
        // 폰켓몬 담을 map 선언
        Map<Integer, Integer> map = new HashMap<>();
        
        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        
        if(map.size() >= size/2) {
            answer = size/2;
        }
        else {
            answer = map.size();
        }
        
        return answer;
    }
}