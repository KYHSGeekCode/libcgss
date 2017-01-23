#pragma once

typedef enum _CGSS_STREAM_SEEK_ORIGIN {
    CGSS_ORIGIN_BEGIN = 0,
    CGSS_ORIGIN_CURRENT = 1,
    CGSS_ORIGIN_END = 2,
    CGSS_ORIGIN_FORCE_DWORD = 0x7fffffff
} CGSS_STREAM_SEEK_ORIGIN;

typedef enum _CGSS_HCA_CIPHER_TYPE {
    CGSS_HCA_CIPH_NO_CIPHER = 0,
    CGSS_HCA_CIPH_STATIC = 1,
    CGSS_HCA_CIPH_WITH_KEY = 56,
    CGSS_HCA_CIPH_FORCE_DWORD = 0x7fffffff
} CGSS_HCA_CIPHER_TYPE;

typedef enum _CGSS_OP_RESULT {
    CGSS_OP_OK = 0,
    CGSS_OP_GENERIC_FAULT = -1,
    CGSS_OP_BUFFER_TOO_SMALL = -2,
    CGSS_OP_NOT_IMPLEMENTED = -3,
    CGSS_OP_INVALID_OPERATION = -4,
    CGSS_OP_INVALID_ARGUMENT = -5,
    CGSS_OP_FORMAT_ERROR = -6,
    CGSS_OP_CHECKSUM_ERROR = -7,
    CGSS_OP_DECODE_FAILED = -8,
    CGSS_OP_INVALID_HANDLE = -9,
    CGSS_OP_FORCE_DWORD = 0x7fffffff
} CGSS_OP_RESULT;

#define CGSS_OP_SUCCEEDED(x) ((CGSS_OP_RESULT)(x) >= 0)

typedef enum _CGSS_FILE_MODE {
    CGSS_FILE_MODE_NONE = 0,
    CGSS_FILE_MODE_APPEND = 1,
    CGSS_FILE_MODE_CREATE = 2,
    CGSS_FILE_MODE_CREATE_NEW = 3,
    CGSS_FILE_MODE_OPEN_EXISTING = 4,
    CGSS_FILE_MODE_OPEN_OR_CREATE = 5,
    CGSS_FILE_MODE_FORCE_DWORD = 0x7fffffff
} CGSS_FILE_MODE;

typedef enum _CGSS_FILE_ACCESS {
    CGSS_FILE_ACCESS_NONE = 0,
    CGSS_FILE_ACCESS_READ = 1,
    CGSS_FILE_ACCESS_WRITE = 2,
    CGSS_FILE_ACCESS_READ_WRITE = 3,
    CGSS_FILE_ACCESS_FORCE_DWORD = 0x7fffffff
} CGSS_FILE_ACCESS;
