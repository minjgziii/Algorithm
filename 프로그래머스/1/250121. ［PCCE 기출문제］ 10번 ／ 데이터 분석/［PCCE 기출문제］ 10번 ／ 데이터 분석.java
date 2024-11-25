import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
              
        Map<Integer, Map<String, Integer>> mp = new HashMap<Integer, Map<String, Integer>>();
        Map<Integer, Integer> ans = new HashMap<Integer, Integer>();
        List<Integer> list = new ArrayList<Integer>();

        for(int i=0; i<data.length; i++) {
            Map<String, Integer> m_data = new HashMap<String, Integer>();
            int code = data[i][0]; // code
            int date = data[i][1]; // date
            int maximum = data[i][2]; // maximum
            int remain = data[i][3]; // remain
            
            m_data.put("code", code);
            m_data.put("date", date);
            m_data.put("maximum", maximum);
            m_data.put("remain", remain);
            
            mp.put(i, m_data);
        }
        
        // System.out.println(mp);

        for(int j=0; j<data.length; j++) {
            if(mp.get(j).get(ext) < val_ext) {
                ans.put(j, mp.get(j).get(sort_by));
                list.add(j);
            }
        }
        
        List<Integer> keys = new ArrayList<>(ans.keySet());
		Collections.sort(keys, (v1, v2) -> (ans.get(v1).compareTo(ans.get(v2))));
        
        int[][] answer = new int[keys.size()][4];
        
        for(int x=0; x<keys.size(); x++) {
            for(int y=0; y<4; y++) {
                answer[x][0] = mp.get(keys.get(x)).get("code");
                answer[x][1] = mp.get(keys.get(x)).get("date");
                answer[x][2] = mp.get(keys.get(x)).get("maximum");
                answer[x][3] = mp.get(keys.get(x)).get("remain");
            }
        }
        
        return answer;
    }
}