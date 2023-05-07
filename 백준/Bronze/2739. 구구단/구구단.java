import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);

        int N = sca.nextInt();

        IntStream.rangeClosed(1, 9).forEach(i -> {
            System.out.println(N + " * " + i + " = " + N * i);
        });

        sca.close();
    }
}
