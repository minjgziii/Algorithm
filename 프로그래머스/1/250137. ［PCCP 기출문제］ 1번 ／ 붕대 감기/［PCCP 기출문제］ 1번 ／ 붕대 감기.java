import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int save_time = bandage[0]; // 시전 시간
        System.out.println(save_time);
        int save_amount = bandage[1]; // 초당 회복량
        int save_add_amount = bandage[2]; // 추가 회복량
        
        int now_time = 1; //현재 시간
        int now_health = health; // 현재 체력
        int suc_cnt = 0; // 연속 성공 횟수
        
        for(int i=0; i<attacks.length; i++) {
            int times = attacks[i][0]; // 공격 시간
            int amounts = attacks[i][1]; // 피해량

            // 공격한 시간이면 -> 피해량만큼 체력 감소 & 연속 성공 초기화
            if(now_time == times) {
                // 체력이 0보다 작아지면 사망 후 -1 출력 
                if(now_health - amounts <= 0) {
                    now_health = -1;
                    break;
                }
                // 체력 감소 & 연속 성공 초기화
                else {
                    now_health -= amounts;
                    suc_cnt = 0;
                }
            }
            
            // 공격한 시간이 아님
            else {
                i--;
                // 현재 최대 체력이면 -> 변화 x & 연속 성공 횟수 +1
                if(now_health == health || now_health + save_amount >= health) {
                    now_health = health;
                    suc_cnt++;
                    if(suc_cnt == save_time) {
                        suc_cnt = 0;
                    }
                }
                // 체력 회복 && 연속 성공 횟수 +1
                else {
                    now_health += save_amount;
                    suc_cnt++;
                    // 연속 성공하면 -> 추가 회복량 획득 & 연속 성공 초기화
                    if(suc_cnt == save_time) {
                        now_health += save_add_amount;
                        suc_cnt = 0;
                    }
                }

                // 연속 성공하면 -> 추가 회복량 획득 & 연속 성공 초기화
                // if(suc_cnt == save_time) {
                //     now_health += save_add_amount;
                //     suc_cnt = 0;
                // }
            }
            //System.out.println(now_time + "  " + now_health+ "  " + suc_cnt);
            now_time++;
        }
        
        return now_health;
    }
}