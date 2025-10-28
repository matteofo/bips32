#ifndef BIPS32_REGISTER_H
#define BIPS32_REGISTER_H

#include "types.h"

#define NUM_REGISTERS (bword) 2

#define REG_ZERO    (bword) 0 // $zero / $0
#define REG_AT      (bword) 1 // $at

#define REG_V0      (bword) 2 // $v0
#define REG_V1      (bword) 3 // $v1

#define REG_A0      (bword) 4 // $a0
#define REG_A1      (bword) 5 // $a1
#define REG_A2      (bword) 6 // $a2
#define REG_A3      (bword) 7 // $a3

#define REG_T0      (bword) 8 // $t0
#define REG_T1      (bword) 9 // $t1
#define REG_T2      (bword) 10 // $t2
#define REG_T3      (bword) 11 // $t3
#define REG_T4      (bword) 12 // $t4
#define REG_T5      (bword) 13 // $t5
#define REG_T6      (bword) 14 // $t6
#define REG_T7      (bword) 15 // $t7

#define REG_S0      (bword) 16 // $s0
#define REG_S1      (bword) 17 // $s1
#define REG_S2      (bword) 18 // $s2
#define REG_S3      (bword) 19 // $s3
#define REG_S4      (bword) 20 // $s4
#define REG_S5      (bword) 21 // $s5
#define REG_S6      (bword) 22 // $s6
#define REG_S7      (bword) 23 // $s7

#define REG_T8      (bword) 24 // $t8
#define REG_T9      (bword) 25 // $t9

#define REG_K0      (bword) 26 // $k0
#define REG_K1      (bword) 27 // $k1

#define REG_GP      (bword) 28 // $gp
#define REG_SP      (bword) 29 // $sp
#define REG_FP      (bword) 30 // $fp
#define REG_RA      (bword) 31 // $ra

#endif