import java.util.*;

class Solution {
    public String solution(String X, String Y) {
        StringBuilder sb = new StringBuilder();
        
        boolean flag = false;
        
        Map<String, Integer> xm = new HashMap<>();
        Map<String, Integer> ym = new HashMap<>();
        
        String[] arr = X.split("");
        
        for(int i = 0; i < X.length(); i++) {
            String temp = arr[i];
            
            if(xm.get(temp) != null) {
                xm.put(temp, xm.get(temp)+1);
            }
            else {
                xm.put(temp, 1);
            }
        }
        
        String[] arr1 = Y.split("");
        
        for(int i = 0; i < Y.length(); i++) {
            
            String temp = arr1[i];
            
            if(ym.get(temp) != null) {
                ym.put(temp, ym.get(temp)+1);
            }
            else {
                ym.put(temp, 1);
            }
        }
        
        List<String> x_keySet = new ArrayList<>(xm.keySet());
        Collections.reverse(x_keySet);
        
        for(String s : x_keySet) {
            int cnt = Math.min(xm.get(s), ym.getOrDefault(s,0));
            
            for(int i=0; i<cnt; i++) {
                flag = true;
                sb.append(s);
            }
        }
        
        if(flag == false) {
            return "-1";
        }
        
        if(sb.charAt(0) == '0') {
            return "0";
        }
        
        return sb.toString();
    }
}