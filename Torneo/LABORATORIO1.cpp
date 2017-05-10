/*Generar a petici๓n los siguientes listados:
a) Mostrar alfab้ticamente los nombres de los equipos.
b) Mostrar la tabla de posiciones del campeonato.          --------------------------------------
c) Mostrar alfab้ticamente los nombres de los jugadores del equipo que se requiera. ---------------------
d) Mostrar alfab้ticamente los nombres de todos los jugadores.		-------------------
e) Mostrar el nombre de los jugadores de todos los equipos que llegaron a 5,10 y 15
amarillas. Tambi้n mostrar los que fueron expulsados y los que llegaron a 3 rojas.
f) Mostrar el puntero del campeonato y a que barrio pertenece.
g) Mostrar los jugadores que tienen actualmente tarjeta roja.*/

// se puso el codigo al que ya estaba y surge un error raro... noce q onda hai q preguntarle al profe

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define num_equipos 20
#define num_partidos 19
#define ANCHO_PANTALLA 80
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


void pausa();
equipo nuevo_equipo();
void guardar_equipo(equipo E);
void menu();
int limite_de_equipos();
void modificar_jugadores();
int contrasena(int j);
int validar_contrasena(char co[]);
void busqueda_jugador_dni();
void tabla_de_posiciones();
void busqueda_equipo_nombre();
void equipos_alfabeticamente();
void jugadores_alfa();
void juga_roja();
void menu_amonestados();
void menu_juga();
void juga_amarilla();
int menu_contra();
void menu_salida();

void fixture();
void ingresar_datos();
void ver_puntero();
void calcular_fixture(int aux_array[num_equipos][num_partidos]);
void mostrar_fixture();
int numero_aleatorio (int x);
void hacer_nulo (int a[]);
void hacer_nulo_matriz (int a[num_equipos][num_partidos]);
void vector_aleatorio (int a, int b[],int res, int au[num_equipos][num_partidos] );
void armar_fixture (int matriz[num_equipos][num_partidos]); 
void mostrar_para_ingresar(int num_fecha, int num_partido);
void leer_fixture();
void ingresar_amarillas(char equip1[],char equip2[],int num_fecha,int gol1,int gol2,int num_partido);
void control_tarjetas(char equip [], char nombre [],int num_fecha);
void jugadores_suspendidos();
int comprobar_fecha (int x);




int main()  //<---------------------principal
{
	system("mode con cols=90 lines=100");
	menu();
	return 0;
}

void menu()
{
	int x=0;
	unsigned int opc,equipos;
	int lo=0;
	equipos=limite_de_equipos();
	if(equipos<20)
	{
	
		do
		{
			printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
			printf("\t\t\tบ	   NUEVO TORNEO    	    บ\n");
			printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n\n");
			printf("\t\t\t1- Ingresar Nuevo Equipo\n");
			printf("\t\t\t2- Salir\n");
			printf("\t\t\tOpcion: ");
			scanf("%d",&opc);
			if(opc==1) guardar_equipo(nuevo_equipo());
		}while(opc==1);
	}
	if(equipos==20)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
			printf("\t\t\tบ	   MENU PRINCIAL    	    บ\n");
			printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
			printf("\n\n\n\n\n");
			printf("\t\t\t1- Mostrar Fixture.\n");
			printf("\t\t\t2- Tabla de Posiciones.\n");
			printf("\t\t\t3- Jugadores Suspendidos de la Fecha.\n");
			printf("\t\t\t4- Amonestados.\n");
			printf("\t\t\t5- Equipos.\n");
			printf("\t\t\t6- Jugadores.\n");
			printf("\t\t\t7- Modificaciones de los Datos de un Jugador.\n");
			printf("\t\t\t8- Puntero del Torneo.\n");
			printf("\t\t\t9- Datos de la Fecha.\n");
			printf("\t\t\t0- Salir.\n");
			printf("\t\tOpcion: ");
			scanf("%d",&opc);
			system("cls");
			switch(opc)
			{
				case 1:
				{
					if(x==0)
					{
						fixture();
					}
					mostrar_fixture();
					break;
				}
				case 2:
				{
					tabla_de_posiciones();
					break;
				}
				case 3:
				{
					jugadores_suspendidos();
					break;
				}
				case 4:
				{
					menu_amonestados();
					break;
				}
				case 5:
				{
					equipos_alfabeticamente();
					break;
					}
				case 6:
				{
					menu_juga();
					break;
				}
				case 7:
				{
					do
					{
						lo=contrasena(menu_contra());
					}while(lo==0);
					if(lo==1) busqueda_jugador_dni();
					break;
				}
				case 8:
				{
					ver_puntero ();
					break;
				}
				case 9:
				{
					ingresar_datos();
					break;
				}
				case 0:
				{
					menu_salida();
					break;
				}
			}
		}while(opc<10 && opc>0);	
	}
}

void menu_amonestados()
{
	unsigned int opc;
	do
	{
		system("cls");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	   MENU AMONESTADOS    	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
		printf("\t\t\t1- Jugadores con Roja\n");
		printf("\t\t\t2- Jugadores con Amarilla\n");
		printf("\t\t\t0- Salir\n");
		printf("\t\t\tOpcion: ");
		scanf("%d",&opc);
		system("cls");
		switch(opc)
		{
			case 1:
			{
				printf("sssss");
				juga_roja();
				break;
			}
			case 2:
			{
				juga_amarilla();
				break;
			}
		}
	}while(opc<3 && opc>0);
	
}

void menu_juga()
{
	unsigned int opc;
	do
	{
		system("cls");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	   MENU JUGADORES    	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
		printf("\t\t\t1- Jugadores de un Equipo\n");
		printf("\t\t\t2- Todos los Jugadores\n");
		printf("\t\t\t0- Salir\n");
		printf("\t\t\tOpcion: ");
		scanf("%d",&opc);
		system("cls");
		switch(opc)
		{
			case 1:
			{
				busqueda_equipo_nombre();
				break;
			}
			case 2:
			{
				jugadores_alfa();
				break;
			}
		}
	}while(opc<3 && opc>0);
}



//FUNCIONES DE EL INGRESO DE LOS EQUIPOS
equipo nuevo_equipo() //<-------------------------ingresa los datos del nuevo equipo
{
	int i,j,tam=0;
	equipo nuevo;
	system("cls");
	printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
	printf("\t\t\tบ	   NUEVO EQUIPO    	    บ\n");
	printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
	printf("\tNombre del Equipo: ");
	fflush(stdin);
	gets(nuevo.nombre);
	printf("\tBarrio de el Equipo:");
	fflush(stdin);
	gets(nuevo.barrio);
	for(i=0;i<20;i++)
	{
		system("cls");
		if(tam!=0)
		{
			printf("|N%c | %-40s| %-15s| %-5s|\n",248,"NOMBRES","DNI","EDAD");
			printf("|---|-----------------------------------------|----------------|------|\n");
			for(j=0;j<tam;j++)
			{
				printf("|%-3d| %-40s| %-15d| %-5d|\n",j+1,nuevo.jugadores[j].nombre,nuevo.jugadores[j].DNI,nuevo.jugadores[j].edad);
				printf("|---|-----------------------------------------|----------------|------|\n");
			}
		}
		tam++;
		printf("\t\nJugador[N%c%d]-->%s\n\n",248,i+1,nuevo.nombre);
		printf("\t\tNombre :");
		fflush(stdin);
		gets(nuevo.jugadores[i].nombre);
		printf("\t\tDNI: ");
		scanf("%d",&nuevo.jugadores[i].DNI);
		fflush(stdin);
		printf("\t\tEdad (18+): ");
		scanf("%d",&nuevo.jugadores[i].edad);
		fflush(stdin);
		nuevo.jugadores[i].tar_R=0;
		nuevo.jugadores[i].tar_A=0;
		if(nuevo.jugadores[i].edad<18)
		{
			printf("-------!LOS JUGADORES DE ESTE TORNEO DEBEN SER DE 18+ DE EDAD!------\n");
			i--;
			tam--;
			pausa();
		}
		
	}
	nuevo.Ptos=0;
	nuevo.goles.gol_favor=0;
	nuevo.goles.gol_contra=0;
	nuevo.goles.gol_dif=0;

	return nuevo;
}

void guardar_equipo(equipo E) //<-------------------Lo guarda en un archivo.bin a lo que ingresamos en nuevo_equipo
{
	FILE* A=fopen("equipos.bin","ab");
	if(A==NULL)
	{
		printf("Error");
		pausa();
	}
	else
	{
		fwrite(&E,sizeof(E),1,A);
		printf("\n\tEquipo Guardado!\n");
		pausa();
		fclose(A);
	}
}

int limite_de_equipos() //<---------------limites de equipos
{
	int i;
	FILE* A=fopen("equipos.bin","rb");
	equipo L;
	if(A==NULL)
	{
		i=0;
	}
	else
	{
		while(fread(&L,sizeof(L),1,A)) i++;
	}
	fclose(A);
	return i;
}


void pausa()  //<-----------------pausas
{
	printf("precione ENTER para conttinuar");
	while(getchar()!='\n');
	getchar();
	printf("");
}

int menu_contra()
{
	int j;
	do
	{
	
		system("cls");
		printf("\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\tบ	   PERIMISO ADMIN   	    บ\n");
		printf("\t\tศอออออออออออออออออออออออออออออออออออผ\n\n");
		printf("\t\t1- Ingresar Contrase%ca \n",164);
		printf("\t\t2- Modificar Contrase%ca\n",164);
		printf("\t\t0- Volver\n");
		printf("\t\tElijo: ");
		scanf("%d",&j);
		return j;
	}while(j<3 && j>0);
}

// FUNCIONES DE LA CONTRASEัA DEL USUARIO	Y BUSQUEDA POR DNI		DARIO---->07.06.15
int contrasena(int j)  //<-----------------------------contrase๑a!
{
	if(fopen("contra.bin","rb")==NULL)
	{
		FILE* C;
		char contra_defecto[7]="123456";
		C=fopen("contra.bin","wb");
		fwrite(&contra_defecto,7,1,C);
		fclose(C);
	}
	int validar=0,a=0;
	char co[7];
	if(j==1)
	{
		printf("Ingrese su contrase%ca de 6 digitos: ",164);
		fflush(stdin);
		gets(co);
		validar = validar_contrasena(co);
		while(validar==0 && a<3)
		{
			printf("Contrase%ca incorrecta, Ingrese de nuevo: ",164);
			fflush(stdin);
			gets(co);
			validar = validar_contrasena(co);
			if(validar==1) a=0;
			else a++;
		}
		if(a>2)
		{
			printf("Supero la cantidad de intentos");
			return 2;
		}
		if(validar==1)	printf("CONTRASE%cA CORRECTA!\n",165);
		return 1;
	}
	else
	{
		printf("Ingrese su contrase%ca: ",164);
		fflush(stdin);
		gets(co);
		validar = validar_contrasena(co);
		while(validar==0 && a<3)
		{
			printf("Contrase%ca incorrecta, Ingrese de nuevo: ",164);
			fflush(stdin);
			gets(co);
			validar = validar_contrasena(co);
			if(validar==1) a=0;
			else a++;
		}
		if(a>2)
		{
			printf("Supero la cantidad de intentos\n");
			return 2;
		}
		
		if(validar==1)
		{
			printf("CONTRASE%cA CORRECTA!\n",165);
			FILE* C;
			C=fopen("contra.bin","wb");
			printf("Ingrese su nueva contrase%ca de 6 digitos: ",164);
			fflush(stdin);
			gets(co);
			fwrite(&co,7,1,C);
			fflush(stdin);
			fclose(C);
			printf("CONTRASE%cA MODIFICADA\n",165);
			system("pause>NULL");
			system("cls");
		}
		
		return 0;
	}
}

int validar_contrasena(char co[]) //verifica que este bien la contrase๑a
{
	FILE* C;
	char fu[7];
	int l;
	C=fopen("contra.bin","rb");
	if(C==NULL)
	{
		printf("error");
		pausa();
	}
	else
	{
		fread(fu,7,1,C);
		l=strcmp(fu,co);
		if(l==0)
		{
			fclose (C);
			return 1;
		}
		else
		{
			fclose (C);
			return 0;
		}
	}
}


void busqueda_jugador_dni()  //<-----------------busqueda y modificacion del jugador por DNI
{
	int salto=0;
	long dni;
	FILE* B;
	int opc;
	int j=0,i=0,k=0,g=0;
	B=fopen("equipos.bin","r+b");
	if(B==NULL)
	{
		printf("Error");
		pausa();
	}
	else
	{
		equipo busq;
		do
		{
			system("cls");
			printf("\n\n\t\t\tIngrese el DNI del jugador:");
			scanf("%d",&dni);
			fseek(B,0,0);
			while( (fread(&busq,sizeof(busq),1,B)) && (salto==0))
			{
				k++; // se puede reemplazar por el filepos guarda la pocision real del archivo
				for(i=0;i<20;i++)
				{
					if(busq.jugadores[i].DNI==dni)
					{
						salto++;
						do
						{
							system("cls");
							printf("\n\n\t\t\tJugador de %s\n\n",busq.nombre);
							printf("\t\t1- nombre: %s\n",busq.jugadores[j].nombre);
							printf("\t\t2- DNI: %d\n",busq.jugadores[j].DNI);
							printf("\t\t3- Edad: %d\n\n",busq.jugadores[j].edad);
							printf("\t\t4- GUARDAR DATOS.\n");
							printf("\t\t5- SALIR.\n");
							printf("\t\tQue quiere modificar?: ");
							scanf("%d",&opc);
							if(opc==1)
							{
								printf("Ingrese nuevo nombre:");
								fflush(stdin);
								gets(busq.jugadores[j].nombre);
							}
							if(opc==2)
							{
								printf("Ingrese nuevo DNI: ");
								scanf("%d",&busq.jugadores[j].DNI);
							}
							if(opc==3)
							{
								do
								{
									printf("Ingrese nueva Edad (18+): ");
									scanf("%d",&busq.jugadores[j].edad);
								}while(busq.jugadores[j].edad<18);
							}
							if(opc==4)
							{
								fseek(B,sizeof(busq)*(k-1),0); //filepos(B) devuelve un long 
								fwrite(&busq,sizeof(busq),1,B);
							}
							
						}while(opc>0 && opc<4);
					}
				}
			}
			if(salto==0)
			{
				printf("NO se encontro al jugador con el DNI %d\n",dni);
				printf("Desea continuar buscando el DNI\n");
				printf("----- 1- Si ---- 2- No --------\n Opcion: ");
				scanf("%d",&opc);
				if(opc==2)	salto = 1;
			}
		}while(salto==0);
		fclose(B);
		printf("\n\n");
		pausa();
	}

}


// TABLA DE POSICIONES 				DARIO------> 08.06.15

void tabla_de_posiciones()
{
	FILE* P;
	int tam=20,i,j;
	P=fopen("equipos.bin","rb");
	char nombres[tam][50],nom[50];
	int ptos[tam],gol_con[tam],gol_fav[tam],dif_gol[tam],pt,gc,gf,df;
	equipo posicion;
	if(P==NULL)
	{
		printf("Error");
		pausa();
	}
	else
	{
		for(i=0;fread(&posicion,sizeof(posicion),1,P);i++)

		{
			strcpy(nombres[i],posicion.nombre);
			ptos[i]=posicion.Ptos;
			gol_con[i]=posicion.goles.gol_contra;
			gol_fav[i]=posicion.goles.gol_favor;
			dif_gol[i]=posicion.goles.gol_dif;
		}
		for(i = 0; i < tam-1; i++)
			for(j = tam-1; j > i; j--)
				if(ptos[j-1] < ptos[j])
				{
					pt= ptos[j-1];
					ptos[j-1]=ptos[j];
					ptos[j]=pt;

					gc= gol_con[j-1];
					gol_con[j-1]=gol_con[j];
					gol_con[j]=gc;

					gf= gol_fav[j-1];
					gol_fav[j-1]=gol_fav[j];
					gol_fav[j]=gf;

					df= dif_gol[j-1];
					dif_gol[j-1]=dif_gol[j];
					dif_gol[j]=df;

					strcpy(nom, nombres[j-1]);
					strcpy(nombres[j-1],nombres[j]);
					strcpy(nombres[j], nom);
				}
		printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("   	   บ	  	  TABLA DE POSICIONES		   บ\n");
		printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
		printf("\t|------------------------------------------------------|\n");
		printf("\t|%-30s %-5s %-5s %-5s %-5s|\n","Nombre","Ptos","GC","GF","DG");
		for(i=0;i<tam;i++)
		{
			printf("\t|------------------------------------------------------|\n");
			printf("\t|%-30s %-5d %-5d %-5d %-5d|\n",nombres[i],ptos[i],gol_con[i],gol_fav[i],dif_gol[i]);
		}
		printf("\t|------------------------------------------------------|\n");
		system("pause>NULL");
		fclose(P);
	}
}



void busqueda_equipo_nombre()		//<-------------busca a un equipo introduciendo el nombre
{
	FILE* E=fopen("equipos.bin","rb");
	char equi[50],jugadores[20][50];
	int c,i=0,h=0;
	equipo com;
	if(E==NULL)
	{
		printf("Error");
		pausa();
	}
	else
	{
		printf("Nombre del equipo: ");
		fflush(stdin);
		gets(equi);
		while(fread(&com,sizeof(com),1,E))
		{
			if((c=strcmp(equi,com.nombre))==0)
			{
				h=1;
				for(i=0;i<20;i++)
				{
					strcpy(jugadores[i],com.jugadores[i].nombre);
				}
			}
		}
		if(h!=0)
		{
			int tam=20,j;
			char temp[50];
			for(i = 0; i < tam-1; i++)
				for(j = tam-1; j > i; j--)
					if(strcmp(jugadores[j-1],jugadores[j]) > 0)
					{
						strcpy(temp,jugadores[j-1]);
						strcpy(jugadores[j-1],jugadores[j]);
						strcpy(jugadores[j], temp);
					}
			printf("\t\tJUGADORES DE %s\n",equi);
			for(i=0;i<tam;i++)
			{
				printf("\t%d-%s\n",i+1,jugadores[i]);
			}
			pausa();
			system("cls");
		}
	}
	fclose(E);
}

// si anda mal fijarse https://ar.answers.yahoo.com/question/index?qid=20100908205719AAK5m7K


void jugadores_alfa()
{
	FILE* J=fopen("equipos.bin","rb");
	equipo orden;
	int i,j=0,h;
	if(J==NULL)
	{
		printf("Error");
		pausa();
	}
	else
	{
		int tam=400;
		char matriz[tam][50];
		while(fread(&orden,sizeof(orden),1,J))
		{
			for(i=0;i<20;i++)
			{
				strcpy(matriz[j],orden.jugadores[i].nombre);
				j++;
			}
		}
		char temp[50];
		for(i = 0; i < tam-1; i++)
			for(j = tam-1; j > i; j--)
				if(strcmp(matriz[j-1],matriz[j]) > 0)
				{
					strcpy(temp, matriz[j-1]);
					strcpy(matriz[j-1],matriz[j]);
					strcpy(matriz[j], temp);
				}
		j=0;
		printf("\t\tTODOS LOS JUGADORES\n\n");
		while(j<400)
		{
			for(h=0;h<20;h++)
			{
				printf("%s\n",matriz[j]);
				fflush(stdin);
				printf("---------------------\n");
				j++;
			}
			system("pause>NULL");
		}
	fclose(J);
	}
}


void equipos_alfabeticamente()
{
	FILE* E=fopen("equipos.bin","rb");
	if(E==NULL)
	{
		printf("error");
		pausa();
	}
	else
	{
		int j,i;
		int tam=20; //es la cantidad de nombres a ordenar
		equipo nuevo;
		char matriz[tam][50];
		char temp[50];
		for(i=0;fread(&nuevo,sizeof(nuevo),1,E);i++)
		{
			fflush(stdin);
			strcpy(matriz[i],nuevo.nombre);
		}
			for(i = 0; i < tam-1; i++)
				for(j = tam-1; j > i; j--)
					if(strcmp(matriz[j-1],matriz[j]) > 0)
					{
						strcpy(temp, matriz[j-1]);
						strcpy(matriz[j-1],matriz[j]);
						strcpy(matriz[j], temp);
					}
			printf("\t\tEQUIPOS\n\n");
			for(i=0;i<tam;i++)
			{
				printf("\t%s\n",matriz[i]);
				printf("\t-------------------\n");
			}
		    
		fclose(E);
	system("pause");

	}

}

void juga_roja()
{
	FILE* A=fopen("equipos.bin","rb");
	if(A==NULL)
	{
		printf("error.");
	}
	else
	{
		equipo aux;
		int tam=400;
		char nombre[tam][50],nom[50];
		int rojas[tam],tama=0,ro,ninguno=0,i,j,k=0;
		while(fread(&aux,sizeof(aux),1,A))
		{
			
			for(i=0;i<20;i++)
			{
				strcpy(nombre[k],aux.jugadores[i].nombre);
				rojas[k]=aux.jugadores[i].tar_R;
				k++;
				if(aux.jugadores[i].tar_R>0)	tama++;
			}
		}
		if(tama==0) 
		{
			printf("\n-----------NINGUN JUGADOR TIENE ROJA.-----------\n");
			ninguno++;
			system("pause>NULL");
		}		
		if(tama!=0)
		{
			for(i = 0; i < tam-1; i++)
				for(j = tam-1; j > i; j--)
					if(rojas[j-1] < rojas[j] )
					{
						
						ro= rojas[j-1];
						rojas[j-1]=rojas[j];
						rojas[j]=ro;
							
						strcpy(nom, nombre[j-1]);
						strcpy(nombre[j-1],nombre[j]);
						strcpy(nombre[j], nom);
					}
		}

		if(ninguno==0)
		{
			printf("%-50s %-5s\n","NOMBRES","TARJETAS ROJAS");
			printf("-------------------------------------------------\n");
			for(i=0;i<tam;i++)
			{
				if(rojas[i]>0)
				{
					printf("%-50s %-5d\n",nombre[i],rojas[i]);
					printf("-----------------------------------------------\n");
					system("pause>NULL");
				}
			}
		}
	}
	fclose(A);
}

void juga_amarilla()
{
	FILE* A=fopen("equipos.bin","rb");
	if(A==NULL)
	{
		printf("error.");
	}
	else
	{
		equipo aux;
		int tam=400;
		char nombre[tam][50],nom[50];
		int amar[tam],tama=0,ro,ninguno=0,i,j,k=0;
		while(fread(&aux,sizeof(aux),1,A))
		{
			
			for(i=0;i<20;i++)
			{
				strcpy(nombre[k],aux.jugadores[i].nombre);
				amar[k]=aux.jugadores[i].tar_A;
				k++;
				if(aux.jugadores[i].tar_A>0)	tama++;
			}
		}
		if(tama==0) 
		{
			printf("\n-----------NINGUN JUGADOR TIENE AMARILLA.-----------\n");
			ninguno++;
			system("pause>NULL");
		}		
		if(tama!=0)
		{
			for(i = 0; i < tam-1; i++)
				for(j = tam-1; j > i; j--)
					if(amar[j-1] < amar[j] )
					{
						
						ro= amar[j-1];
						amar[j-1]=amar[j];
						amar[j]=ro;
							
						strcpy(nom, nombre[j-1]);
						strcpy(nombre[j-1],nombre[j]);
						strcpy(nombre[j], nom);
					}
		}

		if(ninguno==0)
		{
			printf("%-50s %-5s\n","NOMBRES","TARJETAS AMARILLAS");
			printf("-------------------------------------------------\n");
			for(i=0;i<tam;i++)
			{
				if(amar[i]>0)
				{
					printf("%-50s %-5d\n",nombre[i],amar[i]);
					printf("-----------------------------------------------\n");
					system("pause>NULL");
				}
			}
		}
	}
	fclose(A);
}

void fixture()
{
	int matriz[num_equipos][num_partidos];
	int opc;
	FILE* A=fopen("fixture.txt","rt");
	if(A==NULL)
	{
		printf("\nNO EXISTE FIXTURE GENERADO \nDESEA GENERAR UNO?\n1=SI 2=NO  ");
		scanf("%d",&opc);
		if(opc==1)
		{
			hacer_nulo_matriz(matriz);
			calcular_fixture(matriz);
			armar_fixture(matriz);
			leer_fixture();
			mostrar_fixture();
		}
		
	}
	else
	{
		leer_fixture();
		mostrar_fixture();
	}
	
}

void hacer_nulo (int a[])
{
	for (int i=0;i<num_partidos;i++)
	{
		a[i]=' ';
	}
}

int numero_aleatorio (int x)
{
	int cambio =num_equipos;
	int numero;
	int hora = time(NULL);  
    srand(hora);  
    numero =x+ rand()%(cambio-x); 
	return numero;
	
}

void hacer_nulo_matriz (int a[num_equipos][num_partidos])
{
	for (int i=0;i<num_equipos;i++)
	{	
		for(int j=0;j<num_partidos;j++)
		a[i][j]=' ';
	}
}
void vector_aleatorio (int a, int b[],int res, int au[num_equipos][num_partidos] )
{
	
	int x,i,j,k,s,t;
	int aux='\0',aux2=0,bam=0,salto=0,salto2=0,filas=0,aux_num_partidos,super_bandera=0,saltonum_partidos=0;
	int cantidad=num_partidos,tam=num_partidos;
	int array_b[num_partidos];
	
	hacer_nulo(array_b);
	tam=tam-res;
	
	if(tam!=0)
	{
			do
	{	
		
		salto=0;
		
		do
		{	
			
			x=numero_aleatorio(a);
			if(x>res && x!=aux)salto++;	
			
		}while(salto==0);
		
		aux2=0;
		salto2=0;
		if(x!=aux && x!=a)
		{	
			for(i=0;i<tam;i++)
			{
				
					
				if(aux2==0)
				{	
					if(b[i]!=x)
					{
						
						if(b[i]==' ')
						{	
							for(j=0;j<num_partidos;j++)
							{
								if(b[j]==x)
								{
									salto2++;
									}
						
								
							}
							if(salto2==0)
							{
								
								b[i]=x;
								aux2++;
								bam++;
								aux=x;
								
							}
						
							
						}
					}
					
				}
			}
		}
		
		
	}while(bam!=tam);
	
	
	
	for(i=0;i<num_partidos;i++)
	{
		array_b[i]=b[i];
	}
	int columnas_bien=0;
	
		
					for(j=0;j<tam;j++)
					{
				
						}
	salto2=0;
	for(j=0;j<num_equipos;j++)
					{	
						
						if(filas<tam)
						{
							for(i=0;i<num_partidos;i++)
							{
								salto=0;
								
							
									for(s=0;s<tam;s++)
									{
										saltonum_partidos=0;
									
										if( array_b[s]!=' ' && salto==0 && salto2!=tam && au[j][i]==' ' && saltonum_partidos==0 )
										{
											
											au[j][i]=array_b[s];
											array_b[s]=' ';
											filas++;salto++;
											salto2++;
											saltonum_partidos++;
											
											
										}
									
									}
									
								}
						
							}
	
						}
							
					for(j=0;j<num_equipos;j++)
						{
							for(k=0;k<num_partidos;k++)
							{
								
								}
						}
			
		for(j=0;j<num_equipos;j++)
			{
				
				aux2=0;
					for(i=0;i<num_partidos;i++)
				{
					aux2=i;
					if(au[j][i]!=' ')
					{	
				
							for(k=0;k<num_equipos;k++)
							{
								
								if (au[k][i] == au[j][i] &&  au[j][i]!= ' ' && au[k][i]!= ' ' && k!=j )
								{
									
									
									aux2++;
									aux=au[k][i];
									super_bandera=0;
									for (s=0;s<num_partidos;s++)
									{	
																	
										if(au[k][s]!=aux && (au[k][s]== ' ' || au[k][s]>=a) )
										{
											for(t=0;t<num_equipos;t++)
											{
												if(au[t][i]==au[k][s] && t>j && super_bandera==0)
												{
													super_bandera++;
												}												
											}
											if(super_bandera==0)
											{	
												au[k][i]=au[k][s];
												au[k][s]=aux;
											}	
										}	
									}
								}
							}
						}
					}
				}	
}
else 
for(i=0;i<num_equipos;i++)
{
	for(j=0;j<num_partidos;j++)
	{
		if(au[i][j]==' ')
		{
			au[i][j]=cantidad;
		}
	}
}
		
		
}



void calcular_fixture(int aux_array[num_equipos][num_partidos])
{
	int i,j,c,k,s,guardar_i,aux_num_equipos,x,guar_fila,guar_colum,aux,fin;
	int salto=0,pasadas=0,asig_fila=0;
	int array[num_partidos],array_aux1[num_partidos];

	hacer_nulo_matriz(aux_array);

	
				
	for(i=0;i<num_equipos;i++)
	{
	
			guardar_i++;
			hacer_nulo(array);
			asig_fila=0;
			guardar_i=i;
			
			vector_aleatorio(i,array,pasadas,aux_array);
				
				for(j=0;j<num_partidos;j++)
					{
						array_aux1[j]=array[j];
					}		
		
	for(k=0;k<num_partidos;k++)
	{
		
		salto=0;
		for(j=0;j<num_equipos;j++)
	
		{
			for(s=0;s<num_partidos;s++)
			{
				if(array_aux1[k]!=' ' && (aux_array[j][s]== ' ' || array_aux1[k]==aux_array[j][s]) ) 
				
				{
	
					if ( array_aux1[k]==aux_array[j][s])
					{	
						if(salto==0)
						{
					
							if(j>=i )
							{
								salto++;
								guar_fila=array_aux1[k];
								guar_colum=s;
								aux_array[guar_fila][s]=i;
							}
						} 
					}
				}
			}
		}
	}

	pasadas++;
}

}

void armar_fixture(int matriz [num_equipos][num_partidos])
{
	int i,j,f,k,aux_i,num_partido;
	equipo nombres;
	partidos fix;
	char nombres_matriz[num_equipos][50];
	FILE* A,*B,*C;
	A=fopen("fixture.txt","wt");
	B=fopen("equipos.bin","rb");
	C=fopen("fechas.bin","wb");
	if(C==NULL)printf("\nERROR \n");
	if(A==NULL)printf("\nERROR NO SE PUDO GENERAR FIXTURE\n");
	if(B==NULL)printf("\nERROR \n");
	else
	{
		
		for(i=0;i<num_partidos;i++)
		{
			fprintf(A,"\n");
			for(j=0;j<num_equipos;j++)
				{
				fprintf(A,"%d ",matriz[i][j]);
				}
		}
		i=0;
		while(fread(&nombres,sizeof(equipo),1,B)!=NULL)
		{
			strcpy(nombres_matriz[i],nombres.nombre);
			i++;
		}
		
	}
	for(i=0;i<num_partidos;i++)
	{	
		f=i;
		f++;
		for(j=0;j<num_equipos;j++)
		{
			num_partido=j;
			num_partido++;	
			fix.fecha=f;
			strcpy(fix.equipos,nombres_matriz[matriz[j][i]]);
			strcpy(fix.equipos,nombres_matriz[matriz[num_partido][i]]);	
		}
	}
	fwrite(&fix,sizeof(partidos),1,C);
	
	
	fclose(A);
	fclose(B);
	fclose(C);
}


void leer_fixture()
{
	int i=0,j,f,a;
	long posicion;
	int matriz [380];
	char nombres_matriz[19][50];
	
	partidos fix;
	equipo nombre;
	FILE* A=fopen("fechas.bin","a+b");
	FILE*B=fopen("equipos.bin","rb");
	FILE* C=fopen("fixture.txt","rt");
	if(A==NULL)printf("\nERROR\n");
	if(B==NULL)printf("\nERROR\n");
	if(C==NULL)printf("\nERROR\n");
	else
	{
		//cargo matriz nombres
		while(fread(&nombre,sizeof(equipo),1,B)!=NULL)
		{
			strcpy(nombres_matriz[i],nombre.nombre);
			
			i++;
		}
		
	//cargo la matriz fixture
	for(i=0;i<380;i++)
	{
		
		
			fscanf(C,"%d",&a);
			matriz[i]=a;	
		
	}
	//asigno a la estructura FECHAS	
	printf("\nPosicion del scaner := %d \n",posicion);
	/*while(fread(&fix,sizeof(partidos),1,A)!=NULL)
	
	{
		posicion=ftell(A);
		printf("\nPosicion del scaner := %d \n",posicion);
		system("pause");*/
		i=1;
		for(j=0;j<380;j++)//20
		{
			printf("\n\n");
			printf("\n///////Posicion del scaner := %d \n",posicion);
			fix.fecha=i;
			fix.goles=' ';
			strcpy(fix.equipos,nombres_matriz[matriz[j]]);
			fwrite(&fix,sizeof(FECHAS),1,A);
			printf("\nEquipo: %s\ngoles= %d",fix.equipos,fix.goles);
			i++;
			/*system("pause>NULL");*/
			
		}
		
	/*}*/
		
	
	
	rewind(A);printf("\nleyendo fechas...\n");
	while(fread(&fix,sizeof(partidos),1,A)!=NULL)
	{
		printf("\nEquipo: %s\n",fix.equipos);
	}
	rewind(A);
	while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
	{
		if(fix.goles==' ')
		{
			fix.goles=0;
		}
	}

	
	
		
		
	}
	
	fclose(A);
	fclose(B);
	fclose(C);
}


int comprobar_fecha (int x)
{
	partidos comprobar;
	int traba=0;
	FILE*A=fopen("fechas.bin","rb");
	if(A==NULL)printf("\nERROR");
	else
	{
		while(fread(&comprobar,sizeof(partidos),1,A)!=NULL)
		{
			/*printf("\nfecha= %d  goles= %d\ntraba= %d\ncomprobar fecha= %d\n",x,comprobar.goles,traba,comprobar.fecha);
			    */
			if(comprobar.fecha==x)
			{
				if(comprobar.goles==' ')traba++;
				/*printf("\nASIGNO");
				printf("\nfecha= %d  goles= %d\ntraba= %d\n",x,comprobar.goles,traba);
				    */
						}
		}
	}
	fclose(A);
	return traba;
	
	
}
void mostrar_fixture()
{
	int salt=0;
	int dec,x;
	int contador=1;
	partidos fix;
	FILE*A=fopen("fechas.bin","rb");
	if(A==NULL)printf("ERROR");
	else
	{
		for(int i=1;i<=num_partidos;i++)
		
		{	
			printf("\n\n\n\n\n\n\n");
			printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
			printf("\t\t\tบ	      FIXTURE	      	    บ\n");
			printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
			printf("\n\n\n");
			printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,i,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
			rewind(A);contador=1;
			while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
			{
				printf("\n\nfecha:%d	goles:%d\n\nequipo:%s",fix.fecha,fix.goles);
				system("pause>NULL");
				if(i==fix.fecha && fix.goles==' ')
				{
					if(salt==0)
					{	
						printf("\n");
						printf("%d->\t",contador);
						printf("%-35s %c",fix.equipos,32);
						salt++;
					}
					else
					{
						printf("%-20s","VS");
						printf("%-35s %c",fix.equipos,32);
						salt=0;contador++;
					}
					
					
				}
				else
				{
					salt==0;
					if(i==fix.fecha)
					{
						printf("\n\nfecha:%d	goles:%d\n\nequipo:%s",fix.fecha,fix.goles);
						system("pause>NULL");
						printf("\n\n");
						if(salt==0)
						{
							printf("\n");
							printf("%d->\t",contador);
							printf("%-35s %-5d ",fix.equipos,fix.goles);
							salt++;
						}
						else
						{
							printf("\n\nfecha:%d	goles:%d\n\nequipo:%s",fix.fecha,fix.goles);
							system("pause>NULL");
							printf("%-20s","VS");
							printf("%-5d%-35s ",fix.goles,fix.equipos);
							salt=0;contador++;
						}
									
						
					}
						
				}
				
				
			}
			printf("\n\n\n");
			printf("\n1-PASAR A LA SIGUIENTE FECHA\n2-INGRESAR DATOS DEL PARTIDO\n3-VOLVER AL MENU INICIAL\n");
			scanf("%d",&dec);
			if(dec==1)
			{
				system("cls");
				x=comprobar_fecha(i);
				/*printf("\nx= %d\n",x);
				    */
				if(x!=0)
				{
					do
					{
						system("cls");
						printf("\n\n\n\n\n\n\n");
						printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
						printf("\t\t\tบ	      FIXTURE	      	    บ\n");
						printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
						printf("\n\n\n");
						printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,i,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
									
						contador=1;
						rewind(A);
						while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
						{
								if(i==fix.fecha && fix.goles==' ')
						{
							if(salt==0)
							{	
								printf("\n");
								printf("%d->\t",contador);
								printf("%-35s %c",fix.equipos,32);
								salt++;
							}
							else
							{
								printf("%-20s","VS");
								printf("%-35s %c",fix.equipos,32);
								salt=0;contador++;
							}
					
						
						}
					
						
						}
						
						printf("\n\n\n");
						printf("\n\t\tNO SE AN LLENADO TODOS LOS PARTIDOS\n\t\tNO PUEDE PASAR A LA SIGUIENTE FECHA\n\t\t");
						printf("\n\n\n");
						
						
						printf("\n1-PASAR A LA SIGUIENTE FECHA\n2-INGRESAR DATOS DEL PARTIDO\n3-VOLVER AL MENU INICIAL\n");
						scanf("%d",&dec);
						if(dec==1)
						{
							x=comprobar_fecha(i);
						}
						if(dec==2) 
						{
							system("cls");
							ingresar_datos();
							
							i=i-1;
							}
							
					if(dec==3)break;
						
						
					}while(x!=0);	
						
					
					
				} 
				
			
			}	
			if(dec==2) 
			{
				ingresar_datos();
				system("cls");
				i=i-1;
				
			}
			if(dec==3)break;
			
	}
	fclose(A);
	menu();
	
	
}
}

void mostrar_para_ingresar(int num_fecha, int num_partido)
{
	int i=0;
	int salto=0;
	int encontrado=0;
	int contador =1;
	int salt=0;
	int dec;
	int gol1,gol2;
	char equip1 [50];
	char equip2 [50];
	partidos fix;
	equipo ingreso;
	FILE* A=fopen("fechas.bin","r+b");
	FILE* B=fopen("equipos.bin","r+b");
	if(A==NULL)printf("ERROR");
	else
	{
	for(int i=1;i<=num_partidos;i++)
		
	{	
		if(num_fecha==i)
		{
			rewind(A);contador=1;
					while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
				{	
					if(i==fix.fecha && fix.goles==' ')
					{
						if(salt==0)
						{	
							salt++;
							if(num_partido==contador)
							{
								strcpy(equip1,fix.equipos);
								encontrado++;
							}
						}
						else
						{
							salt=0;
							if(num_partido==contador)
							{
								strcpy(equip2,fix.equipos);
								encontrado++;
							}
							contador++;
						}
					}
					else
					{
						if(i==fix.fecha)
						{
							if(salt==0)
							{
								salt++;
								if(num_partido==contador)
								{
									strcpy(equip1,fix.equipos);
									encontrado++;
									encontrado++;
								}
							}
							else
							{
								salt=0;
								if(num_partido==contador)
								{
									strcpy(equip2,fix.equipos);
									encontrado++;
									encontrado++;
								}
								contador++;
							}
						}
					}
				}
		}
			
			
				
	}
	
if(encontrado==2)
	{	
	    system("cls");
	    
	    printf("\n\n\n\n\n\n\n");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	      RESULTADOS     	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
    	printf("\n\n\n");
	    printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,num_fecha,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	    printf("\n\n\n");
	    printf("%d---->\t",num_partido);
	    printf("%-35s %-20s %-35s",equip1,"VS",equip2);
	    printf("\n\n\n%s-------->Goles Logrados= ",equip1);
	    scanf("%d",&gol1);
	    system("cls");
	    fflush(stdin);
	    printf("\n\n\n\n\n\n\n");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	      RESULTADOS     	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
    	printf("\n\n\n");
	    printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,num_fecha,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	    printf("\n\n\n");
	    printf("%d---->\t",num_partido);
	    printf("%-30s%-5d%-20s%-35s",equip1,gol1,"VS",equip2);
	    fflush(stdin);
	    printf("\n\n\n%s-------->Goles Logrados= ",equip2);
	    scanf("%d",&gol2);
	    system("cls");
	    printf("\n\n\n\n\n\n\n");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	      RESULTADOS     	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
    	printf("\n\n\n");
	    printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,num_fecha,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	    printf("\n\n\n");	
	    printf("%-30s %-5d%-20s%-5d%-30s",equip1,gol1,"VS",gol2,equip2);
	    system("cls");
	    printf("\n\n\n\n\n\n\n");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	      RESULTADOS     	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
    	printf("\n\n\n");
	    printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,num_fecha,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	    printf("\n\n\n");
	    printf("%d---->\t",num_partido);
	    printf("%-30s %-5d%-7s%-15d%-30s",equip1,gol1,"VS",gol2,equip2);
	   if(gol1<gol2)
	   {
	   	printf("\n			Ganador %s +3 Puntos!!!\n",equip2);
	   	rewind(A);
	   	rewind(B);
	   	while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
	   	{
	   		i++;
	   		if(strcmp(fix.equipos,equip1)==0 && fix.fecha==num_fecha && salto==0)
			   {
			   	fix.goles=gol1;
			   	fseek(A,(i-1)*sizeof(A),1);
			   	fwrite(&fix,sizeof(partidos),1,A);
				salto++;
			   	printf("\n\n%d\n%s\n%d\n",fix.goles,fix.equipos,fix.fecha);
			   	system("pause");
			   }
			   
			if(strcmp(fix.equipos,equip2)==0 && fix.fecha==num_fecha)
			   {
			   	fix.goles=gol2;
			   	printf("\n%d",fix.goles);
			   	fseek(A,(i-1)*sizeof(A),1);
			   	fwrite(&fix,sizeof(partidos),1,A);
			   	printf("\n%d\n%s\n%d",fix.goles,fix.equipos,fix.fecha);;
			   	system("pause");
			   }	
			   
	   	}
	   	
	   	while(fread(&ingreso,sizeof(EQUIPOS),1,B)!=NULL)
	   	   {
	   	   	if(strcmp(ingreso.nombre,equip2)==0)
			   {
			   	ingreso.Ptos=ingreso.Ptos+3;
			   	ingreso.goles.gol_favor=ingreso.goles.gol_favor+gol2;
			   	ingreso.goles.gol_contra=ingreso.goles.gol_contra+gol1;
			   	ingreso.goles.gol_dif=ingreso.goles.gol_dif+(gol2-gol1);
			   }
			  if(strcmp(ingreso.nombre,equip1)==0)
			  {
			   	ingreso.goles.gol_favor=ingreso.goles.gol_favor+gol1;
			   	ingreso.goles.gol_contra=ingreso.goles.gol_contra+gol2;
			   	ingreso.goles.gol_dif=ingreso.goles.gol_dif+(gol1-gol2);
			   } 
		   }
		fflush(stdin);
		printf("\n		Se realizaron sanciones en el partido?\n1-SI\n2-NO	");
		scanf("%d",&dec);
		if(dec==1)ingresar_amarillas(equip1,equip2,num_fecha,gol1,gol2,num_partido);
	   }
	   if(gol1>gol2)
	   {
	   	printf("\n\n\n\n\n\n\n\n			Ganador %s +3 Puntos!!!\n",equip1);
	   	rewind(A);
	   	rewind(B);
	   	while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
	   	{
	   		if(strcmp(fix.equipos,equip1)==0)
			   {
			   	fix.goles=gol1;
			   }
			if(strcmp(fix.equipos,equip2)==0)
			   {
			   	fix.goles=gol2;
			   }	
	   	}
	   	while(fread(&ingreso,sizeof(EQUIPOS),1,B)!=NULL)
	   	   {
	   	   	if(strcmp(ingreso.nombre,equip1)==0)
			   {
			   	ingreso.Ptos=ingreso.Ptos+3;
			   	ingreso.goles.gol_favor=ingreso.goles.gol_favor+gol1;
			   	ingreso.goles.gol_contra=ingreso.goles.gol_contra+gol2;
			   	ingreso.goles.gol_dif=ingreso.goles.gol_dif+(gol1-gol2);
			   }
		   if(strcmp(ingreso.nombre,equip2)==0)
		   {
		   	ingreso.goles.gol_favor=ingreso.goles.gol_favor+gol2;
		   	ingreso.goles.gol_contra=ingreso.goles.gol_contra+gol1;
		   	ingreso.goles.gol_dif=ingreso.goles.gol_dif+(gol2-gol1);
			}
		   }
		fflush(stdin);
		printf("\n\n\n\n\n		Se realizaron sanciones en el partido?\n1-SI\n2-NO	");
		scanf("%d",&dec);
		if(dec==1)ingresar_amarillas(equip1,equip2,num_fecha,gol1,gol2,num_partido);
	   }
	   if(gol1==gol2)
	   {
	   	printf("\n\n\n\n\n				Empate  +1 Puntos para cada Equipo\n");
	   	while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
	   	{
	   		if(strcmp(fix.equipos,equip1)==0)
			   {
			   	fix.goles=gol2;
			   }
			if(strcmp(fix.equipos,equip2)==0)
			   {
			   	fix.goles=gol1;
			   }	
	   	}
	   	while(fread(&ingreso,sizeof(EQUIPOS),1,B)!=NULL)
	   	   {
	   	   	if(strcmp(ingreso.nombre,equip1)==0)
			   {
			   	ingreso.Ptos=ingreso.Ptos+1;
			   }
		    if(strcmp(ingreso.nombre,equip2)==0)
			   {
			   	ingreso.Ptos=ingreso.Ptos+1;
			   }
		   }
		fflush(stdin);
		printf("\n\n\n\n\n		Se realizaron sanciones en el partido?\n1-SI\n2-NO	");
		scanf("%d",&dec);
		if(dec==1)ingresar_amarillas(equip1,equip2,num_fecha,gol1,gol2,num_partido);
	   }
	}
if(encontrado==4)
{
	while(fread(&fix,sizeof(FECHAS),1,A)!=NULL)
	{
		if(fix.fecha==num_fecha)
		{
			if(strcmp(fix.equipos,equip1)==0)
			{
				gol2=fix.goles;
			}
			if(strcmp(fix.equipos,equip1)==0)
			{
				gol1=fix.goles;
			}
		}
	}
	   system("cls");
	   printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,num_fecha,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	   printf("%s %d ",gol2,equip1);
  	   printf("%*s", ANCHO_PANTALLA/4 + strlen(equip1)/2, "VS");
	   printf("  %d %*s",gol1, ANCHO_PANTALLA/3,equip2);
	   printf("\n\n				PARTIDO YA JUGADO!!!!\n");
}
if(encontrado==0) printf("\n				NO EXISTE PARTIDO\n");
}
fclose(A);
fclose(B);
pausa();
system("cls");	
}

void ingresar_amarillas(char equip1[],char equip2[],int x,int gol1,int gol2, int num_partido)
{
	FILE* A;
	int contador=0;
	int i,k=0,amarilla1,amarilla2,jug,tarjeta;
	int salto1=0,salto2=0;
	char nom1[50],nom2[50];
	equipo amarillas;
	A=fopen("equipos.bin","r+b");
	if(A==NULL)printf("\nError\n");
	else
	{
		
		fflush(stdin);
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\tษอออออออออออออออออออออออออออออออออออป\n");
		printf("\t\t\tบ	     AMONESTACIONES	    บ\n");
		printf("\t\t\tศอออออออออออออออออออออออออออออออออออผ\n");
		printf("\n\n\n");
		printf("\nPARTIDOS%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%cFECHA N%c %d%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,x,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
		
		printf("%s		%d	VS	%d		%s\n",equip1,gol2,gol1,equip2);	
		printf("chau");			
		printf("\t\t");
		printf("\n\n");
		printf("\t\t");
		printf("Numero de Amonesados en el Equipo %s: ",equip1);
		scanf("%d",&amarilla1);
		printf("\n\n");
		printf("\t\t");
		printf("Numero de Amonesados en el Equipo %s: ",equip2);
		scanf("%d",&amarilla2);
		rewind(A);
		//equipo 1
		while(k<amarilla1)
		{
			
			
		
			
				k=0;
				/*printf("\nk= %d marilla= %d equip2",k,amarilla1);
				    */
				while(fread(&amarillas,sizeof(EQUIPOS),1,A)!=NULL)
				{
					contador++;
					if(strcmp(equip1,amarillas.nombre)==0)
				{ 	
					/*printf("\namarrilla1= %d  amarilla 2= %d\n\n",amarilla1,amarilla2);*/
					printf("\nJugadores del Equipo %s	\n",amarillas.nombre);
					for(i=0;i<20;i++)
					{
						
						printf("\t\t");
						printf("N%c->%d %s\n",167,i,amarillas.jugadores[i].nombre);
					
					}
				
			
				
					fflush(stdin);
					printf("\n\n");
					printf("\t\t");
					printf("	Ingrese el Numero del Jugador amonestado:  ");
					scanf("%d",&jug);
					printf("\n\n");
					printf("\t\t");
					printf("\n\t\tNombre: %s Equipo: %s \n\t\tTarjetas Amarillas: %d\n\t\tTarjetas Rojas: %d\n\t\t",amarillas.jugadores[jug].nombre,equip1,amarillas.jugadores[jug].tar_A,amarillas.jugadores[jug].tar_R);
					printf("\n\n");
					fflush(stdin);
					printf("\n\t\t1-Una Tarjeta Amarilla\n\t\t2-Tarjeta Roja\n\tOpcion: ");
					scanf("%d",&tarjeta);
					if(tarjeta==1)
					{
						amarillas.jugadores[jug].tar_A=amarillas.jugadores[jug].tar_A+1;
						amarillas.jugadores[jug].fecha=x;
						amarillas.jugadores[jug].partido=num_partido;
					}
					else
					{
						amarillas.jugadores[jug].tar_R=amarillas.jugadores[jug].tar_R+1;
						amarillas.jugadores[jug].partido=num_partido;
						amarillas.jugadores[jug].fecha=x;
					}
					    
					
					printf("\n\t\tNombre: %s Equipo: %s \n\t\tTarjetas Amarillas: %d\n\t\tTarjetas Rojas: %d\n",amarillas.jugadores[jug].nombre,equip1,amarillas.jugadores[jug].tar_A,amarillas.jugadores[jug].tar_R);
					fseek(A,(contador-1)*sizeof(A),0);
					fwrite(&amarillas,sizeof(EQUIPOS),1,A);
					printf("\n\t\tGuardado!!\n");
					strcpy(nom1,amarillas.jugadores[jug].nombre);
					/*printf("\nnos vamos a la funciones\n");
					puts(equip1);puts(nom1);
					    */
					control_tarjetas(equip1,nom1,x);
					
					/*printf("\nvolvemos d la funcion\n");*/
					
					k++;
					/*printf("\namarilla1= %d \nk=  %d\n",amarilla1,k);
					    */
					
					
				}		
			
			}
		
			
		}
		rewind(A);k=0;
		contador=0;
		//equipos 2
		while(k<amarilla2)
		{
			
			
				
				/*printf("\nk= %d marilla= %d equip2",k,amarilla1);
				    */
				while(fread(&amarillas,sizeof(EQUIPOS),1,A)!=NULL)
				{
					contador++;
				if(strcmp(equip2,amarillas.nombre)==0)
				{	
					printf("\nJugadores del Equipo %s	\n",amarillas.nombre);
					for(i=0;i<20;i++)
					{
						
						printf("\t\t");
						printf("N%c->%d %s\n",167,i,amarillas.jugadores[i].nombre);
					
					}

					fflush(stdin);
					printf("\n\n");
					printf("\t\t");
					printf("	Ingrese el Numero del Jugador amonestado:  ");
					scanf("%d",&jug);
					printf("\n\n");
					printf("\t\t");
					printf("\n\t\tNombre: %s Equipo: %s \n\t\tTarjetas Amarillas: %d\n\t\tTarjetas Rojas: %d\n\t\t",amarillas.jugadores[jug].nombre,equip2,amarillas.jugadores[jug].tar_A,amarillas.jugadores[jug].tar_R);
					printf("\n\n");
					fflush(stdin);
					printf("\n\t\t1-Una Tarjeta Amarilla\n\t\t2-Tarjeta Roja\n\tOpcion: ");
					scanf("%d",&tarjeta);
					if(tarjeta==1)
					{
						amarillas.jugadores[jug].tar_A=amarillas.jugadores[jug].tar_A+1;
						amarillas.jugadores[jug].partido=num_partido;
						amarillas.jugadores[jug].fecha=x;
					}
					else
					{
						amarillas.jugadores[jug].tar_R=amarillas.jugadores[jug].tar_R+1;
						amarillas.jugadores[jug].partido=num_partido;
						amarillas.jugadores[jug].fecha=x;
					}
					printf("\n\t\tNombre: %s Equipo: %s \n\t\tTarjetas Amarillas: %d\n\t\tTarjetas Rojas: %d\n",amarillas.jugadores[jug].nombre,equip1,amarillas.jugadores[jug].tar_A,amarillas.jugadores[jug].tar_R);
					fseek(A,(contador-1)*sizeof(A),0);
					fwrite(&amarillas,sizeof(EQUIPOS),1,A);
					printf("\n\t\tGuardado!!\n");
					strcpy(nom2,amarillas.jugadores[jug].nombre);
					/*printf("\nnos vamos a la funciones\n");
					puts(equip2);puts(nom2);
					    */
					control_tarjetas(equip2,nom2,x);
					/*printf("\nvolveer\n");*/
						
					k++;
					/*printf("\namarilla2= %d \nk= %d\n",amarilla2,k);*/
					
				}
	
			}
			
			
		}
			
	}
	
	fclose(A);
	pausa();
}

void control_tarjetas (char equip [],char nombre [],int fecha_actual)
{
	int i,salto=0,k=0;
	equipo control;
	FILE* A=fopen("equipos.bin","r+b");
	if(A==0) printf("Error");
	else
	{
		
		while(fread(&control,sizeof(EQUIPOS),1,A)!=NULL)
		{
			system("cls");
			/*printf("\nleyendo archivo\n");
			    */
			k++;
			if(strcmp(equip,control.nombre)==0 && salto==0)
			{
				/*printf("\ncomparando nombredel equipo\n");
				puts(equip);puts(control.nombre);
				    */
				for(i=0;i<20;i++)
				{
					/*printf("\ncrecorriendo jugadorres\n");
					puts(nombre);puts(control.jugadores[i].nombre);
					    */
					if(strcmp(nombre,control.jugadores[i].nombre)==0 && salto==0)
					{
													
						for(i=0;i<20;i++)
						{
							if(fecha_actual>control.jugadores[i].fecha)
							{
									
							}
						}
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						/*printf("\nse encontro jugaodr\n");
						    */
						
							/*if(control.jugadores[i].tar_A>=5)
							{
								/*printf("\nASIGNO\n");
								printf("\n///\n");*/
							/*	printf("\nJugador Suspendido!!! NO JUEGA PROXIMA FECHA\n");
								strncat( control.jugadores[i].nombre, "*", 1 );
								fseek(A,sizeof(A)*(k-1),0);
								fwrite(&control,sizeof(EQUIPOS),1,A);
								fecha_guardada=fecha_actual;
								salto++;
								break;
							/*    */
					/*		}
						
						if(control.jugadores[i].tar_R==1)
						{
								
								strncat( control.jugadores[i].nombre, "*", 1 );
								fwrite(&control,sizeof(EQUIPOS),1,A);
								salto++;
								break;
						}*/
						
					}
				}
			}
		}
		
		
	}
	
	fclose(A);
	
}


void  ingresar_datos ()
{
	partidos fix;
	equipo jugar;
	int num_partido,num_fecha;
	int gol1,gol2,i,aux_i,p=0,aux_p1,aux_p2,opc;
	FILE*A,*B;
	A=fopen("fechas.bin","r+b");
	B=fopen("equipos.bin","r+b");
	if(B==NULL)
	{
		printf("\nERROR");
		
	}
	if(A==NULL)
	{
		printf("\nERROR");
		pausa();	
	}
	printf("\n\n");
	printf("\t\t");
	fflush(stdin);
	printf("Ingrese    ");
	printf("\n\n");
	printf("\t\t");
	printf("Numero de Fecha: ");
	scanf("%d",&num_fecha);
	printf("\t\t");
	fflush(stdin);
	printf("Numero de Partido: ");
	scanf("%d",&num_partido);
	
	
	mostrar_para_ingresar(num_fecha,num_partido);
	
		
	fclose(A);
	fclose(B);
}

void ver_puntero()
{
	equipo puntero;
	int aux=0;
	int posicion;
	int i,aux_i;
	FILE* A=fopen("equipos.bin","rb");
	if(A==NULL)printf("\nERROR\n");
	else
	{	i=0;
		while(fread(&puntero,sizeof(EQUIPOS),1,A)!=NULL)
		{
			i++;
			if(aux<puntero.Ptos)
			{
				aux=puntero.Ptos;
				aux_i=i;
			}
		}
		system("cls");
		fseek(A,(aux_i-1)*sizeof(EQUIPOS), 0);
	    fread(&puntero, sizeof(EQUIPOS), 1, A);
	    printf("\n\n\n\n\n\n\n");
	    printf("\t\t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("\t   	   บ	  	  PUNTERO DEL CAMPEONATO	   บ\n");
		printf(" \t\t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
		printf("\n\n\n\n\n");
		printf("\n\t\tNOMBRE DEL EQUIPO:  %s\n\t\tBARRIO: %s\n",puntero.nombre,puntero.barrio);
		pausa();
		
	}
	
	
}
void jugadores_suspendidos ()
{
	int i,opc;
	char nombre[50];
	equipo suspendido;
	FILE* A=fopen("equipos.bin","rb");
	if(A==NULL)printf("ERROR");
	else
	{
		printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
		printf("   	   บ	  	     Suspenciones		   บ\n");
		printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
		fflush(stdin);
		printf("\n1-Ingresar Nombre de Equipo\n2-Ver Todos los Equipos :");
		scanf("%d",&opc);
		
		if(opc==1)
		{
			system("cls");
			printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("   	   บ	  	     Suspenciones		   บ\n");
			printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
			
			fflush(stdin);
			printf("\nIngrese el Nombre del Equipo:  ");
			gets(nombre);
		
			system("cls");
			printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("   	   บ	  	     Suspenciones		   บ\n");
			printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
			printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %s %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,nombre,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
				
			while(fread(&suspendido,sizeof(EQUIPOS),1,A)!=NULL)
			{
				if(strcmp(nombre,suspendido.nombre)==0)
				{
					
					printf("\nNombre Jugadores\n");
					for(i=0;i<20;i++)
					{
						printf("\n");
						printf("%s",suspendido.jugadores[i].nombre);	
					}
			
					printf("\nTodos Aquellos Jugadores que Posean un Simbolo de Asterisco (*) en su Nombre se Encuentran Actualmente SUSPENDIDOS\n");
			
				}
							
					
			
			}
		}
		if(opc==2)
		{
			system("cls");
			printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("   	   บ	  	     Suspenciones		   บ\n");
			printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
			while(fread(&suspendido,sizeof(EQUIPOS),1,A)!=NULL)
			{
			system("cls");
			printf(" \t   ษอออออออออออออออออออออออออออออออออออออออออออออออป\n");
			printf("   	   บ	  	     Suspenciones		   บ\n");
			printf(" \t   ศอออออออออออออออออออออออออออออออออออออออออออออออผ \n\n");
			printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %s %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,167,suspendido.nombre,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
					
				/*printf("\n			EQUIPO: %s \n",suspendido.nombre);*/
				printf("\nNombre Jugadores\n");
				for(i=0;i<20;i++)
				{
					printf("\n");
					printf("%s",suspendido.jugadores[i].nombre);
						
				}
			
				printf("\nTodos Aquellos Jugadores que Posean un Simbolo de Asterisco (*) en su Nombre se Encuentran Actualmente SUSPENDIDOS\n");
				printf("\nPulse Enter para pasar al otro equipo..");
				system("pause>NULL");
				
			
			}
			
		}
		
	}

fclose (A);
}

void menu_salida()
{
printf("\n\n\n\n\n");
printf("\t\t   ถถถถถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t   ถถถถถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t   ถถถถถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t   ถถถถถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t    ถถถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t     ถถถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t       ถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t          ถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t      ถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t      ถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);
printf("\t\t      ถถถถถถถถถถถถถถถถถถถ\n");Sleep(100);

}

