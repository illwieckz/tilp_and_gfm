/*
  Name: Group File Manager
  Copyright (C) 2006 Tyler Cassidy
  Copyright (C) 2006 Romain Lievin
  04/06/06 16:22 - tilibs.c
  
  This program is free software you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation either version 2 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.         
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>
#include <tilp2/tifiles.h>
#include <tilp2/ticables.h>
#include <tilp2/ticonv.h>
#include <gtk/gtk.h>

#include "dialog.h"
#include "tilibs.h"
#include "version.h"

/* Check for tilibs2 versions */
int tilibs_check(void)
{
    char *message;
    
    /* Lets Check for the tilibs2 framework versions, if requirements not met, error out! */
    // libticables2
    if (strcmp(ticables_version_get(), LIBTICABLES2_REQUIRE_VERSION) < 0)
    {
        message = g_strconcat("libticables2 is currently version ",
                              ticables_version_get(),
                              " and GFM requires version <b>",
                              LIBTICABLES2_REQUIRE_VERSION,
                              "</b>. Please upgrade and run GFM Again.", NULL);
        msgbox_error(message);
        g_free(message);
        exit(-1);                                   
    }
    
    // libticonv
    if (strcmp(ticonv_version_get(), LIBTICONV_REQUIRE_VERSION) < 0)
    {
        message = g_strconcat("libticonv is currently version ",
                              ticonv_version_get(),
                              " and GFM requires version <b>",
                              LIBTICONV_REQUIRE_VERSION,
                              "</b>. Please upgrade and run GFM Again.", NULL);
        msgbox_error(message);
        g_free(message);
        exit(-1);                                   
    }
    
    // libtifiles2
    if (strcmp(tifiles_version_get(), LIBTIFILES2_REQUIRE_VERSION) < 0)
    {
        message = g_strconcat("libtifiles2 is currently version ",
                              tifiles_version_get(),
                              " and GFM requires version <b>",
                              LIBTIFILES2_REQUIRE_VERSION,
                              "</b>. Please upgrade and run GFM Again.", NULL);
        msgbox_error(message);
        g_free(message);
        exit(-1);                                   
    }
    
    // Done
    return 0;
}
