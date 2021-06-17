package myshopping;
import java.util.Scanner;

public class LoginMenu {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
				
		System.out.println("欢迎来到我行我素购物管理系统1.0版");
		System.out.println("1.登录系统");
		System.out.println("2.退出");
		System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
		System.out.print("请选择，输入数字：");
		
		int i = input.nextInt();
		System.out.println(" ");
		
		switch(i) {
		case 1:
			System.out.println("欢迎使用我行我素购物管理系统");
			System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
			System.out.println(" ");
			System.out.println("1:客户信息管理");
			System.out.println("2：购物结算");
			System.out.println("3：真情回馈");
			System.out.println("4：注销");
			System.out.println(" ");
			System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
			break;
				
		case 2:
			System.out.println("* * * * * * * * * * * * * * * * * * * * * * * * * *");
			System.out.println("谢谢您的使用！");
			break;
			
		default:
			System.out.println("输入错误");	
			break;
		}
	}

}
