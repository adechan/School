package des;
import main.Utility;
/**
 * A class describing the Fiestel Function.
 * Given one argument of length 32 and another one of length 48, permuting 
 * we get a bistring of length 32, which will be used to compute XOR with the argument
 * of 48 length, to get 8 x 6bitstrings. 
 * It will use the 8 S-boxes so a 48bit value is split into 6-bit sections, and each 
 * section is permuted into a different 6-bit value. 
 * 8 x bistring resulted of length 32 will be permuted according to P Permutation.
 * @author Andreea Rindasu
 *
 */
public class FiestelFunction {
	
	/**
	 * 
	 * @param argument32Bits : bistring of length 32
	 * @param argument48Bits : bistring of length 48
	 * @returns the bistring C of length 32 permuted according to P
	 */
	public static int[] fFunction(int[] argument32Bits, int[] argument48Bits) 
	{
		// expandedArgument: stores the bits of first argument permuted with E
		int expandedArgument[] = new int[48];
		
		// expandedArgument consists of 48bits from first argument, 16 appearing twice
		for(int i = 0; i < 48; i++)
		{
			expandedArgument[i] = argument32Bits[DesBoxes.E[i] - 1];
		}
		
		// compute expanded argument XOR and argument48Bits as a concatenation of 6x 8bitstrings
		int computeResult[] = Utility.xorFunction(expandedArgument, argument48Bits);	

		 // The S boxes are applied to result and, the final result is permuted according to P permutation
		int resultFiestel[] = sBoxes(computeResult);
		return resultFiestel;
	}
	
	/**
	 * 
	 * @param bitstring
	 * @return the permutation of final 8 x bistring of length 32 according to P Permutation 
	 */
	public static int[] sBoxes(int[] bitstring)
	{
		// the result is 32 bits
		int result[] = new int[32];
		
		// we will take each iteration 4 bits: 32/4 = 8
		for(int i = 0; i < 8; i++) 
		{
			// Find row and column to get the entry of a 4length string written in binary

			// Row: b0 b5
			int rowBox[] = new int [2];	
			rowBox[0] = bitstring[6 * i];
			rowBox[1] = bitstring[(6 * i) + 5];	
			String concatenationRowBox = rowBox[0] + "" + rowBox[1];
			
			// Column: b1 b2 b3 b4
			int columnBox[] = new int[4];
			columnBox[0] = bitstring[(6 * i) + 1];
			columnBox[1] = bitstring[(6 * i) + 2];
			columnBox[2] = bitstring[(6 * i) + 3];
			columnBox[3] = bitstring[(6 * i) + 4];
			String concatenationColumnBox = columnBox[0] + "" + columnBox[1] + "" + columnBox[2] + "" + columnBox[3];

			// Convert binary to decimal value
			int valueRow = Integer.parseInt(concatenationRowBox, 2);
			int valueColumn = Integer.parseInt(concatenationColumnBox, 2);
			
			// decimal value
			int valueSBox = DesBoxes.S[i][(valueRow * 16) + valueColumn];
			String binaryValueSBox = Integer.toBinaryString(valueSBox);
			
			// Add '0' in front of the binary number (5: 111 -> 0111)
			while(binaryValueSBox.length() < 4) 
			{
				binaryValueSBox = "0" + binaryValueSBox;
			}
			
			// Add to the result the binary bits
			for(int j = 0; j < 4; j++) 
			{
				result[(i * 4) + j] = Integer.parseInt(binaryValueSBox.charAt(j) + "");
			}
		}

		// Use P Permutation to find finalResult of length 32
		int finalResult[] = new int[32];
		
		for(int i = 0; i < 32; i++)
		{
			finalResult[i] = result[DesBoxes.P[i] - 1];
		}
		
		return finalResult;
		}
}
