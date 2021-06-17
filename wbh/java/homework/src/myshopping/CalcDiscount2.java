package myshopping;


import java.util.Scanner;

public class CalcDiscount2 {
	
	public static void main(String[] args) {
		int Cscore;
		double discount;
		
        Scanner input = new Scanner(System.in);
		score cust = new score();
		cust.setScore(input.nextLine());
		Cscore = Integer.parseInt(cust.getScore());
		if (Cscore < 2000)
		    discount = 0.9;
		else if (2000 <= Cscore && Cscore < 4000)
			discount = 0.8;
		else if (4000 <= Cscore && Cscore < 8000)
			discount = 0.7;
		else
			discount = 0.6;
	}

}

class score{
	String score;

	public String getScore() {
		return score;
	}

	public void setScore(String score) {
		this.score = score;
	}
}