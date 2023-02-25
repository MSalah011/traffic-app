/*
 * bit_manipulation.h
 *
 * Created: 01/02/2023 02:19:33 AM
 *  Author: Mahmoud
 */ 

#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(REG, PIN) REG|=(1<<PIN)

#define CLEAR_BIT(REG, PIN) REG&=~(1<<PIN)

#define TOGGLE_BIT(REG, PIN) REG^=(1<<PIN)

#define READ_BIT(REG, PIN) (REG & (1<<PIN))>>PIN

#endif /* BIT_MANIPULATION_H_ */