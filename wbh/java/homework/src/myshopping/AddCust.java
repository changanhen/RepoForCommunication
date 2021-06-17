package myshopping;
import java.util.Scanner;

public class AddCust {
    
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String date,num,score;
        Custome cust = new Custome();
        System.out.println("我行我素购物管理系统>客户信息管理>添加客户信息");
        System.out.println(" ");
        System.out.print("请输入会员号（<4位整数>):");
        num =  input.nextLine();
        System.out.print("请输入会员生日(月/日<用两位数表示>:)");
        date = input.nextLine();
        System.out.print("请输入积分:");
        score = input.nextLine();
        cust.setNumber(num);
        cust.setDate(date);
        cust.setScore(score);
        if("707".equals(cust.getNumber()))
        {
            System.out.println("客户号" + num + "是无效会员号！");
            System.out.println("录入信息失败！");
        }
        else
        {
            System.out.println("已录入的会员信息是：");
            System.out.println(cust.getNumber() + "    " + cust.getDate() + "    " + cust.getScore());
        }

    }
    
}
class Custome {
    private String number;
    private String date ;
    private String score ;
    
    public String getNumber(){
        String re = "\\d\\d\\d\\d";
        if (number.matches(re))
            return this.number;
        else
            return "707";
    }
    public void setNumber(String number){
        this.number = number;
    }
    
    public String getScore(){
        return this.score;
    }
    public void setScore(String score){
        this.score = score;
    }
    
    public String getDate(){
        return this.date;
    }
    public void setDate(String date){
        this.date = date;
    }
}