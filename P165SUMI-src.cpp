using System;

namespace P165SUMI {
    class Program {
        static long n, m, a, res;

        static long calc(long a, long b) {
            long ans = 0;
            long ssh = (b - a) / 2 + 1;
            ans = (b + a) * ssh / 2;
            return ans;
        }

        static void process() {
            if (a % 2 == 1) {
                n = a;
                m = a - 1;
            } else {
                m = a;
                n = a - 1;
            }

            long s1 = calc(1, n);
            long s2 = calc(2, m);

            long res = s2 - s1;

            Console.WriteLine(res.ToString());
        }
        static void Main(string[] args) {
            a = long.Parse(Console.ReadLine());
            process();
           // Console.ReadKey();
        }
    }
}
