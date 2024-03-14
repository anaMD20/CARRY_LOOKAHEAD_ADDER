#include "carry_lookahead_adder.h"
#include <iostream>


void check_result(ap_uint<16> a, ap_uint<16> b, ap_uint<16> expected_sum, ap_uint<1> expected_carry_out) {
    ap_uint<16> sum;
    ap_uint<1> carry_out;
    carry_lookahead_adder(a, b, sum, carry_out);


    std::cout << "Suma calculata pentru a = " << a.to_string(16)
              << " si b = " << b.to_string(16)
              << " este: " << sum.to_string(16)
              << " cu transport de iesire: " << carry_out << std::endl;

    if (sum != expected_sum || carry_out != expected_carry_out) {
        std::cout << "Eroare: Suma sau transportul de iesire nu este asteptat!" << std::endl
                  << "  Suma asteptata: " << expected_sum.to_string(16)
                  << ", Transport de iesire asteptat: " << expected_carry_out << std::endl;
    } else {
        std::cout << "Test trecut." << std::endl;
    }
}


void test_carry_lookahead_adder() {
    // Teste existente
    check_result(0x0001, 0x0001, 0x0002, 0);
    check_result(0x0F0F, 0xF0F0, 0xFFFF, 0);
    check_result(0xAAAA, 0x5555, 0xFFFF, 0);
    check_result(0x0035, 0x001C, 0x0051, 0);
    check_result(0xFFF0, 0X0020, 0X0010, 1);

}

int main() {
    test_carry_lookahead_adder();
    return 0;
}


