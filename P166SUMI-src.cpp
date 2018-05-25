/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package p166sumi;

import java.util.Scanner;

/**
 *
 * @author Cuong Nguyen
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int res = 0;
        
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; i++){
            res += (in.nextInt() == 0) ? 1 : 0;
        }
        if (res == 1) System.out.println("YES");
        else System.out.println("NO");
    }
    
}
