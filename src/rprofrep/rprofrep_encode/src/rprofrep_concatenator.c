#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sendfile.h>

#include "rprofrep_core.h"

#include "rprofrep_concatenator.h"

rprofrep_status_t rprofrep_concatenator_init(rprofrep_concatenator_t* concatenator, const char* filepath)
{
    concatenator->fd = open(filepath, O_WRONLY | O_CREAT, 0644);
    if (concatenator->fd < 0) {
        return RPROFREP_STATUS_FILE_ERROR("Failed to open concatenator file\n");
    }
    concatenator->size = sizeof(rprofrep_header_section_t); // Reserve space for header
    memset(&concatenator->header, 0, sizeof(concatenator->header));

    return RPROFREP_STATUS_SUCCESS;
}

rprofrep_status_t rprofrep_concatenator_destroy(rprofrep_concatenator_t* concatenator)
{
    if (concatenator && concatenator->fd >= 0) {
        RPROFREP_CHECK_CALL(rprofrep_concatenator_write_header(concatenator));

        close(concatenator->fd);
        concatenator->fd = -1;
    }
    return RPROFREP_STATUS_SUCCESS;
}


rprofrep_status_t rprofrep_concatenator_write_header(rprofrep_concatenator_t* concatenator)
{
    RPROFREP_CHECK_VALID_PTR(concatenator);
    int fd = concatenator->fd;
    if (fd < 0) return RPROFREP_STATUS_NOT_INIT("Concatenator is not initialized\n");

    rprofrep_header_section_t* header = &concatenator->header;

    memcpy(header->magic, RPROFREP_FILE_MAGIC, RPROFREP_FILE_MAGIC_SIZE);
    header->report_version[0] = RPROFREP_VERSION_MAJOR;
    header->report_version[1] = RPROFREP_VERSION_MINOR;
    header->report_version[2] = RPROFREP_VERSION_PATCH;

    if (lseek(fd, 0, SEEK_SET) == (off_t)-1)
        return RPROFREP_STATUS_FILE_ERROR("Failed to seek to beginning of file\n");

    if (write(fd, header, sizeof(*header)) != sizeof(*header))
        return RPROFREP_STATUS_FILE_ERROR("Cannot write into concatenator\n");

    return RPROFREP_STATUS_SUCCESS;
}



rprofrep_status_t rprofrep_concatenator_concat_section(
    rprofrep_concatenator_t* concatenator, 
    const char* filename,
    rprofrep_section_id_t section_id
) {
    RPROFREP_CHECK_VALID_PTR(concatenator, filename);

    int infd = open(filename, O_RDONLY);
    if (infd < 0) {
        return RPROFREP_STATUS_FILE_ERROR("Failed to open '%s'\n", filename);
    }
    
    rprofrep_header_entry_t* hdr_entry = NULL;
    size_t section_offset = concatenator->size;
    size_t section_size = get_file_size(filename);
    off_t remaining = (off_t) section_size;

    if (lseek(concatenator->fd, section_offset, SEEK_SET) < 0) {
        return RPROFREP_STATUS_FILE_ERROR("Failed to seek to offset %lu\n", section_offset);
    }

    ssize_t sent = 0;
    while (remaining > 0) {
        sent = sendfile(concatenator->fd, infd, NULL, remaining);
        if (sent < 0) {
            close(infd);
            return RPROFREP_STATUS_FILE_ERROR("Failed to execute sendfile\n");
        }
        if (sent == 0) {
            close(infd);
            return RPROFREP_STATUS_FILE_ERROR("0 bytes has been sent by sendfile\n");
        }
        remaining -= sent;
    }

    if (section_id < RPROFREP_NB_SECTIONS) {
        hdr_entry = &concatenator->header.sections[section_id];
        size_t curr_off = hdr_entry->offset;
        hdr_entry->offset = curr_off == 0 ? section_offset : curr_off;
        hdr_entry->size  += section_size;
    }

    concatenator->size += section_size;

    close(infd);
    return RPROFREP_STATUS_SUCCESS;
}
