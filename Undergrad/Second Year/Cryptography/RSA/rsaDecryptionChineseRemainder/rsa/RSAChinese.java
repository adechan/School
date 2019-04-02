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
		
		// dp = d mod (p - 1)
		dp = d.remainder(p.subtract(BigInteger.ONE));
		
		// dq = d mod (q - 1)
		dq = d.remainder(q.subtract(BigInteger.ONE));
		
		// qinv = q ^ - 1 mod p
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
		
		// m1 = c^dp mod p
		BigInteger m1 = messageInt.modPow(dp, p);
		
		// m2 = c^dq mod p
	    BigInteger m2 = messageInt.modPow(dq, q);
	    
	    // h = (qinv x (m1 - m2)) mod p
	    BigInteger h = ((m1.subtract(m2)).multiply(qinv)).remainder(p);
	    
	    // message
	    return (h.multiply(q)).add(m2).toByteArray();
	}
	
}
