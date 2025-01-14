import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        
        int left = 0; // 가장 가벼운 사람
        int right = people.length - 1; // 가장 무거운 사람
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++; // 가벼운 사람을 태운다
            }
            right--; // 무거운 사람은 항상 태운다
            answer++; // 보트 하나 사용
        }
        
        return answer;
    }
}