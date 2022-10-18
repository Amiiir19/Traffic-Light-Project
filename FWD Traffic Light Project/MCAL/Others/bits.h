/*
 * bits.h
 *
 * Created: 08-Oct-22 1:33:08 AM
 *  Author: Abdelrahman Mohamed Amir
 */ 


#ifndef BITS_H_
#define BITS_H_

#define setBit(x,bitNum)     (x |= (1<<bitNum))
#define clrBit(x,bitNum)     (x &=~ (1<<bitNum))
#define toggleBit(x,bitNum)  (x ^= (1<<bitNum))
#define readBit(x,bitNum)    ((x &(1<<bitNum))>>bitNum)



#endif /* BITS_H_ */