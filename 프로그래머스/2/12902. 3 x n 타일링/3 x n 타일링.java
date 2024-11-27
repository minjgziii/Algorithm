import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        int size2 = 3;
        int size3 = 4;
        int size4 = 2;
        
        Map<Integer, Map<Integer, Integer>> mp = new HashMap<>();
        
        // 숫자를 2, 3으로 조합
        // 2x + 3y = n
        int a = 0;
        
        for(int x=0; x<=n/2; x++) {
            Map<Integer, Integer> maps = new HashMap<>();
            maps.put(2,0);
            maps.put(3,0);
            
            for(int y=0; y<=n/3; y++) {
                if(2*x + 3*y == n) {
                    maps.put(2,x);
                    maps.put(3,y);
                    break;
                }
            }
            if(!(maps.get(2) == 0 && maps.get(3) ==0)) {
                mp.put(a, maps);
                a++;
            }
        }
        
        Map<Integer, Integer> ans = new HashMap<>();
        
        // 2와 3으로 만들 수 있는 경우의 수 계산
        for(int i=0; i<mp.size(); i++) {
            int twoCnt = 1;
            boolean flag_two = false;
            int threeCnt = 1;
            boolean flag_three = false;
            
            for(int j=1; j<=mp.get(i).get(2); j++) {
                twoCnt *= size2;
                flag_two = true;
            }
           
            for(int k=1; k<=mp.get(i).get(3); k++) {
                threeCnt *= size3;
                flag_three = true;
            }
            
            if(flag_two == true) {
                ans.put(2, twoCnt);
            }
            else {
                ans.put(2, 0);
            }
            if(flag_three == true) {
                ans.put(3, threeCnt);
            }
            else {
                ans.put(3, 0);
            }
        }
        
        int b = a;
        int temp = b;
        // 2 + 2 => 4
        
        for(int x=0; x<=n/2; x++) {
            Map<Integer, Integer> maps = new HashMap<>();
            maps.put(2,0);
            maps.put(4,0);
            
            for(int y=1; y<=n/4; y++) {
                if(2*x + 4*y == n) {
                    maps.put(2,x);
                    maps.put(4,y);
                    break;
                }
            }
            
            if(!(maps.get(2) == 0 && maps.get(4) == 0)) {
                mp.put(b, maps);
                b++;
            }
        }
        
        System.out.println(mp);
        
        // 2와 4로 만들 수 있는 경우의 수 계산
        for(int i=temp; i<mp.size(); i++) {
            int twoCnt = 1;
            boolean flag_two = false;
            int threeCnt = 1;
            boolean flag_three = false;
            
            if(mp.get(i).get(2) != null) {
                for(int j=1; j<=mp.get(i).get(2); j++) {
                    twoCnt *= size2;
                    flag_two = true;
                }
            }
            if(mp.get(i).get(4) != null) {
                for(int k=1; k<=mp.get(i).get(4); k++) {
                    threeCnt *= size4;
                    flag_three = true;
                }
            }
            if(flag_two == true) {
                ans.put(2, ans.get(2)+twoCnt);
            }
            else {
                ans.put(2, ans.get(2));
            }
            if(flag_three == true) {
                ans.put(4, threeCnt);
            }
            else {
                ans.put(4, 0);
            }
        }
        
        for(int i=2; i<=4; i++) {
            answer += ans.get(i);
        }
        
        System.out.println(answer); 
        
        return answer % 1000000007;
    }
}