#include "exp.h"
#include "anasem.h"

/* -----------------------------------
 * Semantics Analyzer
 * -----------------------------------
 */

/* --- Showing exp in infix notation --- */
void showExp(Exp e)
{
  printf("(%d)",e->u.d1.s1);
  showExp2(e->u.d1.s2);
}

void showExp2(Exp2 e2)
{
  switch(e2->flag)
	{
	  case PScons_Soma : printf("(+)");
						 showExp(e2->u.d1.s1);
						 break;
	  case PScons_Sub  : printf("(-)");
						 showExp(e2->u.d2.s1);
						 break;
	  case PScons_NIL  : break;
	}
}

/* --- Showing exp in prefix notation --- */

void preshowExp(Exp e)
{
  switch((e->u.d1.s2)->flag)
	{
	  case PScons_Soma : printf("(+ %d ",e->u.d1.s1);
						 preshowExp((e->u.d1.s2)->u.d1.s1);
						 printf(")");
						 break;
	  case PScons_Sub  : printf("(- %d ",e->u.d1.s1);
						 preshowExp((e->u.d1.s2)->u.d2.s1);
						 printf(")");
						 break;
	  case PScons_NIL  : printf("%d",e->u.d1.s1);
						 break;
	}
}
