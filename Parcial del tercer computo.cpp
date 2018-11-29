//Willliam Alexander Chavez Marquez Carnet: CM18064
//Fecha de entrega 28/11/2018
 #include <iostream>
 #include <windows.h>
 #include <cstdlib>


using namespace std;

//funcion para limpia la pantalla
void l(){
	system ("cls");
}

//funcion para detiene el programa
void c(){
	system ("pause");
}

//variables utlizadas
void torre();
void random();


	
void moverdisco();
int tem,tem2,n,i,j,desde,hacia,con,tam,tamdisco,espacios,k,matriz[100][3];
char cr='±',si,fondo=177;



//Metodo queposiciona el enunciado el enunciado en la consola dando 2 cordenada 
void gotoxy(int x,int y){
	COORD conCord;
	conCord.X=x;
	conCord.Y=y;
}
	
	void linea(int j)
{
 for(int i=0;i<j;i++)
  cout<<cr;
 cout<<endl;
}
void salir()
{
 char r='©';
 system("cls");
 gotoxy(15,8);//Indica la posicion de lo que se imprimira.
 cout<<" Juego Terminado "<<" ";
 gotoxy(15,15);//Indica la posicion de lo que se imprimira.
 cout<<" Juega de nuevo ";

 getchar();
}

int main()
{
	system ("color 37");	
//variable para regresar al menu
int opc;

do
{
	
//limmpiar pantalla
	l();

//opciones que se puede seleccionar
cout<<"\n1. ==> Torre de Hanoi"<<endl;

cout<<"\n2. ==> Numero Random"<<endl;

cout<<"\n3. ==> Salir "<<endl;

//seleccionar
cout<<"\n Ingrese opcion: ";
cin>>opc;

// entrar a la opcion seleccionada
switch(opc)
{
	//Entra a la opcion cliente
	case 1: torre();
 	break;
 	 
 	//Entra a la opcion random
 	case 2: random();
 	break;
 	
 	//Entra a la opcion de salida
 	case 0: exit(1);
	
	/*en el caso que seleccione una opcion que no se encuentre
	se activara el los sigueinres comandos*/
	
	default: 
	//limmpiar pantalla	
	l();
	
	//se imprime en la pantalla
	cout<<"!!!*Opcion no valida*!!!"<<endl; 
	cout<<"==>Intente con otra opcion"<<endl;
	
	//detener la pantalla
	c();
	break;
 	
}
	//Retorna a la seleccion de las opcciones
}while(opc);

return 0;
}

void torre()
{

    system("cls");
    gotoxy(15,8);//Indica la posicion de lo que se imprimira.
    cout<<"Torre de Hanoi\n"<<endl<<endl;
    gotoxy(10,12);//Indica la posicion de lo que se imprimira.
        cout<<"Reglas"<<endl;
    cout<<"==> Solo se puede mover un disco cada vez y para mover otro los demás tienen que estar en postes."<<endl;
    cout<<"==> Un disco de mayor tamaño no puede estar sobre uno más pequeño que él mismo."<<endl;
    cout<<"==> Solo se puede desplazar el disco que se encuentre arriba en cada poste."<<endl<<endl;
    cout<<"Numero de discos para jugar: "<<endl;
    cin>>n;
    system("cls");
    while(n>13||n<3)
    {
        system("cls");
        cout<<"Se juega minimo con tres discos y maximo con 13"<<endl;
		cout<<"Digite la cantidad de discos:";
        cin>>n;
    }
    //codigo de la torre de hanoi reutilizado cambios minimos 
    tam=n+(n-1);
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
              if(j==0)
                  matriz[i][j]=i+1;
              else
                  matriz[i][j]=0;
              for(k=1;k<=tam;k++)
              {
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                       cout<<fondo;    
                   else
                   {
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"|";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(i=1;i<=((tam*3));i++)
    {
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    cout<<endl;
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    moverdisco();
}
void moverdisco()
{
    while(matriz[0][1]!=1&&matriz[0][2]!=1)
    {
    cout<<"\n\n\t\t\tLleva "<<con++<<" movimientos\n";
    do{
        cout<<"Torre donde esta el disco que desea mover: ";
        cin>>desde;
        if(matriz[n-1][desde-1]==0){cout<<"No hay disco en esa torre"<<endl;}
    }
    while(matriz[n-1][desde-1]==0);
    cout<<"Torre donde se moveran el discos: ";
    cin>>hacia;
    desde--;
    hacia--;
    for(i=0;i<n;i++)
    {
        if(matriz[i][desde]!=0)
        {
        tem=matriz[i][desde];
        tem2=i;        
        i=n;
        }
    }
    //lee si se hace un movimiento no valido en el juego tales como poner discos mas grandes encima de los pequenios
    for(i=n-1;i>=0;i--)
    {
        if(matriz[i][hacia]==0)
        {
            if(matriz[i+1][hacia]>tem||i==(n-1))
            {
            matriz[i][hacia]=tem;
            matriz[tem2][desde]=0;
            }
            else
            {
            cout<<"\n\nMovimiento no valido"<<endl
                <<"Cambie los parametros"<<endl;
                con--;
            moverdisco();
            }       
            i=0;
        }
    }
    system("cls");
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
              for(k=1;k<=tam;k++)
              {
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                      cout<<fondo;
                   else
                   {
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                           cout<<"|";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    for(i=1;i<=((tam*3));i++)
    {
        if(i==n-1)
            cout<<"T1";
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        else
            cout<<fondo;
    }
    //lee si as ganado
    cout<<endl;
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    }
    system("color 70");
    cout<<"\n\nGano en "<<con<<" movimientos"<<endl;
    
	cout<<"Desea volver a jugar S / N: ";
		Beep(329,300); 
		Beep(493,300); 
		Beep(698,300); 
		Beep(659,600); 

		Beep(783,300); 
		Beep(698,300); 
		Beep(659,600); 

		Beep(329,100); 
		Beep(493,300); 
		Beep(698,300); 
		Beep(659,600);

		Beep(392,250); 
		Beep(440,200); 
		Beep(587,300); 

		Beep(349,250);
		Beep(587,500); 

		Beep(329,300); 
		Beep(493,300); 
		Beep(698,300); 
		Beep(659,600); 

		Beep(783,300); 
		Beep(698,300); 
		Beep(659,600); 

		Beep(329,100); 
		Beep(493,300); 
		Beep(698,300); 
		Beep(659,600);

		Beep(392,250); 
		Beep(440,200); 
		Beep(587,300); 

		Beep(349,250);
		Beep(587,400);
    cin>>si;
    con=0;
    if(si=='s'||si=='S')
        torre();
    else
        salir();
    getchar();
    
    
}

//crea numeros ramdon y los ordena
void random()
{
	system ("cls");
	int vector [100];
	int i,j, temp;
	
	cout<<"Numeros randoms: "<<endl;
	for (i=0;i<=100; i++)
	{
		vector[i]= rand()%100;
	
		cout<<"==>"<<vector[i]<<"<==";
	}
	cout<<endl;
	cout<<endl;
	
	cout<<"Numeros Random: "<<endl;
	//metodo de la burbuja
	
	for(i=1; i<=100; i++)
	{
		for(j=i+1; j<=100; j++)
		{
			if(vector [j] < vector[i])
			{
				temp=vector[j];
				vector[j]=vector[i];
				vector[i]=vector[j];
				vector[i]=temp;
			}
			
		}
	}
	
	for(i=1; i<=100; i++)
	{
		cout<<i<<") "<<vector[i];
		cout<<endl;
	}

system ("pause");
	
}

