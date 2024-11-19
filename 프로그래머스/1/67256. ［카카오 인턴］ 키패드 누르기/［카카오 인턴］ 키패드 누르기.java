import java.util.*;
class Solution {
    public String solution(int[] numbers, String hand) {
        int left = 10;
        int right = 12;
        String answer = "";
        
        for(int i=0; i< numbers.length;i++){
            System.out.println(left + ":" + right + " : " + numbers[i]);
            if(numbers[i]==0){
                numbers[i] = 11;
            }
            if(numbers[i]%3 == 1){
                left = numbers[i];
                answer += "L";
                continue;
            }   
            else if(numbers[i]%3 == 0){
                right = numbers[i];
                answer += "R";
                continue;
            }
            else {
                int leftR = left/3;
                int rightR = (right-1)/3;
                int answerR = numbers[i]/3;
                
                int leftB = 0;
                int rightB = 0;
                

                if(right%3 == numbers[i]%3){
                    rightB = 1;
                }

                if(left%3 == numbers[i]%3){
                    leftB = 1;
                }

                System.out.println(abs(answerR-leftR)-leftB);
                System.out.println(abs(answerR-rightR)-rightB);
                if(abs(answerR-leftR)-leftB < abs(answerR-rightR)-rightB){
                    left = numbers[i];
                    answer += "L";
                    continue;
                }
                else if(abs(answerR-leftR)-leftB > abs(answerR-rightR)-rightB){
                    right = numbers[i];
                    answer += "R";
                    continue;
                }
                else {
                    if(hand.equals("right")){
                        answer += "R";
                        right = numbers[i];
                    }
                    else{
                        answer += "L";
                        left = numbers[i];
                    }
                    continue;
                }
            }
        }
        
        return answer;
    }
    
    public int abs(int val){
        return val > 0 ? val : -val;
    }
}