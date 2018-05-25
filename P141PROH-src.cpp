/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Scanner;

/**
 *
 * @author thaic_000
 */
class Number {

    public int num;

    public int getNumber() {
        return num;
    }

    public void setNumber(int num) {
        this.num = num;
    }
}

class MySwap {

    public void swap(Number a, Number b) {
        int t = a.getNumber();
        a.setNumber(b.getNumber());
        b.setNumber(t);
    }
}

class Processing {

    MySwap ms = new MySwap();
    Scanner sc = new Scanner(System.in);
    Number[] arrInt = new Number[2000];
    int n;

    public void input() {
        n = sc.nextInt();
    //    System.out.println("n = " + n + "\n");
        for (int i = 1; i <= n; i++) {
            arrInt[i] = new Number(); 
            arrInt[i].setNumber(sc.nextInt());
        }
    }

    public void sort(int n, Number arrInt[]) {
        for (int i = n - 1; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (arrInt[j].getNumber() > arrInt[j + 1].getNumber()) {
                    ms.swap(arrInt[j], arrInt[j + 1]);
                }
            }
        }
    }

    public void process() {
        sort(n, arrInt);
        for (int i = 1; i <= n; i++) {
            System.out.println(arrInt[i].getNumber());
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Processing res = new Processing();
        res.input();
        res.process();
    }
}
