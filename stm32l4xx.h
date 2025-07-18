#ifndef STM32L4XX_H
#define STM32L4XX_H

#include <stdint.h>

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_TypeDef;

typedef struct {
    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

#define PERIPH_BASE 0x40000000U
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000U)

#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800U)

#define RCC_BASE (PERIPH_BASE + 0x00021000U)

#ifdef GPIO_TEST
extern GPIO_TypeDef gpioa_mock;
extern GPIO_TypeDef gpiob_mock;
extern GPIO_TypeDef gpioc_mock;
extern RCC_TypeDef rcc_mock;
#define GPIOA (&gpioa_mock)
#define GPIOB (&gpiob_mock)
#define GPIOC (&gpioc_mock)
#define RCC (&rcc_mock)
#else
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define RCC   ((RCC_TypeDef *)RCC_BASE)
#endif

#define RCC_AHB1ENR_GPIOAEN (1U << 0)
#define RCC_AHB1ENR_GPIOBEN (1U << 1)
#define RCC_AHB1ENR_GPIOCEN (1U << 2)

#endif
