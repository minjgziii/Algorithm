import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            HashMap<Integer, Integer> map = new HashMap<>();

            int N = Integer.parseInt(br.readLine());
            int tmp = 0;

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                tmp = Integer.parseInt(st.nextToken());
                if (!map.isEmpty() && map.containsKey(tmp)) {
                    map.replace(tmp, map.get(tmp) + 1);
                } else {
                    map.put(tmp, 1);
                }
            }
            int num = Integer.parseInt(br.readLine());

            st = new StringTokenizer(br.readLine());
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < num; i++) {
                tmp = Integer.parseInt(st.nextToken());
                if (map.containsKey(tmp)) {
                    sb.append(map.get(tmp)).append(" ");
                } else {
                    sb.append("0 ");
                }
            }
            System.out.println(sb.toString());
        }

        catch(Exception ex) {
            System.out.println("에러");
            ex.printStackTrace();
        }
    }
}