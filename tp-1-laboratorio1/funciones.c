float pedirNumero(char var)
{
    float numero;
    printf("Ingrese un numero entero para %c\n",var);
    scanf("%f",&numero);
    return numero;
}
void suma(float N1,float N2)
{
    float resultado=N1+N2;
    printf("La suma es: %.2f \n", resultado);
}
void resta(float N1,float N2)
{
    float resultado = N1-N2;
    printf("La resta es: %.2f \n",resultado);
}

void dividir(float N1,float N2)
{
    if(N2==0)
    {
        printf("No se puede dividir por cero\n");
    }
    else
    {
      float resultado = N1/N2;
      printf("La division es: %.2f \n",resultado);
    }
}
void multiplicar(float N1,float N2)
{
    float resultado =N1*N2;
    printf("La multiplicacion es: %.2f \n", resultado);
}
void factorial(float N1)
{
    int AuxN1=(int)N1;
    int factorial=1;
    if(N1<0)
    {

    printf("No se puede sacar factorial de un numero negativo y no se puede poner un decimal.");

    }
    else if(N1!=AuxN1)
    {
        printf("No se puede hacer el factorial de un numero decimal");
    }
    else
    {
    for(int i=1; i<=(int)N1; i++)
        {
            factorial = factorial*i;
        }
         printf("El factorial de A es: %d \n",factorial);
    }

}
void mostrarTodo(float N1,float N2)
{
    suma(N1,N2);
    resta(N1,N2);
    dividir(N1,N2);
    multiplicar(N1,N2);
    factorial(N1);
}

