using System;
using System.IO;
class My
{
    static int Main()
    {
        string strName;
        string strDoc;
        int i, ln = 1;
        char ch;
        try
        {
            Console.WriteLine("请输入要显示文件的名称：");
            strName = Console.ReadLine();
            StreamReader sr = new StreamReader(strName);
            strDoc = sr.ReadToEnd();
            StreamWriter sw = new StreamWriter("print.prn");
            sr.Close();
            Console.Write("{0:D4}", ln);
            sw.Write("{0:D4}", ln);
            ln++;
            for (i = 0; i < strDoc.Length; i++)
            {
                ch = strDoc[i];
                Console.Write(ch);
                sw.Write(ch);
                if (ch == '\n')
                {
                    Console.Write("{0:D4}", ln);
                    sw.Write("{0:D4}", ln);
                    ln++;
                }
            }
            sw.Close();
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
        }

        return 0;
    }
}
