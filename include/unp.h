#ifndef _UNP_HDR_H
#define _UNP_HDR_H

#include <sys/types.h>  /*Basic System Data types*/
#include <sys/socket.h> /*Basic Socket Definitions*/
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif
#endif
#include <errno.h>
#include <netinet/in.h>  /*sockaddr_in{} and other internet definitions*/
#include <arpa/inet.h>   /*inet(3) functions*/
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <netdb.h>
#include <stdio.h>
#include <signal.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/stat.h>

/*Max Text Line length*/
#define MAXLINE 4096

/*Buffer Size for read and write*/
#define BUFFSIZE 8192

/*Maximum number of Connection that can be queued*/
#define LISTENQ 1024

/*Following shortens all the typecasts of pointer arguments*/
#define SA struct sockaddr
/*Already Defined for this Platform 
#ifndef HAVE_STRUCT_SOCKADDR_STORAGE
#define __SS_MAXSIZE 128
#define __SS_ALIGNSIZE (sizeof(int64_t))
#ifdef HAVE_SOCKADDR_SA_LEN
#define __SS_PAD1SIZE (__SS_ALIGNSIZE-sizeof(u_char)-sizeof(sa_family_t))
#else
#define __SS_PAD1SIZE  (__SS_ALIGNSIZE-sizeof(sa_family_t))
#endif
#define __SS_PAD2SIZE (__SS_MAXSIZE-2*__SS_ALIGNSIZE)
struct sockaddr_storage{
#ifdef HAVE_SOCKADDR_SA_LEN
     u_char     ss_len;
#endif
     sa_family_t ss_family;
     char        __ss_pad1[__SS_PAD1SIZE];
     int64_t    __ss_align;
     char       __ss_pad2[__SS_PAD2SIZE]; 
};


#endif
*/
/*Deafult File access permissions for file*/
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*Default Permissions for new directory*/
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

/*Error Functions*/
void err_dump(const char *,...);
void err_msg(const char *,...);
void err_quit(const char *,...);
void err_ret(const char *,...);
void err_sys(const char *,...);  

/*Prototypes for Unix Wrapper functions*/


/*Prototypes for out stdio wrapper function*/
void Close(int);
void Write(int,void *,size_t);


/*Prototypes for socket Wrapper Function*/
int    Accept(int,SA*,socklen_t *);
void    Bind(int,const SA*,socklen_t);
void   Connect(int,const SA*,socklen_t);
void   Listen(int,int);
ssize_t Readline(int,void *,size_t);
ssize_t Readn(int,void *,size_t);
int    Socket(int,int,int);





#endif 
