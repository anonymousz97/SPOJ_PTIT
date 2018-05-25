/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author thaic_000
 */
import java.util.Scanner;

public class Main {

    static int res = 0;
    static int MAX = 2000;

    static void process(String a, String b) {
        int f[][] = new int[MAX][MAX];
        int m = a.length();
        int n = b.length();
        a = "*".concat(a);
        b = "*".concat(b);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a.charAt(i) == b.charAt(j)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        res = f[m][n];
    }
    
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String b = sc.nextLine();
        process(a, b);
        System.out.println(res);
    }
}
