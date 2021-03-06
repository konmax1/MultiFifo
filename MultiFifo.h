//
#pragma once


#include "cmsis_os2.h"                  // ::CMSIS:RTOS2




class MultiFifo {
	private:
		osMessageQueueAttr_t attr;	
		osMessageQueueId_t adc_buf;
		osMemoryPoolId_t memory;
		int32_t bufsize;
		int32_t bufnumber;	
		int32_t reloadParam(int32_t internal = 1);
	public:
		MultiFifo(char* _name);
		~MultiFifo();
		MultiFifo(int32_t _bufsize, int32_t _bufnumber,char* _name = "Queue");
		void init(int32_t internal = 1);
		void setBufSize(int32_t val, int32_t internal = 1);
		int32_t getBufSize();
		void setBufNumber(int32_t val, int32_t internal = 1);
		int32_t getBufNumber();	
		int32_t getCurrentSize();
		void fillFifo();
	
		uint32_t getBuf(uint32_t timeout = osWaitForever);	
		void putBuf(uint32_t addr);
		void putBuf();	
		void freeBlock(uint32_t addr);
};

