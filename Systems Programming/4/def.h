#ifndef __DEF_H__
#define __DEF_H__

/**
 * This header file is used for logging purposes
 * Comment below line to enable logging and uncomment to disable logging
 */
#define NDEBUG
#ifdef NDEBUG
#define LOG(FORMAT, ...) ((void)0)
#define ERROR(FORMAT, ...) ((void)0)
#else
#define LOG(FORMAT, ...)  fprintf(stdout, "\n%s() in %s, line %i\n" FORMAT "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(FORMAT, ...) fprintf(stderr, "\n%s() in %s, line %i\n" FORMAT "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#endif
#endif