/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * XILINX CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xaxidma.h"
#include "xparameters.h"
#include "xdebug.h"
#include "xdijkstra.h"
#include "config.h"
#include "graph1.h"
#include "xtime_l.h"

int DMAConfig(void);
int DijkstraConfig(void);
void DijkstraCalculate(void);
void FillBuffer(uint8_t g[N][N]);
void PrintResult(void);
void SoftDijkstraCalculate(void);
void SoftDijkstra2Calculate(void);
int CheckResult(uint8_t a[N],uint8_t b[N]);

XAxiDma AxiDma;
XDijkstra Dijkstra;

u8 *TxBufferPtr = TX_BUFFER_BASE;
u8 *RxBufferPtr = RX_BUFFER_BASE;

const uint8_t START_POINT = 0;

XTime StartTime;
XTime StopTime;
XTime StartSoftTime;
XTime StopSoftTime;

int main()
{
	init_platform();
	if (DMAConfig() == XST_FAILURE)
	{
		while (1)
		{
		}
	}
	if (DijkstraConfig() == XST_FAILURE)
	{
		while (1)
		{
		}
	}
	InitGraph1();
	FillBuffer(graph1);
	XTime_GetTime(&StartTime);
	DijkstraCalculate();
	XTime_GetTime(&StopTime);
	XTime_GetTime(&StartSoftTime);
	SoftDijkstraCalculate();
	//SoftDijkstra2Calculate();
	XTime_GetTime(&StopSoftTime);
	PrintResult();
	if(CheckResult(RxBufferPtr,graph1_res) == XST_SUCCESS)
	{
		printf("\nResult ok.");
	}else
	{
		printf("\nResult failure!");
	}
	printf("\nFinish.");
	while(1){}
	cleanup_platform();
	return 0;
}

int CheckResult(uint8_t a[N],uint8_t b[N])
{
	int i;
	for(i = 0; i < N;i++)
	{
		if(a[i] != b[i])
		{
			return XST_FAILURE;
		}
	}
	return XST_SUCCESS;
}

void FillBuffer(uint8_t g[N][N])
{
	int i, e;
	for (i = 0; i < N; i++)
	{
		for (e = 0; e < N; e++)
		{
			TxBufferPtr[i * N + e] = g[i][e];
		}
	}
	Xil_DCacheFlushRange((u32) TxBufferPtr, N * N);
}
void PrintResult(void)
{
	int i;
	Xil_DCacheInvalidateRange((u32)RxBufferPtr, 32);
	for(i = 0 ;i < N;i++)
	{
		printf("%d:%d\n",i,RxBufferPtr[i]);
	}
	XTime temp = ((StopTime-StartTime)*1000000000)/COUNTS_PER_SECOND;
	printf("\nExecution time:%llu ns",(unsigned long long)(temp));
	temp = ((StopSoftTime-StartSoftTime)*1000000000)/COUNTS_PER_SECOND;
	printf("\nSoft Execution time:%llu ns",(unsigned long long)(temp));
}
void SoftDijkstraCalculate(void)
{
	//void alg(char tab[N+1][N+1], char prev[N+1]) {
	uint8_t (*tab)[N] = graph1;
	int i, j;
	int p = 1;
	char list[N];
	char prev[N];

	for(i = 0; i < N; i++)
	{
		list[i] = 0;
	}
	list[0] = 1;

	for (i = 0; i < N; i++)
	{
		if (list[i] == 1)
		{
			for (j = 0; j < N; j++)
			{
				if (tab[i][j] > 0)
				{
					if (prev[j] == 0)
						prev[j] = i;

					if (list[j] == 0)
						list[j] = 1;

					if (tab[p][j] == 0)
					{
						tab[p][j] = tab[p][i] + tab[i][j];
					}
					else
					{
						if (tab[p][j] > tab[p][i] + tab[i][j])
						{
							tab[p][j] = tab[p][i] + tab[i][j];
							prev[j] = i;
						}
					}
				}
			}
			list[i] = 2;
		}
	}
}
void SoftDijkstra2Calculate(void)
{
	//void alg(char tab[N+1][N+1], char prev[N+1]) {
	uint8_t (*tab)[N] = graph1;
	static char vector[N];
	static unsigned char copy[N][N];
	static unsigned char result[N];
	int i,e;


	for(i = 0; i < N;i++)
	{
			vector[i] = 0;
	}
	vector[1]=1;

	for(i = 0; i < N;i++)
	{
		for(e = 0;e < N ;e++)
		{
			copy[i][e] = tab[i][e];
		}
	}

	while(1)
	{
		for(i = 0; i < N;i++)
		{
			if(vector[i] == 1)
			{
				for( e = 0; e < N;e++)
				{
					copy[e][i]=255;
				}
			}
		}
	//	print_table(tab);
		//znajdz minimum
		int min = 255;
		for(i = 0; i < N;i++)//skacze po wierszach
		{

			if(vector[i] == 1)
			{
				for(e = 0; e < N;e++)
				{

					if(copy[i][e]  < min)
					{
						min = copy[i][e];
					}

				}
			}
		}

		//teraz odejmij minimalna wartosc
		//dla wszystkiech elementow wiersza
		//dla wierszy gdzie vector == 1
		for(i = 0; i < N;i++)//skacze po wierszach
		{
			if(vector[i] == 1)
			{
				//szuka minimum
				for(e = 0; e < N;e++)
				{
					copy[i][e] -= min;
				}
			}
		}

		for(i = 0; i < N;i++)//skacze po wierszach
			{
				if(vector[i] == 1)
				{
					//szuka minimum
					for(e = 0; e < N;e++)
					{

						if(copy[i][e] == 0)
						{
								vector[e]=1;
								result[e] = i;
						}

					}
				}
			}


		//jesli wszystkie elementy wektora == 1
		//to koniec
		uint8_t end = 1;
		for(i = 0; i < N;i++)
		{
			if(vector[i] != 1)
			{
				end = 0;
			}
		}
		if(end) break;

	}

}
void DijkstraCalculate(void)
{
	int Status;
	XDijkstra_Set_start_point_V(&Dijkstra, START_POINT);
	XDijkstra_Start(&Dijkstra);

	Status = XAxiDma_SimpleTransfer(&AxiDma, (u32) TxBufferPtr,
	N * N, XAXIDMA_DMA_TO_DEVICE);

	if (Status != XST_SUCCESS)
	{
		while (1)
		{
		}
	}

	while ((XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE)))
	{
		/* Wait */
	}

	Status = XAxiDma_SimpleTransfer(&AxiDma, (u32) RxBufferPtr, N,
	XAXIDMA_DEVICE_TO_DMA);

	if (Status != XST_SUCCESS)
	{
		while (1)
		{
		}
	}

	while ((XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA)))
	{
		/* Wait */
	}

	while (XDijkstra_IsDone(&Dijkstra) == 0)
	{
	}
}
int DijkstraConfig(void)
{
	if (XDijkstra_Initialize(&Dijkstra,
	XPAR_DIJKSTRA_1_DEVICE_ID) == XST_DEVICE_NOT_FOUND)
	{
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

int DMAConfig(void)
{
	int Status;
	XAxiDma_Config *CfgPtr;
	CfgPtr = XAxiDma_LookupConfig(XPAR_AXI_DMA_0_DEVICE_ID);
	if (!CfgPtr)
	{
		xil_printf("No config found for %d\r\n", XPAR_AXI_DMA_0_DEVICE_ID);
		return XST_FAILURE;
	}

	Status = XAxiDma_CfgInitialize(&AxiDma, CfgPtr);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Initialization failed %d\r\n", Status);
		return XST_FAILURE;
	}

	if (XAxiDma_HasSg(&AxiDma))
	{
		xil_printf("Device configured as SG mode \r\n");
		return XST_FAILURE;
	}

	/* Disable interrupts, we use polling mode
	 */
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

	return XST_SUCCESS;
}
