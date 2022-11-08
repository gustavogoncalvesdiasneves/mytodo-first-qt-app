<!--
    TITLE:      README
    AUTOR:      MARCUS FARIA
    DATA_INIT:  05.11.2022

    PROJECT:    MY TODO - FIRST APP WITH QT
    
    CONNECT ME:
        Linkedin: https://www.linkedin.com/in/marcus-v-faria-4a2117213/
        github (curr-account): https://github.com/mfaria-tech
        github (old-account): https://github.com/Marcus-Faria

    THANK-YOU:
        Thank you so much to Professor Marcos Oliveira for the Modern Qt and C++ course
 -->


<h1 align="center" alt="My Todo - First Qt app"><strong>mytodo-first-qt-app</strong></h1>

<br/>

<p align="center" alt="objetivo do projeto">Meu primeiro aplicativo c++ versionado desenvolvido com o framework Qt. Projeto com o objetivo de fixar conteúdo para a ferramenta Qt e linguagem C++.</p>

<br/>
<img src="img/mytodo_demo.gif" />

<br/><hr/>

<h2>Índice</h2>

- **[Descrição](#descrição)**<br/>
- **[Características](#características)**<br/>
- **[Instalação](#instalação)**<br/>
- **[Compilar o Código-Fonte](#compilar-o-código-fonte)**<br/>


<hr/>
<br/><br/>


## **Descrição**
[mytodo-first-qt-app][link-mytodo-first-qt-app] é um aplicativo de código aberto. Ele irá ajudar na tomada de descisões e definição de prioridades. A aplicação armazena localmente as **tasks** criadas pelo usuário, gravando a hora e data do **registro** de sua última alteração.

<br/><br/>


## **Características**
A aplicação fornece os seguintes recursos:
- Operações CRUD
- Armazenamento de dados em base local
- Biblioteca SQLite
- Código-fonte C++ e Qmake
- Binário disponível para download
- Instalador Windows

<br/><br/>


## **Instalação**
Além de disponibilizado o [código fonte][link-codigo-fonte], tambem é possível baixar a aplicação através do instalador, ou baixar a pasta compactada contendo os binários, ambos disponíveis [neste repositório][link-mytodo-executavel].

Para ambos os métodos de "instalação" da aplicação está sendo disponibilizado um arquivo de validação de integridade dos binários, [clique aqui para acessar o arquivo de checksum][link-checksum].

<br/><br/>


## **Compilar o Código-Fonte**

Para compilar o projeto C++ e as bibliotecas pertencente ao QT, é preciso instalar o ambiente QT Creator no sistema operacional. Para fins de curiosidade, [clique aqui para acessar a documentação oficial da plataforma.][link-doc-qt]

<br/>


### **Compilar o projeto**

Tendo o ambiente configurado, é possível compilar o projeto de duas formas:
 1. Abrindo o projeto direto no ambiente, e executando o código-fonte dentro do ambiente (_recomendado_);
 2. Executando o compilador através de comandos no terminal.

<br/>

#### **Compilando o projeto no terminal**

1. Acesse o diretório do projeto no terminal, ou prompt de comando;
    ~~~Bash
    cd mytodo-first-qt-app/src
    ~~~

2. Execute os seguintes comandos de compilação do projeto (é preciso estar atualizado na versão C++ 17):

    ~~~Bash
    # Gerar o arquivo contendo as diretivas para o Makefile
    #   arquivos gerado: 
    #       .qmake.stash
    #       Makefile
    qmake 
    

    # Criar o executável atraves do Makefile
    #
    # No sistema Windows, caso esteja utilizando o MinGW 32,
    # utilize o comando:
    #       mingw32-make
    make
    ~~~
    No final da execução do comando `make`, serão criados dois diretórios no caminho atual:

     - `debug/`
     - `release/`
    
    <br/>

    A depender de como foi configurado o ambiente, o executável poderá ser encontrado em um destes diretórios.


<br/><br/>


<!-- 
    LOCAL VARIABLES
 -->

[link-mytodo-first-qt-app]: https://github.com/mfaria-tech/mytodo-first-qt-app
[link-mytodo-executavel]: https://github.com/mfaria-tech/mytodo-first-qt-app/tree/main/v1.0.0
[link-codigo-fonte]: https://github.com/mfaria-tech/mytodo-first-qt-app/tree/main/src
[link-checksum]: https://github.com/mfaria-tech/mytodo-first-qt-app/blob/main/v1.0.0/checksum.sha256sum
[link-doc-qt]: https://doc.qt.io/qt-6/get-and-install-qt.html
