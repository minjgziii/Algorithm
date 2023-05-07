import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);

        int N = sca.nextInt();
        int[] array = new int[N];
        int cnt = 0;

        for(int i = 0; i < N; i++) {
            array[i] = sca.nextInt();
        }

        int a = sca.nextInt();

        for(int i = 0; i < array.length; i++) {
            if (a == array[i]){
                cnt++;
            }
        }

        System.out.println(cnt);

        sca.close();
    }
}
