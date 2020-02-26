#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>

int main(int argc, char* argv[]){
    // FILE *fp = NULL;
    pid_t process_id = 0;
    pid_t sid = 0;
    //create child process
    process_id = fork();
    //Indication of fork() failue
    if ( process_id <0){
        printf("fork failed!\n");
        //return failure in exit status
        exit(1);
    }
    //Parent process. Need to kill it.
    if (process_id > 0){
        printf("process_id of child process %d \n", process_id);
        //return success in exit status
        exit(0);
    }
    //unmask the file mode
    umask(0);
    //set new session
    sid = setsid();
    if(sid < 0){
        // return failure
        exit(1);
    }
    //change the current working directory to test_folder
    //chdir("/pine/scr/<first_character>/<first_character>/<onyen_id>/");
    //Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    //open a log file in write mode
    while(1)
    {
        sleep(1440); // 1 day
        // fprintf(fp,"Logging info .. \n");
        // fflush(fp);
        //implement and call some function that does work for this daemon.
        system("find /pine/scr/<first_character>/<first_character>/<onyen_id>/ -exec touch {} \\;");
    }
    // fclose(fp);
    return(0);

}


