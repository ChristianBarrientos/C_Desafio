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
};


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
	int dni_juga[400],i,j,edad[400],rojas[400],ama[400],ptos[20],gf[20],gc[20];
	FILE* J=fopen("jugadores.txt","rt");
	FILE* D=fopen("dni.txt","rt");
	FILE* E=fopen("edades.txt","rt");
	FILE* R=fopen("tarj_rojas.txt","rt");
	FILE* AM=fopen("tarj_ama.txt","rt");
	FILE* P=fopen("ptos.txt","rt");
	FILE* GF=fopen("GF.txt","rt");
	FILE* GC=fopen("GC.txt","rt");
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
		for(i=0;i<400;i++)
		{
			fscanf(R,"%d",&rojas[i]);
		}
		for(i=0;i<400;i++)
		{
			fscanf(AM,"%d",&ama[i]);
		}
		for(i=0;i<20;i++)
		{
			fscanf(P,"%d",&ptos[i]);
		}
		for(i=0;i<20;i++)
		{
			fscanf(GF,"%d",&gf[i]);
		}
		for(i=0;i<20;i++)
		{
			fscanf(GC,"%d",&gc[i]);
		}
		for(i=0;i<20;i++)
		{
			strcpy(nuevo.nombre,nom[i]);
			fflush(stdin);
			strcpy(nuevo.barrio,barrio[i]);
			fflush(stdin);
			nuevo.Ptos=ptos[i];
			nuevo.goles.gol_favor=gf[i];
			nuevo.goles.gol_contra=gc[i];
			nuevo.goles.gol_dif=gf[i]-gc[i];
			for(j=0;j<20;j++)
			{
				fflush(stdin);
				strcpy(nuevo.jugadores[j].nombre,nom_juga[k]);
				fflush(stdin);
				nuevo.jugadores[j].DNI=dni_juga[k];
				nuevo.jugadores[j].edad=edad[k];
				nuevo.jugadores[j].tar_R=rojas[k];
				nuevo.jugadores[j].tar_A=ama[k];
				k++;
			}
			fwrite(&nuevo,sizeof(nuevo),1,A);
		}
	fclose(E);
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
