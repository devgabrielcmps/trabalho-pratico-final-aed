#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>

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

        bool codigoFuncJaExiste(int a, Funcionario *funcionarios, int numFuncionarios){
            for (int i = 0; i < numFuncionarios; i++){
                if (funcionarios[i].getCodigoFunc() == a){
                    return true;
                }
            }
            return false;
        }

        //procedimento para cadastro de funcionarios
        void cadastraFunc(Funcionario *funcionarios, int numFuncionarios, int codFunc, char nomeFunc[99], char cargo[30], int telFunc, float salario){
            if (codigoFuncJaExiste(codFunc, funcionarios, numFuncionarios) == true){
                cout << "Codigo de funcionario ja existe. Cadastro nao realizado." << endl;
                return;
            }
            else{
                setCodigoFunc(codFunc);
                setNomeFunc(nomeFunc);
                setCargo(cargo);
                setTelFunc(telFunc);
                setSalario(salario);
                cout << "Funcionario cadastrado com sucesso!" << endl;
            }            
        }
};
void deletaFuncionario(){
    //fazer função para deletar funcionario por codigo
}

void deletaCliente(){
    //fazer função para deletar cliente por codigo
}

void editaFuncionario(){
    //fazer função para editar funcionario por codigo
}

void editaCliente(){
    //fazer função para editar cliente por codigo
}

void procuraFuncionario(){
    //fazer função para procurar funcionario por codigo
}

void procuraCliente(){
    //fazer função para procurar cliente por codigo
}

class Quarto{
    private:
        int numQuarto;
        int quantHospedes;
        float valorDiaria;
        bool status;
        int codigoCliente;
    public:
        //encapsulamento
        int getNumQuarto(){return numQuarto;};
        int getQuantHospedes(){return quantHospedes;};
        float getValorDiaria(){return valorDiaria;};
        bool getStatus(){return status;};
        int getCodigoCliente(){return codigoCliente;};

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

        void setCodigoCliente(int b){
            if (b > 0)
                codigoCliente = b;
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

        bool numQuartoJaExiste(int a, Quarto *quartos, int numQuartos){
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getNumQuarto() == a){
                    return true;
                }
            }
            return false;
        }

        void cadastraQuarto(Quarto *quartos, int numQuartos, int numeroQuarto, int quantHospedes, float valorDiaria, bool status, int codigoCliente){
            if (numQuartoJaExiste(numeroQuarto, quartos, numQuartos) == true){
                cout << "Quarto ja ocupado! Cadastro nao realizado." << endl;
                return;
            }
            else{
                setNumQuarto(numeroQuarto);
                setQuantHospedes(quantHospedes);
                setValorDiaria(valorDiaria);
                setStatus(status);
                setCodigoCliente(codigoCliente);
                cout << "Quarto cadastrado com sucesso!" << endl;
            }
        }
};

bool verificaCliente(Cliente *cliente, int numCLientes, int codigoCliente){
    for (int i = 0; i < numCLientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            return true;
        }
    }
    return false;
}

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

    int opc;
    do{
        cout << "escolha uma das opcoes :" << endl;
        cout << "1 : Opcoes de clientes." << endl;
        cout << "2 : Opcoes de funcionarios." << endl;
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
            case 1: {
                // opcoes de clientes
                int opc2;
                cout << "1 : Cadastrar cliente." << endl;
                cout << "2 : Editar cliente." << endl;
                cout << "3 : Remover cliente." << endl;
                cin >> opc2;
                if (opc2 < 1 || opc2 > 3){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }
                if (opc2 == 1){
                    // cadastrar cliente
                    int codCliente, telCliente;
                    char nomeCliente[99], end[99];
                    cout << "Digite o codigo do cliente: ";
                    cin >> codCliente;
                    cout << "Digite o nome do cliente: ";
                    scanf(" %[^\n]", nomeCliente);   
                    cout << "Digite o endereco do cliente: ";
                    scanf(" %[^\n]", end);         
                    cout << "Digite o telefone do cliente: ";
                    cin >> telCliente;
                    Cliente novoCliente;
                    novoCliente.cadastraCliente(clientes, numClientes, codCliente, nomeCliente, end, telCliente);
                    novoCliente.adicionaCliente(&clientes, numClientes, capClientes, novoCliente);
                    break;
                }
                else if (opc2 == 2){
                    // editar cliente
                    int codClienteEditar;
                    cout << "Digite o codigo do cliente a ser editado: ";
                    cin >> codClienteEditar;
                    // fazer funcao para ediçao
                    break;
                }
                else {
                    // remover cliente
                    int codClienteRemover;
                    cout << "Digite o codigo do cliente a ser removido: ";
                    cin >> codClienteRemover;
                    // fazer funcao para remoçao
                    break;
                }
                break;
            }
            case 2:{
                //opcoes de funcionario
                int opcFunc;
                cout << "1 : Cadastrar funcionario." << endl;
                cout << "2 : Editar funcionario." << endl;
                cout << "3 : Remover funcionario." << endl;
                cin >> opcFunc;
                if (opcFunc < 1 || opcFunc > 3){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }
                if (opcFunc == 1){
                    //cadastrar funcionario
                    int codFunc, telFunc;
                    char nomeFunc[99], cargo[30];
                    float salario;
                    cout << "Digite o codigo do funcionario: ";
                    cin >> codFunc;
                    cout << "Digite o nome do funcionario: ";
                    scanf(" %[^\n]", &nomeFunc);
                    cout << "Digite o cargo do funcionario: ";
                    scanf(" %[^\n]", &cargo);
                    cout << "Digite o telefone do funcionario: ";
                    cin >> telFunc;
                    cout << "Digite o salario do funcionario: ";
                    cin >> salario;
                    Funcionario novoFunc;
                    novoFunc.cadastraFunc(&novoFunc, numFuncionarios, codFunc, nomeFunc, cargo, telFunc, salario);
                    novoFunc.adicionaFuncionario(&funcionarios, numFuncionarios, capFuncionarios, novoFunc);
                    break;
                }
                
                else if (opcFunc == 2){                        
                    //editar funcionario
                    int codFuncEditar;
                    cout << "Digite o codigo do funcionario a ser editado: ";
                    cin >> codFuncEditar;
                    //fazer funcao para ediçao
                    break;
                  }
                else {
                    //remover funcionario
                    int codFuncRemover;
                    cout << "Digite o codigo do funcionario a ser removido: ";
                    cin >> codFuncRemover;
                    //fazer funcao para remoçao
                    break;
                }
                break;
            }
            case 3:{
                //cadastro de quarto
                int numeroQuarto, quantHospedes, codigoClienteQuarto;
                float valorDiaria;
                bool status;
                cout << "Digite o numero do quarto: ";
                cin >> numeroQuarto;
                cout << "Digite a quantidade de hospedes: ";
                cin >> quantHospedes;
                cout << "Digite o valor da diaria: ";
                cin >> valorDiaria;
                cout << "Digite o status do quarto (1 para ocupado, 0 para livre): ";
                cin >> status;
                cout << "Digite o codigo do cliente que ira ocupar o quarto: ";
                cin >> codigoClienteQuarto;
                //verifica se o codigo do cliente existe
                if (!verificaCliente(clientes, numClientes, codigoClienteQuarto)){
                    cout << "Codigo de cliente nao existe. Cadastro de quarto nao realizado." << endl;
                    break;
                }

                Quarto novoQuarto;
                novoQuarto.cadastraQuarto(quartos, numQuartos, numeroQuarto, quantHospedes, valorDiaria, status, codigoClienteQuarto);
                novoQuarto.adicionaQuarto(&quartos, numQuartos, capQuartos, novoQuarto);
                break;
            }
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