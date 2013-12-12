/*1384:*/
#line 16413 "./marpa.w"

/*1378:*/
#line 16346 "./marpa.w"

/*
 * Copyright 2013 Jeffrey Kegler
 * This file is part of Marpa::R2.  Marpa::R2 is free software: you can
 * redistribute it and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Marpa::R2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with Marpa::R2.  If not, see
 * http://www.gnu.org/licenses/.
 */
/*
 * DO NOT EDIT DIRECTLY
 * This file is written by ctangle
 * It is not intended to be modified directly
 */

/*:1378*/
#line 16414 "./marpa.w"


#ifndef _MARPA_UTIL_H__
#define _MARPA_UTIL_H__ 1

/*1354:*/
#line 16055 "./marpa.w"

#define MARPA_OFF_DEBUG1(a)
#define MARPA_OFF_DEBUG2(a, b)
#define MARPA_OFF_DEBUG3(a, b, c)
#define MARPA_OFF_DEBUG4(a, b, c, d)
#define MARPA_OFF_DEBUG5(a, b, c, d, e)
#define MARPA_OFF_ASSERT(expr)
/*:1354*//*1363:*/
#line 16112 "./marpa.w"


#ifndef MARPA_DEBUG
#define MARPA_DEBUG 0
#endif

#if MARPA_DEBUG

#undef MARPA_ENABLE_ASSERT
#define MARPA_ENABLE_ASSERT 1

#define MARPA_DEBUG1(a)  (_marpa_debug_level && \
    (*_marpa_debug_handler)(a)) 
#define MARPA_DEBUG2(a,b)  (_marpa_debug_level && \
    (*_marpa_debug_handler)((a),(b))) 
#define MARPA_DEBUG3(a,b,c)  (_marpa_debug_level && \
    (*_marpa_debug_handler)((a),(b),(c))) 
#define MARPA_DEBUG4(a,b,c,d)  (_marpa_debug_level && \
    (*_marpa_debug_handler)((a),(b),(c),(d))) 
#define MARPA_DEBUG5(a,b,c,d,e)  (_marpa_debug_level && \
    (*_marpa_debug_handler)((a),(b),(c),(d),(e))) 

#define MARPA_ASSERT(expr) do { if _MARPA_LIKELY (expr) ; else \
       (*_marpa_debug_handler) ("%s: assertion failed %s", STRLOC, #expr); } while (0);
#else 
#define MARPA_DEBUG1(a) 
#define MARPA_DEBUG2(a, b) 
#define MARPA_DEBUG3(a, b, c) 
#define MARPA_DEBUG4(a, b, c, d) 
#define MARPA_DEBUG5(a, b, c, d, e) 
#define MARPA_ASSERT(exp) 
#endif

#ifndef MARPA_ENABLE_ASSERT
#define MARPA_ENABLE_ASSERT 0
#endif

#if MARPA_ENABLE_ASSERT
#undef MARPA_ASSERT
#define MARPA_ASSERT(expr) do { if _MARPA_LIKELY (expr) ; else \
       (*_marpa_debug_handler) ("%s: assertion failed %s", STRLOC, #expr); } while (0);
#endif

/*:1363*/
#line 16419 "./marpa.w"

/*1326:*/
#line 15822 "./marpa.w"

extern void*(*const _marpa_out_of_memory)(void);

/*:1326*//*1356:*/
#line 16076 "./marpa.w"

extern int(*_marpa_debug_handler)(const char*,...);
extern int _marpa_debug_level;
/*:1356*//*1357:*/
#line 16083 "./marpa.w"

#if MARPA_DEBUG >  0
extern int _marpa_default_debug_handler(const char*format,...);
#define MARPA_DEFAULT_DEBUG_HANDLER _marpa_default_debug_handler
#else
#define MARPA_DEFAULT_DEBUG_HANDLER NULL
#endif

/*:1357*/
#line 16420 "./marpa.w"


#endif 

/*:1384*/
