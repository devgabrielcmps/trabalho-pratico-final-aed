// Trabalho Prático AED I 
// Alunos: Gabriel Campos e Lucas Emanuel

#include <iostream>   // Entrada e saída (cout, cin)
#include <string.h>   // Funções para strings em estilo C
#include <cstdlib>    // Funções gerais (system, etc)
#include <cstdio>     // Funções de entrada e saída do C
#include <fstream>    // Manipulação de arquivos

#define valorDiaria 100.0   // Valor fixo da diária do hotel

using namespace std; 

class Cliente{
    private:
        int codigoCliente;      // Código único do cliente
        char nomeCliente[99];   // Nome armazenado em char[]
        char endereco[99];      // Endereço do cliente
        long long int telCliente;         // Telefone

    public:
        // Getters (acessam os dados privados)
        int getCodigoCliente(){ return codigoCliente; };
        char *getNomeCliente(){ return nomeCliente; };
        char *getEndereco(){ return endereco; };
        long long int getTelCliente(){ return telCliente; };

        // Setters (alteram os dados privados)
        void setCodigoCliente(int x){
            if (x > 0)
                codigoCliente = x;
        }

        void setNomeCliente(char y[99]){
            strcpy(nomeCliente, y); // copia o nome
        }

        void setEndereco(char z[99]){
            strcpy(endereco, z); // copia o endereço
        }

        void setTelCliente(long long int a){
            if (a > 0)
                telCliente = a;
        }

        // Adiciona um novo cliente ao vetor dinâmico
        // Se não tiver espaço, realoca aumentando a capacidade
        void adicionaCliente(Cliente **temp, int &num, int &cap, Cliente novoCliente) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2; 
                *temp = (Cliente *)realloc(*temp, cap * sizeof(Cliente));
            }
            Cliente *p = *temp;
            p[num] = novoCliente;
            num++;
        }

        // Verifica se o código já existe no vetor de clientes
        bool codigoClienteJaExiste(int a, Cliente *clientes, int numClientes){
            for (int i = 0; i < numClientes; i++){
                if (clientes[i].getCodigoCliente() == a)
                    return true;
            }
            return false;
        }

        // Cadastra um cliente após verificar se o código já existe
        void cadastraCliente(Cliente *cliente, int numDeClientes, int codCliente,
                             char nomeCliente[99], char end[99], long long int telCliente){

            if (codigoClienteJaExiste(codCliente, cliente, numDeClientes)){
                cout << "Codigo de cliente ja existe. Cadastro nao realizado. \n" << endl;
                return;
            }


            else {
                for (int i = 0; i < numDeClientes; i++){
                    if (cliente[i].getNomeCliente() == nomeCliente){
                        cout << "Nome de cliente ja existe. Cadastro nao realizado. \n" << endl;
                        return;
                    }
                }
                setCodigoCliente(codCliente);
                setNomeCliente(nomeCliente);
                setEndereco(end);
                setTelCliente(telCliente);
                cout << "Cliente cadastrado com sucesso! \n" << endl;
                return;
            }
        }
};


class Funcionario{
    private:
        int codigoFunc;       // Código de identificação do funcionário
        char nomeFunc[99];    // Nome do funcionário
        long long int telFunc;          // Telefone
        char cargo[30];       // Cargo/função do funcionário
        float salario;        // Salário

    public:
        // Getters: acessam os dados privados
        int getCodigoFunc(){ return codigoFunc; };
        char *getNomeFunc(){ return nomeFunc; };
        char *getCargo(){ return cargo; };
        long long int getTelFunc(){ return telFunc; };
        float getSalario(){ return salario; };

        // Setters: modificam os dados privados
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

        void setTelFunc(long long int a){
            if (a > 0)
                telFunc = a;
        }

        void setSalario(float b){
            if (b > 0.0)
                salario = b;
        }

        // Adiciona um novo funcionário ao vetor dinâmico
        // Realoca memória se o vetor estiver cheio
        void adicionaFuncionario(Funcionario **temp, int &num, int &cap, Funcionario novoFunc) {
            if (num == cap) {
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Funcionario *)realloc(*temp, cap * sizeof(Funcionario));
            }
            Funcionario *p = *temp;
            p[num] = novoFunc;
            num++;
        }

        // Verifica se já existe um funcionário com o mesmo código
        bool codigoFuncJaExiste(int a, Funcionario *funcionarios, int numFuncionarios){
            for (int i = 0; i < numFuncionarios; i++){
                if (funcionarios[i].getCodigoFunc() == a){
                    return true;
                }
            }
            return false;
        }

        // Cadastra um funcionário caso o código não esteja repetido
        void cadastraFunc(Funcionario *funcionarios, int numFuncionarios, int codFunc, 
                          char nomeFunc[99], char cargo[30], long long int telFunc, float salario){

            if (codigoFuncJaExiste(codFunc, funcionarios, numFuncionarios)){
                cout << "Codigo de funcionario ja existe. Cadastro nao realizado. \n" << endl;
                return;
            }
            else{
                for (int i = 0; i < numFuncionarios; i++){
                    if (funcionarios[i].getNomeFunc() == nomeFunc){
                        cout << "Nome de funcionario ja existe. Cadastro nao realizado. \n" << endl;
                        return;
                    }
                }
                setCodigoFunc(codFunc);
                setNomeFunc(nomeFunc);
                setCargo(cargo);
                setTelFunc(telFunc);
                setSalario(salario);
                cout << "Funcionario cadastrado com sucesso! \n" << endl;
                return;
            }            
        }
};

bool validaTelefone(long long int tel){
    //contador de digitos para o telefone
    int contador = 0;
    while (tel != 0){
        tel /= 10;
        contador++;
    }
    if (contador >= 8 && contador <= 11){
        return true;
    }
    else{
        return false;
    }
}

void deletaFuncionario(Funcionario *func, int &numFuncs, int codigofunc){
    int index = -1; // posição onde o funcionário será encontrado

    // Procura o funcionário pelo código
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigofunc){ 
            index = i;   // guarda a posição do funcionário
            break;
        }
    }

    // Se encontrou o funcionário
    if (index != -1){
        // Move todos os elementos depois dele uma posição para trás
        for (int j = index; j < numFuncs - 1; j++){
            func[j] = func[j + 1];
        }

        --numFuncs; // diminui o total de funcionários
        cout << "Funcionario deletado com sucesso! \n" << endl;
    }
    else{
        // Caso o código não exista no vetor
        cout << "Funcionario nao encontrado. \n" << endl;
    }
}


void deletaCliente(Cliente *cliente, int &numClientes, int codigoCliente){
    int index = -1; // posição onde o cliente será encontrado

    // Procura o cliente pelo código
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){
            index = i; // guarda a posição do cliente
            break;
        }
    }

    // Se encontrou o cliente
    if (index != -1){
        // Move todos os clientes após o removido uma posição para trás
        for (int j = index; j < numClientes - 1; j++){
            cliente[j] = cliente[j + 1];
        }

        --numClientes; // diminui o total de clientes
        cout << "Cliente deletado com sucesso! \n" << endl;
    }
    else{
        // Caso o código não exista
        cout << "Cliente nao encontrado. \n" << endl;
    }
}

    
void editaFuncionario(Funcionario *func, int numFuncs, int codigoFunc){
    int opcEditar;

    // Percorre a lista de funcionários procurando o código
    for (int i = 0; i < numFuncs; i++){
        if (func[i].getCodigoFunc() == codigoFunc){

            // Menu de edição
            cout << "O que deseja editar?" << endl;
            cout << "[1] Nome." << endl;
            cout << "[2] Cargo." << endl;
            cout << "[3] Telefone." << endl;
            cout << "[4] Salario." << endl;
            cout << ">> ";
            cin >> opcEditar;
            cout << "\n" << endl; // Apenas pula uma linha

            switch (opcEditar){
                case 1:{ // Edita nome
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    fflush(stdin);
                    func[i].setNomeFunc(novoNome);
                    cout << "Nome atualizado com sucesso! \n" << endl;
                    break;
                }
                case 2:{ // Edita cargo
                    char novoCargo[30];
                    cout << "Digite o novo cargo: ";
                    scanf(" %[^\n]", novoCargo);
                    fflush(stdin);
                    func[i].setCargo(novoCargo);
                    cout << "Cargo atualizado com sucesso! \n" << endl;
                    break;
                }
                case 3:{ // Edita telefone
                    long long int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    if (!validaTelefone(novoTel)){
                        cout << "Telefone invalido. Nenhum dado foi alterado. \n" << endl;
                        return;
                    }
                    func[i].setTelFunc(novoTel);
                    cout << "Telefone atualizado com sucesso! \n" << endl;
                    break;
                }
                case 4:{ // Edita salário
                    float novoSalario;
                    cout << "Digite o novo salario: ";
                    cin >> novoSalario;
                    if (novoSalario <= 0.0){
                        cout << "Salario invalido. Nenhum dado foi alterado. \n" << endl;
                        return;
                    }
                    func[i].setSalario(novoSalario);
                    cout << "Salario atualizado com sucesso! \n" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado. \n" << endl;
            }

            return; // Sai da função após editar
        }
    }

    // Se não encontrou o funcionário no vetor
    cout << "Funcionario nao encontrado." << endl;
}


void editaCliente(Cliente *cliente, int numClientes, int codigoCliente){
    // Percorre todos os clientes para encontrar o código
    for (int i = 0; i < numClientes; i++){
        if (cliente[i].getCodigoCliente() == codigoCliente){

            int opcEditar;
            // Menu de opções para editar
            cout << "O que deseja editar?" << endl;
            cout << "[1] Nome." << endl;
            cout << "[2] Endereco." << endl;
            cout << "[3] Telefone." << endl;
            cout << ">> ";
            cin >> opcEditar;

            cout << "\n" << endl; // Apenas pula linha para formatação

            switch (opcEditar){
                case 1:{ // Editar nome
                    char novoNome[99];
                    cout << "Digite o novo nome: ";
                    scanf(" %[^\n]", novoNome);
                    fflush(stdin);
                    cliente[i].setNomeCliente(novoNome);
                    cout << "Nome atualizado com sucesso! \n" << endl;
                    break;
                }
                case 2:{ // Editar endereço
                    char novoEndereco[99];
                    cout << "Digite o novo endereco: ";
                    scanf(" %[^\n]", novoEndereco);
                    fflush(stdin);
                    cliente[i].setEndereco(novoEndereco);
                    cout << "Endereco atualizado com sucesso! \n" << endl;
                    break;
                }
                case 3:{ // Editar telefone
                    long long int novoTel;
                    cout << "Digite o novo telefone: ";
                    cin >> novoTel;
                    if (!validaTelefone(novoTel)){
                        cout << "Telefone invalido. Nenhum dado foi alterado. \n" << endl;
                        return;
                    }
                    cliente[i].setTelCliente(novoTel);
                    cout << "Telefone atualizado com sucesso! \n" << endl;
                    break;
                }
                default:
                    cout << "Opcao invalida. Nenhum dado foi alterado. \n" << endl;
            }

            return; // Sai após editar
        }
    }

    // Caso nenhum cliente tenha o código procurado
    cout << "Cliente nao encontrado." << endl;
}

// Função para procurar um funcionário pelo código
void procuraFuncionario(Funcionario *func, int numFuncs){
    // Percorre o vetor de funcionários
    int codigoFunc, opcPesquisar;
    char nomeFunc[99];
    cout << "[1] Pesquisa por codigo do funcionario." << endl;
    cout << "[2] Pesquisa por nome do funcionario." << endl;
    cout << ">> ";
    cin >> opcPesquisar;
    cout << "\n" << endl; // Apenas pula linha para formatação
    switch(opcPesquisar){
        case 1:{
            cout << "Digite o codigo do funcionario a ser pesquisado: ";
            cin >> codigoFunc;
            for (int i = 0; i < numFuncs; i++){
                // Verifica se o código do funcionário atual é igual ao procurado
                if (func[i].getCodigoFunc() == codigoFunc){
                cout << "Funcionario encontrado! \n" << endl;
            
                    // Exibe os dados do funcionário encontrado
                    cout << "Codigo: " << func[i].getCodigoFunc() << endl;
                    cout << "Nome: " << func[i].getNomeFunc() << endl;
                    cout << "Cargo: " << func[i].getCargo() << endl;
                    cout << "Telefone: " << func[i].getTelFunc() << endl;
                    cout << "Salario: R$ " << func[i].getSalario() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Funcionario nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        case 2:{
            cout << "Digite o nome do funcionario a ser pesquisado: ";
            scanf(" %[^\n]", nomeFunc);
            fflush(stdin);
            for (int i = 0; i < numFuncs; i++){
                // Verifica se o nome do funcionário atual é igual ao procurado
                if (strcmp(func[i].getNomeFunc(), nomeFunc) == 0){
                cout << "Funcionario encontrado! \n" << endl;
            
                    // Exibe os dados do funcionário encontrado
                    cout << "Codigo: " << func[i].getCodigoFunc() << endl;
                    cout << "Nome: " << func[i].getNomeFunc() << endl;
                    cout << "Cargo: " << func[i].getCargo() << endl;
                    cout << "Telefone: " << func[i].getTelFunc() << endl;
                    cout << "Salario: R$ " << func[i].getSalario() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Funcionario nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        default:
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
            return;
    }
    // Caso o funcionário não seja encontrado
    cout << "Funcionario nao encontrado. \n" << endl;
}

// Função para procurar um cliente pelo código
void procuraCliente(Cliente *cliente, int numClientes){
    // Percorre o vetor de clientes
    int codigoCliente, opcPesquisar;
    char nomeCliente[99];
    cout << "[1] Pesquisa por codigo do cliente." << endl;
    cout << "[2] Pesquisa por nome do cliente." << endl;
    cout << ">> ";
    cin >> opcPesquisar;
    cout << "\n" << endl; // Apenas pula linha para formatação

    switch(opcPesquisar){
        case 1:{
            cout << "Digite o codigo do cliente a ser pesquisado: ";
            cin >> codigoCliente;
            for (int i = 0; i < numClientes; i++){
                // Verifica se o código do cliente atual é igual ao procurado
                if (cliente[i].getCodigoCliente() == codigoCliente){
                cout << "Cliente encontrado! \n" << endl;
            
                    // Exibe os dados do cliente encontrado
                    cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
                    cout << "Nome: " << cliente[i].getNomeCliente() << endl;
                    cout << "Endereco: " << cliente[i].getEndereco() << endl;
                    cout << "Telefone: " << cliente[i].getTelCliente() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Cliente nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        case 2:{
            cout << "Digite o nome do cliente a ser pesquisado: ";
            scanf(" %[^\n]", nomeCliente);
            fflush(stdin);
            for (int i = 0; i < numClientes; i++){
                // Verifica se o nome do cliente atual é igual ao procurado
                if (strcmp(cliente[i].getNomeCliente(), nomeCliente) == 0){
                cout << "Cliente encontrado! \n" << endl;
            
                    // Exibe os dados do cliente encontrado
                    cout << "Codigo: " << cliente[i].getCodigoCliente() << endl;
                    cout << "Nome: " << cliente[i].getNomeCliente() << endl;
                    cout << "Endereco: " << cliente[i].getEndereco() << endl;
                    cout << "Telefone: " << cliente[i].getTelCliente() << endl;
                
                    return; // Encerra a função após encontrar
                }
            }
            cout << "Cliente nao encontrado. \n" << endl; //mensagem de erro
            break;
        }
        default:
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
            return;
    }
}

class Quarto{
    private:
        int numQuarto;       // Número do quarto
        int quantHospedes;   // Quantidade máxima de hóspedes
        bool status;         // Status do quarto: true = ocupado, false = livre
        int codigoCliente;   // Código do cliente que está no quarto

    public:
        // Getters: acessam os dados privados
        int getNumQuarto(){ return numQuarto; };
        int getQuantHospedes(){ return quantHospedes; };
        bool getStatus(){ return status; };
        int getCodigoCliente(){ return codigoCliente; };

        // Setters: alteram os dados privados
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

        // Adiciona um novo quarto ao vetor dinâmico
        // Realoca memória se o vetor estiver cheio
        void adicionaQuarto(Quarto **temp, int &num, int &cap, Quarto novoQuarto){
            if (num >= cap){
                cap = (cap == 0) ? 5 : cap * 2;
                *temp = (Quarto*) realloc(*temp, cap * sizeof(Quarto));
            }
            Quarto *p = *temp;
            p[num] = novoQuarto;
            num++;
        }

        // Verifica se o número do quarto já existe
        bool numQuartoJaExiste(int a, Quarto *quartos, int numQuartos){
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getNumQuarto() == a){
                    return true;
                }
            }
            return false;
        }

        // Cadastra um quarto caso o número não esteja repetido
        void cadastraQuarto(Quarto *quartos, int numQuartos, int numeroQuarto, int quantHospedes, bool status){
            if (numQuartoJaExiste(numeroQuarto, quartos, numQuartos)){
                cout << "Quarto ja existe! Cadastro nao realizado. \n" << endl;
                return;
            }
            else{
                setNumQuarto(numeroQuarto);
                setQuantHospedes(quantHospedes);
                status = false; // Quarto inicia como livre
                setStatus(status);
                cout << "Quarto cadastrado com sucesso! \n" << endl;
            }
        }
};

// Função para verificar se um cliente existe no sistema
bool verificaCliente(Cliente *cliente, int numClientes, int codigoCliente){
    // Percorre todos os clientes
    for (int i = 0; i < numClientes; i++){
        // Se o código do cliente atual for igual ao procurado, retorna true
        if (cliente[i].getCodigoCliente() == codigoCliente){
            return true;
        }
    }

    // Se não encontrou nenhum cliente com o código, retorna false
    return false;
}

class Estadia{
    private:
        int codigoEstadia;     // Código único da estadia
        int diaDataEntrada;       // Data de entrada (pode ser formato numérico, ex: YYYYMMDD)
        int mesDataEntrada;      // Mês de entrada
        int anoDataEntrada;      // Ano de entrada
        int diaDataSaida;         // Data de saída
        int mesDataSaida;        // Mês de saída
        int anoDataSaida;       // Ano de saída
        int numDiarias;        // Quantidade de diárias
        int codigoCliente;     // Código do cliente associado à estadia
        int quantHospedes;     // Número de hóspedes para a estadia (puxado do quarto)
        char nomeCliente[99];  // Nome do cliente (copiado da classe Cliente)

    public:
        // Getters: retornam os dados privados
        int getCodigoEstadia(){return codigoEstadia;}; 
        int getdiaDtaEntrada(){return diaDataEntrada;};
        int getmesDtaEntrada(){return mesDataEntrada;};
        int getanoDtaEntrada(){return anoDataEntrada;};
        int getdiaDtaSaida(){return diaDataSaida;};
        int getmesDtaSaida(){return mesDataSaida;};
        int getanoDtaSaida(){return anoDataSaida;};
        int getNumDiarias(){return numDiarias;};
        int getCodigoCliente(){return codigoCliente;};
        int getNumQuarto(){return quantHospedes;};
        char *getNomeCliente(){return nomeCliente;};

        // Setters: alteram os dados privados
        void setcodigoEstadia(int a){
            if (a > 0)
                codigoEstadia = a;
        }
        void setdataEntrada(int b, int c, int d){
            if (b > 0 && b <= 31)
                diaDataEntrada = b;
            if (c > 0 && c <= 12)
                mesDataEntrada = c;
            if (d > 0)
                anoDataEntrada = d;
        }
        void setdataSaida(int e, int f, int g){
            if (e > 0 && e <= 31)
                diaDataSaida = e;
            if (f > 0 && f <= 12)
                mesDataSaida = f;
            if (g > 0)
                anoDataSaida = g;
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
        void setnomeCliente(char g[99]){
            strcpy(nomeCliente, g);
        }

        // Função para cadastrar uma estadia
        void cadastrarEstadia(Estadia *estadias, int numEstadias, Quarto *quartos, int numQuartos, Cliente *clientes, int numClientes){    
            int codCliente, quantHospedes, codEstadia;
            int diaEntrada, mesEntrada, anoEntrada;
            int diaSaida, mesSaida, anoSaida;

            // Pede o código do cliente
            cout << "Digite o codigo do cliente: ";
            cin >> codCliente;

            // Verifica se o cliente existe
            if (verificaCliente(clientes, numClientes, codCliente) == false){
                cout << "Cliente nao existe. Cadastro de estadia nao realizado. \n" << endl;
                return;
            }

            // Solicita dados da estadia
            cout << "Digite a quantidade de hospedes: ";
            cin >> quantHospedes;
            cout << "Digite o codigo da estadia: ";
            cin >> codEstadia;
            cout << "\n" << endl; // Apenas pula linha para formatação

            // Solicita a data de entrada e saída   
            cout << "Digite a data de entrada (DD MM AAAA): ";  
            cin >> diaEntrada >> mesEntrada >> anoEntrada;
            cout << "Digite a data de saida (DD MM AAAA): ";   
            cin >> diaSaida >> mesSaida >> anoSaida;
            // Calcula a diferença em dias entre as duas datas
            int diasEntrada = diaEntrada + mesEntrada * 30 + anoEntrada * 365;
            int diasSaida = diaSaida + mesSaida * 30 + anoSaida * 365;
            int diferenca = diasSaida - diasEntrada;
            // Verifica se a diferença é válida
            if (diferenca <= 0){
            cout << "Data de saida invalida. \n" << endl;  
            return;
            }
            cout << "\n" << endl; // Apenas pula linha para formatação

            // Procura um quarto disponível com capacidade suficiente
            for (int i = 0; i < numQuartos; i++){
                if (quartos[i].getQuantHospedes() >= quantHospedes && quartos[i].getStatus() == false){
                    setcodigoCliente(codCliente);
                    setnumQuarto(quartos[i].getNumQuarto());
                    setcodigoEstadia(codEstadia);
                    setdataEntrada(diaEntrada, mesEntrada, anoEntrada);
                    setdataSaida(diaSaida, mesSaida, anoSaida);

                    for (int j = 0; j < numClientes; j++){
                        // Copia o nome do cliente para a estadia
                        if (clientes[j].getCodigoCliente() == codCliente){
                            setnomeCliente(clientes[j].getNomeCliente());
                            break;
                        }
                    }
                    setnumDiarias(diferenca);

                    cout << "Estadia cadastrada com sucesso! \n" << endl;
                    cout << "Codigo da estadia: " << getCodigoEstadia() << endl;
                    cout << "\n" << endl; // Apenas pula linha para formatação
                    
                    quartos[i].setStatus(true);          // Marca o quarto como ocupado
                    quartos[i].setCodigoCliente(codCliente); // Associa o cliente ao quarto
                    return;
                }
            }

            // Caso não haja quartos disponíveis
            cout << "Nao ha quartos disponiveis para a quantidade de hospedes desejada. Cadastro de estadia nao realizado. \n" << endl;
        }

        // Função para adicionar uma nova estadia ao vetor dinâmico
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


// Função para dar baixa em uma estadia (check-out)
void baixaEstadia(Estadia *estadias, int &numEstadias, Quarto *quartos, int numQuartos){
    // Solicita o código da estadia que será baixada
    cout << "Digite o codigo da estadia para dar baixa: ";
    int codEstadia;
    cin >> codEstadia;

    // Percorre todas as estadias cadastradas
    for (int i = 0; i < numEstadias; i++){
        // Verifica se a estadia atual tem o código informado
        if (estadias[i].getCodigoEstadia() == codEstadia){
            cout << "Estadia encontrada! Baixa realizada com sucesso! \n" << endl;

            // Calcula o valor total da estadia (diárias * valor da diária)
            float valorTotal = estadias[i].getNumDiarias() * valorDiaria;
            cout << "Valor total da estadia: R$ " << valorTotal << endl;

            int numQuarto = estadias[i].getNumQuarto();
            for (int j = 0; j < numQuarto; j++){
                if (estadias[j].getNumQuarto() == numQuarto){
                    // Libera o quarto associado à estadia
                    quartos[j].setStatus(false);
                    quartos[j].setCodigoCliente(0); // Remove a associação do cliente
                    break;
                }
            }

            // Remove a estadia do vetor, deslocando os elementos seguintes
            for (int j = i; j < numEstadias - 1; j++){
                estadias[j] = estadias[j + 1];
            }
            --numEstadias; // Atualiza o número de estadias cadastradas      
            return; // Encerra a função após a baixa
        }
    }

    // Caso a estadia não seja encontrada
    cout << "Estadia nao encontrada. Nenhuma baixa realizada. \n" << endl;
}

void BackupdeDados(Cliente *clientes, int numClientes, Funcionario *funcionarios, int numFuncs, Quarto *quartos, int numQuartos, Estadia *estadias, int numEstadias) {
    
    // --- Backup de Clientes ---
    ofstream backupClientes("clientes.bin", ios::binary); //ofstream eh como se fosse uma caneta, ela qm escreve
    if (!backupClientes.is_open()) {
        cout << "Erro ao criar arquivo de backup de clientes. \n" << endl;
    } else {
        backupClientes.write((char*)&numClientes, sizeof(int));
        for (int i = 0; i < numClientes; i++) {
            backupClientes.write((char*)&clientes[i], sizeof(Cliente));
        }
        backupClientes.close();
    }

    // --- Backup de Funcionários ---
    ofstream backupFuncionarios("funcionarios.bin", ios::binary);
    if (!backupFuncionarios.is_open()) {
        cout << "Erro ao criar arquivo de backup de funcionarios." << endl;
    } else {
        backupFuncionarios.write((char*)&numFuncs, sizeof(int));
        for (int i = 0; i < numFuncs; i++) {
            backupFuncionarios.write((char*)&funcionarios[i], sizeof(Funcionario));
        }
        backupFuncionarios.close();
    }

    // --- Backup de Quartos ---
    ofstream backupQuartos("quartos.bin", ios::binary);
    if (!backupQuartos.is_open()) {
        cout << "Erro ao criar arquivo de backup de quartos. \n" << endl;
    } else {
        backupQuartos.write((char*)&numQuartos, sizeof(int));
        for (int i = 0; i < numQuartos; i++) {
            backupQuartos.write((char*)&quartos[i], sizeof(Quarto));
        }
        backupQuartos.close();
    }

    // --- Backup de Estadias ---
    ofstream backupEstadias("estadias.bin", ios::binary);
    if (!backupEstadias.is_open()) {
        cout << "Erro ao criar arquivo de backup de estadias. \n" << endl;
    } else {
        backupEstadias.write((char*)&numEstadias, sizeof(int));
        for (int i = 0; i < numEstadias; i++) {
            backupEstadias.write((char*)&estadias[i], sizeof(Estadia));
        }
        backupEstadias.close();
    }

    cout << "Backup de todos os dados realizado com sucesso! \n" << endl;
}

void RestaurarDados(Cliente *&clientes, int &numClientes, Funcionario *&funcionarios, int &numFuncs, Quarto *&quartos, int &numQuartos, Estadia *&estadias, int &numEstadias) {

    // --- Restaurar Clientes ---
    ifstream backupClientes("clientes.bin", ios::binary);
    if (!backupClientes.is_open()) {
        cout << "Erro ao abrir arquivo de clientes." << endl;
        numClientes = 0;
        clientes = nullptr;
    } else {
        backupClientes.read((char*)&numClientes, sizeof(int));
        clientes = new Cliente[numClientes];
        for (int i = 0; i < numClientes; i++) {
            backupClientes.read((char*)&clientes[i], sizeof(Cliente));
        }
        backupClientes.close();
    }

    // --- Restaurar Funcionários ---
    ifstream backupFuncionarios("funcionarios.bin", ios::binary);
    if (!backupFuncionarios.is_open()) {
        cout << "Erro ao abrir arquivo de funcionarios." << endl;
        numFuncs = 0;
        funcionarios = nullptr;
    } else {
        backupFuncionarios.read((char*)&numFuncs, sizeof(int));
        funcionarios = new Funcionario[numFuncs];
        for (int i = 0; i < numFuncs; i++) {
            backupFuncionarios.read((char*)&funcionarios[i], sizeof(Funcionario));
        }
        backupFuncionarios.close();
    }

    // --- Restaurar Quartos ---
    ifstream backupQuartos("quartos.bin", ios::binary);
    if (!backupQuartos.is_open()) {
        cout << "Erro ao abrir arquivo de quartos. \n" << endl;
        numQuartos = 0;
        quartos = nullptr;
    } else {
        backupQuartos.read((char*)&numQuartos, sizeof(int));
        quartos = new Quarto[numQuartos];
        for (int i = 0; i < numQuartos; i++) {
            backupQuartos.read((char*)&quartos[i], sizeof(Quarto));
        }
        backupQuartos.close();
    }

    // --- Restaurar Estadias ---
    ifstream backupEstadias("estadias.bin", ios::binary);
    if (!backupEstadias.is_open()) {
        cout << "Erro ao abrir arquivo de estadias. \n" << endl;
        numEstadias = 0;
        estadias = nullptr;
    } else {
        backupEstadias.read((char*)&numEstadias, sizeof(int));
        estadias = new Estadia[numEstadias];
        for (int i = 0; i < numEstadias; i++) {
            backupEstadias.read((char*)&estadias[i], sizeof(Estadia));
        }
        backupEstadias.close();
    }

    cout << "Restauracao de todos os dados concluida! \n" << endl;
}


//procedimento para mostrar as estadias cadastradas de um cliente especifico
// Função para mostrar estadias cadastradas
// Permite filtrar por código do cliente ou por nome do cliente
void mostraEstadias(Estadia *estadias, int numEstadias){
    int opcMostrar, codigoCliente;
    char nomeClienteBusca[99];

    // Menu de opções para o usuário
    cout << "Escolha uma das opcoes para mostrar as estadias:" << endl;
    cout << "[1] Mostrar estadias por codigo do cliente." << endl;
    cout << "[2] Mostrar estadias por nome do cliente." << endl;  
    cout << ">> "; 
    cin >> opcMostrar;
    cout << "\n" << endl; // Pula linha para melhor formatação

    switch (opcMostrar){
        case 1:{
            // Filtra estadias pelo código do cliente
            cout << "Digite o codigo do cliente: ";
            cin >> codigoCliente;

            for (int i = 0; i < numEstadias; i++){
                if (estadias[i].getCodigoCliente() == codigoCliente){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getdiaDtaEntrada() << "/" << estadias[i].getmesDtaEntrada() << "/" << estadias[i].getanoDtaEntrada() << endl;
                    cout << "Data de saida: " << estadias[i].getdiaDtaSaida() << "/" << estadias[i].getmesDtaSaida() << "/" << estadias[i].getanoDtaSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                    return; // Sai da função após encontrar
                }
            }
            cout << "Cliente nao possui estadias cadastradas. \n" << endl;
            break;
        }
        case 2:{
            // Filtra estadias pelo nome do cliente
            cout << "Digite o nome do cliente: ";
            scanf(" %[^\n]", nomeClienteBusca);

            for (int i = 0; i < numEstadias; i++){
                if (strcmp(estadias[i].getNomeCliente(), nomeClienteBusca) == 0){
                    cout << "Estadia encontrada!" << endl;
                    cout << "Codigo da estadia: " << estadias[i].getCodigoEstadia() << endl;
                    cout << "Data de entrada: " << estadias[i].getdiaDtaEntrada() << "/" << estadias[i].getmesDtaEntrada() << "/" << estadias[i].getanoDtaEntrada() << endl;
                    cout << "Data de saida: " << estadias[i].getdiaDtaSaida() << "/" << estadias[i].getmesDtaSaida() << "/" << estadias[i].getanoDtaSaida() << endl;
                    cout << "Numero de diarias: " << estadias[i].getNumDiarias() << endl;
                    cout << "Nome do cliente: " << estadias[i].getNomeCliente() << endl;
                    cout << "Codigo do cliente: " << estadias[i].getCodigoCliente() << endl;
                    cout << "Numero do quarto: " << estadias[i].getNumQuarto() << endl;
                    return; // Sai da função após encontrar
                }
            }
            cout << "Cliente nao possui estadias cadastradas. \n" << endl;
            break;
        }
        default:
            // Caso a opção digitada seja inválida
            cout << "Opcao invalida. Nenhum dado foi mostrado. \n" << endl;
    }
}

int main() {
    // Vetores dinâmicos para armazenar clientes, funcionários, quartos e estadias
    Cliente *clientes = NULL;
    Funcionario *funcionarios = NULL;
    Quarto *quartos = NULL;
    Estadia *estadias = NULL;

    // Contadores e capacidades iniciais dos vetores
    int numClientes = 0, capClientes = 0;
    int numFuncionarios = 0, capFuncionarios = 0;
    int numQuartos = 0, capQuartos = 0;
    int numEstadias = 0, capEstadias = 0;

    int opc; // variável para armazenar a opção escolhida no menu

    do {
        // Menu principal do sistema
        cout << "\nEscolha uma dentre as opcoes: " << endl;
        cout << "[1] Opcoes de clientes" << endl;
        cout << "[2] Opcoes de funcionarios" << endl;
        cout << "[3] Cadastrar quarto" << endl;
        cout << "[4] Cadastrar estadia" << endl;
        cout << "[5] Dar baixa em uma estadia" << endl;
        cout << "[6] Mostrar estadias." << endl;
        cout << "[7] Pesquisar cliente/funcionario" << endl;
        cout << "[8] Fazer backup " << endl;
        cout << "[9] Restaurar backup" << endl;
        cout << "[0] Sair." << endl;
        cout << ">> ";

        cin >> opc; // Lê a opção do usuário
        cout << "\n" << endl; // Pula linha para formatação

        switch (opc) {
            case 1: {
                // Submenu de clientes
                int opc2;
                cout << "[1] Cadastrar cliente." << endl;
                cout << "[2] Editar cliente." << endl;
                cout << "[3] Remover cliente." << endl;
                cout << ">> ";
                cin >> opc2;
                cout << "\n" << endl;

                // Validação da opção
                if (opc2 < 1 || opc2 > 3){
                    cout << "opcao invalida, retornando ao menu principal. \n" << endl;
                    break;
                }

                if (opc2 == 1){
                    // Cadastro de cliente
                    int codCliente;
                    long long int telCliente;
                    char nomeCliente[99], end[99];
                    cout << "Digite o codigo do cliente: ";
                    cin >> codCliente;
                    if (codCliente <= 0){
                        cout << "Codigo invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    cout << "Digite o nome do cliente: ";
                    scanf(" %[^\n]", nomeCliente);
                    fflush(stdin);
                    cout << "Digite o endereco do cliente: ";
                    scanf(" %[^\n]", end);    
                    fflush(stdin);     
                    cout << "Digite o telefone do cliente: ";
                    cin >> telCliente;
                    if (!validaTelefone(telCliente)){
                        cout << "Telefone invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    Cliente novoCliente;
                    novoCliente.cadastraCliente(clientes, numClientes, codCliente, nomeCliente, end, telCliente);
                    novoCliente.adicionaCliente(&clientes, numClientes, capClientes, novoCliente);
                    break;
                }
                else if (opc2 == 2){
                    // Editar cliente existente
                    int codClienteEditar;
                    cout << "Digite o codigo do cliente a ser editado: ";
                    cin >> codClienteEditar;
                    editaCliente(clientes, numClientes, codClienteEditar);
                    break;
                }
                else {
                    // Remover cliente
                    int codClienteRemover;
                    cout << "Digite o codigo do cliente a ser removido: ";
                    cin >> codClienteRemover;
                    deletaCliente(clientes, numClientes, codClienteRemover);
                    break;
                }
                break;
            }

            case 2: {
                // Submenu de funcionários
                int opcFunc;
                cout << "[1] Cadastrar funcionario." << endl;
                cout << "[2] Editar funcionario." << endl;
                cout << "[3] Remover funcionario." << endl;
                cout << ">> ";
                cin >> opcFunc;
                cout << "\n" << endl;

                if (opcFunc < 1 || opcFunc > 3){
                    cout << "opcao invalida, retornando ao menu principal. \n" << endl;
                    break;
                }

                if (opcFunc == 1){
                    // Cadastro de funcionário
                    int codFunc; 
                    long long int telFunc;
                    char nomeFunc[99], cargo[30];
                    float salario;
                    cout << "Digite o codigo do funcionario: ";
                    cin >> codFunc;
                    if (codFunc <= 0){
                        cout << "Codigo invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    cout << "Digite o nome do funcionario: ";
                    scanf(" %[^\n]", nomeFunc);
                    fflush(stdin);
                    cout << "Digite o cargo do funcionario: ";
                    scanf(" %[^\n]", cargo);
                    fflush(stdin);
                    cout << "Digite o telefone do funcionario: ";
                    cin >> telFunc;
                    if (!validaTelefone(telFunc)){
                        cout << "Telefone invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }
                    cout << "Digite o salario do funcionario: ";
                    cin >> salario;
                    if (salario <= 0) {
                        cout << "Salario invalido. Cadastro nao realizado. \n" << endl;
                        break;
                    }

                    Funcionario novoFunc;
                    novoFunc.cadastraFunc(funcionarios, numFuncionarios, codFunc, nomeFunc, cargo, telFunc, salario);
                    novoFunc.adicionaFuncionario(&funcionarios, numFuncionarios, capFuncionarios, novoFunc);
                    break;
                }
                else if (opcFunc == 2){                        
                    // Editar funcionário existente
                    int codFuncEditar;
                    cout << "Digite o codigo do funcionario a ser editado: ";
                    cin >> codFuncEditar;
                    editaFuncionario(funcionarios, numFuncionarios, codFuncEditar);
                    break;
                }
                else {
                    // Remover funcionário
                    int codFuncRemover;
                    cout << "Digite o codigo do funcionario a ser removido: ";
                    cin >> codFuncRemover;
                    deletaFuncionario(funcionarios, numFuncionarios, codFuncRemover);
                    break;
                }
                break;
            }

            case 3: {
                // Cadastro de quarto
                int numeroQuarto, quantHospedes;
                bool status = false; // quarto inicia como livre
                cout << "Digite o numero do quarto: ";
                cin >> numeroQuarto;
                if (numeroQuarto <= 0){
                    cout << "Numero de quarto invalido. Cadastro nao realizado. \n" << endl;
                    break;
                }
                cout << "Digite a capacidade de hospedes: ";
                cin >> quantHospedes;
                if (quantHospedes <= 0){
                    cout << "Capacidade invalida. Cadastro nao realizado. \n" << endl;
                    break;
                }

                Quarto novoQuarto;
                novoQuarto.cadastraQuarto(quartos, numQuartos, numeroQuarto, quantHospedes, status);
                novoQuarto.adicionaQuarto(&quartos, numQuartos, capQuartos, novoQuarto);
                break;
            }

            case 4: {
                // Cadastro de estadia
                Estadia novaEstadia;
                novaEstadia.cadastrarEstadia(estadias, numEstadias, quartos, numQuartos, clientes, numClientes);
                novaEstadia.adicionaEstadia(&estadias, numEstadias, capEstadias, novaEstadia);
                break;
            }

            case 5:
                // Dar baixa em uma estadia
                baixaEstadia(estadias, numEstadias, quartos, numQuartos);
                break;

            case 6:
                // Mostrar estadias
                mostraEstadias(estadias, numEstadias);
                break;

            case 7: {
                // Pesquisar cliente ou funcionário
                int opcPesquisar;
                cout << "[1] Pesquisar cliente." << endl;
                cout << "[2] Pesquisar funcionario." << endl;
                cout << ">> ";
                cin >> opcPesquisar;
                cout << "\n" << endl;

                if (opcPesquisar < 1 || opcPesquisar > 2){
                    cout << "opcao invalida, retornando ao menu principal." << endl;
                    break;
                }

                if (opcPesquisar == 1){
                    // Pesquisar cliente
                    procuraCliente(clientes, numClientes);
                    break;
                }
                else {
                    // Pesquisar funcionário
                    procuraFuncionario(funcionarios, numFuncionarios);
                    break;
                }
                break;
            }

            case 8:
                // Backup de dados do sistema
                BackupdeDados(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;

            case 9:
                //Restaura dados do sistema
                RestaurarDados(clientes, numClientes, funcionarios, numFuncionarios, quartos, numQuartos, estadias, numEstadias);
                break;

            default:
                // Qualquer opção inválida ou 0 sai do programa
                cout << "\nFechando programa....." << endl;
                break;
        }

    } while(opc >= 1 && opc <= 9); // Loop continua enquanto o usuário não digitar 0 ou uma opção inválida
}
