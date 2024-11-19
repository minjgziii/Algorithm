import java.util.*;


// [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]] board
// [1,5,3,5,1,2,1,4] moves


class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> basket = new Stack<>();

        for(int i=0; i<moves.length; i++) {
            int n = moves[i]; // 현재 움질일 위치 1

            // 2차원 배열 돌면서
            for(int j=0; j<board[0].length; j++) {
                boolean flag = false;

                // 0이 아니면 (인형이 있는 경우) 4
                if(board[j][n-1] != 0) {
                    // 바구니가 비어있는 경우
                    if(basket.empty()) {
                        basket.push(board[j][n-1]);
                        board[j][n-1] = 0;
                        flag = true;
                        break;
                    }
                    // 같은 인형이 있는 경우
                    else if (basket.peek() == board[j][n-1]) {
                        basket.pop();
                        board[j][n-1] = 0;
                        answer+=2;
                        flag = true;
                        break;
                    }
                    // 바구니에 넣기
                    else {
                        basket.push(board[j][n-1]);
                        board[j][n-1] = 0;
                        flag = true;
                        break;
                    }
                }
                // 0이면 아무 일도 일어나지 않음

                if(flag == true) {
                    break;
                }
            }
        }
    return answer;
}
}