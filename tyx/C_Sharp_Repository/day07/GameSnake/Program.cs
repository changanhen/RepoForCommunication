using System.Collections.Generic;

namespace 贪吃蛇form
{
    public class Snake
    {
        public int Location_x;//0为x，1为y
        public int Location_y;
        public static int width = 10, height = 10;
        public static List<Snake> realsnake = new List<Snake>();

        //当前方向
        public static int wasd;




        public Snake()
        {
            Location_x = 250;
            Location_y = 250;

        }
        public static void Snakestart()
        {
            wasd = 4;

            realsnake.Clear();
            Snake s0 = new Snake();
            Snake s1 = new Snake();
            Snake s2 = new Snake();
            Snake s3 = new Snake();
            realsnake.Add(s0);

            s1.Location_x = s0.Location_x - 10;
            realsnake.Add(s1);
            s2.Location_x = s1.Location_x - 10;
            realsnake.Add(s2);
            s3.Location_x = s2.Location_x - 10;
            realsnake.Add(s3);
            //添加四个长度，横向添加list 初始化小蛇蛇完成
        }

        public static void SnakeMove(int x)//8426
        {
            int i = realsnake.Count - 1;

            if (x == 8)
            {
                //对list蛇身进行处理
                Snakelist();
                realsnake[i].Location_y -= 10;
            }
            else if (x == 4)
            {
                Snakelist();
                realsnake[i].Location_x -= 10;
            }
            else if (x == 2)
            {
                Snakelist();
                realsnake[i].Location_y += 10;
            }
            else if (x == 6)
            {
                Snakelist();
                realsnake[i].Location_x += 10;

            }
        }

        public static void Snakelist()
        {
            int j = 0;
            int x, y;
            int i = realsnake.Count - 1;
            for (j = 0; j < i; j++)
            {
                x = realsnake[j + 1].Location_x;
                y = realsnake[j + 1].Location_y;
                realsnake[j].Location_y = y;
                realsnake[j].Location_x = x;
            }
        }
        public static void EatLong()
        {
            Snake S_eat = new Snake();
            int xx = realsnake[realsnake.Count - 1].Location_x;
            int yy = realsnake[realsnake.Count - 1].Location_y;
            if (wasd == 8)
            {
                S_eat.Location_y = yy - 10;
                S_eat.Location_x = xx;
                realsnake.Add(S_eat);
            }
            else if (wasd == 4)
            {
                S_eat.Location_x = xx - 10;
                S_eat.Location_y = yy;
                realsnake.Add(S_eat);
            }
            else if (wasd == 2)
            {
                S_eat.Location_y = yy + 10;
                S_eat.Location_x = xx;
                realsnake.Add(S_eat);
            }
            else if (wasd == 6)
            {
                S_eat.Location_y = yy;
                S_eat.Location_x = xx + 10;
                realsnake.Add(S_eat);
            }
        }
    }
}