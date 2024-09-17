#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/*
int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Not Enough Arguments Passed!");
        return 1;
    }

    FILE *outputFile = fopen("output.txt","w");
    if(outputFile == NULL){
        perror("Error Opening output.txt");
        return 1;
    }

    for(int i = 1; i < argc; i++){
        fprintf(outputFile,"%s\n",argv[i]);
    }

    fclose(outputFile);
    return 0;
}
*/

int getLength(char str[]){
    int length = 0;
    for(int i = 0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Not Enough Arguments Passed!");
        return 1;
    }

    int fd = open("output.txt",O_WRONLY);
    if(fd == -1){
        printf("Couldnt open output.txt");
        return 1;
    }

    for(int i = 1; i < argc; i++){
        write(fd, argv[i],getLength(argv[i]));
        write(fd,"\n",1);
    }

    close(fd);
    return 0;
}