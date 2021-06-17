package myshopping;
import java.util.Scanner;

public class MainMean {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int noin,jud;

		System.out.println("欢迎使用Myshopping管理系统");
		System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
		System.out.println(" ");
		System.out.println("1:客户信息管理");
		System.out.println("2：购物结算");
		System.out.println("3：真情回馈");
		System.out.println("4：注销");
		System.out.println(" ");
		System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
		
		System.out.print("请选择，输入数字：");
		
		while(true) {
			noin = input.nextInt();
			jud = 0;
		    switch(noin) {
		    case 1:
		    	System.out.println("客户信息管理");
		    	break;
		    case 2:
		     	System.out.println("执行购物结算");
		    	break;
		    case 3:
			    System.out.println("真情回馈");
		    	break;
		    case 4:	
		    	System.out.println("注销");
			    break;
			default:
				jud = 1;
				System.out.print("输入错误，请重新输入数字：");
				break;
		    }
		    
		    if(jud == 0)
		    	break;		    	
		
		}
		
		System.out.println("程序结束");
	}

}
