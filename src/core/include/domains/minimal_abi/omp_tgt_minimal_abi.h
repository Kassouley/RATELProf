#ifndef OMP_TGT_MINIMAL_ABI_H_
#define OMP_TGT_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>

/* ============================================================================ *
 * Minimal ABI Header for OMP_TGT
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Types
 * ============================================================================ */

typedef enum omp_interop_property omp_interop_property_t;

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */

enum omp_interop_property {
	omp_ipr_fr_id = -1,
	omp_ipr_fr_name = -2,
	omp_ipr_vendor = -3,
	omp_ipr_vendor_name = -4,
	omp_ipr_device_num = -5,
	omp_ipr_platform = -6,
	omp_ipr_device = -7,
	omp_ipr_device_context = -8,
	omp_ipr_targetsync = -9,
	omp_ipr_first = -9,
};

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef void *omp_depend_t;
typedef void *omp_interop_t;
typedef intptr_t omp_intptr_t;
typedef uintptr_t omp_uintptr_t;

#endif /* OMP_TGT_MINIMAL_ABI_H_ */
