#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
	int threadpool_create(void **__pool, unsigned int max_thread_num, unsigned int queue_max_size);
	int threadpool_destroy(void *_pool);
	int threadpool_add_task(void *pool, void *(*function)(void *arg), void *arg);
#ifdef __cplusplus
}
#endif
