class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int i = 0;
        
        while(true) {
            boolean flag = false;
            
            if(i == s.length()-1) {
                break;
            }
            
            char a = s.charAt(i); // 비교 기준 문자 b
            int a_cnt = 1;
            int not_a_cnt = 0;
            
            for(int j=i+1; j< s.length(); j++) {
                if(j >= s.length()-1) {
                    flag = true;
                    break;
                }
                if(a == s.charAt(j)) {
                    a_cnt++;
                }
                else {
                    not_a_cnt++;
                }
                
                if(not_a_cnt == a_cnt) {
                    answer++;
                    i = j+1;
                    break;
                }
            }
            
            if(flag == true) {
                break;
            }
        }
        
        return answer+1;
    }
}