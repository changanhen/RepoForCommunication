using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp16
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "闲得无聊来解压";
            Program pro = new Program();
            Array array = new Array();
            Run run = new Run();
            string[,] a = new string[5, 5];
            array.Fullarray(a);
            array.Showarray(a);
            run.Runarray(a);
            Console.SetCursorPosition(0, 6);
            Console.WriteLine("谢谢使用！");
        }
    }

    public class Array
    {
        public void Fullarray(string[,] a)
        {
            for (int i=0;i<a.GetLength(0);i++)
            {
                for (int j=0;j<a.GetLength(1);j++)
                {
                    a[i, j] = "【空位】";
                }
            }
        }
        public void Showarray(string[,] a)
        {
            for (int i=0;i<a.GetLength(0);i++)
            {
                for (int j = 0; j < a.GetLength(1); j++)
                {
                    if (a[i,j]=="【空位】")
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write("{0} ",a[i,j]);
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write("{0} ",a[i, j]);

                    }
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = ConsoleColor.Gray;
            Console.WriteLine("请按wasd方向键移动，j选取，q退出");
        }
        /*public void AddArray(string[,] a ,int x, int y)
        {
            a[y, x]++;
            Console.Clear();
            Showarray(a);
        }*/
        public void ChaArray(string[,] a, int x, int y)
        {
            a[y, x]="【无座】";
            Console.Clear();
            Showarray(a);
        }
    }

    public class Run
    {
        private int x;
        private int y;
        public void Runarray(string[,] a)
        {
            Array array = new Array();
            Adjust adjust = new Adjust();
            x = 0; y = 0;
            int count = 0;
            Console.SetCursorPosition(0, 0);
            while (!adjust.Isquit(count))
            {
                ConsoleKeyInfo key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case ConsoleKey.A:
                        x = x > 0 ? x - 10 : x;
                        break;
                    case ConsoleKey.D:
                        x = x < (a.GetLength(1) - 1) * 5 ? x + 10 : x;
                        break;
                    case ConsoleKey.W:
                        y = y > 0 ? y - 1 : y;
                        break;
                    case ConsoleKey.S:
                        y = y < a.GetLength(0) - 1 ? y + 1 : y;
                        break;
                    case ConsoleKey.J:
                        array.ChaArray(a, x, y);
                        break;
                    case ConsoleKey.Q:
                        count = 1;
                        break;
                    default:
                        break;
                }
                Console.SetCursorPosition(x, y);
            }
        }
    }
    public class Adjust
    {
        public bool Isquit(int count)
        {
            return count == 1 ? true : false;
        }
    }

}