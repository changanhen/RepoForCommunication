using System;
class AnyType<T>
{
    public static double Abs(T x)
    {
        string t = x.ToString();
        double y = Convert.ToDouble(t);
        y = y < 0 ? -y : y;
        return y;
    }
}
class My
{
    static int Main()
    {
        int x = -3;
        double y;
        y = AnyType<int>.Abs(x);
        Console.WriteLine("{0}的绝对值是{1}", x, y);
        return 0;
    }
}
