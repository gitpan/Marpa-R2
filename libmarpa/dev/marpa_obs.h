/* This file is a modification of one of the versions of the GNU obstack.h
 * which was LGPL 2.1.  Here is the copyright notice from that file:
 *
 * obstack.h - object stack macros
 * Copyright (C) 1988-1994,1996-1999,2003,2004,2005,2009
 *    Free Software Foundation, Inc.
 * This file is part of the GNU C Library.
 */

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

#ifndef MARPA_OBS_H
#define MARPA_OBS_H 1

#include <stddef.h>

/* If B is the base of an object addressed by P, return the result of
   aligning P to the next multiple of A + 1.  B and P must be of type
   char *.  A + 1 must be a power of 2.  */

#define __BPTR_ALIGN(B, P, A) ((B) + (((P) - (B) + (A)) & ~(A)))

/* Similiar to _BPTR_ALIGN (B, P, A), except optimize the common case
   where pointers can be converted to integers, aligned as integers,
   and converted back again.  If ptrdiff_t is narrower than a
   pointer (e.g., the AS/400), play it safe and compute the alignment
   relative to B.  Otherwise, use the faster strategy of computing the
   alignment relative to 0.  */

#define __PTR_ALIGN(B, P, A)						    \
  __BPTR_ALIGN (sizeof (ptrdiff_t) < sizeof (void *) ? (B) : (char *) 0, \
		P, A)

#include <string.h>

struct _obstack_chunk		/* Lives at front of each chunk. */
{
  char  *limit;			/* 1 past end of this chunk */
  struct _obstack_chunk *prev;	/* address of prior chunk or NULL */
  char	contents[4];		/* objects begin here */
};

struct obstack		/* control current object in current chunk */
{
  long	chunk_size;		/* preferred size to allocate chunks in */
  struct _obstack_chunk *chunk;	/* address of current struct obstack_chunk */
  char	*object_base;		/* address of object we are building */
  char	*next_free;		/* where to add next char to current object */
  char	*chunk_limit;		/* address of char after current chunk */
  union
  {
    ptrdiff_t tempint;
    void *tempptr;
  } temp;			/* Temporary for some macros.  */
  int   alignment_mask;		/* Mask of alignment for each object. */
  unsigned maybe_empty_object:1;/* There is a possibility that the current
				   chunk contains a zero-length object.  This
				   prevents freeing the chunk if we allocate
				   a bigger chunk to replace it. */
};

/* Declare the external functions we use; they are in obstack.c.  */

extern void _marpa_obs_newchunk (struct obstack *, int);
#define _obstack_newchunk _marpa_obs_newchunk

extern int _marpa_obs_begin (struct obstack *, int, int);
#define my_obstack_begin _marpa_obs_begin

extern int _marpa_obs_memory_used (struct obstack *);
#define _obstack_memory_used _marpa_obs_memory_used

void _marpa_obs_free (struct obstack *__obstack);
void _marpa_obs_clear (struct obstack *__obstack);

/* Pointer to beginning of object being allocated or to be allocated next.
   Note that this might not be the final address of the object
   because a new chunk might be needed to hold the final size.  */

#define my_obstack_base(h) ((void *) (h)->object_base)

/* Size for allocating ordinary chunks.  */

#define obstack_chunk_size(h) ((h)->chunk_size)

/* Pointer to next byte not yet allocated in current chunk.  */

#define obstack_next_free(h)	((h)->next_free)

/* Mask specifying low bits that should be clear in address of an object.  */

#define obstack_alignment_mask(h) ((h)->alignment_mask)

/* To prevent prototype warnings provide complete argument list.  */
#define my_obstack_init(h)	my_obstack_begin ((h), 0, 0)

#define obstack_1grow_fast(h,achar) (*((h)->next_free)++ = (achar))

#define my_obstack_blank_fast(h,n) ((h)->next_free += (n))

#define obstack_memory_used(h) _obstack_memory_used (h)

# define obstack_object_size(h) \
 (unsigned) ((h)->next_free - (h)->object_base)

/* Reject any object being built, as if it never existed */
# define my_obstack_reject(h) \
  ((h)->next_free = (h)->object_base)

# define obstack_room(h)		\
 (unsigned) ((h)->chunk_limit - (h)->next_free)

# define obstack_empty_p(h) \
 ((h)->chunk->prev == 0							\
  && (h)->next_free == __PTR_ALIGN ((char *) (h)->chunk,		\
				    (h)->chunk->contents,		\
				    (h)->alignment_mask))

/* Note that the call to _obstack_newchunk is enclosed in (..., 0)
   so that we can avoid having void expressions
   in the arms of the conditional expression.
   Casting the third operand to void was tried before,
   but some compilers won't accept it.  */

# define obstack_make_room(h,length)					\
( (h)->temp.tempint = (length),						\
  (((h)->next_free + (h)->temp.tempint > (h)->chunk_limit)		\
   ? (_obstack_newchunk ((h), (h)->temp.tempint), 0) : 0))

# define obstack_grow(h,where,length)					\
( (h)->temp.tempint = (length),						\
  (((h)->next_free + (h)->temp.tempint > (h)->chunk_limit)		\
   ? (_obstack_newchunk ((h), (h)->temp.tempint), 0) : 0),		\
  memcpy ((h)->next_free, where, (h)->temp.tempint),			\
  (h)->next_free += (h)->temp.tempint)

# define obstack_grow0(h,where,length)					\
( (h)->temp.tempint = (length),						\
  (((h)->next_free + (h)->temp.tempint + 1 > (h)->chunk_limit)		\
   ? (_obstack_newchunk ((h), (h)->temp.tempint + 1), 0) : 0),		\
  memcpy ((h)->next_free, where, (h)->temp.tempint),			\
  (h)->next_free += (h)->temp.tempint,					\
  *((h)->next_free)++ = 0)

# define obstack_1grow(h,datum)						\
( (((h)->next_free + 1 > (h)->chunk_limit)				\
   ? (_obstack_newchunk ((h), 1), 0) : 0),				\
  obstack_1grow_fast (h, datum))

# define obstack_ptr_grow(h,datum)					\
( (((h)->next_free + sizeof (char *) > (h)->chunk_limit)		\
   ? (_obstack_newchunk ((h), sizeof (char *)), 0) : 0),		\
  obstack_ptr_grow_fast (h, datum))

# define obstack_int_grow(h,datum)					\
( (((h)->next_free + sizeof (int) > (h)->chunk_limit)			\
   ? (_obstack_newchunk ((h), sizeof (int)), 0) : 0),			\
  obstack_int_grow_fast (h, datum))

# define obstack_ptr_grow_fast(h,aptr)					\
  (((const void **) ((h)->next_free += sizeof (void *)))[-1] = (aptr))

# define obstack_int_grow_fast(h,aint)					\
  (((int *) ((h)->next_free += sizeof (int)))[-1] = (aint))

# define my_obstack_blank(h,length)					\
( (h)->temp.tempint = (length),						\
  (((h)->chunk_limit - (h)->next_free < (h)->temp.tempint)		\
   ? (_obstack_newchunk ((h), (h)->temp.tempint), 0) : 0),		\
  my_obstack_blank_fast (h, (h)->temp.tempint))

# define my_obstack_alloc(h,length)					\
 (my_obstack_blank ((h), (length)), my_obstack_finish ((h)))

#define my_obstack_new(h, type, count) \
    ((type *)my_obstack_alloc((h), (sizeof(type)*(count))))

# define obstack_copy(h,where,length)					\
 (obstack_grow ((h), (where), (length)), my_obstack_finish ((h)))

# define obstack_copy0(h,where,length)					\
 (obstack_grow0 ((h), (where), (length)), my_obstack_finish ((h)))

# define my_obstack_finish(h)						\
( ((h)->next_free == (h)->object_base					\
   ? (((h)->maybe_empty_object = 1), 0)					\
   : 0),								\
  (h)->temp.tempptr = (h)->object_base,					\
  (h)->next_free							\
    = __PTR_ALIGN ((h)->object_base, (h)->next_free,			\
		   (h)->alignment_mask),				\
  (((h)->next_free - (char *) (h)->chunk				\
    > (h)->chunk_limit - (char *) (h)->chunk)				\
   ? ((h)->next_free = (h)->chunk_limit) : 0),				\
  (h)->object_base = (h)->next_free,					\
  (h)->temp.tempptr)

# define my_obstack_free(h)	(_marpa_obs_free((h)))

#endif /* marpa_obs.h */
