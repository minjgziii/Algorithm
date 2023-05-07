import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int cnt = 0;

        List<Integer> list = new ArrayList<>();

        for (int i = 1; i <= N; i++)
            list.add(i);

        st = new StringTokenizer(br.readLine());

        while (M-- > 0) {
            int num = Integer.parseInt(st.nextToken());
            int idx = list.indexOf(num);

            if (idx == 0) {
                list.remove(0);
                continue;
            }

            if (idx < list.size() - idx) {
                for (int i = 0; i < idx; i++ ){
                    list.add(list.remove(0));
                }
                cnt += idx;
            }
            else {
                for (int i = 0; i < list.size() - idx; i++){
                    int tmp = list.remove(list.size() -1);
                    list.add(0, tmp);
                }
                cnt += list.size() - idx;
            }
            list.remove(0);
        }

        System.out.println(cnt);
    }
}