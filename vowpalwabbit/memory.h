#pragma once
void* calloc_or_die(size_t nmemb, size_t size);

void* calloc_aligned_or_die(size_t nmemb, size_t size);

void free_it(void* ptr);
