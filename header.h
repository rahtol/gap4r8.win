void __assert_func, (const char *file, int line, const char *s, const char *condition);
int *__errno (void);
struct _reent *__getreent, (void);
___gmp_bits_per_limb
___gmp_snprintf
___gmpn_add
___gmpn_add_1
___gmpn_cmp
___gmpn_divrem_1
___gmpn_gcd
___gmpn_gcd_1
___gmpn_get_str
___gmpn_lshift
___gmpn_mod_1
___gmpn_mul
___gmpn_mul_1
___gmpn_mul_n
___gmpn_rshift
___gmpn_set_str
___gmpn_sub
___gmpn_sub_1
___gmpn_sub_n
___gmpn_tdiv_qr
__imp____ctype_ptr__
int	access (const char *__path, int __amode);
int chdir (const char *__path);
int chmod (const char *__path, mode_t __mode);
int close (int __fildes);
int closedir (DIR *);
char *dlerror (void);
void *dlopen (const char *, int);
int dlclose (void *);
int dup (int __fildes);
int dup2 (int __fildes, int __fildes2);
char **environ;
int execv (const char *__path, char * const __argv[]);
double exp10 (double);
pid_t fork (void);
pid_t getpid (void);
int getrusage (int __who, struct rusage *__rusage);
int gettimeofday (struct timeval *__restrict __p, void *__restrict __tz);
int __cdecl ioctl (int __fd, int __cmd, ...);
int isatty (int __fildes);
int kill (pid_t, int);
off_t lseek (int __fildes, off_t __offset, int __whence);
int lstat (const char *__restrict __path, struct stat *__restrict __buf);
int madvise (void *__addr, size_t __len, int __advice);
int mkdir (const char *_path, mode_t __mode);
char *mkdtemp (char *);
int mkstemp (char *);
void *mmap (void *__addr, size_t __len, int __prot, int __flags, int __fd, off_t __off);
int munmap (void *__addr, size_t __len);
_open
DIR *opendir (const char *);
_openpty
_pclose
_popen
_printf
_read
_readdir
_realpath
_rmdir
_sbrk
_select
_setpgid
int sigaction (int, const struct sigaction *, struct sigaction *);
int sigemptyset (sigset_t *);
_siginterrupt
_sleep
_snprintf
_spawnve
_stat
_strlcat
_strlcpy
_sysconf
_tcgetattr
_tcsetattr
_timer_create
_timer_settime
_times
_ttyname
_unlink
_waitpid
_write

