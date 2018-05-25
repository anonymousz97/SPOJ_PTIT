/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package acmptit;

import java.util.Scanner;

/**
 *
 * @author thaic_000
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        long a, b;
        a = sc.nextLong();
        b = sc.nextLong();
        long res = 0;
        while (a > 0){
            if (a < b) {
                long t = a;
                a = b;
                b = t;
            }
            res += a / b;
            a -= a / b * b;
            
        }
        System.out.println(res);
    }
    
}
