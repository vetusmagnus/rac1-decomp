#include "common.h"
#include "callees.h"
#include "structs.h"

/*
 * core_text object 0x122818-0x122AD8. Boundaries are retail's linker fill
 * (0xCDCDCDCD) between objects; see docs/DECOMP_PROGRESS.md.
 *
 * Sony's libgraph: graph016.o (sceGsSetDefStoreImage) and graph017.o
 * (sceGsExecLoadImage), back to back. Built with Sony's 2.9-ee
 * (Makefile.sn, EE29_CORE), like the prebuilt libgraph.a.
 */

/* Declarations in scope here before the split. */
extern long func_00116F68(int arg0, int arg1, int arg2);
extern int D_0015ED10;
extern void *D_0012F86C NOT_SDA;
extern int func_001162B8(void *arg0, void *arg1, void *arg2);
extern int func_00116320(void *arg0, void *arg1, void *arg2);
extern long func_001163A0(void *arg0, void *arg1, void *arg2);
extern void func_00116408(void *arg0);
extern void func_00113968(void);
extern void func_00114438(void *, void *);
extern char D_00152470[];
extern int func_00119088();
extern long func_00116108_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00116108");
extern long func_001188C8_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_001188C8");
extern long func_00114518_wide(int *errOut, void *a, void *b, void *c)
    __asm__("func_00114518");
extern int func_00112468(int *errOut, int arg1);
extern int func_00114060(int, void *);
extern void func_00113AE0(void *);
extern void func_00117118(void *, void *, int, int);
extern int func_00119008();
extern int D_0012FCF0 NOT_SDA;
extern void func_00118E90(int arg0, void *arg1);
extern void *D_00154A40 NOT_SDA;
extern int D_00155080[];
extern void func_001193F8(int);
extern void func_00118AD0(int, int);
extern int D_00154F54;
extern int D_0012FD04;
extern int D_00154F64 NOT_SDA;
extern int D_00154F6C NOT_SDA;
extern void func_0011AA90(int, int, int, int, int, int, int);
extern void func_0011AA00(void);
extern int D_0012FD08 NOT_SDA;
extern int func_0011D960(void);
extern void func_0011D9A8(void);
extern int func_00118C70(void *);
extern int D_0012FDA0;
extern int D_0012FDA4;
extern char D_00157E80[];
extern int D_0012FD9C;
extern void func_0011BBF0(void);
extern int D_0012FD9C NOT_SDA;
extern char D_0012FCEC[];
extern char D_001580A8[];
extern int D_0012FDA8;
extern void func_001153FC(void *, int, int);
extern int D_0012FD94;
extern int D_0012FDAC;
extern char D_00158140[];
extern int D_00158180;
extern int D_001581C0;
extern char D_00158528[];
extern int D_0012FDB4;
extern int func_0011CE70(int arg0, int arg1, int arg2, void *arg3);
extern void func_00118EC0(void);
extern void func_0011D4E0(void);
extern void func_00118EB0(void);
extern int D_00130420;
extern int D_00130424;
extern int D_00130BD0[];
extern char D_00130428[];
extern int func_0011DC50(void);
extern void func_00118D80(int);
extern int func_00120F30(int);
extern void *D_00159840;
extern int D_001313E0;
extern int D_001313E8;
extern int D_001313EC;
extern int D_001313F0;
extern int D_001313E4;
extern int D_001313FC;
extern int func_0011B4C8();
extern int func_00120D28(int);
extern void func_00118C90(int);
extern char D_00132590[];
extern int D_00131440;
extern void func_0011A6C8();
extern int func_0011B6B8(void *);
extern char D_00153000[];
extern char D_00132E08[];
extern int D_001313D0;
extern int func_00121040(int);
extern int D_001325C0;
extern char D_00132E40[];

typedef int u128 __attribute__((mode(TI)));

typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long pad16 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs1 : 4;
    unsigned long regs2 : 4;
    unsigned long regs3 : 4;
    unsigned long regs4 : 4;
    unsigned long regs5 : 4;
    unsigned long regs6 : 4;
    unsigned long regs7 : 4;
    unsigned long regs8 : 4;
    unsigned long regs9 : 4;
    unsigned long regs10 : 4;
    unsigned long regs11 : 4;
    unsigned long regs12 : 4;
    unsigned long regs13 : 4;
    unsigned long regs14 : 4;
    unsigned long regs15 : 4;
} GifTag_122818;

typedef struct {
    unsigned int w0, w4, w8, wC;
    GifTag_122818 giftag;
    long bitbltbuf, bitbltbufaddr;
    long trxpos, trxposaddr;
    long trxreg, trxregaddr;
    long finish, finishaddr;
    long trxdir, trxdiraddr;
} StoreImage_122818;

/* Fills a GS store-image packet: DMA/VIF words, a 5-register A+D giftag, then BITBLTBUF/TRXPOS/TRXREG/FINISH/TRXDIR; returns 7. */
int func_00122818_r(StoreImage_122818 *p, short sbp, short sbw, short spsm,
                    short x, short y, short w, short h) __asm__("func_00122818");
int func_00122818_r(StoreImage_122818 *p, short sbp, short sbw, short spsm,
                    short x, short y, short w, short h) {
    long t = (long)(y << 16);
    p->w0 = 0;
    p->w4 = 0x06008000;
    p->w8 = 0x13000000;
    p->wC = 0x50000006;
    *(u128 *)&p->giftag = 0;
    p->giftag.nloop = 5;
    p->giftag.eop = 1;
    p->giftag.nreg = 1;
    p->giftag.regs0 = 0xE;
    p->bitbltbuf = (long)sbp | (long)(sbw << 16) | ((long)spsm << 24);
    p->bitbltbufaddr = 0x50;
    p->trxpos = (long)x | t;
    p->trxposaddr = 0x51;
    p->trxreg = (long)w | ((long)h << 32);
    p->trxregaddr = 0x52;
    p->finish = 0;
    p->finishaddr = 0x61;
    p->trxdir = 1;
    p->trxdiraddr = 0x53;
    __asm__ __volatile__("sync");
    return 7;
}

extern void func_0011A6C8(void *);
extern char D_001532D0[];

typedef struct {
    long q[12];
} GsLoadImage;

/* sceGsExecLoadImage(src, dst): waits for the GS transfer unit
 * (0x1000A000 bit 8) to go idle, starts an image load from src (its
 * 0x70000000 scratchpad segment tagged with bit 31) sized by the 15-bit
 * field in src->q[10], waits again and starts the transfer to dst.
 * Returns -1 after 0x1000000 polls in total. The abort is written out in
 * each loop, not shared through a goto: the compiler merges the two copies
 * into retail's single call, where a shared label needs an extra branch. */
int func_00122958(GsLoadImage *src, void *dst) {
    unsigned int count = 0;

    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (count++ > 0x1000000) {
            func_0011A6C8(D_001532D0);
            return -1;
        }
    }

    *(volatile unsigned int *)0x1000A020 = 6;
    if (((unsigned int)src & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)src & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = (unsigned int)src & 0x0FFFFFFF;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;

    while (*(volatile unsigned int *)0x1000A000 & 0x100) {
        if (count++ > 0x1000000) {
            func_0011A6C8(D_001532D0);
            return -1;
        }
    }

    *(volatile unsigned int *)0x1000A020 = (unsigned int)(int)(src->q[10] & 0x7FFF);
    if (((unsigned int)dst & 0x70000000) == 0x70000000) {
        *(volatile unsigned int *)0x1000A010 = ((unsigned int)dst & 0x0FFFFFFF) | 0x80000000;
    } else {
        *(volatile unsigned int *)0x1000A010 = (unsigned int)dst & 0x0FFFFFFF;
    }
    *(volatile unsigned int *)0x1000A000 = 0x101;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/core_text", func_00122AD4);
