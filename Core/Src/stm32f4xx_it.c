/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
__attribute__((naked)) void DebugMon_Handler(void)
{
  __asm volatile (
      "tst lr, #4            \n"   // بررسی اینکه استک PSP یا MSP هست
      "ite eq                \n"
      "mrseq r0, msp         \n"   // اگر MSP بود
      "mrsne r0, psp         \n"   // اگر PSP بود
      "b debug_monitor_handler_c \n"
  );
}

/* USER CODE BEGIN 0 */
typedef struct __attribute__((packed)) {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t return_address;
    uint32_t xpsr;
} ContextStateFrame;

// اگر CMSIS این بیت‌ها رو نداشت، خودمون تعریف می‌کنیم
#ifndef CoreDebug_DEMCR_MON_STEP_Msk
#define CoreDebug_DEMCR_MON_STEP_Pos   18U
#define CoreDebug_DEMCR_MON_STEP_Msk   (1UL << CoreDebug_DEMCR_MON_STEP_Pos)
#endif

void debug_monitor_handler_c(ContextStateFrame *frame) {
    uint32_t dfsr = SCB->DFSR;

    const uint32_t dfsr_halt_bit = (1UL << 0);
    const uint32_t dfsr_bkpt_bit = (1UL << 1);
    const uint32_t dfsr_dwt_bit  = (1UL << 2);

    bool is_halt = (dfsr & dfsr_halt_bit) != 0;
    bool is_bkpt = (dfsr & dfsr_bkpt_bit) != 0;
    bool is_dwt  = (dfsr & dfsr_dwt_bit)  != 0;

    // پاک کردن بیت‌ها
    SCB->DFSR = dfsr_halt_bit | dfsr_bkpt_bit | dfsr_dwt_bit;

    // چاپ وضعیت رجیسترها روی UART (از printf استفاده می‌کنه)
    printf("=== DebugMonitor exception ===\r\n");
    printf("r0   = 0x%08lx\r\n", frame->r0);
    printf("r1   = 0x%08lx\r\n", frame->r1);
    printf("r2   = 0x%08lx\r\n", frame->r2);
    printf("r3   = 0x%08lx\r\n", frame->r3);
    printf("r12  = 0x%08lx\r\n", frame->r12);
    printf("lr   = 0x%08lx\r\n", frame->lr);
    printf("pc   = 0x%08lx\r\n", frame->return_address);
    printf("xpsr = 0x%08lx\r\n", frame->xpsr);

    // رفتار بر اساس نوع exception
    if (is_bkpt) {
    	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_4);
        // عبور از دستور bkpt (۲ بایت)
        frame->return_address += 2;
        // فعال کردن single-step
        CoreDebug->DEMCR |= CoreDebug_DEMCR_MON_STEP_Msk;
    } else if (is_halt) {
        // غیر فعال کردن single-step
        CoreDebug->DEMCR &= ~CoreDebug_DEMCR_MON_STEP_Msk;
    }
}
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
//void DebugMon_Handler(void)
//{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
//}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
