
/**
 * \file sine_table_big.h
 * \brief Sine Loopup table declarations
 * \author Ludwig Orgler <lorgler@synapticon.com>
 * \author Martin Schwarz <mschwarz@synapticon.com>
 * \version 1.0
 * \date 10/04/2014
 */

 

int arctg1(int Real, int Imag);

extern short arctg_table[];

extern short sine_third[257];

extern short sine_table[257];

int sine_third_expanded(int angle);

int sine_table_expanded(int angle);
