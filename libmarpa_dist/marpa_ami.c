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

/*28:*/
#line 512 "./marpa_ami.w"


#include <stdarg.h> 
#include <stdio.h> 

/*:28*//*29:*/
#line 517 "./marpa_ami.w"

#include "config.h"

#ifndef MARPA_DEBUG
#define MARPA_DEBUG 0
#endif

#include "marpa.h"
#include "marpa_ami.h"

/*5:*/
#line 180 "./marpa_ami.w"

#define PRIVATE_NOT_INLINE static
#define PRIVATE static inline

/*:5*/
#line 527 "./marpa_ami.w"


/*:29*/

#line 1 "./marpa_ami.c.p40"

/*30:*/
#line 532 "./marpa_ami.w"


/*19:*/
#line 355 "./marpa_ami.w"

int marpa__default_debug_handler(const char*format,...)
{
va_list args;
va_start(args,format);
vfprintf(stderr,format,args);
va_end(args);
putc('\n',stderr);
return 1;
}


/*:19*/
#line 534 "./marpa_ami.w"


/*:30*/
