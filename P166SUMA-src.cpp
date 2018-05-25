/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package p166suma;

import java.util.Scanner;

/**
 *
 * @author Cuong Nguyen
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    static int MAX = 5005;
    static int []d = new int [MAX];
    static int res = 0;
    static int n;
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i = 1; i <= n; i++) d[i] = 0;
        for (int i = 1; i <= n; i++){
            int x = in.nextInt();
            if (x <= n) d[x] = 1;
        }
        for (int i = 1; i <= n; i++){
            res += d[i];
        }
        res = n - res;
        System.out.println(res);
    }
    
}
