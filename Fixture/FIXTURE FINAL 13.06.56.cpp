#include<stdio.h>  
#include<stdlib.h> 
#include<windows.h>
#include<time.h>

struct fechas
{
	
	int alguien;
	int goles;
	char rival [30];
};

typedef struct EQUIPOS
{
       
        char nombre[30];
        char barrio[30];
        int Ptos;
       	fechas contrarios[3];
        char partidos [4];
        
}equipo;
	
equipo cargar (equipo x){
	int a;
	fflush(stdin);
	printf ("ingrese nombre del equipo\n");
	gets (x.nombre);
	fflush(stdin);
	return x; 	
	}
	


void hacer_nulo (int a[])
{
	for (int i=0;i<3;i++)
	{
		a[i]=' ';
	}
}

int numero_aleatorio ()
{
	int cambio =4;
	int numero;
	int hora = time(NULL);  
    srand(hora);  
    numero = rand()%cambio; 
	return numero;
	
}


void tiempo ()
{	int i;
	printf ("cargando ...");
	for (i=0;i<3;i++){
	printf ("..");
	Sleep(100);
	system ("cls");
	

}}

void vector_aleatorio (int a, int b[],int res, int au[4][3] )
{

	int x,i,j,k,s,t,aux='\0',aux2=0,bam=0,salto2=0;
	int cantidad=3,salto=0,tam=3;
	int aur[4][3],filas=0;
	int asig=0;
	int array_b[3],salto3=0;
	int aux_3,super_bandera=0;
	hacer_nulo(array_b);
	tam=tam-res;
	
	printf("\n\n\t\t////////VECTOR_ALEATORIO///////\n\n");
	if(tam!=0)
	{
			do
	{	
		
		salto=0;
		
		do
		{	
			
			x=numero_aleatorio();
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
							for(j=0;j<3;j++)
							{
								if(b[j]==x)
								{
									salto2++;
									}
						
								
							}
							if(salto2==0)
							{
								printf("\nSE ASIGNO\n\n");
								
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
	
	
	
	for(i=0;i<3;i++)
	{
		array_b[i]=b[i];
	}
	int columnas_bien=0;
	
	printf("\n////EL VALOR DEL ARRAY AUXILIAR  Y DEL ARRAY ES:\n\n");
		
					for(j=0;j<tam;j++)
					{
					printf("%d\t",array_b[j]);
						}
					

	
	salto2=0;
	printf("\n\n////INGRESANDO EL VECTOR ALEATORIO EN LA MATRIZ NULA////\n");
	printf("\n\n");
	
	for(j=0;j<4;j++)
					{	
						
						if(filas<tam)
						{
							for(i=0;i<3;i++)
							{
								salto=0;
								printf("\nPOSICION J=%d	I=%d	",j,i);
							
									for(s=0;s<tam;s++)
									{
										salto3=0;
										printf("\n TAM=:%d	B[S]=%d[%d]\n",tam,array_b[s],s);
										
									
										if( array_b[s]!=' ' && salto==0 && salto2!=tam && au[j][i]==' ' && salto3==0 )
										{
											printf("\nse asigno\n el b[s]=%d[%d]	au[%d][%d]=%d\n	",array_b[s],s,j,i,au[j][i]);
											
											au[j][i]=array_b[s];
											array_b[s]=' ';
											filas++;salto++;
											
											salto2++;
											salto3++;
											printf("\nse asigno\n el b[s]=%d[%d]	au[%d][%d]=%d\n	",array_b[s],s,j,i,au[j][i]);
											
										}
									
									}
									
								
							
							}
						
							}
	
						}
							
		printf("\n\n////LA MATRIZ NULA NOS QUEDA\n\n////");
		printf("\n/////LA MATRIZ AUX_ARRAY NOS VA QUEDANDO\n");
					for(j=0;j<4;j++)
						{
							printf("\n");
							for(k=0;k<3;k++)
							{
								printf("\t%d",au[j][k]);
								}
						}
				
		printf("\n\n////SE FIJA ELEMENTOS REPETIDOS EN COLUMNAS\n\n////");
	
		
		for(j=0;j<4;j++)
			{
				
				aux2=0;
					for(i=0;i<3;i++)
				{
					aux2=i;
					if(au[j][i]!=' ')
					{	
					
							printf("\nAGARRAMOS EL ELEMENTO\n");
							printf("\nMATRIZ POSICION [%d][%d]=%d (j,I)\n\n",j,i,au[j][i]);
							printf("\nLO COMPARAMOS CON:\n");
							
							for(k=0;k<4;k++)
							{
								
								printf("\nMATRIZ POSICION [%d][%d]=%d (K,I)\n\n",k,i,au[k][i]);
								
								
								if (au[k][i] == au[j][i] &&  au[j][i]!= ' ' && au[k][i]!= ' ' && k!=j )
								{
									
									printf("\nSE REALIZA LA ASIGNACION\n");
									
									
									
									
									
									aux2++;
									aux=au[k][i];
									super_bandera=0;
									
									
									for (s=0;s<3;s++)
									{	
										
										printf("\nAGARRAMOS EL ELEMENTO A CAMBIAR POR EL REPRETIDO\n");
										printf("\nau[%d][%d]=%d(k)(s)\n",k,s,au[k][s]);
										
										
										if(au[k][s]!=aux && (au[k][s]== ' ' || au[k][s]>=a) )
										{
											printf("\nMATRIZ POSICION [%d][%d]=%d (K,S)\n\n",k,s,au[k][s]);
											for(t=0;t<4;t++)
											{
												
												printf("\nRECORREMOS LA FILA\n ");
												printf("\nMATRIZ POSICION au[%d][%d]=%d (t,s)\n\n",t,s,au[t][i]);
												
												if(au[t][i]==au[k][s] && t>j && super_bandera==0)
												{
													super_bandera++;
													
													
											
												}												
											}
											if(super_bandera==0)
											{	
												printf("\nSE LOGRO EL CAMBIO\n");
												au[k][i]=au[k][s];
												au[k][s]=aux;
											}
											
										}
										
									}
									
									
									
									printf("\naux=%d	aux2=%d(posicion I)	aux_3=%d\n",aux,aux2,aux_3);
									
									
								
								
								}
							}
						}
				}
			}
			
			
			printf("\n/////LA MATRIZ NULA NOS VA QUEDANDO\n\n////");
					for(j=0;j<4;j++)
						{
							printf("\n");
							for(k=0;k<3;k++)
							{
								printf("\t%d",au[j][k]);
								}
						}
			
		
			
}
else 
for(i=0;i<4;i++)
{
	for(j=0;j<3;j++)
	{
		if(au[i][j]==' ')
		{
			au[i][j]=cantidad;
		}
	}
}
		
		
	}


void hacer_nulo_matriz (int a[4][3])
{
	for (int i=0;i<4;i++)
	{	
		for(int j=0;j<3;j++)
		a[i][j]=' ';//aca va el nulo
	}
}
int main ()
{
	equipo asd[4];
	equipo dsa;
	int i=0,j,aux,array[3];
	int bandera=0,aux_array[4][3];
	int c,k,guardar_i;
	int salto=0;
	int auxiliar,auxiliar_4;
	int pasadas=0;
	int una_sola_vez=0;
	int auxiliar_i=0;
	int s;
	int array_aux1[3];
	int asig_fila=0;
	int bandera_ya=0;
	int aux_4;
	int tal_vez=0;
	int guar_fila;
	int guar_colum;
	
	
	hacer_nulo_matriz(aux_array);

	for (i=0;i<4;i++)//cargar equipos
			{
				asd[i]=cargar(dsa);
				}
				
	for(i=0;i<4;i++)
	{
	
			hacer_nulo(array);
			asig_fila=0;
			guardar_i=i;
				
				/*do
				{
					
					vector_aleatorio(i,array,pasadas,aux_array);//me va a devolver un vector q no tenga a I y q este entre 0 y 3 menos el numero de pasadas
				
					for(j=0;j<3;j++)
					{
					aux_array[0][j]=array[j];
					}
					printf("\n\n\t\t////////MAIN DO WHILE ///////\n\n");
					printf("\n\n");
					system("pause");
					printf("\n////EL VALOR DEL VECTOR ALEATORIO ES:\n");
					for(j=0;j<3;j++)
					{
					printf("%d\t",array[j]);
						}
						system("\npause");
					
				
						for(j=0;j<3;j++)
					{
						array_aux1[j]=array[j];
					}
						
					for(j=0;j<4;j++)
					
				{
					asig_fila=0;
				printf("\n\n////ASIGNANDO EL QUIPO QUE JUEGA A LA MATRIZ CONTRINCANTES \n\n///");
				
					for(k=0;k<3;k++)
					{	
						
						printf("\n\nJ=%d\tK=%d\n",j,k);
					
						if(aux_array[j][k]==' ')
						{	
							printf("//PASO CONDICION DE NULO(matriz)\n");
							for(s=0;s<3;s++)
							{
									if(	array_aux1[s]!=' '&& j==array_aux1[s] && asig_fila== 0 && s==k)
									{
										printf("\n\nASIGNO\t J=%d\tK=%d\n\n",j,k);
										aux_array[j][k]=auxiliar_i;
										asig_fila++;
										printf("\n////ACA ESTA TOCANDO LA MATRIZ\tJ=%d\tK=%d\tauxilir_i=%d\n",j,k,auxiliar_i);
									}	
							}	
						}
					}
					
				}
					
					
					printf("\n/////LA MATRIZ CONTRINCANTES NOS VA QUEDANDO\n");
					for(j=0;j<4;j++)
						{
							printf("\n");
							for(k=0;k<3;k++)
							{
								printf("\t%d",aux_array[j][k]);
								}
						}
					
					printf("\n\n");
					system("\npause");
					
					una_sola_vez=1;
					pasadas++;
					
				continue;
				}while(una_sola_vez==0 || tal_vez==1);*/
				
				
			
			
				hacer_nulo(array);
				
			printf("\n\n////MAIN  FUERA DEL WHILE////\n\n");
			printf("\n\n");
			
			
			printf("\n/////LA MATRIZ CONTRINCANTES NOS VA QUEDANDO\n");
			for(j=0;j<4;j++)
			{
				printf("\n");
				for(k=0;k<3;k++)
				{
					printf("\t%d",aux_array[j][k]);
				}
			}
		
			
			printf("\n\n////NOS VAMOS A LA FUNCION VECTORALEATORIO////\n\n");
			printf("\n\n");
			
			vector_aleatorio(i,array,pasadas,aux_array);
				for(j=0;j<3;j++)
					{
						array_aux1[j]=array[j];
					}
			
			printf("\n\n////MAIN  FUERA DEL WHILE ////\n\n");
			printf("\n\n");
			
			printf("\n\n////EL VALOR DEL VECTOR ES:\n");
			for(j=0;j<3;j++)
			{
				printf("%d\t",array[j]);
			}
				
			printf("\n////EL VALOR DE I ES %d\n",i);
			printf("\n///EL VALOR DE PASADAS ES %d\n",pasadas);
	
			
			
			printf("\n/////LA MATRIZ CONTRINCANTES ANTES DE ENTRARA LA ASIGNAION\n");
			for(j=0;j<4;j++)
			{
				printf("\n");
				for(k=0;k<3;k++)
				{
					printf("\t%d",aux_array[j][k]);
				}
			}
			
			printf("\n\n////ASIGNANDO EL QUIPO QUE JUEGA A LA MATRIZ CONTRINCANTES \n\n///");
			printf("\n\n");
			
		
		
		
		
		guardar_i++;
	
	
	
	for(k=0;k<3;k++)
	{
		printf("\n\n////AGARRAMOS EL ARRAY[%d]=%d(K)\n",k,array_aux1[k]);
		printf("COMPRAMOS CON\n\n");
		
		salto=0;
		for(j=0;j<4;j++)
		
		
		

		{
			for(s=0;s<3;s++)
			{
				printf("\nAUX_ARRAY[%d][%d]=%d\n",j,s,aux_array[j][s]);
				if(array_aux1[k]!=' ' && (aux_array[j][s]== ' ' || array_aux1[k]==aux_array[j][s]) ) 
				
				{
					printf("\npaso if\n\n");
					if ( array_aux1[k]==aux_array[j][s])
					{
						
						printf("\npaso if\n\n");	
						if(salto==0)
						{
							printf("\npaso if\n\n");
							if(j>=i )
							{
								printf("\npaso if\n\n");
								printf("\nASIGNA\n");
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
	
	
		
	/*	for(k=0;k<3;k++)
		{
			asig_fila=0;
			if(array_aux1!= ' ' )
			{
				for(j=0:j<3;j++)
				{	
					if(aux_array[guardar_i][j]==' ' )
					{
						if( aux_array[i][j]== array_aux1[k] && asig_fila=0 )
							{
								aux_array[gauardar_i][j]=i;
								asig_fila++;
							}
							else
							{
						
							}
					}
				
							
				}
			}
				
		}
		
		
		
		
		
		
		
			
		/*	for(j=0;j<4;j++)
			{
				asig_fila=0;
				for(k=0;k<3;k++)
				{
					
					printf("\n\nJ=%d\tK=%d\n",j,k);
					
					if(aux_array[j][k]==' ')
					{	
						printf("//PASO CONDICION DE NULO(matriz)\n");
						for(s=0;s<3;s++)
						{
								printf("\n//RECCORRO EL VECTOR\n");
								printf("\n array[%d]=%d\n",s,array_aux1[s]);
								system("pause");
								if(	array_aux1[s]!=' ')
								{
									printf("\npaso if\n");
									if( asig_fila== 0)
									{
										printf("\npaso if\n");
										if( s==k ||j==4 ) 
										{
											printf("\npaso if\n");
											if(array_aux1[s]==j )//////
											{
											printf("\npaso if\n");
									printf("\n\nASIGNO\t J=%d\tK=%d\n\n",j,k);
									aux_array[j][k]=i;
									asig_fila++;
									printf("\n////ACA ESTA TOCANDO LA MATRIZ\tJ=%d\tK=%d\tauxilir_i=%d\n",j,k,i);
											}	
										
									}
									}
								}
									 
								 
						}	
					}
				}
			}*/
			printf("\n/////LA MATRIZ CONTRINCANTES DESPUES DE LA ASIGNAICON\n");
			for(j=0;j<4;j++)
			{
				printf("\n");
				for(k=0;k<3;k++)
				{
					printf("\t%d",aux_array[j][k]);
				}
			}
			
			printf("\n\n\n////TERMINO DE RECORRER UN EQUIPO\n\n\n///");
			
				
			
			pasadas++;
			
		}
	
			
	printf("\n//LLEGAMOS CHRITSIAN\n");
	
	for(j=0;j<4;j++)
	{
		printf("\n");
		for(i=0;i<3;i++)
		{
			asd[j].contrarios[i].alguien=aux_array[j][i];
			auxiliar_4=aux_array[j][i];
			strcpy(asd[j].contrarios[i].rival,asd[auxiliar_4].nombre);//ACA ESTA EL ERROR DE IMPRESION PUTO EL Q LEE
			printf("%d",asd[j].contrarios[i].alguien);
		}
	}
	
	
	for(i=1;i<4;i++)
	{
		printf ("\nFECHA NUMERO %d",i);
		printf("\nPARTIDOS \t\n");
		for(j=0;j<2;j++)
		{
		
			printf ("%s	VS	%s\n",asd[j].nombre,asd[j].contrarios[i].rival);
			
		}
	}

	return 0;
	
	
	
}
