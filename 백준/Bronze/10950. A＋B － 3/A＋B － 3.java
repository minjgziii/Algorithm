import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        
        int T = sca.nextInt();
        int[] arr = new int[T];

        for( int i = 0; i < T; i++ ){
            int a = sca.nextInt();
            int b = sca.nextInt();

            arr[i] = a + b;
        }
        
        for( int t : arr ){
            System.out.println(t);
        }

        sca.close();
    }
}
