/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Based on arch/arm/include/asm/page.h
 *
 * Copyright (C) 1995-2003 Russell King
 * Copyright (C) 2017 ARM Ltd.
 */
#ifndef __ASM_PAGE_DEF_H
#define __ASM_PAGE_DEF_H

#include <linux/const.h>

/* PAGE_SHIFT determines the page size */

/*
 * CONFIG_ARM64_PAGE_SHIFT 기본 값은 12 (4K PAGE_SIZE) 이다.
 * 즉, PAGE_MASK 또한 0xFFFF FFFF FFFF F000으로 된다.
 */
#define PAGE_SHIFT		CONFIG_ARM64_PAGE_SHIFT
#define PAGE_SIZE		(_AC(1, UL) << PAGE_SHIFT)
#define PAGE_MASK		(~(PAGE_SIZE-1))

#endif /* __ASM_PAGE_DEF_H */
