import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            String text = br.readLine();
            int index = Integer.parseInt(br.readLine());

            bw.write(text.substring(index-1, index));
            bw.close();
        }
        catch(Exception ex) {
            System.out.println("에러");
            ex.printStackTrace();
        }
    }
}
