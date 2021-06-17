using System;

namespace H4Q3
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please enter a string");
            string s = Console.ReadLine();
            s = s.ToUpper();
            char[] str = s.ToCharArray();
            for (int i = 0; i < str.Length; i++)
            {
                str[i] = (char)((str[i] - 'A' + 3) % 26 + 'A');
            }
            string outstr = new string(str);
            Console.WriteLine("The Encrypted string: " + outstr);
        }
    }
}
