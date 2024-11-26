import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> mp = new HashMap<>();
        
        // 장르별로 합산
        for(int i=0; i<genres.length; i++) {
            if(mp.containsKey(genres[i]) == true) {
                mp.put(genres[i], mp.get(genres[i])+plays[i]);
            }
            else {
                mp.put(genres[i], plays[i]);
            }
        }
        
        // mp의 value값 순서대로 내림차순 정렬
        List<String> keys = new ArrayList<>(mp.keySet());
        Collections.sort(keys, (v2, v1) -> (mp.get(v1).compareTo(mp.get(v2))));
        
        List<Integer> ans = new ArrayList<>(); // 인덱스(답)을 저장할 리스트
        
        for(int i=0; i<keys.size(); i++) {
            Map<Integer, Integer> mm = new HashMap<>();
            int size = 0;
            
            for(int j=0; j<genres.length; j++) {
                if(keys.get(i).equals(genres[j])) {
                    mm.put(j, plays[j]);
                    size++;
                }
            }
            
            List<Integer> kk = new ArrayList<>(mm.keySet());
            Collections.sort(kk, (v2, v1) -> (mm.get(v1).compareTo(mm.get(v2))));
            
            if(size >= 2) {
                size = 2;
            }
            
            for(int x=0; x<size; x++) {
                if(!(kk.get(x) == null)) {
                    ans.add(kk.get(x));
                }
            }
        }
        
        int[] answer = new int[ans.size()];
        
        for(int i=0; i<ans.size(); i++) {
            answer[i] = ans.get(i);
        }
        
        return answer;
    }
}