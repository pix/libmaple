/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *****************************************************************************/

/**
 * @file systick.h
 *
 * @brief Various system timer definitions
 */

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "libmaple_types.h"
#include "util.h"

#ifdef __cplusplus
extern "C"{
#endif

/** SysTick register map type */
typedef struct systick_reg_map {
    __io uint32 CSR;            /**< Control and status register */
    __io uint32 RVR;            /**< Reload value register */
    __io uint32 CNT;            /**< Current value register ("count") */
    __io uint32 CVR;            /**< Calibration value register */
} systick_reg_map;

/** SysTick register map base pointer */
#define SYSTICK_BASE                    ((struct systick_reg_map*)0xE000E010)

/*
 * Register bit definitions.
 */

/* Control and status register */

#define SYSTICK_CSR_COUNTFLAG           BIT(16)
#define SYSTICK_CSR_CLKSOURCE           BIT(2)
#define SYSTICK_CSR_CLKSOURCE_EXTERNAL  0
#define SYSTICK_CSR_CLKSOURCE_CORE      BIT(2)
#define SYSTICK_CSR_TICKINT             BIT(1)
#define SYSTICK_CSR_TICKINT_PEND        BIT(1)
#define SYSTICK_CSR_TICKINT_NO_PEND     0
#define SYSTICK_CSR_ENABLE              BIT(0)
#define SYSTICK_CSR_ENABLE_MULTISHOT    BIT(0)
#define SYSTICK_CSR_ENABLE_DISABLED     0

/* Calibration value register */

#define SYSTICK_CVR_NOREF               BIT(31)
#define SYSTICK_CVR_SKEW                BIT(30)
#define SYSTICK_CVR_TENMS               0xFFFFFF

/** System elapsed time, in milliseconds */
extern volatile uint32 systick_uptime_millis;

static inline uint32 systick_uptime(void) {
    return systick_uptime_millis;
}

void systick_init(uint32 reload_val);
void systick_disable();
void systick_enable();

static inline uint32 systick_get_count(void) {
    return SYSTICK_BASE->CNT;
}

static inline uint32 systick_check_underflow(void) {
    return SYSTICK_BASE->CSR & SYSTICK_CSR_COUNTFLAG;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif

