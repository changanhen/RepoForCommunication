public class Prime2 {
	public static int calculateNumber(int Nmax) {
		boolean[] isPrime = new boolean[Nmax + 1];
		int[] prime = new int[Nmax / 10];
		int totalPrimes = 1;
		for (int i = 3; i <= Nmax; i += 2)
			isPrime[i] = true;
		isPrime[2] = true;
		prime[0] = 2;
		for (int i = 3; i <= Nmax; i += 2) {
			if (isPrime[i])
				prime[totalPrimes++] = i;
			for (int j = 1; i * prime[j] <= Nmax && j < totalPrimes; j++){
				isPrime[i * prime[j]] = false;
				if(i%prime[j]==0)
					break;
			}
		}
		return totalPrimes;
	}
 
	public static void main(String[] args) {
		final int Nmax = 100000000;
		double startTime = System.currentTimeMillis();
		int primeNum = Prime2.calculateNumber(Nmax);
		double timeSpent = (System.currentTimeMillis() - startTime) / 1000;
		System.out.println("The prime numbers from 1 to " + Nmax + " is "
				+ primeNum);
		System.out.println("Time spent : " + timeSpent + " s");
	}
}