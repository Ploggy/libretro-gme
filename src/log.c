#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "libretro.h"

static retro_log_printf_t log_cb;

void init_log(retro_environment_t environ_cb)
{
   struct retro_log_callback log;
   if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log))
      log_cb = log.log;
   else
      log_cb = NULL;
}

void handle_error( const char* error )
{
   char str [256];
   if(error)
   {
      sprintf( str, "Error: %s", error );
      log_cb(RETRO_LOG_ERROR, str );
   }
}

void handle_info( const char* info )
{
   char str [256];
   if(info)
   {
      sprintf( str, "Info: %s\n", info );
      log_cb(RETRO_LOG_INFO, str );
   }
}
