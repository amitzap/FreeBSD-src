/*
 * System call numbers.
 *
 * DO NOT EDIT-- this file is automatically @generated.
 * $FreeBSD$
 */

#define	IBCS2_SYS_syscall	0
#define	IBCS2_SYS_exit	1
#define	IBCS2_SYS_fork	2
#define	IBCS2_SYS_ibcs2_read	3
#define	IBCS2_SYS_write	4
#define	IBCS2_SYS_ibcs2_open	5
#define	IBCS2_SYS_close	6
#define	IBCS2_SYS_ibcs2_wait	7
#define	IBCS2_SYS_ibcs2_creat	8
#define	IBCS2_SYS_link	9
#define	IBCS2_SYS_ibcs2_unlink	10
#define	IBCS2_SYS_ibcs2_execv	11
#define	IBCS2_SYS_ibcs2_chdir	12
#define	IBCS2_SYS_ibcs2_time	13
#define	IBCS2_SYS_ibcs2_mknod	14
#define	IBCS2_SYS_ibcs2_chmod	15
#define	IBCS2_SYS_ibcs2_chown	16
#define	IBCS2_SYS_break	17
#define	IBCS2_SYS_ibcs2_stat	18
#define	IBCS2_SYS_ibcs2_lseek	19
#define	IBCS2_SYS_getpid	20
#define	IBCS2_SYS_ibcs2_mount	21
#define	IBCS2_SYS_ibcs2_umount	22
#define	IBCS2_SYS_ibcs2_setuid	23
#define	IBCS2_SYS_getuid	24
#define	IBCS2_SYS_ibcs2_stime	25
#define	IBCS2_SYS_ptrace	26
#define	IBCS2_SYS_ibcs2_alarm	27
#define	IBCS2_SYS_ibcs2_fstat	28
#define	IBCS2_SYS_ibcs2_pause	29
#define	IBCS2_SYS_ibcs2_utime	30
#define	IBCS2_SYS_ibcs2_access	33
#define	IBCS2_SYS_ibcs2_nice	34
#define	IBCS2_SYS_ibcs2_statfs	35
#define	IBCS2_SYS_sync	36
#define	IBCS2_SYS_ibcs2_kill	37
#define	IBCS2_SYS_ibcs2_fstatfs	38
#define	IBCS2_SYS_ibcs2_pgrpsys	39
#define	IBCS2_SYS_ibcs2_xenix	40
#define	IBCS2_SYS_dup	41
#define	IBCS2_SYS_pipe	42
#define	IBCS2_SYS_ibcs2_times	43
#define	IBCS2_SYS_profil	44
#define	IBCS2_SYS_ibcs2_plock	45
#define	IBCS2_SYS_ibcs2_setgid	46
#define	IBCS2_SYS_getgid	47
#define	IBCS2_SYS_ibcs2_sigsys	48
#define	IBCS2_SYS_ibcs2_msgsys	49
#define	IBCS2_SYS_ibcs2_sysi86	50
#define	IBCS2_SYS_ibcs2_shmsys	52
#define	IBCS2_SYS_ibcs2_semsys	53
#define	IBCS2_SYS_ibcs2_ioctl	54
#define	IBCS2_SYS_ibcs2_uadmin	55
#define	IBCS2_SYS_ibcs2_utssys	57
#define	IBCS2_SYS_fsync	58
#define	IBCS2_SYS_ibcs2_execve	59
#define	IBCS2_SYS_umask	60
#define	IBCS2_SYS_chroot	61
#define	IBCS2_SYS_ibcs2_fcntl	62
#define	IBCS2_SYS_ibcs2_ulimit	63
				/* 70 is obsolete rfs_advfs */
				/* 71 is obsolete rfs_unadvfs */
				/* 72 is obsolete rfs_rmount */
				/* 73 is obsolete rfs_rumount */
				/* 74 is obsolete rfs_rfstart */
				/* 75 is obsolete rfs_sigret */
				/* 76 is obsolete rfs_rdebug */
				/* 77 is obsolete rfs_rfstop */
#define	IBCS2_SYS_ibcs2_rmdir	79
#define	IBCS2_SYS_ibcs2_mkdir	80
#define	IBCS2_SYS_ibcs2_getdents	81
#define	IBCS2_SYS_ibcs2_sysfs	84
#define	IBCS2_SYS_ibcs2_getmsg	85
#define	IBCS2_SYS_ibcs2_putmsg	86
#define	IBCS2_SYS_poll	87
#define	IBCS2_SYS_ibcs2_secure	89
#define	IBCS2_SYS_ibcs2_symlink	90
#define	IBCS2_SYS_ibcs2_lstat	91
#define	IBCS2_SYS_ibcs2_readlink	92
#define	IBCS2_SYS_sigreturn	103
#define	IBCS2_SYS_ibcs2_isc	105
#define	IBCS2_SYS_MAXSYSCALL	128