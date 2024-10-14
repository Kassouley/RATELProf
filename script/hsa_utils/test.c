#include <stdio.h>
#include <hsa/hsa.h>

// Function to get the maximum number of queues per agent
hsa_status_t get_agent_max_queues(hsa_agent_t agent, void* data) {
    hsa_status_t status = HSA_STATUS_SUCCESS;
    uint32_t* max_queues_size = (uint32_t*)data;
    uint32_t max_queues = 0;
    
    // Get the maximum number of queues for this agent
    status = hsa_agent_get_info(agent, HSA_AGENT_INFO_QUEUES_MAX, &max_queues);
    if (status != HSA_STATUS_SUCCESS) {
        printf("Error getting agent info.\n");
        return status;
    }

    // Accumulate the max queues count
    *max_queues_size += max_queues;

    return HSA_STATUS_SUCCESS;
}

int main() {
    // Initialize the HSA runtime
    hsa_status_t status = hsa_init();
    if (status != HSA_STATUS_SUCCESS) {
        printf("HSA runtime initialization failed.\n");
        return -1;
    }

    // Variable to store the total maximum number of queues
    uint32_t max_queues_size = 0;

    // Iterate over all agents and accumulate the maximum number of queues
    status = hsa_iterate_agents(get_agent_max_queues, &max_queues_size);
    if (status != HSA_STATUS_SUCCESS) {
        printf("Failed to iterate over agents.\n");
    } else {
        printf("Total maximum number of queues across all agents: %u\n", max_queues_size);
    }

    // Shutdown the HSA runtime
    status = hsa_shut_down();
    if (status != HSA_STATUS_SUCCESS) {
        printf("HSA runtime shutdown failed.\n");
        return -1;
    }

    return 0;
}
