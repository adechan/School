package rsa;

import java.math.BigInteger;
import java.util.Random;

public class RSAChinese extends RSA {
	
	private BigInteger dp;
	private BigInteger dq;
	private BigInteger qinv;
	
	// Generates a public key for encryption and a private key for decryption
	public RSAChinese()
	{
		// Generate the standard RSA primes and keys
		super();
		
		dp = d.remainder(p.subtract(BigInteger.ONE));
		dq = d.remainder(q.subtract(BigInteger.ONE));
		qinv = q.modInverse(p);	
	}
	
	@Override
	public byte[] decryptText(String ciphertext)
	{
		return this.decryptText(ciphertext.getBytes());
	}

	@Override
	public byte[] decryptText(byte[] ciphertext)
	{
		System.out.println("Using TCR...");
		BigInteger messageInt = new BigInteger(ciphertext);
		
		BigInteger m1 = messageInt.modPow(dp, p);
	    BigInteger m2 = messageInt.modPow(dq, q);
	    BigInteger h = ((m1.subtract(m2)).multiply(qinv)).remainder(p);
	    return (h.multiply(q)).add(m2).toByteArray();
	}
	
}