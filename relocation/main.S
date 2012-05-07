
main.o:     file format elf32-i386


Disassembly of section .text:

00000000 <main>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	83 e4 f0             	and    $0xfffffff0,%esp
   6:	83 ec 10             	sub    $0x10,%esp
   9:	a1 00 00 00 00       	mov    0x0,%eax
   e:	89 04 24             	mov    %eax,(%esp)
  11:	e8 fc ff ff ff       	call   12 <main+0x12>
  16:	b8 00 00 00 00       	mov    $0x0,%eax
  1b:	c9                   	leave  
  1c:	c3                   	ret    
