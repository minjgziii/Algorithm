import java.util.*;

class Solution {
    public int[] solution(String[] wallpaper) {
        int lux=wallpaper[0].length();
        int luy=-1;
        int rdx=-1;
        int rdy=-1;
        for(int i=0; i<wallpaper.length; i++) {
            String str = wallpaper[i];
            if(str.indexOf("#") > -1){
                lux = lux>str.indexOf("#")?str.indexOf("#"):lux;
                luy = luy==-1?i:luy;
                rdx=rdx<str.lastIndexOf("#")?str.lastIndexOf("#"):rdx;
                rdy=i;
            }
        }
        int[] answer = {luy, lux, rdy+1, rdx+1};
        return answer;
        
        
        
        
        
        
//         ArrayList<String> s_lst = new ArrayList<>();
//         ArrayList<Integer> x_lst = new ArrayList<Integer>();
//         ArrayList<Integer> y_lst = new ArrayList<Integer>();
        
//         for(String s : wallpaper) {
//             int y = 1; // y축 원소
//             // for문으로 배열 
    
            
//             s_lst.add(s);
//             y_lst.add(y);
            
//             // x축 원소
//             for(int x=0; x<s.length(); x++) {
//                 if(s[x].equals("#")) {
//                     x_lst.add(x);
//                 }
//             }
            
//         }
        
//         Arrays.sort(x_lst);
    }
}