import java.util.Scanner;
 
/**
 *
 * @author thaic_000
 */
public class Main {
 
    
    public static int gcd(int a, int b){
       if (b == 0) return a;
       return gcd(b, a % b); 
    }
    
    public static void main(String[] args) {
        int n, m, a, b, x;
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        a = sc.nextInt();
        for (int i = 1; i <= m; i++) x = sc.nextInt();
        b = sc.nextInt();
        for (int i = 1; i <= n; i++) x = sc.nextInt();
        
        if (m < n) System.out.println("0/1");
        else
            if (m > n){
                if (a * b > 0) System.out.println("Infinity");
                else System.out.println("-Infinity");
            }
            else
            {
                int dau = a * b;
                a = Math.abs(a);
                b = Math.abs(b);
                int k = gcd(a, b);
                if (dau < 0) System.out.print("-");
                System.out.println(a / k + "/" + b / k);
            }
    }
}