# swapper_pg_dir

`swapper page table` is used as the kernel page table after regular mapping is possible. The table is read-only for the security.

There is also another page table named `init_pg_dir`. At first, only
`swapper_pg_dir` was used, but due to the security reason, `init_pg_dir` is used
during the initial boot process, then, `swapper_pg_dir` is used as read-only
page directory.

## Reference

- http://jake.dothome.co.kr/head-64-60/