
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
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, p, q;
        a = sc.nextInt();
        b = sc.nextInt();
        p = Math.min(a, b);
        q = Math.max(a, b);
        System.out.println(p + " " + (q - p) / 2);
    }
}
