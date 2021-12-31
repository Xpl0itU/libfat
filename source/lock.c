#include "common.h"

#if defined(__WUT__)
void (* fat_OSInitMutex)(void* mutex);
void (* fat_OSLockMutex)(void* mutex);
void (* fat_OSUnlockMutex)(void* mutex);

s32 (* fat_OSDynLoad_Acquire)(const char* rpl, u32 *handle);
s32 (* fat_OSDynLoad_FindExport)(u32 handle, s32 isdata, const char* symbol, void* address);
#endif

#if !defined(USE_LWP_LOCK) && !(defined(__wiiu__) && defined(__WUT__))

#ifndef mutex_t
typedef int mutex_t;
#endif

void __attribute__ ((weak)) _FAT_lock_init(mutex_t *mutex)
{
	return;
}

void __attribute__ ((weak)) _FAT_lock_deinit(mutex_t *mutex)
{
	return;
}

void __attribute__ ((weak)) _FAT_lock(mutex_t *mutex)
{
	return;
}

void __attribute__ ((weak)) _FAT_unlock(mutex_t *mutex)
{
	return;
}

#endif // USE_LWP_LOCK
