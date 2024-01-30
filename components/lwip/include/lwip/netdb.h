/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stddef.h>
#include_next "lwip/netdb.h"
#include "sdkconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline int gethostbyname_r(const char *name, struct hostent *ret, char *buf, size_t buflen, struct hostent **result, int *h_errnop)
{ return lwip_gethostbyname_r(name, ret, buf, buflen, result, h_errnop); }
static inline struct hostent *gethostbyname(const char *name)
{ return lwip_gethostbyname(name); }
static inline void freeaddrinfo(struct addrinfo *ai)
{ lwip_freeaddrinfo(ai); }
static inline int getaddrinfo(const char *nodename, const char *servname, const struct addrinfo *hints, struct addrinfo **res)
{ return lwip_getaddrinfo(nodename, servname, hints, res); }

static inline int dns_resolve_start(const char *nodename, u8_t dns_addrtype, void **ctx)
{ return lwip_dns_resolve_start(nodename, dns_addrtype, ctx); }
static inline int dns_resolve_check(ip_addr_t *addr, void *ctx)
{ return lwip_dns_resolve_check(addr, ctx); }
#ifdef __cplusplus
}
#endif
