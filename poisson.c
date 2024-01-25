#include<stdio.h>
#include<math.h>



void writeGrid(int N, double grid[N][N]){
	int i,j;
	FILE* fout = fopen("grid.txt", "w");


	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			fprintf(fout, "%30.16g ", grid[i][j]);
		}
		fprintf(fout, "\n");
	}
	fclose(fout);
}


void copy(const int N, double from[N][N], double to[N][N]){
	int i,j;
	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			to[i][j] = from[i][j];
		}
	}
}



int main(){
	double PI = 3.14159265358979323846;
	double dens=0;

//set a delta for the separation inbetwen points
	double delta =0.1;
//boundary conditions U(0,y)=U(L,y)=U(x,0)=0 U(x,L)=100 a box
	double max=20;
	int tamano=max/delta;
	printf("\n resta: %8.4d", tamano);

	double U[tamano][tamano];
//fullfill the matrix with zeros esta sera mi guess
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++){
			U[i][j]=0;
			}
	}
//mi condicion inicial esto no es exactamente una funcion pero a ver si sirve
	for(int i=0;i<tamano;i++){
				U[i][0]=100;
				}

	double oldcopy[tamano][tamano];
	double resta[tamano][tamano];
	copy(tamano, U, oldcopy);

	for(int i=1;i<tamano-1;i++){
				for(int j=1;j<tamano-1;j++){
		U[i][j]=((U[i+1][j]+U[i-1][j]+U[i][j+1]+U[i][j-1])/4)+PI*dens*pow(delta,2);
		resta[i][j]=U[i][j]-oldcopy[i][j];
				}
		}
printf("\n resta: %8.4f", resta[1][1]);
	  double maximum = resta[1][1];
	  int m=tamano, n=tamano;
	  for (int c = 1; c < m-1; c++){
	    for (int d = 1; d < n-1; d++){
	      if (resta[c][d] > maximum){
	        maximum = resta[c][d];}}}
	  printf("\n maximum: %8.4f", maximum);



	while(maximum>0.01){
		copy(tamano, U, oldcopy);
	for(int i=1;i<tamano-1;i++){
			for(int j=1;j<tamano-1;j++){
	U[i][j]=((U[i+1][j]+U[i-1][j]+U[i][j+1]+U[i][j-1])/4)+PI*dens*pow(delta,2);
	resta[i][j]=U[i][j]-oldcopy[i][j];
	//printf("\n resta: %8.4f", resta[i][j]);

			}
	}
	maximum=resta[0][0];
	  for (int c = 1; c < m-1; c++){
	    for (int d = 1; d < n-1; d++){
	      if (resta[c][d] > maximum){
	        maximum = resta[c][d];}}}
	  printf("\n maximum: %8.4f", maximum);
	}


	//create my mesh
	writeGrid(tamano, U);
	return 0;
}
