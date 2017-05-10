N#include<stdio.h>  
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

int numero_aleatorio (int x)
{
	int cambio =4;
	int numero;
	int hora = time(NULL);  
    srand(hora);  
    numero =x+ rand()%(cambio-x); 
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
	
	int x,i,j,k,s,t;
	int aux='\0',aux2=0,bam=0,salto=0,salto2=0,filas=0,aux_3,super_bandera=0,salto3=0;
	int cantidad=3,tam=3;
	int array_b[3];
	
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
							for(j=0;j<3;j++)
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
	
	
	
	for(i=0;i<3;i++)
	{
		array_b[i]=b[i];
	}
	int columnas_bien=0;
	
		
					for(j=0;j<tam;j++)
					{
				
						}
	salto2=0;
	for(j=0;j<4;j++)
					{	
						
						if(filas<tam)
						{
							for(i=0;i<3;i++)
							{
								salto=0;
								
							
									for(s=0;s<tam;s++)
									{
										salto3=0;
									
										if( array_b[s]!=' ' && salto==0 && salto2!=tam && au[j][i]==' ' && salto3==0 )
										{
											
											au[j][i]=array_b[s];
											array_b[s]=' ';
											filas++;salto++;
											salto2++;
											salto3++;
											
											
										}
									
									}
									
								}
						
							}
	
						}
							
					for(j=0;j<4;j++)
						{
							for(k=0;k<3;k++)
							{
								
								}
						}
			
		for(j=0;j<4;j++)
			{
				
				aux2=0;
					for(i=0;i<3;i++)
				{
					aux2=i;
					if(au[j][i]!=' ')
					{	
				
							for(k=0;k<4;k++)
							{
								
								if (au[k][i] == au[j][i] &&  au[j][i]!= ' ' && au[k][i]!= ' ' && k!=j )
								{
									
									
									aux2++;
									aux=au[k][i];
									super_bandera=0;
									for (s=0;s<3;s++)
									{	
																	
										if(au[k][s]!=aux && (au[k][s]== ' ' || au[k][s]>=a) )
										{
											for(t=0;t<4;t++)
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
		a[i][j]=' ';
	}
}
int main ()
{
	equipo asd[4];
	equipo dsa;
	
	int i,j,c,k,s,guardar_i,aux_4,x,guar_fila,guar_colum,aux,fin;
	int salto=0,pasadas=0,asig_fila=0;
	int array[3],array_aux1[3],aux_array[4][3];

	hacer_nulo_matriz(aux_array);

	for (i=0;i<4;i++)
			{
				asd[i]=cargar(dsa);
				}
				
	for(i=0;i<4;i++)
	{
	
			guardar_i++;
			hacer_nulo(array);
			asig_fila=0;
			guardar_i=i;
			
			vector_aleatorio(i,array,pasadas,aux_array);
				
				for(j=0;j<3;j++)
					{
						array_aux1[j]=array[j];
					}		
		
	for(k=0;k<3;k++)
	{
		
		salto=0;
		for(j=0;j<4;j++)
	
		{
			for(s=0;s<3;s++)
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
	
	for(j=0;j<4;j++)
	{
			printf ("\n");
		for(i=0;i<3;i++)
		{
			asd[j].contrarios[i].alguien=aux_array[j][i];
			
			strcpy(asd[j].contrarios[i].rival,asd[aux_array[j][i]].nombre);
			printf("%d",asd[j].contrarios[i].alguien);
		}
	}
	
	
	
	
	for(i=0;i<3;i++)
	{
		c=i;
		c++;
		printf ("\nFECHA NUMERO %d",c);
		salto=0;
		
		for(j=0;j<4;j++)
		{
			x=aux_array[j][i];
			c=j;
			c++;
				if(salto<2 && x!=c)
				{
				printf("%s	VS	%s\n",asd[x].nombre,asd[j].nombre);
				
				salto++;
				}					
		}
	}
	return 0;
}
