#include "carry_lookahead_adder.h"

void cla_4bit(ap_uint<4> a, ap_uint<4> b, ap_uint<1> carry_in, ap_uint<4>& sum, ap_uint<1>& carry_out) {

    ap_uint<1> G[4], P[4], C[5];
    C[0] = carry_in;

    for (int i = 0; i < 4; i++) {
        G[i] = a[i] & b[i];
        P[i] = a[i] | b[i];
    }


    C[1] = G[0] | (P[0] & C[0]);
    C[2] = G[1] | (P[1] & C[1]);
    C[3] = G[2] | (P[2] & C[2]);
    C[4] = G[3] | (P[3] & C[3]);


    for (int i = 0; i < 4; i++) {
        sum[i] = a[i] ^ b[i] ^ C[i];
    }

    carry_out = C[4];
}


void carry_lookahead_adder(ap_uint<16> a, ap_uint<16> b, ap_uint<16>& sum, ap_uint<1>& carry_out) {
    ap_uint<4> sum_blocks[4];
    ap_uint<1> carry = 0, carry_blocks[4];

    // Divide 'a' and 'b' into 4-bit blocks and sum them using the cla_4bit function
    for (int i = 0; i < 4; i++) {
        cla_4bit(a.range((i+1)*4-1, i*4), b.range((i+1)*4-1, i*4), carry, sum_blocks[i], carry_blocks[i]);
        carry = carry_blocks[i]; // The carry out becomes the carry in for the next block
    }

    // Combine the 4-bit block sums into the 16-bit sum
    for (int i = 0; i < 4; i++) {
        sum.range((i+1)*4-1, i*4) = sum_blocks[i];
    }

    // The carry out of the last block is the carry out of the entire 16-bit adder
    carry_out = carry_blocks[3];
}



