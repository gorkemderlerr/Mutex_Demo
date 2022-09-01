#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include<unistd.h>

    void *producer(void *);
    void *consumer(void *);
    pthread_mutex_t lock;
    int product = 10;

    int main(){

        int j;
        pthread_t producer_t, 
		consumer_t;
        pthread_mutex_init(&lock,NULL);

        for(j=0;j<100;j++){

            pthread_create(&producer_t,NULL,
			producer,NULL);
            pthread_create(&consumer_t,NULL,
			consumer,NULL);

            pthread_join(producer_t,NULL);
            pthread_join(consumer_t,NULL);

        }

        pthread_mutex_destroy(&lock);


    }

    void *producer(void *n){
    	
        pthread_mutex_lock(&lock);
        
        while(product!=10){
            printf("number of producer= %d \n",product);
            
            product++;
        }





        pthread_mutex_unlock(&lock);

    }


    void *consumer(void *n){
        pthread_mutex_lock(&lock);

        while(product!=0){
            printf("number of consumer = %d \n",product);
            product--;
        }



        pthread_mutex_unlock(&lock);


    }
