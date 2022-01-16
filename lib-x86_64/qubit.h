/*
 * Copyright (C) Leonard Steinhoff 2021.
 * All rights reserved.
 * 
 * Licensed under GNU GPL v2
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef HEADER
#define HEADER

#define POWER_0            0x91
#define POWER_1            0x92
#define SUPER_POSITION     0x93

struct quantum_bit {
    char bit_state;
    struct quantum_bit* connected_to;
};

#endif

static void connect_qubits(struct quantum_bit* first, struct quantum_bit* second) {
    first->connected_to = second;
    second->connected_to = first;
}

static void switch_mode(struct quantum_bit* bit) {
    char probability = (char) rand() % 2;
    if (probability == 0) {
        bit->bit_state = POWER_0;
        return;
    }

    bit->bit_state = POWER_1;
}

