#include <iostream>
#include <string.h>
#include <mpi.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	
	int rank_proc;
	int n_procs;
	
	int i;
	const int STD_TAG=0;
	const int size_buffer=50;
	char mensagem[size_buffer];
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank_proc);
	
	if( rank_proc != 0){
		sprintf(mensagem, "Mensagem do processo %d", rank_proc);
		
		MPI_Send(mensagem, strlen(mensagem)+1, MPI_CHAR, 0, STD_TAG, MPI_COMM_WORLD);
	}
	else{
		for(i=1; i<n_procs;i++){
			MPI_Recv(mensagem, size_buffer, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			
			printf("\nProcesso %d de %d, enviou a mensagem: %s", status.MPI_SOURCE, n_procs, mensagem);
			
			
		}
		printf("\n");
	}
	
	MPI_Finalize();
	
	return 0;
}
