#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct GOLES
{
       int gol_favor;
       int gol_contra;
       int gol_dif;
}goles;

struct jugador
{
       char nombre[50];
       long DNI;
       int edad;
       int tar_A;
       int tar_R; 
	   int partido;
	   int fecha;     
};

typedef struct FECHAS
{
	int fecha;
	char equipos [50];
	int goles;

	
}partidos;

typedef struct EQUIPOS
{
        struct jugador jugadores[20];
        char nombre[50];
        char barrio[50];
        int Ptos;
        struct GOLES goles;
        
}equipo;


void cargar_datos();
void mostrar();
int main()
{
	int j;
	printf("1- Cargar datos.\n");
	printf("2- Mostrar datos.\n");
	printf("Cual? :");
	scanf("%d",&j);
	if(j==1)	cargar_datos();
	if(j==2)	mostrar();
	return 0;
}

void cargar_datos()
{
	FILE* A=fopen("equipos.bin","wb");
	equipo nuevo;
	int k=0;
	char nom[20][50]={"Boca Juniors","San Lorenzo","Racing Club","River Plate","Rosario Centra","Belgrano","Tigre","Gimnasia La Plata","Olimpo","Estudiantes","Union Santa Fe","Banfield","Lanus","Aldosivi","Argentinos Juniors","Independiente","San Martin","Velez","Sarmiento","Temperley"};
	char barrio[20][50]={"Brinca","Corre","Permanece de pie","Rio verde","Rio mucho","Rio loco","Caballo","Corcelitos","Perritos","Gatitos","Ratoncitos","Amas de casa","Universitarios","Trabajadores","Tintoreros","Capitalistas","Belojo","Beldía","Belseno","Belhombro"};
	char nom_juga[400][50];
	int dni_juga[400],i,j,edad[400];
	FILE* J=fopen("jugadores.txt","rt");
	FILE* D=fopen("dni.txt","rt");
	FILE* E=fopen("edades.bin","rt");
	if(A==NULL)
	{
		printf("Error");
	}
	else
	{
		for(i=0;(fscanf(J," %[^\n]",nom_juga[i])) != EOF;i++)
		{
			
		}
		for(i=0;i<400;i++)
		{
			fscanf(D,"%d",&dni_juga[i]);
		}
		for(i=0;i<400;i++)
		{
			fscanf(E,"%d",&edad[i]);
		}
		for(i=0;i<20;i++)
		{
			strcpy(nuevo.nombre,nom[i]);
			fflush(stdin);
			strcpy(nuevo.barrio,barrio[i]);
			fflush(stdin);
			nuevo.Ptos=0;
			nuevo.goles.gol_favor=0;
			nuevo.goles.gol_contra=0;
			nuevo.goles.gol_dif=0;
			for(j=0;j<20;j++)
			{
				fflush(stdin);
				strcpy(nuevo.jugadores[j].nombre,nom_juga[k]);
				fflush(stdin);
				nuevo.jugadores[j].DNI=dni_juga[k];
				nuevo.jugadores[j].edad=edad[k];
				k++;
				nuevo.jugadores[j].tar_R=0;
				nuevo.jugadores[j].tar_A=0;
			}
			fwrite(&nuevo,sizeof(nuevo),1,A);
		}
	fclose(A);
	fclose(J);
	fclose(D);
	}
}

void mostrar()
{
	FILE* A=fopen("equipos.bin","rb");
	equipo nuevo;
	int i;
	if(A==NULL)
	{
		printf("Error");
	}
	else
	{
		while(fread(&nuevo,sizeof(nuevo),1,A))
		{
			printf("\tNombre del Equipo: %s\n",nuevo.nombre);
			fflush(stdin);
			printf("\tBarrio de el Equipo: %s\n",nuevo.barrio);
			fflush(stdin);
			printf("\tPtos: %d\n",nuevo.Ptos);
			printf("\tGF: %d\n",nuevo.goles.gol_favor);
			printf("\tGC: %d\n",nuevo.goles.gol_contra);
			printf("\tDG: %d\n\n",nuevo.goles.gol_dif);
			for(i=0;i<20;i++)
			{
				printf("\tJugador[N%c%d]-->%s\n\n",248,i+1,nuevo.nombre);
				fflush(stdin);
				printf("Nombre :%s\n",nuevo.jugadores[i].nombre);
				fflush(stdin);
				printf("DNI: %d\n",nuevo.jugadores[i].DNI);
				fflush(stdin);
				printf("Tarjutas Rojas: %d\n",nuevo.jugadores[i].tar_R);
				printf("Tarjetas Amarillas: %d\n",nuevo.jugadores[i].tar_A);
				system("pause>NULL");
				printf("-------------------------------------\n");
			}
			system("cls");
			system("pause>NULL");
		}
	fclose(A);
		
	}
}
