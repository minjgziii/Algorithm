import java.util.*;

class Solution {
    public long solution(int n) {
        
        // 홀수는 0
        if(n % 2 == 1) {
            return 0;
        }
        
        long answer = 0L;
        
        long[] ans = new long[n+1];
        
        ans[2] = 3;
        ans[4] = 11;
        
        long[] sum = new long[n+1];
        sum[4] = 3;
        
        for(int i=6; i<=n; i += 2) {
            ans[i] = (3*ans[i-2] + 2*sum[i-2] + 2)%1000000007L;
            sum[i] = (sum[i-2] + ans[i-2])%1000000007L;
        }
        
        answer = ans[n];
        
        return answer;
    }
}