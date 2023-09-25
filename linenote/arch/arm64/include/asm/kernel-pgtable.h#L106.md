# SWAPPER_PTE_FLAGS

This is a macro definition that specifies a set of flags or attributes for a
Page Table Entry (PTE). In ARM64 architecture, a PTE is used to manage the
translation from virtual memory addresses to physical memory addresses.

To see the detail of each flag, see
[[https://developer.arm.com/documentation/102376/0100/Describing-memory-in-AArch64.]].

- `PTE_TYPE_PAGE`
- `PTE_AF`: Access Flag
- `PTE_SHARED`: represents that this memory page is shared among multiple
  processes or entities.
- `PTE_UXN`: Execution permissions

## AF (Access Flag)

- [[https://developer.arm.com/documentation/102376/0100/Access-Flag]]

Access Flag (AF) bit to track whether a region covered by the translation table
entry has been accessed.

- AF=0, Region not accessed.
- AF=1, Region accessed.

The AF bit is useful for operation systems, because you can use it to identify
which pages are not currently being used and could be paged-out (removed from
RAM).