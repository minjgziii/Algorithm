import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        int a = sca.nextInt();
        int b = sca.nextInt();
        sca.close();

        if(a > b)
            System.out.println(">");
        else if(a < b)
            System.out.println("<");
        else
            System.out.println("==");
    }
}
