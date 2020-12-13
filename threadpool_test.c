#include <stdio.h>

#include "threadpool.h"

void nothing(void* voidptr) {
    (void)voidptr;
    return;
}

int main() {
    Threadpool pool;

    POOL_create(&pool, 8);

    for (int i = 0; i < 5000; i++) {
        POOL_exectask(&pool, nothing, NULL);
    }

    POOL_destroy(&pool);
}