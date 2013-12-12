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
 * This file is written by the Marpa build process
 * It is not intended to be modified directly
 */

/*21:*/
#line 352 "./marpa_ami.w"


#ifndef _MARPA_AMI_H__
#define _MARPA_AMI_H__ 1

#include "marpa_util.h"

#if defined(__GNUC__) && (__GNUC__ >   2) && defined(__OPTIMIZE__)
#define _MARPA_LIKELY(expr) (__builtin_expect ((expr), 1))
#define _MARPA_UNLIKELY(expr) (__builtin_expect ((expr), 0))
#else
#define _MARPA_LIKELY(expr) (expr)
#define _MARPA_UNLIKELY(expr) (expr)
#endif

#define marpa_new(type,count) ((type*) marpa_malloc((sizeof(type) *(count) ) ) ) 
#define marpa_renew(type,p,count)  \
((type*) marpa_realloc((p) ,(sizeof(type) *(count) ) ) )  \

#define MARPA_DSTACK_DECLARE(this) struct marpa_dstack_s this
#define MARPA_DSTACK_INIT(this,type,initial_size)  \
( \
((this) .t_count= 0) , \
((this) .t_base= marpa_new(type,((this) .t_capacity= (initial_size) ) ) )  \
) 
#define MARPA_DSTACK_INIT2(this,type)  \
MARPA_DSTACK_INIT((this) ,type,MAX(4,1024/sizeof(this) ) )  \

#define MARPA_DSTACK_IS_INITIALIZED(this) ((this) .t_base) 
#define MARPA_DSTACK_SAFE(this)  \
(((this) .t_count= (this) .t_capacity= 0) ,((this) .t_base= NULL) )  \

#define MARPA_DSTACK_CLEAR(this) ((this) .t_count= 0) 
#define MARPA_DSTACK_PUSH(this,type) ( \
(_MARPA_UNLIKELY((this) .t_count>=(this) .t_capacity)  \
?marpa_dstack_resize2(&(this) ,sizeof(type) )  \
:0) , \
((type*) (this) .t_base+(this) .t_count++)  \
) 
#define MARPA_DSTACK_POP(this,type) ((this) .t_count<=0?NULL: \
((type*) (this) .t_base+(--(this) .t_count) ) ) 
#define MARPA_DSTACK_INDEX(this,type,ix) (MARPA_DSTACK_BASE((this) ,type) +(ix) ) 
#define MARPA_DSTACK_TOP(this,type) (MARPA_DSTACK_LENGTH(this) <=0 \
?NULL \
:MARPA_DSTACK_INDEX((this) ,type,MARPA_DSTACK_LENGTH(this) -1) ) 
#define MARPA_DSTACK_BASE(this,type) ((type*) (this) .t_base) 
#define MARPA_DSTACK_LENGTH(this) ((this) .t_count) 
#define MARPA_DSTACK_CAPACITY(this) ((this) .t_capacity)  \

#define MARPA_STOLEN_DSTACK_DATA_FREE(data) (marpa_free(data) ) 
#define MARPA_DSTACK_DESTROY(this) MARPA_STOLEN_DSTACK_DATA_FREE(this.t_base) 
#define MARPA_DSTACK_RESIZE(this,type,new_size)  \
(marpa_dstack_resize((this) ,sizeof(type) ,(new_size) ) ) 

#line 367 "./marpa_ami.w"

/*13:*/
#line 310 "./marpa_ami.w"

struct marpa_dstack_s;
typedef struct marpa_dstack_s*MARPA_DSTACK;
/*:13*/
#line 368 "./marpa_ami.w"


/*:21*/
#line 1 "./marpa_ami.h.p5"
static inline void * marpa_dstack_resize2( struct marpa_dstack_s* this, size_t type_bytes);
static inline void * marpa_dstack_resize ( struct marpa_dstack_s *this, size_t type_bytes, int new_size);
/*22:*/
#line 371 "./marpa_ami.w"


/*14:*/
#line 313 "./marpa_ami.w"

struct marpa_dstack_s{int t_count;int t_capacity;void*t_base;};
/*:14*/
#line 373 "./marpa_ami.w"

/*7:*/
#line 196 "./marpa_ami.w"

static inline
void marpa_free(void*p)
{
free(p);
}

/*:7*//*8:*/
#line 203 "./marpa_ami.w"


static inline
void*marpa_malloc(size_t size)
{
void*newmem= malloc(size);
if(_MARPA_UNLIKELY(!newmem)){(*_marpa_out_of_memory)();}
return newmem;
}

static inline
void*
marpa_malloc0(size_t size)
{
void*newmem= marpa_malloc(size);
memset(newmem,0,size);
return newmem;
}

static inline
void*
marpa_realloc(void*p,size_t size)
{
if(_MARPA_LIKELY(p!=NULL)){
void*newmem= realloc(p,size);
if(_MARPA_UNLIKELY(!newmem))(*_marpa_out_of_memory)();
return newmem;
}
return marpa_malloc(size);
}

/*:8*//*15:*/
#line 315 "./marpa_ami.w"

static inline void*marpa_dstack_resize2(struct marpa_dstack_s*this,size_t type_bytes)
{
return marpa_dstack_resize(this,type_bytes,this->t_capacity*2);
}

/*:15*//*17:*/
#line 324 "./marpa_ami.w"

static inline void*
marpa_dstack_resize(struct marpa_dstack_s*this,size_t type_bytes,
int new_size)
{
if(new_size> this->t_capacity)
{

this->t_capacity= new_size;
this->t_base= marpa_realloc(this->t_base,new_size*type_bytes);
}
return this->t_base;
}
/*:17*/
#line 374 "./marpa_ami.w"


#endif 

/*:22*/
