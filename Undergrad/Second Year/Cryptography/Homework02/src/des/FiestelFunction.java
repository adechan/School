package des;
import main.Utility;

/**
 * A class describing the Fiestel function. 
 * f (A, J) A = 32 bits, J = 48 bits
 * 
 * -> The first argument A is expanded to a bistring of length 48 according to E table;
 * E(A) consists of the 32 bits from A, permuted in a certain way, with 16 of the bits appearing twice
 * 
 * -> Compute E(A) XOR J and write the result as the concatenation of 8 x 6bit strings B
 * 
 * -> Using 8 S-Boxes, each Si is a fixed 4 x 16 array whose entries come from the integeres 0-15;
 * Given a bistring of length 6 Bj, we compute Sj Bj as :
 * ---> the 2 bits b1b6 determine the binary representation of a column C of the 4 bits b2b3b4b5
 * ---> Sj(Bj) is defined to be the entry Sj(r, c) written in binary as a bistring of length 4; j <= 8
 * 
 * -> The bistring C of length 32 is permuted according to a permutation P
 * 
 * P(C) is defined to be f(A, J)
 * @author Andreea Rindasu
 *
 */
public class FiestelFunction {
	
	/**
	 * 
	 * @param argument : bistring of length 32
	 * @param roundKey : bistring of length 48
	 * @returns the bistring C of length 32 permuted according to P : P(C)
	 */
	public static int[] fFunction(int[] argument, int[] roundKey) 
	{
		// The 32 bits of the argument array are expanded using E table.
		int expandedArgument[] = new int[48];
		
		// E(argument) consists of the 32 bits from argument permuted with 16 of the bits appearing twice
		for(int i = 0; i < 48; i++)
		{
			expandedArgument[i] = argument[DesBoxes.E[i] - 1];
		}
		
		// Compute expanded argument XOR generated round key as concatenation of 8 x 6bit strings
		int temp[] = Utility.xor(expandedArgument, roundKey);	

		 // The S boxes are applied to this XOR result and this is the output of the Fiestel function 
		int output[] = sBoxes(temp);
		return output;
	}
	
	/**
	 * Given a bistring of length 6, Bj we compute SjBj:
	 * The 2 bits b1b6 determine the binary representation of a column c of the four bits b2b3b4b5
	 * Sj(Bj) is defined to be the entry Sj(r,c) written in binary as a bistring of length 4
	 * Cj = Sj(Bj)
	 * @param bits
	 * @return the bistring C of length 32 is permuted according to permutation P
	 */
	public static int[] sBoxes(int[] bits)
	{
		int output[] = new int[32];
		
		// input will be 32 bits and we will take 4 bits of input each iteration so loop 32/4 = 8 bits 
		for(int i = 0; i < 8; i++) 
		{
			// Needs a row and a column which is found from the input bits 

			// for row: b0b5
			int row[] = new int [2];	
			row[0] = bits[6 * i];
			row[1] = bits[(6 * i) + 5];
			
			String sRow = row[0] + "" + row[1];
			
			// for column: b2b3b4b5
			int column[] = new int[4];
			column[0] = bits[(6 * i) + 1];
			column[1] = bits[(6 * i) + 2];
			column[2] = bits[(6 * i) + 3];
			column[3] = bits[(6 * i) + 4];
			
			String sColumn = column[0] +""+ column[1] +""+ column[2] +""+ column[3];

			// Convert binary to decimal value to be given into the array as input 
			int inputRow = Integer.parseInt(sRow, 2);
			int inputColumn = Integer.parseInt(sColumn, 2);
			
			// 16 array
			int x = DesBoxes.S[i][(inputRow * 16) + inputColumn];
			
			// We get the decimal value of the SBox, but we have to convert it to binary 
			String s = Integer.toBinaryString(x);
			
			// Add '0' in front of the binary number 
			// 5: 111 but we need 0111
			while(s.length() < 4) 
			{
				s = "0" + s;
			}
			
			// The binary bits are added to the output
			for(int j = 0; j < 4; j++) 
			{
				output[(i * 4) + j] = Integer.parseInt(s.charAt(j) + "");
			}
		}

		// Use the P permutation to the output to get the final result of one SBox round
		int finalResult[] = new int[32];
		
		for(int i = 0; i < 32; i++)
		{
			finalResult[i] = output[DesBoxes.P[i] - 1];
		}
		
		return finalResult;
		}
}
