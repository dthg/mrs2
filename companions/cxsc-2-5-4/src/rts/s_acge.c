/*
**  CXSC is a C++ library for eXtended Scientific Computing (V 2.5.4)
**
**  Copyright (C) 1990-2000 Institut fuer Angewandte Mathematik,
**                          Universitaet Karlsruhe, Germany
**            (C) 2000-2014 Wiss. Rechnen/Softwaretechnologie
**                          Universitaet Wuppertal, Germany   
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; either
**  version 2 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* CVS $Id: s_acge.c,v 1.21 2014/01/30 17:24:13 cxsc Exp $ */

/****************************************************************/
/*                                                              */
/*      Filename        : s_acge.c                              */
/*                                                              */
/*      Entries         : a_bool s_acge(s,n,t)                  */
/*                        a_char s[];                           */
/*                        a_intg n;                             */
/*                        a_char t;                             */
/*                                                              */
/*      Arguments       : s = string                            */
/*                        n = length of string s                */
/*                        t = character                         */
/*                                                              */
/*      Description     : Compare for string greater/equal      */
/*                        character.                            */
/*                                                              */
/****************************************************************/

#ifndef ALL_IN_ONE
#ifdef AIX
#include "/u/p88c/runtime/o_defs.h"
#else
#include "o_defs.h"
#endif
#define local
#endif

#ifdef LINT_ARGS
local a_bool s_acge(a_char s[],a_intg n,a_char t)
#else
local a_bool s_acge(s,n,t)

a_char s[];
a_intg n;
a_char t;
#endif
        {
        if (n==0) return(FALSE);
        return((*s>=t) ? TRUE : FALSE);
        }





