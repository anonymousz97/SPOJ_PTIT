
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sev_user
 */
public class Main {
    static int n;
    static int MAX = 4000;
    static int []d = new int [MAX];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int x;
        for (int i = 0; i < MAX; i++) d[i] = 0;
        for (int i = 1; i <= n; i++){
            x = sc.nextInt();
            d[x] = 1;
        }
        for (int i = 1; i < MAX; i++){
            if (d[i] == 0){
                System.out.println(i);
                break;
            }
        }
    }
}
