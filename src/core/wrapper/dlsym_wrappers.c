/* # THIS FILE HAS BEEN AUTOMATICALLY GENERATED BY THE GILDA TOOL.
 * # DO NOT MODIFY UNLESS YOU KNOW WHAT YOU ARE DOING.
 * # ANY CHANGES MAY BE OVERWRITTEN BY SUBSEQUENT RUNS OF GILDA.
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ratelprof.h"

typedef void* (*__dlsym_t)(void *handle, const char *symbol);

void* dlsym(void *handle, const char *symbol) {
  static __dlsym_t dlsym_fn = NULL;
  if (dlsym_fn == NULL)
    dlsym_fn = (__dlsym_t)dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.2.5");

  if (handle != NULL) {
		if (handle == omp_tgt_rtl_api_table.handler && omp_tgt_rtl_api_table.is_populate) {
			omp_tgt_rtl_api_id_t id = get_omp_tgt_rtl_funid_by_name(symbol);
			if (id != OMP_TGT_RTL_API_ID_UNKNOWN) {
				return omp_tgt_rtl_api_table.api_ptr[id];
			}
		} 
  }
  return dlsym_fn(handle, symbol);
}
