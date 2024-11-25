import java.util.*;

class Solution {
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        
        List<Integer> ans = new ArrayList<Integer>();
        
        for(int i=0; i<mats.length; i++) {
            int size = mats[i]; // mat의 사이즈
            boolean isAll = false; // 모두 -1인지
            
            for(int j=0; j<=park.length-size; j++) {
                for(int k=0; k<=park[0].length-size; k++) {
                    boolean flag = true;
                    
                    for(int x=0; x<size; x++) {
                        for(int y=0; y<size; y++) {
                            if(!park[j+x][k+y].equals("-1")) {
                                flag = false;
                                break;
                            }
                        }
                        if(flag == false) {
                            break;
                        }
                    }
                    // 다 -1이면
                    if(flag == true) {
                        isAll = true;
                        break;
                    }
                }
                if(isAll == true) {
                    break;
                }
            }
            if(isAll == true) {
                ans.add(size);
            }
        }
        
        if(ans.size() == 0) {
            return -1;
        }
        
        Collections.sort(ans);
        answer = ans.get(ans.size()-1);
        
        return answer;
    }
}