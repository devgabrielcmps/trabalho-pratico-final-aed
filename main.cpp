#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#define valorDiaria 100

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

void deletaFuncionario(Funcionario *func, int &numFuncs, int codigofunc){
    int index = -1;
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigofunc){ //move todos os elementos uma posiçao para tras para deletar o funcionario
            index = i;
            break;
        }
    }
    if (index != -1){
        for (int j = index; j < numFuncs - 1; j++){
            func[j] = func[j + 1];
        }
        --numFuncs;
        cout << "Funcionario deletado com sucesso!" << endl;
    }
    else{
        cout << "Funcionario nao encontrado." << endl;
    }
}

void deletaCliente(Cliente *cliente, int &numClientes, int codigoCliente){
    int index = -1;
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            index = i;
            break;
        }
    }
    if (index != -1){
        for (int j = index; j < numClientes - 1; j++){ //move todos os elementos uma posiçao para tras para deletar o cliente
            cliente[j] = cliente[j + 1];
        }
        --numClientes;
        cout << "Cliente deletado com sucesso!" << endl;
    }
    else{
        cout << "Cliente nao encontrado." << endl;
    }
}
    
void editaFuncionario(Funcionario *func, int numFuncs, int codigoFunc){
    int opcEditar;
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigoFunc){
            cout << "O que deseja editar?" << endl;
            cout << "1 : Nome." << endl;
            cout << "2 : Cargo." << endl;
            cout << "3 : Telefone." << endl;
            cout << "4 : Salario." << endl;
            cin >> opcEditar;
            switch (opcEditar){
                case 1:{
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    func[i].setNomeFunc(novoNome);
                    cout << "Nome atualizado com sucesso!" << endl;
                    break;
                }
                case 2:{
                    char novoCargo[30];
                    cout << "Digite o novo cargo: ";
                    scanf(" %[^\n]", novoCargo);
                    func[i].setCargo(novoCargo);
                    cout << "Cargo atualizado com sucesso!" << endl;
                    break;
                }
                case 3:{
                    int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    func[i].setTelFunc(novoTel);
                    cout << "Telefone atualizado com sucesso!" << endl;
                    break;
                }
                case 4:{
                    float novoSalario;
                    cout << "Digite o novo salario: ";
                    cin >> novoSalario;
                    func[i].setSalario(novoSalario);
                    cout << "Salario atualizado com sucesso!" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado." << endl;
            }
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

void editaCliente(Cliente *cliente, int numClientes, int codigoCliente){
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            int opcEditar;
            cout << "O que deseja editar?" << endl;
            cout << "1 : Nome." << endl;
            cout << "2 : Endereco." << endl;
            cout << "3 : Telefone." << endl;
            cin >> opcEditar;
            switch (opcEditar){
                case 1:{
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    cliente[i].setNomeCliente(novoNome);
                    cout << "Nome atualizado com sucesso!" << endl;
                    break;
                }
                case 2:{
                    char novoEndereco[99];
                    cout << "Digite o novo endereco: ";
                    scanf(" %[^\n]", novoEndereco);
                    cliente[i].setEndereco(novoEndereco);
                    cout << "Endereco atualizado com sucesso!" << endl;
                    break;
                }
                case 3:{
                    int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    cliente[i].setTelCliente(novoTel);
                    cout << "Telefone atualizado com sucesso!" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado." << endl;
            }
        }
    }
    cout << "Cliente nao encontrado." << endl;
}

void procuraFuncionario(Funcionario *func, int numFuncs, int codigoFunc){
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigoFunc){
            cout << "Funcionario encontrado!" << endl;
            cout << "Codigo: " << func[i].getCodigoFunc() << endl;
            cout << "Nome: " << func[i].getNomeFunc() << endl;
            cout << "Cargo: " << func[i].getCargo() << endl;
            cout << "Telefone: " << func[i].getTelFunc() << endl;
            cout << "Salario: " << func[i].getSalario() << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

void procuraCliente(Cliente *cliente, int numClientes, int codigoCliente){
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            cout << "Cliente encontrado!" << endl;
            cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
            cout << "Nome: " << cliente[i].getNomeCliente() << endl;
            cout << "Endereco: " << cliente[i].getEndereco() << endl;
            cout << "Telefone: " << cliente[i].getTelCliente() << endl;
            cout << "Quarto numero: " << cliente[i].getCodigoCliente() << endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;
}

class Quarto{
    private:
        int numQuarto;
        int quantHospedes;
        bool status;
        int codigoCliente;
    public:
        //encapsulamento
        int getNumQuarto(){return numQuarto;};
        int getQuantHospedes(){return quantHospedes;};
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

        void cadastraQuarto(Quarto *quartos, int numQuartos, int numeroQuarto, int quantHospedes, bool status){
            if (numQuartoJaExiste(numeroQuarto, quartos, numQuartos) == true){
                cout << "Quarto ja ocupado! Cadastro nao realizado." << endl;
                return;
            }
            else{
                setNumQuarto(numeroQuarto);
                setQuantHospedes(quantHospedes);
                setStatus(status);
                cout << "Quarto cadastrado com sucesso!" << endl;
            }
        }
};

//procedimento para verificar se o quarto pertence ao cliente
//caso precise, pode ser usado para verificar se o cliente pode fazer check-out ou não
//usar na classe estadia
//talvez esta funcao nao seja mais necessaria
void verificaQuartoPertenceCliente(Quarto *quarto, int numQuartos, int numeroQuarto, int codigoCliente){
    for (int i = 0; i < numQuartos; i++){
        if (quarto[i].getNumQuarto() == numeroQuarto){
            if (quarto[i].getCodigoCliente() == codigoCliente){
                cout << "O quarto pertence ao cliente." << endl;
            }
            else{
                cout << "O quarto nao pertence ao cliente." << endl;
            }
            return;
        }
    }
    cout << "Quarto nao encontrado." << endl;
}

//versao booleana da funcao acima
bool verificaQuartoPertenceClienteBool(Quarto *quarto, int numQuartos, int numeroQuarto, int codigoCliente){
    for (int i = 0; i < numQuartos; i++){
        if (quarto[i].getNumQuarto() == numeroQuarto &&
            quarto[i].getCodigoCliente() == codigoCliente){
            return true;
        }
    }
    return false;
}
//procedimento para verificar se o cliente existe
//caso precise, pode ser usado para verificar se o cliente pode fazer check-in ou não
bool verificaCliente(Cliente *cliente, int numCLientes, int codigoCliente){
    for (int i = 0; i < numCLientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            return true;
        }
    }
    return false;
}

class Estadia{
    private:
        int codigoEstadia;
        int dataEntrada;
        int dataSaida;
        int numDiarias;
        //puxando codigo cliente e num quarto das classes cliente e quarto;
        int codigoCliente;
        int quantHospedes;
        char nomeCliente[99];
    public:
        //encapsulamento
        int getCodigoEstadia(){return codigoEstadia;};
        int getDataEntrda(){return dataEntrada;};
        int getDataSaida(){return dataSaida;};
        int getNumDiarias(){return numDiarias;};
        int getCodigoCliente(){return codigoCliente;};
        int getNumQuarto(){return quantHospedes;};
        char *getNomeCliente(){return nomeCliente;};

        void setcodigoEstadia(int a){
            if (a > 0)
                codigoEstadia = a;
        }
        void setdataEntrada(int b){
            if (b > 0)
                dataEntrada = b;
        }
        void setdataSaida(int c){
            if (c > 0)
                dataSaida = c;
        }
        void setnumDiarias(int d){
            if (d > 0)
                numDiarias = d;
        }
        void setcodigoCliente(int e){
            if (e > 0)
                codigoCliente = e;
        }
        void setnumQuarto(int f){
            if (f > 0)
                quantHospedes = f;
        }
        void  setnomeCliente(char g[99]){
            strcpy(nomeCliente, g);
        }

    void cadastrarEstadia(Estadia *estadias, int numEstadias, Quarto *quartos, int numQuartos){    
        int codCliente, quantHospedes, dataEntrada, dataSaida;
        cout << "Digite o codigo do cliente: ";
        cin >> codCliente;
        cout << "Digite a quantidade de hospedes: ";
        cin >> quantHospedes;
        cout << "Digite a data de entrada: ";
        cin >> dataEntrada;
        cout << "Digite a data de saida: ";
        cin >> dataSaida;

        for (int i = 0; i < numQuartos; i++){
            if (quartos[i].getQuantHospedes() >= quantHospedes && quartos[i].getStatus() == false){
                setcodigoCliente(codCliente);
                setnumQuarto(quartos[i].getNumQuarto());
                setdataEntrada(dataEntrada);
                setdataSaida(dataSaida);
                int diarias = dataSaida - dataEntrada;
                setnumDiarias(diarias);
                cout << "Estadia cadastrada com sucesso!" << endl;
                quartos[i].setStatus(true); //marca o quarto como ocupado
                quartos[i].setCodigoCliente(codCliente); //associa o cliente ao quarto
                return;
            }
        }
    }

    void adicionaEstadia(Estadia **temp, int &num, int &cap, Estadia novaEstadia){
        if (num >= cap){
            cap = (cap == 0) ? 5 : cap * 2;
            *temp = (Estadia*) realloc(*temp, cap * sizeof(Estadia));
        }
        Estadia *p = *temp;
        p[num] = novaEstadia;
        num++;
    }


};

void BackupdeDados(Cliente *cliente, int numClientes, Funcionario *funcionario, int numFuncs ,Quarto *quarto, int numQuartos, Estadia *estadia, int numEstadias){
    //implementar backup de dados
    FILE *backup;
    backup = fopen("backup.bin", "wb");
    if (backup == NULL){
        cout << "Erro ao criar arquivo de backup." << endl;
        return;
    }
    for (int i = 0; i < numClientes; i++){
        fwrite(&cliente[i], sizeof(Cliente), 1, backup);
    }

    for (int i = 0; i < numFuncs; i++){
        fwrite(&funcionario[i], sizeof(Funcionario), 1, backup);
    }

    for (int i = 0; i < numQuartos; i++){
        fwrite(&quarto[i], sizeof(Quarto), 1, backup);
    }

    for (int i = 0; i < numEstadias; i++){
        fwrite(&estadia[i], sizeof(Estadia), 1, backup);
    }

    fclose(backup);
    cout << "Backup realizado com sucesso!" << endl;
}

void RestaurarDados(){
    //implementar restaurar dados
}

//procedimento para mostrar as estadias cadastradas de um cliente especifico
void mostraEstadias(Estadia *estadias, int numEstadias){
    int opcMostrar, codigoCliente;
    char nomeClienteBusca[99];
    cout << "Escolha uma das opcoes para mostrar as estadias:" << endl;
    cout << "1 : Mostrar estadias por codigo do cliente." << endl;
    cout << "2 : Mostrar estadias por nome do cliente." << endl;   
    cin >> opcMostrar;
    switch (opcMostrar){
        case 1:{
            cout << "Digite o codigo do cliente: ";
            cin >> codigoCliente;
            for (int i = 0; i < numEstadias; i++){
                if (estadias[i].getCodigoCliente() == codigoCliente){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getDataEntrda() << endl;
                    cout << "Data de saida: " << estadias[i].getDataSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                }
            }
            break;
        }
        case 2:{
            cout << "Digite o nome do cliente: ";
            scanf(" %[^\n]", nomeClienteBusca);
            for (int i = 0; i < numEstadias; i++){
                if (strcmp(estadias[i].getNomeCliente(), nomeClienteBusca) == 0){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getDataEntrda() << endl;
                    cout << "Data de saida: " << estadias[i].getDataSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                }
            }
            break;
        }
        default:
            cout << "Opcao invalida. Nenhum dado foi mostrado." << endl;
        
    }
}
void baixaEstadia(){
    //implementar baixa de estadia
}

int main() {
    Cliente *clientes = NULL;
    Funcionario *funcionarios = NULL;
    Quarto *quartos = NULL;
    Estadia *estadias = NULL;

    int numClientes = 0, capClientes = 0;
    int numFuncionarios = 0, capFuncionarios = 0;
    int numQuartos = 0, capQuartos = 0;
    int numEstadias = 0, capEstadias = 0;

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
                    editaCliente(clientes, numClientes, codClienteEditar);
                    break;
                }
                else {
                    // remover cliente
                    int codClienteRemover;
                    cout << "Digite o codigo do cliente a ser removido: ";
                    cin >> codClienteRemover;
                    deletaCliente(clientes, numClientes, codClienteRemover);
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
                    scanf(" %[^\n]", nomeFunc);
                    cout << "Digite o cargo do funcionario: ";
                    scanf(" %[^\n]", cargo);
                    cout << "Digite o telefone do funcionario: ";
                    cin >> telFunc;
                    cout << "Digite o salario do funcionario: ";
                    cin >> salario;
                    Funcionario novoFunc;
                    novoFunc.cadastraFunc(funcionarios, numFuncionarios, codFunc, nomeFunc, cargo, telFunc, salario);
                    novoFunc.adicionaFuncionario(&funcionarios, numFuncionarios, capFuncionarios, novoFunc);
                    break;
                }
                
                else if (opcFunc == 2){                        
                    //editar funcionario
                    int codFuncEditar;
                    cout << "Digite o codigo do funcionario a ser editado: ";
                    cin >> codFuncEditar;
                    editaFuncionario(funcionarios, numFuncionarios, codFuncEditar);
                    break;
                  }
                else {
                    //remover funcionario
                    int codFuncRemover;
                    cout << "Digite o codigo do funcionario a ser removido: ";
                    cin >> codFuncRemover;
                    deletaFuncionario(funcionarios, numFuncionarios, codFuncRemover);
                    break;
                }
                break;
            }
            case 3:{
                //cadastro de quarto
                int numeroQuarto, quantHospedes, codigoClienteQuarto;
                bool status;
                cout << "Digite o numero do quarto: ";
                cin >> numeroQuarto;
                cout << "Digite a capacidade de hospedes: ";
                cin >> quantHospedes;
                cout << "Digite o status do quarto (1 para ocupado, 0 para livre): ";
                cin >> status;

                Quarto novoQuarto;
                novoQuarto.cadastraQuarto(quartos, numQuartos, numeroQuarto, quantHospedes, status);
                novoQuarto.adicionaQuarto(&quartos, numQuartos, capQuartos, novoQuarto);
                break;
            }
            case 4:{
                //cadastrar estadia
                Estadia novaEstadia;
                novaEstadia.cadastrarEstadia(estadias, numEstadias, quartos, numQuartos);
                novaEstadia.adicionaEstadia(&estadias, numEstadias, capEstadias, novaEstadia);
                break;
            }
            case 5:
                //dar baixa em estadia
                break;
            case 6:{
                //mostrar estadias
                mostraEstadias(estadias, numEstadias);
                break;
            }
            case 7:{
                //pesquisar cliente/funcionario
                int opcPesquisar;
                cout << "1 : Pesquisar cliente." << endl;
                cout << "2 : Pesquisar funcionario." << endl;
                cin >> opcPesquisar;
                if (opcPesquisar < 1 || opcPesquisar > 2){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }
                if (opcPesquisar == 1){
                    //pesquisar cliente
                    int codClientePesquisar;
                    cout << "Digite o codigo do cliente a ser pesquisado: ";
                    cin >> codClientePesquisar;
                    procuraCliente(clientes, numClientes, codClientePesquisar);
                    break;
                }
                else {
                    //pesquisar funcionario
                    int codFuncPesquisar;
                    cout << "Digite o codigo do funcionario a ser pesquisado: ";
                    cin >> codFuncPesquisar;
                    procuraFuncionario(funcionarios, numFuncionarios, codFuncPesquisar);
                    break;
                }
                break;
            }
            case 8:
                //backup de dados
                BackupdeDados(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;
            case 9:
                //restaurar dados
                break;
            default:
                cout << "opcao invalida, fechando programa....." << endl;
                break;
        }
    }while(opc >=1 && opc <= 9);


}