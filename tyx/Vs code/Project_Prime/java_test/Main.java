public class Main{
    public static void main(String[] args) {
        int [] pri = new int [200000];
        pri [0] = 1;
        pri [1] = 1;
        pri [2] = 0;
        int i = 0, p = 0, k = 0;
        for ( p = 0; p < 10002; p++)
        {
            if ( pri[p] ==0)
            {
                System.out.println ( p );
                for ( i= pri[p] ; i<10002 ; i++)
                {
                    if ( pri[i] == 1)
                        continue;
                    else
                    {
                        if ( i % p == 0 )
                            pri [i] =1;
                    }
                }
            } 
        }
    }
}