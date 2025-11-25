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
        //encapsulamento
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
        //procedimento de cadastro de clientes
        /*void cadastraCliente(int codCliente, char nomeCliente[99], char end[99], int telCliente){
            //apenas o basico feito
            setCodigoCliente(codCliente);
            setNomeCliente(nomeCliente);
            setEndereco(end);
            setTelCliente(telCliente);
        
        }*/
        
};


class Funcionario{
    private:
        int codigoFunc;
        char nomeFunc[99];
        int telFunc;
        char cargo[30];
        float salario;
    public:
        //encapsulamento
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

        void setCargo(char z[30]){
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
        //procedimento para cadastro de funcionarios
        /*void cadastraFunc(int codFunc, char nomeFunc[99], char cargo[30], int telFunc, float salario){
        //apenas o basico feito
            setCodigoFunc(codFunc);
            setNomeFunc(nomeFunc);
            setCargo(cargo);
            setTelFunc(telFunc);
            setSalario(salario);
        
        }*/
};

class Quarto{
    private:
        int numQuarto;
        int quantHospedes;
        float valorDiaria;
        bool status;
    public:
        //encapsulamento
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
        //procedimento para cadastro de quartos
        /*void cadastraQuarto(int num, int quant, float diaria, bool stat){
        //apenas o basico
            setNumQuarto(num);
            setQuantHospedes(quant);
            setValorDiaria(diaria);
            setStatus(stat);
        }*/
};

/* class Estadia{
    private:
        //código da  estadia, data de  entrada,  data de saída, quantidade de diárias,  código 
        //do cliente, número do quarto 
        int codigoEstadia;
        int dataEntrada;
        int dataSaida;
        int numDiarias;
        //puxar codigo cliente e num quarto das classes cliente e quarto;
    public:
        //encapsulamento
        int getCodigoEstadia(){return codigoEstadia;};
        int getDataEntrda(){return dataEntrada;};
        int getDataSaida(){return dataSaida;};
        int getNumDiarias(){return numDiarias;};

        void setcodigoEstadia(int a){}
        void setdataEntrada(int b){}
        void setdataSaida(int c){}
        void setnumDiarias(int d){}

};*/ 
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
