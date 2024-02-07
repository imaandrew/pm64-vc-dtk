#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "types.h"

typedef struct {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ void* cpu;
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ void* ram;
    /* 0x24 */ u8 unk_24[0x38];
    /* 0x5C */ s32 unk_5C;
} System;

extern System* lbl_80246B64;

#endif