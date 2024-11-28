import java.util.*;

class Solution {
    public int solution(int n, long l, long r) {
        int answer = 0;
        
        for(long i = l - 1; i <= r - 1; i++){
            boolean flag = true; // 0이 나타났는지
            long start = i; // 시작점
            
            while(start >= 5){
                if(start % 5 == 2){
                    flag = false;
                    break;
                }
                start /= 5;
            }
            
            if(start == 2) {
                flag = false;
            }
            
            if(flag == true) {
                answer++;
            } 
        }
        return answer;
    }
}