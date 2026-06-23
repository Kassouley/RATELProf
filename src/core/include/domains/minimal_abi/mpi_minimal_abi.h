#ifndef MPI_MINIMAL_ABI_H_
#define MPI_MINIMAL_ABI_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* ============================================================================ *
 * Minimal ABI Header for MPI
 * Auto-generated from CSV type definitions
 * ============================================================================ */

/* ============================================================================ *
 * Enum Definitions
 * ============================================================================ */


/* ============================================================================ *
 * Opaque Types
 * ============================================================================ */

typedef struct mpi_instance_t *MPI_Session;
typedef struct mpi_communicator_t *MPI_Comm;
typedef struct mpi_op_t *MPI_Op;
typedef struct mpi_status_public_t *MPI_Status;
typedef struct mpi_message_t *MPI_Message;
typedef struct mpi_info_t *MPI_Info;
typedef struct mpi_win_t *MPI_Win;
typedef struct mpi_datatype_t *MPI_Datatype;
typedef struct mpi_f08_status_public_t *MPI_F08_status;
typedef struct mpi_file_t *MPI_File;
typedef struct mpi_errhandler_t *MPI_Errhandler;
typedef struct mpi_request_t *MPI_Request;
typedef struct mpi_group_t *MPI_Group;

/* ============================================================================ *
 * Basic Types
 * ============================================================================ */

typedef void MPI_Session_errhandler_function(MPI_Session *, int *, ...);
typedef int MPI_Comm_copy_attr_function(MPI_Comm, int, void *, void *, void *, int *);
typedef int MPI_Copy_function(MPI_Comm, int, void *, void *, void *, int *);
typedef int MPI_Grequest_query_function(void *, MPI_Status *);
typedef int MPI_Grequest_free_function(void *);
typedef ptrdiff_t MPI_Aint;
typedef int MPI_Win_copy_attr_function(MPI_Win, int, void *, void *, void *, int *);
typedef void MPI_Win_errhandler_function(MPI_Win *, int *, ...);
typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn;
typedef int MPI_Datarep_extent_function(MPI_Datatype, MPI_Aint *, void *);
typedef int MPI_Delete_function(MPI_Comm, int, void *, void *);
typedef int MPI_Comm_delete_attr_function(MPI_Comm, int, void *, void *);
typedef long long MPI_Count;
typedef long long MPI_Offset;
typedef void MPI_Comm_errhandler_function(MPI_Comm *, int *, ...);
typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn;
typedef void mpi_file_errhandler_function(MPI_File *, int *, ...);
typedef int MPI_Win_delete_attr_function(MPI_Win, int, void *, void *);
typedef int MPI_Datarep_conversion_function(void *, MPI_Datatype, int, void *, MPI_Offset, void *);
typedef void MPI_User_function(void *, void *, int *, MPI_Datatype *);
typedef int MPI_Type_delete_attr_function(MPI_Datatype, int, void *, void *);
typedef mpi_file_errhandler_function MPI_File_errhandler_fn;
typedef mpi_file_errhandler_function MPI_File_errhandler_function;
typedef int MPI_Type_copy_attr_function(MPI_Datatype, int, void *, void *, void *, int *);
typedef int MPI_Grequest_cancel_function(void *, int);

/* ============================================================================ *
 * Structure Definitions
 * ============================================================================ */

struct mpi_predefined_op_t;

struct mca_base_pvar_handle_t;

struct mpi_predefined_datatype_t;

struct mpi_predefined_file_t;

struct mpi_predefined_group_t;

struct mca_base_var_enum_t;

struct mpi_communicator_t;

struct mpi_op_t;

struct mca_base_pvar_session_t;

struct mpi_file_t;

struct mpi_instance_t;

struct mpi_predefined_info_t;

struct mpi_request_t;

struct mpi_mpit_cvar_handle_t;

struct mpi_message_t;

struct mpi_predefined_win_t;

struct mpi_errhandler_t;

struct mpi_predefined_request_t;

struct mpi_info_t;

struct mpi_predefined_message_t;

struct mpi_predefined_errhandler_t;

struct mpi_predefined_instance_t;

struct mpi_status_public_t;

struct mpi_group_t;

struct mpi_predefined_communicator_t;

struct mpi_win_t;

struct mpi_datatype_t;

struct mpi_f08_status_public_t;


#endif /* MPI_MINIMAL_ABI_H_ */
