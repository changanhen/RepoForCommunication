using System;
using System.Globalization;

namespace CsharpItoa
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入一个字符串：");
            string former = Console.ReadLine();
            string latter = IdnMapping.GetAscii(former, 16);
        }
    }
}
