#include <mpi.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#define n 1
int a[] = {14};
double a2[1000];
void main(int argc, char* argv[])
{
	int pid, np, i;
    MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &pid);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
    if (pid == 0) {
        for (i = 0; i < n; i++) {
            a2[i]=a[i]-4;
            MPI_Send(&a2[i], 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        }
    }
    if (pid == 1) {
        for (i = 0; i < n; i++) {
            MPI_Recv(&a2[i], 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, &status);
            a2[i]=a2[i]/5;
            MPI_Send(&a2[i], 1, MPI_DOUBLE, 2, 1, MPI_COMM_WORLD);
        }
    }
    if (pid == 2) {
        for (i = 0; i < n; i++) {
            MPI_Recv(&a2[i], 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &status);
            a2[i]=a2[i]+3;
            MPI_Send(&a2[i], 1, MPI_DOUBLE, 3, 2, MPI_COMM_WORLD);
        }
    }
    if (pid == 3) {
        for (i = 0; i < n; i++) {
            MPI_Recv(&a2[i], 1, MPI_DOUBLE, 2, 2, MPI_COMM_WORLD, &status);
            a2[i]=a2[i]*7;
            printf("%f",a2[i]);
        }
    }
    MPI_Finalize();
}