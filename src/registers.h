#ifndef BIPS32_REGISTER_H
#define BIPS32_REGISTER_H

#include "types.h"

#define NUM_REGISTERS (word) 32

#define REG_ZERO    (word) 0 // $zero / $0
#define REG_AT      (word) 1 // $at

#define REG_V0      (word) 2 // $v0
#define REG_V1      (word) 3 // $v1

#define REG_A0      (word) 4 // $a0
#define REG_A1      (word) 5 // $a1
#define REG_A2      (word) 6 // $a2
#define REG_A3      (word) 7 // $a3

#define REG_T0      (word) 8 // $t0
#define REG_T1      (word) 9 // $t1
#define REG_T2      (word) 10 // $t2
#define REG_T3      (word) 11 // $t3
#define REG_T4      (word) 12 // $t4
#define REG_T5      (word) 13 // $t5
#define REG_T6      (word) 14 // $t6
#define REG_T7      (word) 15 // $t7

#define REG_S0      (word) 16 // $s0
#define REG_S1      (word) 17 // $s1
#define REG_S2      (word) 18 // $s2
#define REG_S3      (word) 19 // $s3
#define REG_S4      (word) 20 // $s4
#define REG_S5      (word) 21 // $s5
#define REG_S6      (word) 22 // $s6
#define REG_S7      (word) 23 // $s7

#define REG_T8      (word) 24 // $t8
#define REG_T9      (word) 25 // $t9

#define REG_K0      (word) 26 // $k0
#define REG_K1      (word) 27 // $k1

#define REG_GP      (word) 28 // $gp
#define REG_SP      (word) 29 // $sp
#define REG_FP      (word) 30 // $fp
#define REG_RA      (word) 31 // $ra

#endif