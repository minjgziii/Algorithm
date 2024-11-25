import java.util.*;

class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int n = board.length;
        
        int[] i_y = {0, 0, 1, -1};
        int[] i_x = {1, -1, 0, 0};
        
        for(int a=0; a<4; a++) {
            int y_idx = h+i_y[a];
            int x_idx = w+i_x[a];
            
            if(y_idx>=0 && y_idx<n && x_idx>=0 && x_idx < n) {
                if(board[y_idx][x_idx].equals(board[h][w])) {
                    answer++;
                }
            }
        }
        
        return answer;
    }
}