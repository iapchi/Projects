    /**
      *Jacky Li
      *
      *
      */
//Symbolic constants
#ifndef __DEF_H__
#define __DEF_H__

#define NDEBUG
#ifdef NDEBUG
#define LOG(FORMAT, ...) ((void)0)
#define ERROR(FORMAT, ...) ((void)0)
#else
#define LOG(FORMAT, ...)  fprintf(stdout, "\n%s() in %s, line %i: " FORMAT "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#define ERROR(FORMAT, ...) fprintf(stderr, "\n%s() in %s, line %i: " FORMAT "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#endif


#endif