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
    public static int MAX = 10000;
    public static boolean [] isPrime = new boolean [MAX];
    public static int [] primeList = new int [5000];
    public static int [] d = new int [5000];
    public static int psize = 0;
    public static int res;
    
    public static void SNT() {
        for (int i = 1; i < MAX; i++){
            isPrime[i] = true;
        }
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                primeList[++psize] = i;
                for (int j = i * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    
    public static boolean dieuKien(int a, int b) {
        if (a < 1000 || b < 1000)return false;
        
        int d = 0;
        int x, y;
        while (a != 0) {
            x = a % 10;
            a /= 10;
            y = b % 10;
            b /= 10;
            if (x != y) {
                d++;
            }
        }
        
        return (d == 1);
    }
    
    public static int BFS(String  a, String b) {
        int []q = new int [5000];
        
        int u = 0;
        int v = 0;
        
        for (int i = 1; i <= psize; i++) {
            if (Integer.parseInt(a) ==  primeList[i]){
                u = i;
            }
            if (Integer.parseInt(b) ==  primeList[i]){
                v = i;
            }
        }
        for (int i = 1; i <= psize; i++) {
            d[i] = MAX * 100;
        }
        d[u] = 0;
        int l = 1, r = 1;
        q[1] = u;
        
        while (l <= r) {
            int s = q[l++];
            for (int t = 1; t <= psize; t++) {
                if (dieuKien(primeList[s], primeList[t])
                        && d[t] > d[s] + 1) {
                    q[++r] = t;
                    d[t] = d[s] + 1;
                }
            }
        }
        return d[v];
    }
    
    static void process(String a, String b) {
        System.out.println(BFS(a, b));
    }
    
    public static void main(String[] args) {
        SNT();
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        for (int i = 0; i < n; i++) {
            String a = in.next();
            String b = in.next();
            process(a, b);
        }
    }
}
