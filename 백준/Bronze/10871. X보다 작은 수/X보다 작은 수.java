import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);

        int N = sca.nextInt();
        int X = sca.nextInt();

        int[] arr = new int[N];

        for(int i = 0; i < N; i++){
            arr[i] = sca.nextInt();
            if(X > arr[i]){
                System.out.print(arr[i] + " ");
            }
        }

        sca.close();
    }
}
