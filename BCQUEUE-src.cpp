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

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c, x = 0;
        Queue q = new Queue();
        for (int i = 1; i <= n; i++){
            c = sc.nextInt();
            if (c == 3) x = sc.nextInt();
            
            switch (c) {
                case 1: {
                    System.out.println(q.size());
                    break;
                }
                case 2: {
                    if (q.empty()) System.out.println("YES");
                    else System.out.println("NO");
                    break;
                }
                
                case 3: {
                    q.push(x);
                    break;
                }
                case 4: {
                    if (!q.empty()) q.pop();
                    break;
                }
                case 5: {
                    if (q.empty()) System.out.println("-1");
                    else System.out.println(q.front());
                    break;
                }
                case 6: {
                    if (q.empty()) System.out.println("-1");
                    else System.out.println(q.back());
                    break;
                }
            }
        }
    }
    
}

class Queue{
    public int l, r;
    public int q[] = new int [20000];
    
    Queue(){
       l  = 1;
       r = 0;
    }
    
    public void push(int v){
        q[++r] = v;
    }
    
    public int pop(){
        int v = q[l++];
        return v;
    }
    
    public boolean empty(){
        return (l > r);
    }
    
    public int front(){
        return q[l];
    }
    
    public int back(){
        return q[r];
    }
    
    public int size(){
        return (r - l + 1);
    }
}