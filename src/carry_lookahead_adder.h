#ifndef CARRY_LOOKAHEAD_ADDER_H
#define CARRY_LOOKAHEAD_ADDER_H

#include <ap_int.h>



void carry_lookahead_adder(ap_uint<16> a, ap_uint<16> b, ap_uint<16>& sum, ap_uint<1>& carry_out);
#endif // CARRY_LOOKAHEAD_ADDER_H
