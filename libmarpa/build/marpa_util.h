/*1197:*/
#line 13787 "./marpa.w"

/*1192:*/
#line 13745 "./marpa.w"

/*
 * Copyright 2012 Jeffrey Kegler
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

/*:1192*/
#line 13788 "./marpa.w"


#ifndef __MARPA_UTIL_H__
#define __MARPA_UTIL_H__

/*1143:*/
#line 13228 "./marpa.w"

#define my_new(type, count) ((type *)my_malloc((sizeof(type)*(count))))
#define my_renew(type, p, count) \
    ((type *)my_realloc((p), (sizeof(type)*(count))))

/*:1143*//*1198:*/
#line 13803 "./marpa.w"


#if     __GNUC__ >  2 || (__GNUC__ == 2 && __GNUC_MINOR__ >  4)
#define UNUSED __attribute__((__unused__))
#else
#define UNUSED
#endif

#if defined (__GNUC__) && defined (__STRICT_ANSI__)
#  undef inline
#  define inline __inline__
#endif

#undef      MAX
#define MAX(a, b)  (((a) >  (b)) ? (a) : (b))

#undef      CLAMP
#define CLAMP(x, low, high)  (((x) >  (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#undef STRINGIFY_ARG
#define STRINGIFY_ARG(contents)       #contents
#undef STRINGIFY
#define STRINGIFY(macro_or_string)        STRINGIFY_ARG (macro_or_string)


#if defined(__GNUC__) && (__GNUC__ < 3) && !defined(__cplusplus)
#  define STRLOC __FILE__ ":" STRINGIFY (__LINE__) ":" __PRETTY_FUNCTION__ "()"
#else
#  define STRLOC __FILE__ ":" STRINGIFY (__LINE__)
#endif


#if defined (__GNUC__)
#  define STRFUNC     ((const char*) (__PRETTY_FUNCTION__))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 19901L
#  define STRFUNC     ((const char*) (__func__))
#else
#  define STRFUNC     ((const char*) ("???"))
#endif

#if defined(__GNUC__) && (__GNUC__ >  2) && defined(__OPTIMIZE__)
#define LIKELY(expr) (__builtin_expect ((expr), 1))
#define UNLIKELY(expr) (__builtin_expect ((expr), 0))
#else
#define LIKELY(expr) (expr)
#define UNLIKELY(expr) (expr)
#endif

#if defined __GNUC__
# define alignof(type) (__alignof__(type))
#else
# define alignof(type) (offsetof (struct { char __slot1; type __slot2; }, __slot2))
#endif

/*:1198*/
#line 13793 "./marpa.w"

/*1133:*/
#line 13101 "./marpa.w"

extern void(*_marpa_out_of_memory)(void);

/*:1133*/
#line 13794 "./marpa.w"

/*1142:*/
#line 13190 "./marpa.w"

static inline
void my_free(void*p)
{
free(p);
}

static inline
void*my_malloc(size_t size)
{
void*newmem= malloc(size);
if(UNLIKELY(!newmem))(*_marpa_out_of_memory)();
return newmem;
}

static inline
void*
my_malloc0(size_t size)
{
void*newmem= my_malloc(size);
memset(newmem,0,size);
return newmem;
}

static inline
void*
my_realloc(void*p,size_t size)
{
if(LIKELY(p!=NULL)){
void*newmem= realloc(p,size);
if(UNLIKELY(!newmem))(*_marpa_out_of_memory)();
return newmem;
}
return my_malloc(size);
}

/*:1142*/
#line 13795 "./marpa.w"


#endif __MARPA__UTIL_H__

/*:1197*/
