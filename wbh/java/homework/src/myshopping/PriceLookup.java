package myshopping;
import java.util.Scanner;

public class PriceLookup {
	public static void main(String[] args) {
		int noin;
		String jud;
		Scanner ninput = new Scanner(System.in);
		Scanner jinput = new Scanner(System.in);
		Goods A = new Goods("T恤",245.0,1);
		Goods B = new Goods("网球鞋",570,2);
		Goods C = new Goods("网球怕",320,3);
		
		System.out.println("MyShopping管理系统 > 购物结算");
		System.out.println(" ");
		System.out.println("*****************************************");
		System.out.println("请选择购买的商品编号：");				
		System.out.println("1.T恤	2.网球鞋	  3.网球拍");
		System.out.println("*****************************************");
		
		while(true) {
			System.out.print("请输入商品编号:");
			noin = ninput.nextInt();
			switch(noin) {
			    case 1:
				    System.out.println(A.getName() + "  ￥" +A.getPrice() );
				    break;
			    case 2:
				    System.out.println(B.getName() + "  ￥" +B.getPrice() );
				    break;
			    case 3:
			    	System.out.println(C.getName() + "  ￥" +C.getPrice() );
			    	break;
			    default:
			    	System.out.println("error");
			    	break;
			}					
			
			System.out.print("是否继续（y/n）");
			jud = jinput.nextLine();
			if("y".equals(jud)) {
				continue;
			}
			else{
				System.out.println("程序结束！");
				break;
			}
		}
		
		
		
	}

}

class Goods{
	private String name;
	private double price;
	private int goodsNo;
	public Goods(String name, double price, int goodsNo) {
		this.goodsNo = goodsNo;
		this.price = price;
		this.name = name;
	}
	public String getName() {
		return name;
	}
	
	public double getPrice() {
		return price;
	}
	
	public int getGoodsNo() {
		return goodsNo;
	}

}