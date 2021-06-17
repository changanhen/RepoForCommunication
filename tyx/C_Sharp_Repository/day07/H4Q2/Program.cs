using System;

namespace H4Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            Trans trans = new Trans();
            Console.WriteLine("Please enter a decimal number: ");
            int deci = Convert.ToInt32(Console.ReadLine());
            string bin = trans.ToStr(deci, 2);
            string oct = trans.ToStr(deci, 8);
            string hex = trans.ToStr(deci, 16);
            Console.WriteLine("Binary form: {0}\nOctonary form: {1}\nHexadecimal form: {2}", bin, oct, hex);
        }
    }
    class Trans
    {
        public string ToStr(int deci, int knary)
        {
            return Convert.ToString(deci, knary);
        }
    }
}
