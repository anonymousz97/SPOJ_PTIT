using System;

namespace P165SUMH {
    class Program {
        static int n;
        static string s;

        static bool check(string a, string b) {
            int la = a.Length;
            int lb = b.Length;

            if (lb < la - 1) return false;

            int pos1 = 0;
            for (int i = 0; i < la; i++) {
                if (a[i] != b[i]) {
                    pos1 = i;
                    break;
                }
            }
            if (a[pos1] != '*') return false;

            int pos2 = 0;
            for (int i = 1; i < la; i++) {
                if (a[la - i] != b[lb - i]) {
                    pos2 = la - i;
                    break;
                }
            }
            if (a[pos2] != '*') return false;
            return true;
        }

        static void Main(string[] args) {
            n = int.Parse(Console.ReadLine());
            s = Console.ReadLine();
            for (int i = 0; i < n; i++) {
                string p = Console.ReadLine();
                if (check(s, p)) {
                    Console.WriteLine("DA");
                } else Console.WriteLine("NE");
            }
        //   Console.ReadKey();
        }
    }
}
