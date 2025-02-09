#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ratelinfo_agents_query.h"

// Function to write agent info to CSV
void write_agent_info_to_csv(FILE *csv_file, ratelinfo_agent_data_t agent_data) {
    fprintf(csv_file, 
            "%u, %s, %s, %s, "
            "%s, %s, "
            "%u, " 
            "%u, %u, %u, %u, "
            "%u, %u, "
            "%u, %u, " 
            "%s, %u, %u, ", 
            agent_data.node, agent_data.name, agent_data.product_name, agent_data.device_type_name, 
            agent_data.feature, agent_data.machine_model, 
            agent_data.driver_node_id,
            agent_data.cache_size[0], agent_data.cache_size[1], agent_data.cache_size[2], agent_data.cache_size[3], 
            agent_data.cu_count, agent_data.cacheline_size, 
            agent_data.max_clock_freq, agent_data.max_mem_clock, 
            agent_data.uuid, agent_data.version_major, agent_data.version_minor);

    if (agent_data.device_type == 1) {
        fprintf(csv_file, "%s, %u, " 
                          "%u, %u, %u, %u, " 
                          "%u, %u, %u, %u, " 
                          "%u, " 
                          "%u, %u, %u, %s, " 
                          "%u, " 
                          "%u, %u, " 
                          "%u, %u, %u, %u, %u, " 
                          "%u, %lu\n",
                agent_data.isa_name, agent_data.wavefront_size,
                agent_data.workgroup_max_dim[0], agent_data.workgroup_max_dim[1], agent_data.workgroup_max_dim[2], agent_data.workgroup_max_size,
                agent_data.grid_max_dim[0], agent_data.grid_max_dim[1], agent_data.grid_max_dim[2], agent_data.grid_max_size, 
                agent_data.fbarrier_max_size,
                agent_data.queues_max, agent_data.queue_min_size, agent_data.queue_max_size, agent_data.queue_type, 
                agent_data.chip_id, 
                agent_data.max_wave_per_cu, agent_data.num_simd_per_cu, 
                agent_data.num_se, agent_data.num_sa_per_se, agent_data.num_sdma_eng, agent_data.num_sdma_xgmi_eng, agent_data.num_xcc,
                agent_data.driver_uid, agent_data.nearest_cpu.handle);
        free(agent_data.isa_name);
    } else {
        fprintf(csv_file, "-, -, " 
                          "-, -, -, -," 
                          "-, -, -, -," 
                          "-, " 
                          "-, -, -, -," 
                          "-, " 
                          "-, -, " 
                          "-, -, -, -, -, " 
                          "-, -\n");
    }
}


int write_to_csv(ratelinfo_agent_data_t* agents_list, size_t agents_count) {

    // Open CSV file for writing
    FILE *csv_file = fopen("amd_agent_info.csv", "w");
    if (!csv_file) {
        printf("Failed to open CSV file\n");
        return -1;
    }

    // Write header to CSV
    fprintf(csv_file, "Node, Name, Product Name, Device Type, "
                      "Feature, Machine Model, "
                      "Driver Node ID, "
                      "Cache L1, Cache L2, Cache L3, Cache L4, "
                      "CU Count, Cacheline Size, "
                      "Max Clock Frequency, Max Mem Clock, "
                      "UUID, Version Major, Version Minor, "
                      "ISA Name, Wavefront Size, "
                      "Workgroup Max X, Workgroup Max Y, Workgroup Max Z, Workgroup Max Size, "
                      "Grid Max X, Grid Max Y, Grid Max Z, Grid Max Size, "
                      "FBarrier Max Size, "
                      "Queues Max, Queue Min Size, Queue Max Size, Queue Type, "
                      "Chip ID, "
                      "Max Waves Per CU, Num SIMD Per CU, "
                      "Num Shader Engines, Num Shader Arrays Per SE, Num SDMA Engines, Num SDMA XGMI Engines, Num XCC, "
                      "Driver UID, Nearest CPU\n");


    for (size_t i = 0; i < agents_count; i++)
    {
        write_agent_info_to_csv(csv_file, agents_list[i]);
    }
    

    // Close CSV file
    fclose(csv_file);

    printf("AMD agent information written to amd_agent_info.csv\n");
    return 0;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s --export | --max-queue\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "--export") == 0) {
        size_t agents_count = 0;
        ratelinfo_agent_data_t* agents_list = NULL;
        
        ratelinfo_query_agent_data(&agents_list, &agents_count);
        write_to_csv(agents_list, agents_count);
    } 
    else if (strcmp(argv[1], "--max-queue") == 0) {
        uint32_t max_queues_size = 0;
        ratelinfo_get_max_queue(&max_queues_size);
        printf("%u\n", max_queues_size);
    } 
    else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        fprintf(stderr, "Usage: %s --export | --max-queue\n", argv[0]);
        return 1;
    }

    return 0;
}
