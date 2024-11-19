import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        
         // 선물 받은 사람 정보 저장
        Map<String, Integer> grade = new HashMap<String, Integer>(); // 선물 지수
        
        // key : 선물 준 사람, value : 선물 받은 사람 리스트
        Map<String, Map<String, Integer>> info = new HashMap<String, Map<String, Integer>>();
        
        // receiver 초기화
        
        
        // map에 friends 삽입
        for(int i=0; i<friends.length; i++) {
            Map<String, Integer> receiver = new HashMap<String, Integer>();
            for(int j=0; j<friends.length; j++) {
            receiver.put(friends[j], 0);
            }
            info.put(friends[i], receiver);
        }
        
        // 선물 주고 받은 내역 저장
        for(int i=0; i<gifts.length; i++) {
            String data = gifts[i]; // muzi frodo
            
            String[] givRec = data.split(" ");
            String d_giver = givRec[0]; // 선물 준 사람 muzi
            String d_receiver = givRec[1]; // 선물 받은 사람 frodo
            
            Map<String, Integer> temp = info.get(d_giver); // muzi가 준 사람들 리스트    
            int cnt = temp.get(d_receiver); // frodo가 muzi에게 받은 선물 개수
            temp.put(d_receiver, cnt+1);
            info.put(d_giver, temp);
            
        }
        
        // 선물 지수 계산
        for(int i=0; i<friends.length; i++) {
            Map<String, Integer> temp = info.get(friends[i]);
            
            // 준 선물 개수
            int giveCnt =0;
            
            for(String person : temp.keySet()) {
                giveCnt += info.get(friends[i]).get(person);
            }
            
            // 받은 선물 개수
            int receiveCnt = 0;
            for(String person : temp.keySet()) {
                receiveCnt += info.get(person).get(friends[i]);
            }
            
            int i_grade = giveCnt - receiveCnt; // 선물 지수
            grade.put(friends[i], i_grade);
        }
      
        // 돌면서 다음 달 받을 개수 세기
        for(int i=0; i<friends.length; i++) {
            int willReceives = 0;
            Map<String, Integer> temp = info.get(friends[i]); // muzi가 준 사람들 리스트
            //System.out.println(temp);
                        
            for (String person : temp.keySet()) {
                int gives = info.get(friends[i]).get(person); // 자기가 준 개수
                int receives = info.get(person).get(friends[i]); // 이 사람에게 받은 개수
                
                // 자기가 준 개수가 더 많을 경우, 선물을 하나 받음
                if(receives < gives) {
                    willReceives++;
                }
                // 두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면 선물 지수 비교
                else if((receives == 0 && gives == 0) || (receives == gives)) {
                    // 선물 지수가 크면 선물을 받음
                    if(grade.get(person) < grade.get(friends[i])) {
                        willReceives++; 
                    }
                }
            }
            
            if (answer < willReceives) {
                answer = willReceives;
            }
        }
        
        return answer;
    }
}