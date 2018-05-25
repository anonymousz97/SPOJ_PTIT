
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Cuong Nguyen
 */
public class Main {
    public static int MAX = 200;
    public static int CMAX = 1000;
    public static int INF = Integer.MAX_VALUE / 2;
    
    public static int n, weight, res, sum;
    public static int f[][] = new int [MAX][CMAX];
    public static int w[] = new int [MAX];
    public static int c[] = new int [MAX];
    
    static void Init() {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= weight; j++) {
                f[i][j] = 0;
            }
        }
    }
    
    static void process() {
        Init();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= weight; j++) {
                f[i][j] = f[i - 1][j];
                if (w[i] <= j) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - w[i]] + c[i]);
                }
            }
        }
        System.out.println(f[n][weight]);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        weight = in.nextInt();
        sum = 0;
        for (int i = 1; i <= n; i++) {
            w[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        process();
    }
}
