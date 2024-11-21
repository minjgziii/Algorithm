class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        // video_len
        String[] vl_data = video_len.split(":");
        int vl_min = Integer.parseInt(vl_data[0]);
        int vl_sec = Integer.parseInt(vl_data[1]);
        int vl_now = vl_min*60 + vl_sec; 
        
        // pos
        String[] p_data = pos.split(":");
        int p_min = Integer.parseInt(p_data[0]);
        int p_sec = Integer.parseInt(p_data[1]);
        int p_now = p_min*60 + p_sec;
        
        // op_start
        String[] os_data = op_start.split(":");
        int os_min = Integer.parseInt(os_data[0]);
        int os_sec = Integer.parseInt(os_data[1]);
        int os_now = os_min*60 + os_sec;
        
        // op_end
        String[] oe_data = op_end.split(":");
        int oe_min = Integer.parseInt(oe_data[0]);
        int oe_sec = Integer.parseInt(oe_data[1]);
        int oe_now = oe_min*60 + oe_sec;
        
        int ans = p_now;
        
        for(int i=0; i<commands.length; i++) {
            //현재 재생 위치가 오프닝 구간인 경우 자동으로 오프닝이 끝나는 위치로 이동
            if(ans >= os_now && ans <= oe_now) {
                ans = oe_now;
            }
            // 10초 후로 이동
            if(commands[i].equals("next")) {
                ans += 10;
            }
            // 10초 전으로 이동
            else if(commands[i].equals("prev")) {
                ans -= 10;
            }
            
            // 현재 위치가 동영상 위치보다 이상일 때
            if(ans >= vl_now) {
                ans = vl_now;
            }
            if(ans <= 0) {
                ans = 0;
            }
        }
        
        if(ans >= os_now && ans <= oe_now) {
            ans = oe_now;
        }
        
        int min = ans / 60;
        int sec = ans % 60;
        
        String s_min = Integer.toString(min);
        String s_sec = Integer.toString(sec);
        
        if(s_min.length() == 1) {
            s_min = "0" + s_min;
        }
        if(s_sec.length() == 1) {
            s_sec = "0" + s_sec;
        }
        
        answer += s_min + ":" + s_sec;
        
        return answer;
    }
}