#include <pthread.h>
#include <stdio.h>

int i = 0;

void* incrementingThreadFunction(){
    for(int j = 0; j < 1000000; j++) i += 1;
    return NULL;
}

void* decrementingThreadFunction(){
    for(int j = 0; j < 1000000; j++) i -= 1;
    return NULL;
}

int main(){

    pthread_t incrementingThread;
    pthread_t decrementingThread;

    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);

    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

    printf("The magic number is: %d\n", i);
    
    return 0;
}

/*
- int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine) (void *arg), void *arg);

pthread_create() was invoked from a child process created by calling fork() from a multi-threaded process.
This child process is restricted from becoming multi-threaded.
*/

//Assembly code (sort of)
/*
run 1-6: i = 0
run 7:   i = -995731
run 8:   i = 0
run 9:   i = -995379

random number after.


eax, ecx: general purpose register
rbp: base pointer
rsp: stack pointer

incrementingThreadFunction:
1:
    push    rbp
    mov     rbp, rsp

2:  (i += 1;)
    mov     eax, DWORD PTR i[rip] ; DWORD - 32 bit
    add     eax, 1
    mov     DWORD PTR i[rip], eax

3:
    nop
    pop     rbp
    ret

decrementingThreadFunction
1:
      push    rbp
      mov     rbp, rsp

2:    (i -= 1;)
      mov     eax, DWORD PTR i[rip]
      sub     eax, 1
      mov     DWORD PTR i[rip], eax

3:
      nop
      pop     rbp
      ret
*/
