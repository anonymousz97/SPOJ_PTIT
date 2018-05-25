import java.util.Scanner;
 
/**
 *
 * @author thai_c00
 */
public class Main {
 
    /**
     * @param args the command line arguments
     */
    static int MAX = 1050;
    static int INF = 1000000007;
    static int a[][] = new int [MAX][MAX];
    static int n, m, h;
    static int d[] = new int [MAX];
    static int id[] = new int [MAX];
 
    static void input(){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        h = sc.nextInt();
 
        int x, y;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) a[i][j] = 0;
        }
        for (int i = 1; i <= m; i++) id[i] = sc.nextInt();
 
        for (int i = 1; i <= h; i++){
            x = sc.nextInt();
            y = sc.nextInt();
            a[x][y] = 1;
            a[y][x] = 1;
        }
    }
 
    static void process(){
        for (int i = 0; i < n; i++) d[i] = INF;
        for (int i = 1; i <= m; i++){
            BFS(id[i]);
        }
        int ires = 0;
        for (int i = 1; i < n; i++){
            if (d[i] > d[ires]) ires = i;
        }
        System.out.println(ires);
    }
 
    static void BFS(int s){
        Queue q = new Queue();
        q.push(s);
        d[s] = 0;
 
        int u;
        while (!q.empty()){
            u = q.pop();
 
            for (int v = 0; v < n; v++){
                if (a[u][v] == 1 && d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }
 
    public static void main(String[] args) {
        // TODO code application logic here
        input();
        process();
    }
 
}
 
class Queue{
    public int l, r;
    public int q[] = new int [20000];
 
    Queue(){
        l = r = 0;
    }
 
    public void push(int v){
        q[++r] = v;
    }
 
    public int pop(){
        int v = q[l++];
        return v;
    }
 
    boolean empty(){
        return (l > r);
    }
}