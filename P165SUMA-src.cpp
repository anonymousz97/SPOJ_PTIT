using System;


namespace P165SUMA {
    class Program {
        static long n, k;
        static string s;
        static void process() {           
            long l = s.Length;          
            if (k == 0) {
                Console.WriteLine(s);
                return;
            }
            s = "_" + s;
            char[] a = s.ToCharArray();
            for (int i = 1; i < l; i++) {
                if (a[i] == '4' && a[i + 1] == '7') {
                    if (i < l - 1 && a[i + 2] == '7' && i % 2 == 1) {
                        k %= 2;
                        if (k == 1) {
                            a[i + 1] = '4';
                        }
                        break;
                    } else if (i > 1 && a[i - 1] == '4' && i % 2 == 0) {
                        k %= 2;
                        if (k == 1) {
                            a[i] = '7';
                        }
                        break;
                    } else {
                        if (i % 2 == 1) {
                            a[i + 1] = '4';
                        } else {
                            a[i] = '7';
                        }
                        if (--k == 0) {
                            break;
                        }
                    }
                }
            }

            for (int i = 1; i <= l; i++) {
                Console.Write(a[i]);
            }
            Console.WriteLine();
        }
        static void Main(string[] args) {
            string[] a = Console.ReadLine().Trim().Split(' ');
            n = int.Parse(a[0]);
            k = int.Parse(a[1]);
            s = Console.ReadLine();
            process();
      //      Console.ReadKey();
        }
    }
}
