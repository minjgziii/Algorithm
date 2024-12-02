import java.util.*;

class Solution {
    static Map<String, String> map = new HashMap<>();
    static Map<String, ArrayList<Integer>> rcd = new HashMap<>();
    static String[] inf;
    static String[] score;
    static int sum;
    
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        
        map.put("java", "0");
        map.put("cpp", "1");
        map.put("python", "2");
        map.put("backend", "0");
        map.put("frontend", "1");
        map.put("junior", "0");
        map.put("senior", "1");
        map.put("chicken", "0");
        map.put("pizza", "1");
        
        // 지원자 정보
        for(String temp : info) {
            String[] s = temp.split(" ");
            String key = "";
            
            // 점수 제외 저장
            for(int i=0; i<4; i++) {
                key += map.get(s[i]);
            }
            
            // rcd에 key가 없으면
            if(!rcd.containsKey(key)) {
                ArrayList<Integer> list = new ArrayList<>();
                list.add(Integer.parseInt(s[4])); // 점수 저장
                rcd.put(key, list);
            }
            // 이미 있는 경우, 점수 list 형태로 value 저장
            else {
                rcd.get(key).add(Integer.parseInt(s[4]));
            }
        }
        
        // 정렬
        Set<String> set = rcd.keySet();
        
        for(String key : set) {
            Collections.sort(rcd.get(key));
        }
        
        for(int i=0; i<query.length; i++) {
            sum = 0;
             
            inf = query[i].split(" and ");
            score = inf[3].split(" ");
            inf[3] = score[0];
            backtrack(0, "");
            
            answer[i] = sum;
        }
        
        return answer;
    }
    
    
    // 백트래킹
    public void backtrack(int depth, String key) {
        if(depth == 4) {
            if(!rcd.containsKey(key)) {
                return;
            }
            
            ArrayList<Integer> temp = rcd.get(key);
            
            int start = 0;
            int end = temp.size();
            int target = Integer.parseInt(score[1]);
            
            while(start < end) {
                int mid = (start + end) / 2;
                
                // 해당하는 점수
                if(temp.get(mid) >= target) {
                    end = mid;
                }
                else {
                    start = mid + 1;
                }
            }
            sum += temp.size() - start;
            
            return;
        }
        
        if(!inf[depth].equals("-")) {
            backtrack(depth+1, key + map.get(inf[depth]));
        }
        else {
            backtrack(depth+1, key+"0");
            backtrack(depth+1, key+"1");
            
            if(depth == 0) {
                backtrack(depth+1, key+"2");
            }
        }
    }
}