//ASCII字符值为33_126的字符输出到文件code.txt.十_八_十六进制及码值代表的字符
using System;
using System.IO;
namespace My
{
    class Program
    {
        static void Main(string[] args)
        {
            string strName = "code.txt";
            try
            {

                StreamWriter wr = new StreamWriter(strName);
                int i = 33;
                int a;
                string c, d, e;
                char b;
                for (; i <= 126; i++)
                {
                    a = i;
                    b = (char)i;
                    c = Convert.ToString(a, 2);
                    d = Convert.ToString(a, 8);
                    e = Convert.ToString(a, 16);
                    wr.WriteLine("{0,4}{1,4}{2,4}{3,4}", i, d, e, b);
                }
                wr.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
