# init_pg_dir

The symbol is defined at `arch/arm64/kernel/vmlinux.lds.S`.

```asm
. = ALIGN(PAGE_SIZE);
init_pg_dir = .;
. += INIT_DIR_SIZE;
init_pg_end = .;
```

`INIT_DIR_SIZE` is defined at `arch/arm64/include/asm/kernel-pgtable.h`.

```c
#define INIT_DIR_SIZE (PAGE_SIZE * EARLY_PAGES(KIMAGE_VADDR, _end))
```

Let's look into the each macro definition.

- PAGE_SIZE: 4096
- EARLY_PAGES
- KIMAGE_VADR
- _end

## PAGE_SIZE

In `arch/arm64/include/asm/page-def.h`, `PAGE_SIZE` is defined. So the PAGE_SIZE
is going to be `1 << 12 (4096)`.

```c
#define PAGE_SHIFT CONFIG_ARM64_PAGE_SHIFT // default: 12
#define PAGE_SIZE (_AC(1, UL) << PAGE_SHIFT)
```

Here, `_AC` macro is used. About this usage, there is already a comment like
below:

```c
/* Some constant macros are used in both assembler and
 * C code.  Therefore we cannot annotate them always with
 * 'UL' and other type specifiers unilaterally.  We
 * use the following macros to deal with this.
 *
 * Similarly, _AT() will cast an expression with a type in C, but
 * leave it unchanged in asm.
 */
```

## EARLY_PAGES

This is the size of early pages. This consists of early-staged pgdir, PGD, PUD,
and PMD.

```c
#define EARLY_PAGES(vstart, vend) ( 1 			/* PGDIR page */				\
+ EARLY_PGDS((vstart), (vend)) 	/* each PGDIR needs a next level page table */	\
+ EARLY_PUDS((vstart), (vend))	/* each PUD needs a next level page table */	\
+ EARLY_PMDS((vstart), (vend)))	/* each PMD needs a next level page table */
```