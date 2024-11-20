import java.util.*;

//입력값 〉 5, [5, 3], [4, 2]
//기댓값 〉 5

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        Arrays.sort(lost);
        Arrays.sort(reserve);
        answer = n - lost.length; // 현재 체육복 있는 학생
        
        for(int i=0; i<lost.length; i++) {
            for(int j=0; j<reserve.length; j++) {
                if(lost[i] == reserve[j]) {
                    answer++;
                    lost[i] = -10;
                    reserve[j] = -10;
                    break;
                }
            }
        }
        
        // 체육복을 잃어버린 학생들
        for(int i=0; i<lost.length; i++) {
            int max = lost[i] + 1;
            int min = lost[i] - 1;
            
            if(lost[i] == -10) {
                continue;
            }
            
            for(int j=0; j<reserve.length; j++) {
                if(reserve[j] == -10) {
                    continue;
                }
                if(reserve[j] == min) {
                    answer++;
                    reserve[j] = -10;
                    break;
                }
                else if(reserve[j] == max) {
                    answer++;
                    reserve[j] = -10;
                    break;
                }
            }
        }
        return answer;
    }
}