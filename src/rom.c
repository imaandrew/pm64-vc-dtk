#include "types.h"
#include "system.h"
#include "xlHeap.h"

typedef struct {
    s32 unk_00;
    u8 unk_04[4];
    u32 unk_08;
    u8 unk_0C[4];
    s8 unk_10[10];
    u8 unk_1A[0x1FA];
    u32 unk_214;
    u8 unk_218[4];
    s32 unk_21C;
    u8 unk_220[0x18004];
    s32 unk_18224;
    u8 unk_18228[0x1844];
    s32 unk_19A6C;
    s32 unk_19A70;
    u8 unk_19A74[0x3B];
    u8 code[4];
} Rom;

s32 romGetCode(Rom *arg0, s32 *arg1) {
    *arg1 = arg0->code[0] << 0x18 | arg0->code[1] << 0x10 | arg0->code[2] << 0x8 | arg0->code[3];
    return 1;
}

s32 romPut8(void) {
    return 1;
}

s32 romPut16(void) {
    return 1;
}

s32 romPut32(void) {
    return 1;
}

s32 romPut64(void) {
    return 1;
}

s32 romGet8(Rom *arg0, u32 arg1, s8 *arg2) {
    s8 sp8;

    if ((arg1 & 0x7FFFFFF) < arg0->unk_214 && (romCopy(arg0, &sp8, arg1 & 0x07FFFFFF, sizeof(s8), 0) != 0)) {
        *arg2 = sp8;
        return 1;
    }
    return 1;
}

s32 romGet16(Rom *arg0, u32 arg1, s16 *arg2) {
    s16 sp8;

    if ((arg1 & 0x7FFFFFF) < arg0->unk_214 && (romCopy(arg0, &sp8, arg1 & 0x07FFFFFF, sizeof(s16), 0) != 0)) {
        *arg2 = sp8;
        return 1;
    }
    return 1;
}

s32 romGet32(Rom *arg0, u32 arg1, s32 *arg2) {
    s32 sp8;

    if ((arg1 & 0x7FFFFFF) < arg0->unk_214 && (romCopy(arg0, &sp8, arg1 & 0x07FFFFFF, sizeof(s32), 0) != 0)) {
        *arg2 = sp8;
        return 1;
    }
    return 1;
}

s32 romGet64(Rom *arg0, u32 arg1, s64 *arg2) {
    s64 sp8;

    if ((arg1 & 0x7FFFFFF) < arg0->unk_214 && (romCopy(arg0, &sp8, arg1 & 0x07FFFFFF, sizeof(s64), 0) != 0)) {
        *arg2 = sp8;
        return 1;
    }
    return 1;
}

s32 romPutDebug8(void) {
    return 1;
}

s32 romPutDebug16(void) {
    return 1;
}

s32 romPutDebug32(void) {
    return 1;
}

s32 romPutDebug64(void) {
    return 1;
}

s32 romGetDebug8(Rom* arg0, u32 arg1, s8 *arg2) {
    *arg2 = 0;
    return 1;
}

s32 romGetDebug16(Rom* arg0, u32 arg1, s16 *arg2) {
    *arg2 = 0;
    return 1;
}

s32 romGetDebug32(Rom* arg0, u32 arg1, s32 *arg2) {
    *arg2 = 0;
    return 1;
}

s32 romGetDebug64(Rom* arg0, u32 arg1, s64 *arg2) {
    *arg2 = 0;
    return 1;
}

typedef struct unk_struct {
    u32 unk_00;
    u32 unk_04;
    s32 (*unk_08)(struct unk_struct*, s32);
    u32 unk_0C;
    u32 unk_10;
} unk_struct;

s32 romGetBlock(Rom *arg0, unk_struct* arg1) {
    u32 sp8;

    if (arg1->unk_10 < 0x4000000) {
        if (ramGetBuffer(lbl_80246B64->ram, &sp8, arg1->unk_10, &arg1->unk_04) == 0) {
            return 0;
        }
        if (romCopy(arg0, sp8, arg1->unk_0C, arg1->unk_04, NULL) == 0) {
            return 0;
        }
    }
    if (arg1->unk_08(arg1, 1) == 0) {
        return 0;
    }
    return 1;
}

s32 romGetImage(Rom *arg0, u8 *arg1) {
    s32 i;

    if (arg0->unk_10[0] == 0) {
        return 0;
    }

    if (arg1) {
        for (i = 0; arg0->unk_10[i] != 0; i++) {
            arg1[i] = arg0->unk_10[i];
        }
    }
    return 1;
}

s32 romUpdate(void) {
    return 1;
}

s32 fn_8004361C(Rom *arg0) {
    if (arg0->unk_08 != 0) {
        if (fn_800428AC() == 0) {
            return 0;
        }
        arg0->unk_08 = 0;
        return 1;
    }
    return 1;
}

s32 fn_800435B8(Rom *arg0, s32 *arg1, s32 arg2, s32 *arg3) {
    u32 temp_r7;
    u32 temp_r8;

    if (arg0->unk_21C == 1) {
        temp_r8 = arg2 & 0x07FFFFFF;
        if (arg3) {
            temp_r7 = arg0->unk_214;
            if (temp_r8 >= temp_r7) {
                return 0;
            }
            if (temp_r8 + *arg3 > temp_r7) {
                *arg3 -= temp_r7 - temp_r8;
            }
        }
        *arg1 = arg0->unk_00 + temp_r8;
        return 1;
    }
    return 0;
}

s32 fn_80041A3C(void);

s32 romSetImage(Rom *arg0, s8 *arg1) {
    s32 spC;
    u32 sp8;
    s32 temp_r7;
    s32 var_r4;
    u32 temp_r4;

    s32 i;
    for (i = 0; (arg1[i] != 0) && (i < 0x200); i++) {
        arg0->unk_10[i] = arg1[i];
    }

    arg0->unk_10[i] = 0;
    xlFileGetSize(arg0->unk_218, arg0->unk_10);
    if (!xlFileOpen(&spC, 1, arg1)) {
        return 0;
    }
    if (!xlFileRead(spC, (u32) &sp8, 4)) {
        return 0;
    }
    if (!xlFileClose(&spC)) {
        return 0;
    }
    temp_r4 = sp8 >> 2U;
    arg0->unk_214 = temp_r4;
    temp_r7 = (temp_r4 + 0x1FFF) & 0xFFFFE000;
    arg0->unk_19A70 = temp_r7;
    arg0->unk_19A6C = (s32) (temp_r7 / 8192);
    if ((temp_r7 + 0x01B00000) < 0x03600000 && !xlHeapTake(arg0, temp_r7 | 0x70000000) || !fn_80060C78(lbl_80246B64->unk_5C, arg0, temp_r7 | 0x70000000, &fn_80041A3C)) {
        var_r4 = 0;
    } else {
        var_r4 = 1;
        arg0->unk_18224 = (s32) arg0->unk_00;
    }
    return (u32) (-var_r4 | var_r4) >> 0x1FU;
}
