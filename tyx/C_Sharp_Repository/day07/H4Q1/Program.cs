using System;

namespace H4Q1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("*****这是转置四阶方阵的程序*****");
            int[,] array = new int[4, 4]
            {
                {4, 6, 8, 9},
                {2, 7, 4, 5},
                {3, 8, 16, 15},
                {1, 5, 7, 11}
            };
            Invert(array, 4);
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine("{0}\t{1}\t{2}\t{3}\n", array[i, 0], array[i, 1], array[i, 2], array[i, 3]);
            }
        }
        static void Invert(int[,] array, int order)
        {
            for (int i = 0; i < order; i++)
            {
                for (int j = i; j < order; j++)
                {
                    int tmp = array[i, j];
                    array[i, j] = array[j, i];
                    array[j, i] = tmp;
                }
            }
        }
    }
}
