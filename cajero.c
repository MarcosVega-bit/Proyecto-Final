// PROTOTIPOS
void menu();
void depositar(int cantidad);
void retirar(int cantidad);


// VARIABLE GLOBAL
int saldo_actual = 100;
int cantidad;
int pin,k,n;
int* s;
char transaction = 's';

#include <stdio.h>
#include <stdlib.h>

int  main()
{
    menu();
}

void menu()
{
    // VARIABLE PARA ALMACENAR LA OPCION

    int opc;
    while (pin != 1520){
                printf("Por favor, ingrese su número PIN secreto:\n");
                scanf("%d", &pin);
                if (pin != 1520)
                printf("Por favor, ingrese su contraseña.\n");
        }
do{
    printf("Bienvenido al sevicio del cajero automático\n");
    printf("1. Consultar saldo");
    printf("\n2. Depositar");
    printf("\n3. Retirar");
    printf("\n4. Salir");

    // ALMACENAMOS SU OPCION
    printf("\nDigite su opcion: ");
    scanf("%i" , &opc);

    // CREAMOS UN SWITCH PARA REDIRECCIONAR A LAS FUNCIONES
    switch(opc)
    {
        case 1: printf("\nTu saldo actual es de %i " , saldo_actual);
        break;

        case 2:
        printf("\nCuanto dinero desea depositar: ");
        scanf("%i" , &cantidad);
        s=(int*)malloc(cantidad*sizeof(int));
         depositar(cantidad); // LE ENVIAMOS EL PARAMETRO A LA FUNCION
        break;

        case 3:
        printf("\nCuanto dinero desea retirar: ");
         scanf("%i" , &cantidad);
        s=(int*)malloc(cantidad*sizeof(int));
        retirar(cantidad); // LE ENVIAMOS EL PARAMETRO A LA FUNCION
        break;

        case 4:
	printf("\n Gracias por usar el cajero automático!"); 
	break;
     // CERRAMOS EL PROGRAMA

        default:
            printf("\nOpcion no valida");
            break;
        }
printf("\n\n\n ¿Desea tener otra transacción?: \n");
                fflush(stdin);
                scanf("%c", &transaction);
                if (transaction == 'n'|| transaction == 'N')
                    k = 1;
} while (opc!=4);
        printf("\n\n Gracias por utilizar el servicio del cajero automático!");

}

// CREAR LAS FUNCIONES DEPOSITAR
void depositar(int cantidad)
{

    saldo_actual += cantidad; // ACTUALIZAMOS EL SALDO ACTUAL
    printf("\nHas depositado exitosamente %i USD, tu saldo actual es de %i USD" , cantidad , saldo_actual );

}
// FUNCION PARA RETIRAR
void retirar(int cantidad)
{
    // CONDICIONAL DE CHECKEO
    if (cantidad <= saldo_actual) // SI SE CUMPLE, ENTRAMOS AL CONDICIONAL
    {

    saldo_actual -= cantidad;

    printf("\nHas retirado exitosamente %i USD, tu saldo actual es de %i USD" , cantidad , saldo_actual );

    }
    else
    {
printf("\nNo tienes suficiente dinero, tu saldo actual es de %i", saldo_actual);
    }

}
