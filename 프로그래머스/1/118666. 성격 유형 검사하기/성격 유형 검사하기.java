import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        Map<String, Integer> m = new HashMap<String, Integer>();
        
        m.put("R",0);
        m.put("T",0);
        m.put("C",0);
        m.put("F",0);
        m.put("J",0);
        m.put("M",0);
        m.put("A",0);
        m.put("N",0);
        
        
        for(int i=0; i<survey.length; i++) {
            String data = survey[i];
            String n_data = data.substring(0,1);
            String y_data = data.substring(1,2);
            
            int choice = choices[i];
            
            // 선택이 3 이하일 경우 -> 비동의 값 점수 추가
            if(choice <= 3) {
                int temp = m.get(n_data);
                
                m.replace(n_data, temp+ 4-choice);
            }
            // 선택이 5 이상일 경우 -> 동의 값 점수 추가
            else if(choice >= 5) {        
                int temp = m.get(y_data);
                m.replace(y_data, temp + choice - 4);
            }
            // 모르겠음 선택한 경우
            else {
                // -
            }
            System.out.println("R : " + m.get("R"));
            System.out.println("T : " + m.get("T"));
        }
        System.out.println(m.get("R"));
        System.out.println(m.get("T"));
        
        if(m.get("R") >= m.get("T")) {
            answer += "R";
        }
        else {
            answer += "T";
        }
        
        
        if(m.get("C") >= m.get("F")) {
            answer += "C";
        }
        else {
            answer += "F";
        }
        
        if(m.get("J") >= m.get("M")) {
            answer += "J";
        }
        else {
            answer += "M";
        }
        
        if(m.get("A") >= m.get("N")) {
            answer += "A";
        }
        else {
            answer += "N";
        }
        
        return answer;
    }
}