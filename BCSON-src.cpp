
import java.lang.*;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author thaic_000
 */
public class Main {
    static int n, k;
    static int MAX = 100006;
    static int a[] = new int [MAX];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        Arrays.sort(a, 0, n);
        
        int res = 0;
        int p;
        for (int i = 1; i <= n; i++){
            if (a[i] != a[i - 1]){
                p = i;
                if (p >= k){
                    res = a[i];
                    break;
                }
            }
        }
        System.out.println(res);
    }
}
