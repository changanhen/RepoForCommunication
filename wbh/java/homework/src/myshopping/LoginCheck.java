package myshopping;
import java.util.Scanner;

public class LoginCheck {
	public static void main(String[] args) {
		Scanner nameinput = new Scanner(System.in);
		Scanner passinput = new Scanner(System.in);
		
		int loop,times=3;
		String username,code;
		
	    String[] name = {"jim","lily","bob"};
	    String[] password = { "12345" , "22222" , "44444" } ;
	    User user = new User(name,password);
	    

	    
	    while(times>=0) {
	    	System.out.print("请输入用户名：");
		    username = nameinput.nextLine();
		    System.out.print("请输入密码：");
	        code = passinput.nextLine();	        
	        for(loop=0;loop<3;loop++) {
	    	    if(user.getName()[loop].equals(username)) {
	    		    if(user.getPassword()[loop].equals(code)) {
	    		     	System.out.println("欢迎登录系统！");
	    		     	times=-1;
	    		     	break;
	    	    	}
	    		    else {
	    		    	System.out.println("输入错误！您还有" + (times-1) +"次机会！");
	    		    	times--;
	    		    	break;
	    	    	}	    			
	    	    }

	        }
	    	if(loop == 3) {
	    	    System.out.println("用户名不存在！");
	    	}	        
	        
	        
	        if(times==0) {
	        	System.out.println("对不起！您三次均属入错误！");
	        	times--;
	        }	        	
	    }	    	    
	}
}

class User{
	private String[] Name;
	private String[] Password;
	
	public User(String[] name , String[] password) {
		this.Password = password;
		this.Name = name;		
	}
	
	public String[] getName() {
		return Name;
	}

	
	public String[] getPassword() {
		return Password;
	}
		
	
}