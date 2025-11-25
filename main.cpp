#include <iostream>
#include <string.h>

using namespace std;

class Cliente{
    private:
        int codigoCliente;
        char nomeCliente[99];
        char endereco[99];
        int telCliente;
    public:
        int getCodigoCliente(){return codigoCliente;};
        char *getNomeCliente(){return nomeCliente;};
        char *getEndereco(){return endereco;};
        int getTelCliente(){return telCliente;};

        void setCodigoCliente(int x){
            if (x > 0)
                codigoCliente = x;
        }

        void setNomeCliente(char y[99]){
            strcpy(nomeCliente, y);
        }

        void setEndereco(char z[99]){
            strcpy(endereco, z);
        }

        void setTelCliente(int a){
            if (a > 0)
                telCliente = a;
        }
};

class Funcionario{
    private:
        int codigoFunc;
        char nomeFunc[99];
        int telFunc;
        char cargo[50];
        float salario;
    public:
        int getCodigoFunc(){return codigoFunc;};
        char *getNomeFunc(){return nomeFunc;};
        char *getCargo(){return cargo;};
        int getTelFunc(){return telFunc;};
        float getSalario(){return salario;};

        void setCodigoFunc(int x){
            if (x > 0)
                codigoFunc = x;
        }

        void setNomeFunc(char y[99]){
            strcpy(nomeFunc, y);
        }

        void setCargo(char z[50]){
            strcpy(cargo, z);
        }

        void setTelFunc(int a){
            if (a > 0)
                telFunc = a;
        }

        void setSalario(float b){
            if (b > 0.0)
                salario = b;
        }
};

class Quarto{
    private:
        int numQuarto;
        int quantHospedes;
        float valorDiaria;
        bool status;
    public:
        int getNumQuarto(){return numQuarto;};
        int getQuantHospedes(){return quantHospedes;};
        float getValorDiaria(){return valorDiaria;};
        bool getStatus(){return status;};

        void setNumQuarto(int x){
            if (x > 0)
                numQuarto = x;
        }

        void setQuantHospedes(int y){
            if (y > 0)
                quantHospedes = y;
        }

        void setValorDiaria(float z){
            if (z > 0)
                valorDiaria = z;
        }

        void setStatus(bool a){
            status = a;
        }
};

/* class Estadia{
    
};*/ 
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
