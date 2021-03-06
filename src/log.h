/* 
 * Copyright (C) 2012 Vadim Kochan
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA.
 * 
 * Author:   Vadim Kochan <vadim4j@gmail.com>
 */
 
#ifndef _LOG_HEADER_
#define _LOG_HEADER_

#define DEBUG_LOG_ID    0
#define INFO_LOG_ID     1
#define ERROR_LOG_ID    2
#define FATAL_LOG_ID    3
#define WARN_LOG_ID     4

typedef int ( * log_handler_t ) ( int log_type, char *msg);

/*
 * set logging handler
 * printf is used as default logger
 */
void set_logger( log_handler_t log_handler );

/*
 * logs formatted messages for log handler
 * if log handler is NULL then printf is used
 * as default
 */
void do_log( int log_type, char *fmt, ... );

#define DEBUG 1
							
#define LOG_DEBUG(fmt, ...) \
	do { if ( DEBUG ) do_log(DEBUG_LOG_ID, "[DEBUG] %s:%d:%s(): " fmt,__FILE__ \
							,__LINE__ ,__FUNCTION__,  ## __VA_ARGS__); } while (0)

#define LOG_ERROR(fmt, ...) do_log( ERROR_LOG_ID, "[ERROR] " fmt, ## __VA_ARGS__ )
#define LOG_WARN(fmt, ...) do_log( WARN_LOG_ID, "[WARN] " fmt, ## __VA_ARGS__ )
#define LOG_FATAL(fmt, ...) do_log( FATAL_LOG_ID, "[FATAL] " fmt, ## __VA_ARGS__ )
#define LOG_INFO(fmt, ...) do_log( INFO_LOG_ID, "[INFO] " fmt, ## __VA_ARGS__ )



#endif