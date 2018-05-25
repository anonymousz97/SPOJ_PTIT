
import java.util.Scanner;


public class Main {
    public static String A, B;
    public static Scanner sc = new Scanner(System.in);
    public static int [][] F = new int [5002][5002];
    
    public static void main(String[] args) {
        
//        int test = sc.nextInt();
//        String bf = sc.nextLine();
        int test = 1;
        for (int t = 0; t < test; t++) {
            
            A = sc.nextLine();
            
            for (int i = 0; i <= A.length(); i++) {
                for (int j = 0;  j <= A.length(); j++) {
                    F[i][j] = 0;
                }
            }
            
            StringBuilder kq = new StringBuilder(A);
            B = kq.reverse().toString();
            
            A = "*" + A;
            B = "*" + B;
        
            int res = 0;
            for (int i = 1; i < A.length(); i++) {
                for (int j = 1; j < B.length(); j++) {
                    if (A.charAt(i) == B.charAt(j)) {
                        F[i][j] = F[i - 1][j - 1] + 1;
                    } else {
                        F[i][j] = Math.max(F[i - 1][j], F[i][j - 1]);
                    }
                }
            }

            res = F[A.length() - 1][B.length() - 1];

            System.out.println(res);
        } 
    }
}
