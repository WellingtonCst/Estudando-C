#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    while(1) {
        time_t rawtime;
        struct tm * timeinfo;

        time (&rawtime);
        timeinfo = localtime (&rawtime);
        printf ("Data e Hora atual: %s", asctime(timeinfo));
        sleep(1); // Pausa por um segundo
    }

    return 0;
}
