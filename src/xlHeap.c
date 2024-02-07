#include "types.h"

void OSSetMEM1ArenaLo(void*);
void OSSetMEM2ArenaLo(void*);
void* lbl_80246D50[2];

s32 xlHeapReset(void) {
    OSSetMEM1ArenaLo(lbl_80246D50[0]);
    OSSetMEM2ArenaLo(lbl_80246D50[1]);
    return 1;
}
