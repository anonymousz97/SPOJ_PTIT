using System;


namespace P165PROA {
    class Program {
        static void Main(string[] args) {
            string s = Console.ReadLine();
            int l = s.Length;
            char[] ch = new char[l + 1];
            int t = 0;
            for (int i = 0; i < l; i++) {
                while (t > 0 && ch[t] < s[i]) {
                    t--;
                }
                ch[++t] = s[i];
            }
            for (int i = 1; i <= t; i++) {
                Console.Write(ch[i]);
            }
        }
    }
}
