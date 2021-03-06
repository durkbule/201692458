/* Copyright (C) Uppsala University
 *
 * This file is distributed under the terms of the GNU general Public
 * License (GPL), see the file LICENSE
 *
 * Author: Erik Nordström, <erikn@it.uu.se>
 */
#ifndef _DSR_RERR_H
#define _DSR_RERR_H

#include "dsr.h"

#ifdef NS2
#include "endian.h"
#endif

#ifndef NO_GLOBALS

struct dsr_rerr_opt {            //路由错误选项
	u_int8_t type;
	u_int8_t length;
	u_int8_t err_type;
#if defined(__LITTLE_ENDIAN_BITFIELD)
	u_int8_t res:4;
	u_int8_t salv:4;
#elif defined (__BIG_ENDIAN_BITFIELD)
	u_int8_t res:4;
	u_int8_t salv:4;
#else
#error  "Please fix <asm/byteorder.h>"
#endif
	u_int32_t err_src;
	u_int32_t err_dst;
	char info[0];
};

#define DSR_RERR_HDR_LEN sizeof(struct dsr_rerr_opt)
#define DSR_RERR_OPT_LEN (DSR_RERR_HDR_LEN - 2)

struct node_unreach_info {
	u_int32_t unr_node;
};

#define NODE_UNREACHABLE          1
#define FLOW_STATE_NOT_SUPPORTED  2
#define OPTION_NOT_SUPPORTED      3

#endif				/* NO_GLOBALS */

#ifndef NO_DECLS

int dsr_rerr_send(struct dsr_pkt *dp_trigg, struct in_addr unr_addr);   //发送路由错误
int dsr_rerr_opt_recv(struct dsr_pkt *dp, struct dsr_rerr_opt *dsr_rerr_opt); //接收路由错误选项

#endif				/* NO_DECLS */

#endif				/* _DSR_RERR_H */
