using System;

namespace H6Q2
{
    class Program
    {
        static void Main(string[] args)
        {
            double[, ] array = new double[2, 2];
            Console.WriteLine("Please enter two Coordinates(upleft_x, upleft_y, downright_x, downright_y): ");
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    array[i, j] = Convert.ToDouble(Console.ReadLine());
            Ellipse ellipse = new Ellipse(array);
            Console.WriteLine("The area of this ellipse is " + ellipse.Area());
        }
    }
    class Ellipse
    {
        Coordinates left = new Coordinates(0, 0);
        Coordinates right = new Coordinates(0, 0);
        public double Area()
        {
            return Math.PI * (right.X - left.X) * (left.Y - right.Y) / 4;
        }
        public Ellipse(double[, ] array)
        {
            left.X = array[0, 0];
            left.Y = array[0, 1];
            right.X = array[1, 0];
            right.Y = array[1, 1];
        }
    }
    class Coordinates
    {
        public double X;
        public double Y;
        public Coordinates(double x, double y)
        {
            X = x;
            Y = y;
        }
    }
}
