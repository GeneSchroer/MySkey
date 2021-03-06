/*
 * S/KEY v1.1b (skey.h)
 *
 * Authors:
 *          Neil M. Haller <nmh@thumper.bellcore.com>
 *          Philip R. Karn <karn@chicago.qualcomm.com>
 *          John S. Walden <jsw@thumper.bellcore.com>
 *
 * Modifications:
 *          Scott Chasin <chasin@crimelab.com>
 *
 * Main client header
 */




#include <stdio.h>
#include <ctype.h>
#include "config.h"

#ifdef HAVE_STD_LIB
#include <stdlib.h>
#endif


#ifdef HAVE_UNISTD
#include <unistd.h>
#endif


#ifdef HAVE_SYS_TYPES
#include <sys/types.h>
#endif


#ifdef HAVE_GRP
#include <grp.h>
#endif

/*#ifdef HAVE_STD_LIB

#include <string.h>
#include <signal.h>


#ifdef stty
# undef stty
#endif
 
#ifdef gtty
# undef gtty
#endif



# ifdef HAVE_TERMIO
# include <termio.h>
# define TTYSTRUCT termio
# else
	# ifdef HAVE_TERMIOS
	# include <termios.h>
	# define TTYSTRUCT termio
	# else
	# include <sgtty.h>
	# define TTYSTRUCT sgttyb
	# endif
# endif

#ifdef TCSETA
#define SET_PARAM TCSETA
#endif
#ifdef TCGETA
#define GET_PARAM TCGETA
#endif

#ifndef SET_PARAM
	#ifdef TIOCSETN
	#define SET_PARAM TIOCSETN
	#endif
#endif
*/




#if	defined(__TURBOC__) || defined(__STDC__) || defined(LATTICE)
#define	ANSIPROTO	1
#endif

#ifndef	__ARGS
#ifdef	ANSIPROTO
#define	__ARGS(x)	x
#else
#define	__ARGS(x)	()
#endif
#endif

#ifdef SOLARIS
#define setpriority(x,y,z)      z
#endif

/* Server-side data structure for reading keys file during login */
struct skey
{
  FILE *keyfile;
  char buf[256];
  char *logname;
  int n;
  char *seed;
  char *val;
  long recstart;		/* needed so reread of buffer is efficient */


};

/* Client-side structure for scanning data stream for challenge */
struct mc
{
  char buf[256];
  int skip;
  int cnt;
};

void f __ARGS ((char *x));
int keycrunch __ARGS ((char *result, char *seed, char *passwd));
char *btoe __ARGS ((char *engout, char *c));
char *put8 __ARGS ((char *out, char *s));
int etob __ARGS ((char *out, char *e));
void rip __ARGS ((char *buf));
int skeychallenge __ARGS ((struct skey * mp, char *name, char *ss));
int skeylookup __ARGS ((struct skey * mp, char *name));
int skeyverify __ARGS ((struct skey * mp, char *response));
