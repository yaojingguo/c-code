
prog:     file format elf32-i386


Disassembly of section .init:

08048298 <_init>:
 8048298:	55                   	push   %ebp
 8048299:	89 e5                	mov    %esp,%ebp
 804829b:	53                   	push   %ebx
 804829c:	83 ec 04             	sub    $0x4,%esp
 804829f:	e8 00 00 00 00       	call   80482a4 <_init+0xc>
 80482a4:	5b                   	pop    %ebx
 80482a5:	81 c3 50 1d 00 00    	add    $0x1d50,%ebx
 80482ab:	8b 93 fc ff ff ff    	mov    -0x4(%ebx),%edx
 80482b1:	85 d2                	test   %edx,%edx
 80482b3:	74 05                	je     80482ba <_init+0x22>
 80482b5:	e8 1e 00 00 00       	call   80482d8 <__gmon_start__@plt>
 80482ba:	e8 d1 00 00 00       	call   8048390 <frame_dummy>
 80482bf:	e8 8c 01 00 00       	call   8048450 <__do_global_ctors_aux>
 80482c4:	58                   	pop    %eax
 80482c5:	5b                   	pop    %ebx
 80482c6:	c9                   	leave  
 80482c7:	c3                   	ret    

Disassembly of section .plt:

080482c8 <__gmon_start__@plt-0x10>:
 80482c8:	ff 35 f8 9f 04 08    	pushl  0x8049ff8
 80482ce:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80482d4:	00 00                	add    %al,(%eax)
	...

080482d8 <__gmon_start__@plt>:
 80482d8:	ff 25 00 a0 04 08    	jmp    *0x804a000
 80482de:	68 00 00 00 00       	push   $0x0
 80482e3:	e9 e0 ff ff ff       	jmp    80482c8 <_init+0x30>

080482e8 <__libc_start_main@plt>:
 80482e8:	ff 25 04 a0 04 08    	jmp    *0x804a004
 80482ee:	68 08 00 00 00       	push   $0x8
 80482f3:	e9 d0 ff ff ff       	jmp    80482c8 <_init+0x30>

Disassembly of section .text:

08048300 <_start>:
 8048300:	31 ed                	xor    %ebp,%ebp
 8048302:	5e                   	pop    %esi
 8048303:	89 e1                	mov    %esp,%ecx
 8048305:	83 e4 f0             	and    $0xfffffff0,%esp
 8048308:	50                   	push   %eax
 8048309:	54                   	push   %esp
 804830a:	52                   	push   %edx
 804830b:	68 e0 83 04 08       	push   $0x80483e0
 8048310:	68 f0 83 04 08       	push   $0x80483f0
 8048315:	51                   	push   %ecx
 8048316:	56                   	push   %esi
 8048317:	68 b4 83 04 08       	push   $0x80483b4
 804831c:	e8 c7 ff ff ff       	call   80482e8 <__libc_start_main@plt>
 8048321:	f4                   	hlt    
 8048322:	90                   	nop
 8048323:	90                   	nop
 8048324:	90                   	nop
 8048325:	90                   	nop
 8048326:	90                   	nop
 8048327:	90                   	nop
 8048328:	90                   	nop
 8048329:	90                   	nop
 804832a:	90                   	nop
 804832b:	90                   	nop
 804832c:	90                   	nop
 804832d:	90                   	nop
 804832e:	90                   	nop
 804832f:	90                   	nop

08048330 <__do_global_dtors_aux>:
 8048330:	55                   	push   %ebp
 8048331:	89 e5                	mov    %esp,%ebp
 8048333:	53                   	push   %ebx
 8048334:	83 ec 04             	sub    $0x4,%esp
 8048337:	80 3d 14 a0 04 08 00 	cmpb   $0x0,0x804a014
 804833e:	75 3f                	jne    804837f <__do_global_dtors_aux+0x4f>
 8048340:	a1 18 a0 04 08       	mov    0x804a018,%eax
 8048345:	bb 18 9f 04 08       	mov    $0x8049f18,%ebx
 804834a:	81 eb 14 9f 04 08    	sub    $0x8049f14,%ebx
 8048350:	c1 fb 02             	sar    $0x2,%ebx
 8048353:	83 eb 01             	sub    $0x1,%ebx
 8048356:	39 d8                	cmp    %ebx,%eax
 8048358:	73 1e                	jae    8048378 <__do_global_dtors_aux+0x48>
 804835a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048360:	83 c0 01             	add    $0x1,%eax
 8048363:	a3 18 a0 04 08       	mov    %eax,0x804a018
 8048368:	ff 14 85 14 9f 04 08 	call   *0x8049f14(,%eax,4)
 804836f:	a1 18 a0 04 08       	mov    0x804a018,%eax
 8048374:	39 d8                	cmp    %ebx,%eax
 8048376:	72 e8                	jb     8048360 <__do_global_dtors_aux+0x30>
 8048378:	c6 05 14 a0 04 08 01 	movb   $0x1,0x804a014
 804837f:	83 c4 04             	add    $0x4,%esp
 8048382:	5b                   	pop    %ebx
 8048383:	5d                   	pop    %ebp
 8048384:	c3                   	ret    
 8048385:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048389:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048390 <frame_dummy>:
 8048390:	55                   	push   %ebp
 8048391:	89 e5                	mov    %esp,%ebp
 8048393:	83 ec 18             	sub    $0x18,%esp
 8048396:	a1 1c 9f 04 08       	mov    0x8049f1c,%eax
 804839b:	85 c0                	test   %eax,%eax
 804839d:	74 12                	je     80483b1 <frame_dummy+0x21>
 804839f:	b8 00 00 00 00       	mov    $0x0,%eax
 80483a4:	85 c0                	test   %eax,%eax
 80483a6:	74 09                	je     80483b1 <frame_dummy+0x21>
 80483a8:	c7 04 24 1c 9f 04 08 	movl   $0x8049f1c,(%esp)
 80483af:	ff d0                	call   *%eax
 80483b1:	c9                   	leave  
 80483b2:	c3                   	ret    
 80483b3:	90                   	nop

080483b4 <main>:
 80483b4:	55                   	push   %ebp
 80483b5:	89 e5                	mov    %esp,%ebp
 80483b7:	83 e4 f0             	and    $0xfffffff0,%esp
 80483ba:	83 ec 10             	sub    $0x10,%esp
 80483bd:	a1 10 a0 04 08       	mov    0x804a010,%eax
 80483c2:	89 04 24             	mov    %eax,(%esp)
 80483c5:	e8 0a 00 00 00       	call   80483d4 <foo>
 80483ca:	b8 00 00 00 00       	mov    $0x0,%eax
 80483cf:	c9                   	leave  
 80483d0:	c3                   	ret    
 80483d1:	90                   	nop
 80483d2:	90                   	nop
 80483d3:	90                   	nop

080483d4 <foo>:
 80483d4:	55                   	push   %ebp
 80483d5:	89 e5                	mov    %esp,%ebp
 80483d7:	5d                   	pop    %ebp
 80483d8:	c3                   	ret    
 80483d9:	90                   	nop
 80483da:	90                   	nop
 80483db:	90                   	nop
 80483dc:	90                   	nop
 80483dd:	90                   	nop
 80483de:	90                   	nop
 80483df:	90                   	nop

080483e0 <__libc_csu_fini>:
 80483e0:	55                   	push   %ebp
 80483e1:	89 e5                	mov    %esp,%ebp
 80483e3:	5d                   	pop    %ebp
 80483e4:	c3                   	ret    
 80483e5:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 80483e9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080483f0 <__libc_csu_init>:
 80483f0:	55                   	push   %ebp
 80483f1:	89 e5                	mov    %esp,%ebp
 80483f3:	57                   	push   %edi
 80483f4:	56                   	push   %esi
 80483f5:	53                   	push   %ebx
 80483f6:	e8 4f 00 00 00       	call   804844a <__i686.get_pc_thunk.bx>
 80483fb:	81 c3 f9 1b 00 00    	add    $0x1bf9,%ebx
 8048401:	83 ec 1c             	sub    $0x1c,%esp
 8048404:	e8 8f fe ff ff       	call   8048298 <_init>
 8048409:	8d bb 18 ff ff ff    	lea    -0xe8(%ebx),%edi
 804840f:	8d 83 18 ff ff ff    	lea    -0xe8(%ebx),%eax
 8048415:	29 c7                	sub    %eax,%edi
 8048417:	c1 ff 02             	sar    $0x2,%edi
 804841a:	85 ff                	test   %edi,%edi
 804841c:	74 24                	je     8048442 <__libc_csu_init+0x52>
 804841e:	31 f6                	xor    %esi,%esi
 8048420:	8b 45 10             	mov    0x10(%ebp),%eax
 8048423:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048427:	8b 45 0c             	mov    0xc(%ebp),%eax
 804842a:	89 44 24 04          	mov    %eax,0x4(%esp)
 804842e:	8b 45 08             	mov    0x8(%ebp),%eax
 8048431:	89 04 24             	mov    %eax,(%esp)
 8048434:	ff 94 b3 18 ff ff ff 	call   *-0xe8(%ebx,%esi,4)
 804843b:	83 c6 01             	add    $0x1,%esi
 804843e:	39 fe                	cmp    %edi,%esi
 8048440:	72 de                	jb     8048420 <__libc_csu_init+0x30>
 8048442:	83 c4 1c             	add    $0x1c,%esp
 8048445:	5b                   	pop    %ebx
 8048446:	5e                   	pop    %esi
 8048447:	5f                   	pop    %edi
 8048448:	5d                   	pop    %ebp
 8048449:	c3                   	ret    

0804844a <__i686.get_pc_thunk.bx>:
 804844a:	8b 1c 24             	mov    (%esp),%ebx
 804844d:	c3                   	ret    
 804844e:	90                   	nop
 804844f:	90                   	nop

08048450 <__do_global_ctors_aux>:
 8048450:	55                   	push   %ebp
 8048451:	89 e5                	mov    %esp,%ebp
 8048453:	53                   	push   %ebx
 8048454:	83 ec 04             	sub    $0x4,%esp
 8048457:	a1 0c 9f 04 08       	mov    0x8049f0c,%eax
 804845c:	83 f8 ff             	cmp    $0xffffffff,%eax
 804845f:	74 13                	je     8048474 <__do_global_ctors_aux+0x24>
 8048461:	bb 0c 9f 04 08       	mov    $0x8049f0c,%ebx
 8048466:	66 90                	xchg   %ax,%ax
 8048468:	83 eb 04             	sub    $0x4,%ebx
 804846b:	ff d0                	call   *%eax
 804846d:	8b 03                	mov    (%ebx),%eax
 804846f:	83 f8 ff             	cmp    $0xffffffff,%eax
 8048472:	75 f4                	jne    8048468 <__do_global_ctors_aux+0x18>
 8048474:	83 c4 04             	add    $0x4,%esp
 8048477:	5b                   	pop    %ebx
 8048478:	5d                   	pop    %ebp
 8048479:	c3                   	ret    
 804847a:	90                   	nop
 804847b:	90                   	nop

Disassembly of section .fini:

0804847c <_fini>:
 804847c:	55                   	push   %ebp
 804847d:	89 e5                	mov    %esp,%ebp
 804847f:	53                   	push   %ebx
 8048480:	83 ec 04             	sub    $0x4,%esp
 8048483:	e8 00 00 00 00       	call   8048488 <_fini+0xc>
 8048488:	5b                   	pop    %ebx
 8048489:	81 c3 6c 1b 00 00    	add    $0x1b6c,%ebx
 804848f:	e8 9c fe ff ff       	call   8048330 <__do_global_dtors_aux>
 8048494:	59                   	pop    %ecx
 8048495:	5b                   	pop    %ebx
 8048496:	c9                   	leave  
 8048497:	c3                   	ret    
