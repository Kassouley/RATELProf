#ifndef MPI_HELPER_H
#define MPI_HELPER_H

static inline int get_mpi_rank_from_env() 
{
    static int rank = -2; // -2 indicates not initialized, -1 indicates not found
    if (rank != -2) return rank; // Return cached rank if already set
    rank = -1;

    const char* env_vars[] = {
        "OMPI_COMM_WORLD_RANK",
        "PMI_RANK",
        "MPI_LOCALRANKID",
        "SLURM_PROCID",
        "MPIRUN_RANK"
    };

    for (int i = 0; i < sizeof(env_vars)/sizeof(env_vars[0]); ++i) {
        const char* val = getenv(env_vars[i]);
        if (val != NULL) {
            rank = atoi(val); // Cache the rank
            break;
        }
    }
    return rank;
}

static inline int get_mpi_world_size_from_env()
{
    const char* env_vars[] = {
        "OMPI_COMM_WORLD_SIZE",  // OpenMPI
        "PMI_SIZE",              // MPICH / Intel MPI
        "SLURM_NTASKS"           // Slurm
    };

    for (int i = 0; i < sizeof(env_vars)/sizeof(env_vars[0]); ++i) {
        const char* val = getenv(env_vars[i]);
        if (val) return atoi(val);
    }

    return -1;  // Not found / Not an MPI job
}

static inline bool is_main_rank()
{
    int rank = get_mpi_rank_from_env();
    return (rank == 0 || rank == -1);
}

#endif // MPI_HELPER_H