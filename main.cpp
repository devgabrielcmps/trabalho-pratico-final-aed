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

        //funcao para adicionar mais clientes, caso precise
        //passa por referência o vetor de clientes, o número atual de clientes cadastrados,
        //a capacidade atual do vetor e volta o vetor do novo cliente
        void adicionaCliente(Cliente **temp, int &num, int &cap, Cliente novoCliente) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2; 
                *temp = (Cliente *)realloc(*temp, cap * sizeof(Cliente));
            }
            Cliente *p = *temp;
            p[num] = novoCliente;
            num++;
        }

        bool  codigoClienteJaExiste(int a, Cliente *clientes, int numClientes){
            for (int i = 0; i < numClientes; i++){
                if (clientes[i].getCodigoCliente() == a){
                    return true;
                }
            }
            return false;
        }

        //procedimento de cadastro de clientes
        void cadastraCliente(Cliente *cliente, int numDeClientes, int codCliente, char nomeCliente[99], char end[99], int telCliente){
            //apenas o basico feito
            if (codigoClienteJaExiste(codCliente, cliente, numDeClientes) == true){
                cout << "Codigo de cliente ja existe. Cadastro nao realizado." << endl;
                return;
            }
            else{
                setCodigoCliente(codCliente);
                setNomeCliente(nomeCliente);
                setEndereco(end);
                setTelCliente(telCliente);
                cout << "Cliente cadastrado com sucesso!" << endl;
            }
        
        }
        
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
        //funcao para adicionar mais funcionário, caso precise
        //passa por referência o vetor de funcionários, o número atual de funcionários cadastrados,  
        //a capacidade atual do vetor e volta o vetor do novo funcionário
        void adicionaFuncionario(Funcionario **temp, int &num, int &cap, Funcionario novoFunc) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Funcionario *)realloc(*temp, cap * sizeof(Funcionario));
            }
            Funcionario *p = *temp;
            p[num] = novoFunc;
            num++;
        }

        //procedimento para cadastro de funcionarios
        void cadastraFunc(int codFunc, char nomeFunc[99], char cargo[30], int telFunc, float salario){
            //apenas o basico feito
            setCodigoFunc(codFunc);
            setNomeFunc(nomeFunc);
            setCargo(cargo);
            setTelFunc(telFunc);
            setSalario(salario);
        }
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


        //procedimento para adicionar quartos, caso precise
        //passa por referência o vetor de quartos, o número atual de quartos cadastrados,  
        //a capacidade atual do vetor e volta o vetor do novo quarto
        void adicionaQuarto(Quarto **temp, int &num, int &cap, Quarto novoQuarto){
            if (num >= cap){
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Quarto*) realloc(*temp, cap * sizeof(Quarto));
            }
            Quarto *p = *temp;
            p[num] = novoQuarto;
            num++;
        }
};

/* class Estadia{
    private:
        //código da  estadia, data de  entrada,  data de saída, quantidade de diárias, 
        //código do cliente, número do quarto 
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
    Cliente *clientes = NULL;
    Funcionario *funcionarios = NULL;
    Quarto *quartos = NULL;

    int numClientes = 0, capClientes = 0;
    int numFuncionarios = 0, capFuncionarios = 0;
    int numQuartos = 0, capQuartos = 0;

    //possivel função para verificar se o código do cliente já existe
    /*bool codigoClienteJaExiste(int a, int numClientes){
        for (int i = 0; i < numClientes; i++){
            if (a == Cliente[i].getCodigoCliente()){
                return true;
            }
        }
        return false;
    }*/

    int opc;
    do{
        cout << "escolha uma das opcoes :" << endl;
        cout << "1 : Cadastro de clientes." << endl;
        cout << "2 : Cadastro de funcionarios." << endl;
        cout << "3 : Cadastro de quarto." << endl;
        cout << "4 : Cadastro de estadia." << endl;
        cout << "5 : Dar baixa em uma estadia." << endl;
        cout << "6 : Mostrar suas estadias." << endl;
        cout << "7 : Pesquisar cliente/funcionario." << endl;
        cout << "8 : Backup de dados." << endl;
        cout << "9 : Restaurar dados" << endl;
        
        cin >> opc;
        if (opc < 1 || opc > 9){
            cout << "opcao invalida, tente novamente." << endl;
        }

        switch (opc){
            case 1:
                //cadastrar cliente
                break;
            case 2:
                //cadastrar funcionario
                break;
            case 3:
                //cadastrar quarto
                break;
            case 4:
                //cadastrar estadia
                break;
            case 5:
                //dar baixa em estadia
                break;
            case 6:
                //mostrar estadias
                break;
            case 7:
                //pesquisar cliente/funcionario
                break;
            case 8:
                //backup de dados
                break;
            case 9:
                //restaurar dados
                break;
        }
    }while(opc >=1 && opc <= 9);


}
