import java.util.*;

class Solution {
    static int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    public int[] solution(int m, int n, int[][] picture) {
        Queue<Integer> queue = new LinkedList<>();
        int numberOfArea = 0; // 영역의 개수
        int maxSizeOfOneArea = 0; // 영역의 최대값
        
        int[][] visited = new int[101][101];
        
        // visited 배열 초기화
        for (int i = 0; i < picture.length; i++) {
            Arrays.fill(visited[i], 0);
        }

        int[] answer = new int[2];
        
        List<Integer> list = new ArrayList<Integer>();
        
        for(int i=0; i<picture.length; i++) {
            for(int j=0; j<picture[0].length; j++) {
                int now = picture[i][j];
                
                if(now != 0 && visited[i][j] == 0) {
                    list.add(bfs(now, i, j, picture, visited));
                }
            }
        }
        
        Collections.sort(list);
        
        
        numberOfArea = list.size();
        maxSizeOfOneArea = list.get(list.size()-1);
        
        answer[0] = numberOfArea; 
        answer[1] = maxSizeOfOneArea;
        
        return answer;
    }
    
    public int bfs(int now, int i_x, int i_y, int[][] picture, int[][] visited) {
        int answer = 1;
        int[] start = {i_x, i_y};
        
        Queue<int[]> q = new LinkedList<>();
        q.offer(start);
        visited[i_x][i_y] = 1;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            
            for(int[] now_d : dir) {
                int now_x = x + now_d[0];
                int now_y = y + now_d[1];
                
                // index가 범위를 넘어가는 경우
                if(now_x < 0 || now_y < 0 || now_x > picture.length-1 || now_y > picture[0].length-1) {
                    continue;
                }
                // 현재 위치에서 값이 now값과 다른 경우
                if(picture[now_x][now_y] != now) {
                    continue;
                }
                // 이미 방문한 곳이면
                if(visited[now_x][now_y] == 1) {
                    continue;
                }
                
                answer++;
                visited[now_x][now_y] = 1;
                q.offer(new int[]{now_x, now_y});
                
            }
        }
        
        return answer;
    }
}