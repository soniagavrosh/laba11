#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/Gavrosh"

int main(int argc, char **argv){
        sem_t *sem;
        if(argc != 2){
                if((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED){
                        fprintf(stderr, "Gavrosh sem_open error");
                        return 1;
                }
                printf("Gavrosh sem_open. Gavrosh semaphore is taken.\n Waiting for it to be dropped.\n");
                if(sem_wait(sem)<0)
                        fprintf(stderr, "Gavrosh sem_wait error");
                if(sem_close(sem)<0)
                        fprintf(stderr, "Gavrosh sem_close error");
                return 0;
        }
        else{
                printf("Dropping Gavrosh semaphore\n");
                if((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED){
                        fprintf(stderr, "Gavrosh sem_open error");
                        return 1;
                }
                sem_post(sem);
                printf("Gavrosh sem_post. Gavrosh semaphore dropped.\n");
                return 0;
        }
}




