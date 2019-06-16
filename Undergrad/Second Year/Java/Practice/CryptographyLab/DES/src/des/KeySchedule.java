package des;

/**
 * A class describing the key schedule.
 * Given a 64bit key of which 56bits comprise the key and 8bits are parity-check bits, we need to discard the parity-check
 * bits and permute the remaining bits to PC1. The remaining bits will be split into C and D, which will be used to compute 
 * 16 times a cyclic shift to the left of 1 or 2 positions, so we get each round a 48bit key.
 * @author Andreea Rindasu
 *
 */
public class KeySchedule {

	// first 28 bits 
	public static int[] C = new int[28];
	// last 28 bits 
	public static int[] D = new int[28];
	
	// 16 subkeys comprised of 48 of the bits
	public static int[][] subkey = new int[16][48];
	
	/**
	 * 
	 * @param bits
	 * @param rotationValue
	 * @return each bit is rotated to the left and the leftmost bit is stored at the rightmost bit
	 */
	public static int[] leftShift(int[] bits, int rotationValue) 
	{
		// result: stores the bits
		int result[] = new int[bits.length];
		
		System.arraycopy(bits, 0, result, 0, bits.length);
		
		// rotate to the left according to rotationValue
		// and the leftmost bit is stored at the rightmomst bit
		for(int i = 0; i < rotationValue; i++) 
		{
			int leftmostBit = result[0];
			
			// shift to the left
			for(int j = 0; j < bits.length - 1; j++) 
			{
				result[j] = result[j + 1];
			}
			
			result[bits.length - 1] = leftmostBit;
		}
		return result;
	}
	
	/** 
	 * Generates the 16 round keys
	 * @param round
	 * @param key
	 * @return round keys
	 */
	public static int[] keySchedule(int round, int[] key)
	{

		// new C and D will be generated in this round
		int keyScheduleC[] = new int[28];
		int keyScheduleD[] = new int[28];
		
		// set how many rotations are need to be done in each round
		int rotationTimes = (int) DesBoxes.shiftPositions[round];
		
		keyScheduleC = leftShift(C, rotationTimes);
		keyScheduleD = leftShift(D, rotationTimes);
		
		int concatenationCD[] = new int[56];
		
		System.arraycopy(keyScheduleC, 0, concatenationCD, 0, 28);
		System.arraycopy(keyScheduleD, 0, concatenationCD, 28, 28);
		
		int generatedSubkey[] = new int[48];
		// apply the PC2 to concatenation of the Ci Di
		for(int i = 0; i < generatedSubkey.length; i++) 
		{
			generatedSubkey[i] = concatenationCD[DesBoxes.PC2[i] - 1];
		}
		
		// stores the generated subkey
		subkey[round] = generatedSubkey;
		
		// stores keyScheduleC in C and keyScheduleD in D
		// so this becomes old C and D for next round
		C = keyScheduleC;
		D = keyScheduleD;
		
		return generatedSubkey;
	}
}
