using System;

namespace SPOJPTIT
{
    class Program
    {
        static void Main(String[] args)
        {
            String s = Console.ReadLine();
            long a = long.Parse(s.Substring(0, s.IndexOf(" ")));
            long b = long.Parse(s.Substring(s.IndexOf(" ") + 1, s.Length - s.IndexOf(" ") - 1));

            Console.WriteLine((a + b).ToString());
          //  Console.ReadKey();
        }
    }
}