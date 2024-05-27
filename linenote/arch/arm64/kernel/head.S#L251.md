# Identity Mapping

`idmap (Identity Mapping)` is used to enable MMU. After turning on MMU, then, linear mapping can be used.

- idmap: physical address == virtual address
- linear mapping: physical address + offset == virtual address

# Purpose

During the initial stages of booting, the CPU starts in a simple mode without full virtual memory support. To facilitate early boot operations, the kernel sets up identity mappings for critical regions of memory. This allows the code to run with minimal address translation, simplifying access to memory.

# Multiple Uses

실제로 head.S 에서 .section ".idmap.text", "a" statement는 여러번 사용된다. 이러한 방식은 Code Grouping, Maintaining Context, Organizational Structure 의 이유 등으로 사용된다.
