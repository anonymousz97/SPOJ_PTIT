using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P166SUMH {
    class Program {
        const int MAX = 60;
        static int r, c, res;
        static string[] s = new string[MAX];

        static bool inside(int u, int v) {
            return (u > 0 && u <= r && v > 0 && v <= c);
        }

        static int tinh(int x, int y) {
            int ans = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int u = x + dx;
                    int v = y + dy;
                    if (!inside(u, v) || (u == x && v == y)) continue;
                    if (s[u][v] == 'o') ans++;
                }
            }
            return ans;
        }

        static void process() {
            res = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (s[i][j] == 'o') {
                        res += tinh(i, j);
                    }
                }
            }
            res /= 2;

            int m = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (s[i][j] == '.') {
                        m = Math.Max(m, tinh(i, j));
                    }
                }
            }

            res += m;
        }
        static void Main(string[] args) {
            string[] b = Console.ReadLine().Trim().Split(' ');
            r = int.Parse(b[0]);
            c = int.Parse(b[1]);
            for (int i = 1; i <= r; i++) {
                s[i] = Console.ReadLine();
                s[i] = "." + s[i];
            }
            process();
            Console.WriteLine(res);
            Console.ReadKey();
        }
    }
}
