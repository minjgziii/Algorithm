import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String s = br.readLine();
            System.out.print(s.length());
        }
        catch(Exception ex) {
            System.out.println("에러");
            ex.printStackTrace();
        }
    }
}
