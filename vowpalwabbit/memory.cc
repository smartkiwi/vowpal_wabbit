#include <stdlib.h>
#include <iostream>
#include <errno.h>

void* calloc_or_die(size_t nmemb, size_t size)
{
  if (nmemb == 0 || size == 0)
    return NULL;
  
  void* data = calloc(nmemb, size);
  if (data == NULL) {
    std::cerr << "internal error: memory allocation failed; dying!" << std::endl;
    throw std::exception();
  }
  return data;
}

// allocates page memory aligned block for array
void* calloc_aligned_or_die(size_t nmemb, size_t size)
{
  if (nmemb == 0 || size == 0)
    return NULL;

  size_t length = nmemb * size;

  void* data;

  if (0 != posix_memalign(&data, sysconf(_SC_PAGE_SIZE), length))
  {
    int errsv = errno;
    std::cerr << "internal error: memory allocation failed; dying!. errro code: " << errsv << std::endl;
    throw std::exception();
  }

  if (data == NULL) {
    std::cerr << "internal error: memory allocation failed; dying!" << std::endl;
    throw std::exception();
  }

  return data;
}


void free_it(void*ptr)
{
  if (ptr != NULL)
    free(ptr);
}

