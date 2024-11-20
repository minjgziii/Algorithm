import java.util.*;

class Solution {
    public Deque<Integer> solution(String today, String[] terms, String[] privacies) {
        Deque<Integer> answer = new ArrayDeque<>();
        Map<String, Integer> mp = new HashMap<String, Integer>(); // 약관과 유효기간
        
        // 오늘 날짜 
        String today_year = today.substring(0,4); // year
        int i_t_y = Integer.parseInt(today_year);
        
        String today_mon = today.substring(5,7); // month
        int i_t_mon = Integer.parseInt(today_mon);
        
        String today_date = today.substring(8,10); // day
        int i_t_date = Integer.parseInt(today_date);
        
        // 약관 종류와 유효기간 저장
        for(int i=0; i<terms.length; i++) {
            String[] tem_data = terms[i].split(" ");
            String t = tem_data[0]; // 약관 종류
            int period = Integer.parseInt(tem_data[1]); // 유효기간
            
            mp.put(t, period);
        }
        
        
        for(int i=0; i<privacies.length; i++) {
            String[] data = privacies[i].split(" ");
            String date = data[0]; // 날짜
            String type = data[1]; // 약관 종류
            
            String year = date.substring(0,4); // 년
            int i_year = Integer.parseInt(year);
            String mon = date.substring(5,7); // 달
            int i_mon = Integer.parseInt(mon);
            String day = date.substring(8,10); // 일
            int i_day = Integer.parseInt(day);
            
            int per = mp.get(type); // 유효기간
            // 유효기간이 12달 초과이면
            if(per > 12) {
                i_year += per/12;
                per = per % 12;
            }
            
            // 기준 값
            String bound = "";
            String s_day = "";
            
            // day가     
            if(i_day - 1 <= 0) {
                s_day = "28";
                i_mon -= 1;
            }
            else {
                s_day = Integer.toString(i_day-1);
            }
            if(s_day.length() == 1) {
                s_day = "0" + s_day;
            }
            
            // 년도 변화 없음
            if(i_mon + per <= 12) {
                String a = Integer.toString(i_mon + per);
                if(a.length() == 1) {
                    a = "0" + a;
                }
                bound = Integer.toString(i_year) + "." + a + "." + s_day;
            }
            // 년도 + 1
            else {
                String a = Integer.toString(i_mon + per - 12);
                if(a.length() == 1) {
                    a = "0" + a;
                }
                String b = Integer.toString(i_year + 1);
                bound = b + "." + a + "." + s_day;
            }
            
            int a_today= Integer.parseInt(today.replace(".", ""));
            int a_bound = Integer.parseInt(bound.replace(".", ""));
            
            
            // 유효기간이 지났으면 파기
            if(a_today > a_bound ) {
                answer.add(i+1);
            }
            
        }
        return answer;
        
    }
}