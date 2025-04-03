#include "clases4.cpp"

int main() {
    CuentaCorriente miCuenta("Sofía");

    miCuenta.depositar(200);//Deposito en el objeto creado de CuentaCorriente, micuenta
    miCuenta.retirar(150);//Retiro de la cuenta
    miCuenta.retirar(100); // Si no alcanza en la cuenta corriente, se intenta con caja de ahorro

    miCuenta.mostrar_info();

    return 0;
}