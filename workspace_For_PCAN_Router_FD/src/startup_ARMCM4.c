/******************************************************************************
 * @file     startup_ARMCM4.c
 * @brief    CMSIS-Core(M) Device Startup File for a Cortex-M4 Device
 * @version  V2.0.0
 * @date     04. June 2019
 ******************************************************************************/
/*
 * Copyright (c) 2009-2019 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined (ARMCM4)
  #include "ARMCM4.h"
#elif defined (ARMCM4_FP)
  #include "ARMCM4_FP.h"
#else
  #error device not specified!
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler Function Prototype
 *----------------------------------------------------------------------------*/
typedef void( *pFunc )( void );

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;

extern __NO_RETURN void __PROGRAM_START(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
void __NO_RETURN Default_Handler(void);
void __NO_RETURN Reset_Handler  (void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void WDT_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void TIMER0_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIMER1_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIMER2_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIMER3_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void IntDefaultHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SSP0_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void SSP1_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void PLL0_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void EINT3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void BOD_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void I2S_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void ENET_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void MCI_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void MCPWM_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void PLL1_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void USBActivity_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void CANActivity_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void SSP2_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void LCD_IRQHandler         (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void EEPROM_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* added PEAK-System due to CAN firmware download */
extern int  __code_checksum;
#define USER_CODE_CHECKSUM (unsigned int) (&__code_checksum)

extern const pFunc __VECTOR_TABLE[];
       const pFunc __VECTOR_TABLE[] __VECTOR_TABLE_ATTRIBUTE = {
  (pFunc)(&__INITIAL_SP),                   /*     Initial Stack Pointer */
  Reset_Handler,                            /*     Reset Handler */
  NMI_Handler,                              /* -14 NMI Handler */
  HardFault_Handler,                        /* -13 Hard Fault Handler */
  MemManage_Handler,                        /* -12 MPU Fault Handler */
  BusFault_Handler,                         /* -11 Bus Fault Handler */
  UsageFault_Handler,                       /* -10 Usage Fault Handler */
  (pFunc)USER_CODE_CHECKSUM,                /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  SVC_Handler,                              /*  -5 SVCall Handler */
  DebugMon_Handler,                         /*  -4 Debug Monitor Handler */
  0,                                        /*     Reserved */
  PendSV_Handler,                           /*  -2 PendSV Handler */
  SysTick_Handler,                          /*  -1 SysTick Handler */

  /* Interrupts */
  WDT_IRQHandler,                     /* 16, 0x40 - WDT */
  TIMER0_IRQHandler,                  /* 17, 0x44 - TIMER0 */
  TIMER1_IRQHandler,                  /* 18, 0x48 - TIMER1 */
  TIMER2_IRQHandler,                  /* 19, 0x4c - TIMER2 */
  TIMER3_IRQHandler,                  /* 20, 0x50 - TIMER3 */
  UART0_IRQHandler,                   /* 21, 0x54 - UART0 */
  UART1_IRQHandler,                   /* 22, 0x58 - UART1 */
  UART2_IRQHandler,                   /* 23, 0x5c - UART2 */
  UART3_IRQHandler,                   /* 24, 0x60 - UART3 */
  PWM1_IRQHandler,                    /* 25, 0x64 - PWM1 */
  I2C0_IRQHandler,                    /* 26, 0x68 - I2C0 */
  I2C1_IRQHandler,                    /* 27, 0x6c - I2C1 */
  I2C2_IRQHandler,                    /* 28, 0x70 - I2C2 */
  IntDefaultHandler,                  /* 29, Not used */
  SSP0_IRQHandler,                    /* 30, 0x78 - SSP0 */
  SSP1_IRQHandler,                    /* 31, 0x7c - SSP1 */
  PLL0_IRQHandler,                    /* 32, 0x80 - PLL0 (Main PLL) */
  RTC_IRQHandler,                     /* 33, 0x84 - RTC */
  EINT0_IRQHandler,                   /* 34, 0x88 - EINT0 */
  EINT1_IRQHandler,                   /* 35, 0x8c - EINT1 */
  EINT2_IRQHandler,                   /* 36, 0x90 - EINT2 */
  EINT3_IRQHandler,                   /* 37, 0x94 - EINT3 */
  ADC_IRQHandler,                     /* 38, 0x98 - ADC */
  BOD_IRQHandler,                     /* 39, 0x9c - BOD */
  USB_IRQHandler,                     /* 40, 0xA0 - USB */
  CAN_IRQHandler,                     /* 41, 0xa4 - CAN */
  DMA_IRQHandler,                     /* 42, 0xa8 - GP DMA */
  I2S_IRQHandler,                     /* 43, 0xac - I2S */
  ENET_IRQHandler,                    /* 44, 0xb0 - Ethernet */
  MCI_IRQHandler,                     /* 45, 0xb4 - SD/MMC card I/F */
  MCPWM_IRQHandler,                   /* 46, 0xb8 - Motor Control PWM */
  QEI_IRQHandler,                     /* 47, 0xbc - Quadrature Encoder */
  PLL1_IRQHandler,                    /* 48, 0xc0 - PLL1 (USB PLL) */
  USBActivity_IRQHandler,             /* 49, 0xc4 - USB Activity interrupt to wakeup */
  CANActivity_IRQHandler,             /* 50, 0xc8 - CAN Activity interrupt to wakeup */
  UART4_IRQHandler,                   /* 51, 0xcc - UART4 */
  SSP2_IRQHandler,                    /* 52, 0xd0 - SSP2 */
  LCD_IRQHandler,                     /* 53, 0xd4 - LCD */
  GPIO_IRQHandler,                    /* 54, 0xd8 - GPIO */
  PWM0_IRQHandler,                    /* 55, 0xdc - PWM0 */
  EEPROM_IRQHandler,                  /* 56, 0xe0 - EEPROM */
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
  __set_MSP ( (unsigned int)&__INITIAL_SP); /* added PEAK-System due to CAN bootloader */

  SystemInit();                             /* CMSIS System Initialization */
  __PROGRAM_START();                        /* Enter PreMain (C library entry point) */
}

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}
