#ifndef _CPM_SYSFUNC_HEADER_
#define _CPM_SYSFUNC_HEADER_

#include "common_datatypes.h"

typedef struct {
	uint8_t drive;
	char filename[8];
	char filetype[3];
	uint8_t ex;
	uint8_t s1;
	uint8_t s2;
	uint8_t rc;
	uint8_t al[16];
	uint8_t cr;
	uint8_t r0;
	uint8_t r1;
	uint8_t r2;
} FCB; /* File Control Block */

void cpm_sysfunc_init(void);

char *cpm_gets(char *p);
char cpm_getchar(void);
void cpm_putchar(char c);

uint8_t cpm_openFile(FCB *cb);
uint8_t cpm_closeFile(FCB *cb);

uint8_t cpm_makeFile(FCB *cb);
uint8_t cpm_deleteFile(FCB *cb);
uint8_t cpm_setFileAttribs(FCB *cb);

uint8_t cpm_readSeqRecord(FCB *cb);
uint8_t cpm_writeSeqRecord(FCB *cb);
uint8_t cpm_readRandRecord(FCB *cb);
uint8_t cpm_writeRandRecord(FCB *cb);
void cpm_updateRandRecPtr(FCB *cb);
uint8_t cpm_computeFileSize(FCB *cb);

void cpm_setDMAAddr(uint16_t addr);

uint8_t cpm_getCurDrive(void);
uint8_t cpm_setCurDrive(uint8_t drive);
uint8_t cpm_resetDrives(void);

#endif /* _CPM_SYSFUNC_HEADER_ */
