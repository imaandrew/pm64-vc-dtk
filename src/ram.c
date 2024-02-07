#include "types.h"
#include "system.h"

typedef struct {
    u8 unk_00[4];
    u8* rdram;
    s32 size;
    s32 var[16];
} Ram;

s32 ramPutControl8(Ram* arg0, s32 arg1, s8* arg2) {
    return 0;
}

s32 ramPutControl16(Ram* arg0, s32 arg1, s16* arg2) {
    return 0;
}

s32 ramPutControl32(Ram* arg0, s32 arg1, s32* arg2) {
    switch (arg1 & 0x3f) {
        case 0:
            arg0->var[0] = *arg2;
            break;
        case 4:
            arg0->var[1] = *arg2;
            break;
        case 8:
            arg0->var[2] = *arg2;
            break;
        case 12:
            arg0->var[3] = *arg2;
            break;
        case 16:
            arg0->var[4] = *arg2;
            break;
        case 20:
            arg0->var[5] = *arg2;
            break;
        case 24:
            arg0->var[6] = *arg2;
            break;
        case 28:
            arg0->var[7] = *arg2;
            break;
        case 32:
            arg0->var[8] = *arg2;
            break;
        case 36:
            arg0->var[9] = *arg2;
            break;
        default:
            return 0;
    }

    return 1;
}

s32 ramPutControl64(Ram* arg0, s32 arg1, s64* arg2) {
    return 0;
}

s32 ramGetControl8(Ram* arg0, s32 arg1, s8* arg2) {
    return 0;
}

s32 ramGetControl16(Ram* arg0, s32 arg1, s16* arg2) {
    return 0;
}

s32 ramGetControl32(Ram* arg0, s32 arg1, s32* arg2) {
    *arg2 = 0;
    switch (arg1 & 0x3f) {
        case 0:
            *arg2 = arg0->var[0];
            break;
        case 4:
            *arg2 = arg0->var[1];
            break;
        case 8:
            *arg2 = arg0->var[2];
            break;
        case 12:
            *arg2 = arg0->var[3];
            break;
        case 16:
            *arg2 = arg0->var[4];
            break;
        case 20:
            *arg2 = arg0->var[5];
            break;
        case 24:
            *arg2 = arg0->var[6];
            break;
        case 28:
            *arg2 = arg0->var[7];
            break;
        case 32:
            *arg2 = arg0->var[8];
            break;
        case 36:
            *arg2 = arg0->var[9];
            break;
        default:
            return 0;
    }

    return 1;
}

s32 ramGetControl64(Ram* arg0, s32 arg1, s64* arg2) {
    return 0;
}

s32 ramPutRI8(Ram* arg0, s32 arg1, s8* arg2) {
    return 0;
}

s32 ramPutRI16(Ram* arg0, s32 arg1, s16* arg2) {
    return 0;
}

s32 ramPutRI32(Ram* arg0, s32 arg1, s32* arg2) {
    switch (arg1 & 0x1f) {
        case 0:
            arg0->var[10] = *arg2 & 0xf;
            break;
        case 4:
            arg0->var[11] = *arg2 & 0x7f;
            break;
        case 12:
            arg0->var[12] = *arg2 & 0x7;
            break;
        case 16:
            arg0->var[13] = *arg2;
            break;
        case 20:
            arg0->var[14] = *arg2 & 0xf;
            break;
        case 8:
        case 24:
        case 28:
            break;
        default:
            return 0;
    }

    return 1;
}

s32 ramPutRI64(Ram* arg0, s32 arg1, s64* arg2) {
    return 0;
}

s32 ramGetRI8(Ram* arg0, s32 arg1, s8* arg2) {
    return 0;
}

s32 ramGetRI16(Ram* arg0, s32 arg1, s16* arg2) {
    return 0;
}

s32 ramGetRI32(Ram* arg0, s32 arg1, s32* arg2) {
    switch (arg1 & 0x1f) {
        case 0:
            *arg2 = arg0->var[10] & 0xf;
            break;
        case 4:
            *arg2 = arg0->var[11] & 0x7f;
            break;
        case 12:
            *arg2 = arg0->var[12] & 0x7;
            break;
        case 16:
            *arg2 = arg0->var[13];
            break;
        case 20:
            *arg2 = arg0->var[14] & 0xf;
            break;
        case 24:
            *arg2 = 0;
            break;
        case 8:
        case 28:
            break;
        default:
            return 0;
    }

    return 1;
}

s32 ramGetRI64(Ram* arg0, s32 arg1, s64* arg2) {
    return 0;
}

s32 ramPut8(Ram* arg0, s32 arg1, s8* arg2) {
    u32 temp_r4 = arg1 & 0x03FFFFFF;
    
    if (temp_r4 < arg0->size)
        arg0->rdram[temp_r4] = *arg2;
    
    return 1;
}

s32 ramPut16(Ram* arg0, s32 arg1, s16* arg2) {
    u32 temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *(s16*)&arg0->rdram[temp_r4 & 0xFFFFFFFE] = (u16)(*arg2);
    }
    return 1;
}

s32 ramPut32(Ram* arg0, s32 arg1, s32* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *(s32*)&arg0->rdram[temp_r4 & 0xFFFFFFFC] = *arg2;
    }
    return 1;
}

s32 ramPut64(Ram* arg0, s32 arg1, s64* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *(s64*)&arg0->rdram[temp_r4 & 0xFFFFFFF8] = *arg2;
    }
    return 1;
}

s32 ramGet8(Ram* arg0, s32 arg1, s8* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *arg2 = arg0->rdram[temp_r4];
    } else {
        *arg2 = 0;
    }
    return 1;
}

s32 ramGet16(Ram* arg0, s32 arg1, s16* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *arg2 = *(s16*)&arg0->rdram[temp_r4 & 0xFFFFFFFE];
    } else {
        *arg2 = 0;
    }
    return 1;
}

s32 ramGet32(Ram* arg0, s32 arg1, s32* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *arg2 = *(s32*)&arg0->rdram[temp_r4 & 0xFFFFFFFC];
    } else {
        *arg2 = 0;
    }
    return 1;
}

s32 ramGet64(Ram* arg0, s32 arg1, s64* arg2) {
    u32 temp_r4;

    temp_r4 = arg1 & 0x03FFFFFF;
    if (temp_r4 < arg0->size) {
        *arg2 = *(s64*)&arg0->rdram[temp_r4 & 0xFFFFFFF8];
    } else {
        *arg2 = 0;
    }
    return 1;
}

typedef struct unk_fn_8004165C {
    u8 unk_00[8];
    s32 (*unk_08)(struct unk_fn_8004165C*, s32);
} unk_fn_8004165C;

s32 fn_8004165C(void* arg0, unk_fn_8004165C* arg1) {
    if (arg1->unk_08 && !arg1->unk_08(arg1, 1)) {
        return 0;
    }
    return 1;
}

s32 ramGetBuffer(Ram* arg0, void** arg1, u32 arg2, s32* arg3) {
    arg2 = arg2 & 0x03FFFFFF;
    if (arg0->size == 0) {
        return 0;
    }

    if (arg3 && ((arg2 + *arg3) >= arg0->size)) {
        *arg3 = arg0->size - arg2;
        if (*arg3 < 0) {
            *arg3 = 0;
        }
    }
    *arg1 = arg0->rdram + (arg2 & (arg0->size - 1));
    return 1;
}

s32 ramWipe(Ram* arg0) {
    if (arg0->size && !xlHeapFill32((s32*)arg0->rdram, arg0->size, 0)) {
        return 0;
    }
    return 1;
}

s32 ramSetSize(Ram* arg0, s32 arg1) {
    s32 temp_r31;

    if (arg0->rdram) {
        return 0;
    }
    temp_r31 = (arg1 + 0x3FF) & 0xFFFFFC00;
    if (!xlHeapTake(&arg0->rdram, temp_r31 | 0x30000000)) {
        return 0;
    }
    arg0->size = temp_r31;
    return 1;
}

s32 ramGetSize(Ram* arg0, s32* arg1) {
    if (arg1) {
        *arg1 = arg0->size;
    }
    return 1;
}

s32 cpuSetDeviceGet(void*, s32*, s32 (*func8)(Ram*, s32, s8*), s32 (*func16)(Ram*, s32, s16*),
                    s32 (*func32)(Ram*, s32, s32*), s32 (*func64)(Ram*, s32, s64*)); /* extern */
s32 cpuSetDevicePut(void*, s32*, s32 (*func8)(Ram*, s32, s8*), s32 (*func16)(Ram*, s32, s16*),
                    s32 (*func32)(Ram*, s32, s32*), s32 (*func64)(Ram*, s32, s64*)); /* extern */
s32 cpuSetGetBlock(void*, s32*, s32 (*func)(void*, unk_fn_8004165C*));

s32 ramEvent(Ram* arg0, s32 arg1, s32* arg2) {
    s32 temp_r0;

    switch (arg1) {
        case 2:
            arg0->size = 0;
            arg0->rdram = 0;
            break;
        case 0x1002:
            switch (*arg2 & 0xFF) {
                case 0:
                    if (cpuSetGetBlock(lbl_80246B64->cpu, arg2, fn_8004165C) == 0) {
                        return 0;
                    }
                    if (cpuSetDevicePut(lbl_80246B64->cpu, arg2, ramPut8, ramPut16, ramPut32, ramPut64) == 0) {
                        return 0;
                    }
                    if (cpuSetDeviceGet(lbl_80246B64->cpu, arg2, ramGet8, ramGet16, ramGet32, ramGet64) == 0) {
                        return 0;
                    }
                    break;
                case 1:
                    if (cpuSetDevicePut(lbl_80246B64->cpu, arg2, ramPutRI8, ramPutRI16, ramPutRI32, ramPutRI64) == 0) {
                        return 0;
                    }
                    if (cpuSetDeviceGet(lbl_80246B64->cpu, arg2, ramGetRI8, ramGetRI16, ramGetRI32, ramGetRI64) == 0) {
                        return 0;
                    }
                    break;
                case 2:
                    if (cpuSetDevicePut(lbl_80246B64->cpu, arg2, ramPutControl8, ramPutControl16, ramPutControl32,
                                        ramPutControl64) == 0) {
                        return 0;
                    }
                    if (cpuSetDeviceGet(lbl_80246B64->cpu, arg2, ramGetControl8, ramGetControl16, ramGetControl32,
                                        ramGetControl64) == 0) {
                        return 0;
                    }
                    break;
            }
        case 0:
        case 1:
        case 3:
        case 0x1003:
        case 0x1004:
        case 0x1007:
            break;
        default:
            return 0;
    }

    return 1;
}
