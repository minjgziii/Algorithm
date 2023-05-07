import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner sca = new Scanner(System.in);

        int max = 0;
        int num = 0;
        int row = 1;
        int col = 1;

        for (int i = 1; i <= 81; i++) {
            num = sca.nextInt();

            if (num > max) {
                max = num;
                row = i % 9 == 0 ? i / 9 : i / 9 + 1;
                col = i % 9 == 0 ? 9 : i % 9;
            }
        }

        System.out.println(max);
        System.out.println(row + " " + col);
    }
}