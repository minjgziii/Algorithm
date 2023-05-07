import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);

        int N = sca.nextInt();
        int M = sca.nextInt();

        int[][] A = new int[N][M];

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                A[i][j] = sca.nextInt();
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                A[i][j] += sca.nextInt();
                System.out.print(A[i][j] + " ");
            }
            System.out.println("");
        }
    }
}
