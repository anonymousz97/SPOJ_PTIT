/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;

/**
 *
 * @author Cuong Nguyen
 */
public class Main {
    public static int MAX = 15;
    public static int []x = new int [MAX];
    public static int n, k;
    
    public static void show() {
        for (int i = 1; i <= k; i++) {
            System.out.print(x[i] + " ");
        }
        System.out.println();
    }
    
    public static void Try(int i) {
        for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
            x[i] = j;
            if (i == k) {
                show();
            } else Try(i + 1);
        }
    }
    
    public static void process() {
        x[0] = 0;
        Try(1);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        k = in.nextInt();
        process();
    }
}
