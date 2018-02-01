#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
//Trabalho
typedef struct Conta  //"Conta é apenas um nome, sem validade nem uma em si, so para saber que usuario pertence a classe, Conta.
{
    char nome[30];
    char senha[15];
    int creditos;
    int nivel;
    int cont;
    int code;
} Usuario; //Usuario é o tipo de dado criado, e usuario uma variavel do tipo "Usuario".


int cc=0; //contador global
Usuario usuario[5];  //vetor do tipo Usuario que possibilitara o usuario de criar no maximo 4 contas, pq o 0 estara sendo usando para outros propositos.
FILE *salvar;        //Ponteiro (*salvar) to tipo FILE, possibilitara armazenar o progresso em jogo em um arquivo de texto.
int logar=0;         /*Contador simples proposito impedir que tela Carregar seja mostrada novamente a cada entrada no menu "logar", so eh incrementado um vez (+1) em toda a execuçao do programa*/
int you;
char Player[25];
int nivel;

void gotoxy(int x, int y);
void Carregando ();
void MolduraBemVindo();
void Mensagem();
int Cursor();
void MolduraMenuIniciar();
void MolduraCriarConta();
void MolduraLogar();
void Bemvindo();
void Sobre();
void MenuIniciar();
void CriarConta();
void Logar();
void MolduraMenuPrincipal();
int Verificacao(int a);
void Editar(int opt);
void Deletar(int a);
void MenuPrincipal();
int Sword1(int opsword, int turn);
int Sword2(int opsword, int turn);
int Shield1(int typeatk1);
int Shield2(int typeatk2);
void Jogar();
void Jogador();
int Oponente(int def);
void MolduraOpcao();
void MolduraGameplay();
void YouWin();
void YouLose();
void Opcoes();
void Sair(); //omg this is gonna be the last :D

int main ()
{
    MenuIniciar();
    getch();
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}
void Mensagem()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,9); //Parte de cima
            putchar(201);
            for(int y=0; y<36; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,15); //Parte de baixo
                putchar(200);
                for(int y=0; y<36; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<5; b++)  //Tamanho lados
    {
        gotoxy(23,b+10); //Escolha de linha lados
        putchar(186);
        gotoxy(60,b+10);
        putchar(186);
    }
}
void Carregando ()
{
    if (salvar==NULL) goto here;
    salvar = fopen("Save.txt","r");
    while(fread(&usuario,sizeof(usuario),1,salvar))
    {
here:
        for (int loading=0; loading < 32; loading++)
        {
            putchar(220);
            Sleep(200);
        }
    }

}
void MolduraMenuIniciar()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(25,10); //Parte de cima
            putchar(201);
            for(int y=0; y<30; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(25,25); //Parte de baixo
                putchar(200);
                for(int y=0; y<30; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<14; b++)  //Tamanho lados
    {
        gotoxy(25,b+11); //Escolha de linha lados
        putchar(186);
        gotoxy(56,b+11);
        putchar(186);
    }
}
void MolduraBemVindo()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(25,8); //parte de cima
            putchar(201);
            for(int y=0; y<30; y++) //comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(25,15); //parte de baixo
                putchar(200);
                for(int y=0; y<30; y++)//comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<6; b++)  //tamanho lados
    {
        gotoxy(25,b+9); //escolha de linha lados
        putchar(186);
        gotoxy(56,b+9);
        putchar(186);
    }

}
void Sobre()
{
    if (logar==0)
        logar+=1;
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,6); //Parte de cima
            putchar(201);
            for(int y=0; y<34; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,23); //Parte de baixo
                putchar(200);
                for(int y=0; y<34; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<16; b++)  //Tamanho lados
    {
        gotoxy(23,b+7); //linha esquerda
        putchar(186);
        gotoxy(58,b+7);//linha direita
        putchar(186);
    }
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(20,3); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(20,26); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<22; b++)  //Tamanho lados
    {
        gotoxy(20,b+4); //Escolha de linha lados
        putchar(186);
        gotoxy(61,b+4);
        putchar(186);
        gotoxy(34,5);
        printf("EPIC DUEL 1.0");
        gotoxy(28,24);
        printf("T&M entertainment - 2017");
        gotoxy(26,25);
        printf("todos os direitos reservados");
        gotoxy(39,8);
        printf("SOBRE");
        gotoxy(29,10);
        printf("Projeto desenvolvido por");
        gotoxy(33,12);
        printf("Moises Kerschner");
        gotoxy(29,14);
        printf("de Sistemas da Informacao");
        gotoxy(40,16);
        printf("&");
        gotoxy(33,18);
        printf("Theylor Fiorentin");
        gotoxy(29,20);
        printf("de Ciencia da Computacao");
        gotoxy(29,22);
        printf("VOLTAR AO MENU PRINCIPAL");
    }
    getch();
    system("cls");
    MenuIniciar();
}
void MolduraCriarConta()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(25,10); //Parte de cima
            putchar(201);
            for(int y=0; y<30; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(25,25); //Parte de baixo
                putchar(200);
                for(int y=0; y<30; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<14; b++)  //Tamanho lados
    {
        gotoxy(25,b+11); //Escolha de linha lados
        putchar(186);
        gotoxy(56,b+11);
        putchar(186);
    }
    gotoxy(36,5);
    printf("EPIC DUEL");
    gotoxy(35,12);
    printf("CRIAR CONTA");
    gotoxy(28,15);
    printf("NOME:");
    gotoxy(28,17);
    printf("SENHA:");
    gotoxy(28,19);
    printf("REPITA A SENHA:");


}
void MolduraLogar()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,8); //Parte de cima
            putchar(201);
            for(int y=0; y<34; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,27); //Parte de baixo
                putchar(200);
                for(int y=0; y<34; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<18; b++)  //Tamanho lados
    {
        gotoxy(23,b+9); //linha esquerda
        putchar(186);
        gotoxy(58,b+9);//linha direita
        putchar(186);
    }
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(20,3); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(20,30); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<26; b++)  //Tamanho lados
    {
        gotoxy(20,b+4); //Escolha de linha lados
        putchar(186);
        gotoxy(61,b+4);
        putchar(186);


    }
}
void Bemvindo()
{
    MolduraBemVindo();
    gotoxy(26,11);
    printf ("  BEM VINDO AO EPIC DUEL 1.0 ");
    gotoxy(36,18);
    printf("Carregando");
    gotoxy(25,19);
    Carregando();
    system("cls");
}
void MenuIniciar()
{
    if (cc==0 && logar == 0 )   //se o cc é 0 e logar  0 entao vai aparecer a tela de loading.
        Bemvindo();
    salvar = fopen("Save.txt","r");
    while(fread(&usuario,sizeof(usuario),1,salvar)) {}
    fclose(salvar);
    cc =  usuario[0].cont;
voltar3:
    MolduraMenuIniciar();
    ///////
    gotoxy(36,5);
    printf("EPIC DUEL");
    int op1;
    gotoxy(35,9);
    printf("Menu Iniciar ");
    gotoxy(27,12);
    printf("1 Novo Jogo");
    gotoxy(27,14);
    printf("2 Logar");
    gotoxy(27,16);
    printf("3 Sobre");
    gotoxy(27,18);
    printf("4 Sair");
    gotoxy(35,24);
    printf("Opcao: ");
    scanf("%d", &op1);
    system("cls");
    ////////////////
    switch (op1)
    {
    case 1:
        fflush(stdin);
        system("cls");
        if (usuario[0].cont>3)
        {
            Mensagem();
            gotoxy(28,11);
            printf("VOCE EXEDEU O NUMERO MAXIMO");
            gotoxy(34,13);
            printf("DE CONTAS CRIADA!");
            gotoxy(23,18);
            printf("Aperte qualquer tecla para continuar...");
            getch();
            system("cls");
            fflush(stdin);
            goto voltar3;
        }
        CriarConta();
    case 2:
        fflush(stdin);
        system("cls");
        Logar();
        break;
    case 3:
        fflush(stdin);
        system("cls");
        Sobre();
    case 4:
        Sair();
    default:
        gotoxy(32,24);
        printf("Entrada Invalida!");
        fflush(stdin);
        getch ();
        system("cls");
        goto voltar3; //cuida das entrada inválidas.
    }

}
void MolduraMenuPrincipal()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,6); //Parte de cima
            putchar(201);
            for(int y=0; y<34; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,23); //Parte de baixo
                putchar(200);
                for(int y=0; y<34; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<16; b++)  //Tamanho lados
    {
        gotoxy(23,b+7); //linha esquerda
        putchar(186);
        gotoxy(58,b+7);//linha direita
        putchar(186);
    }
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(20,3); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(20,26); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<22; b++)  //Tamanho lados
    {
        gotoxy(20,b+4); //Escolha de linha lados
        putchar(186);
        gotoxy(61,b+4);
        putchar(186);
        gotoxy(34,5);
        printf("EPIC DUEL 1.0");
        gotoxy(28,24);
        printf("T&M entertainment - 2017");
        gotoxy(26,25);
        printf("todos os direitos reservados");
        gotoxy(34,8);
        printf("MENU PRINCIPAL");
        gotoxy(26,11);
        printf("User: ");
        gotoxy(49,11);
        printf("Nivel: ");
        gotoxy(37,13);
        printf("1-JOGAR");
        gotoxy(37,15);
        printf("2-OPCOES");
        gotoxy(34,17);
        printf("3-MENU INICIAR");
        gotoxy(35,22);
        printf(">>  ");

    }
}
void CriarConta()
{
    MolduraCriarConta();
    char check[15], inpt;
    cc+=1; //
    fflush(stdin);
voltar:
    MolduraCriarConta();
    gotoxy(34,15);
    fflush(stdin);
    gets(usuario[cc].nome);
    if (strlen(usuario[cc].nome)>= 10 || strlen(usuario[cc].nome) <= 3)
    {
        gotoxy(32,24);
        printf("MINIMO 3 CARATERES!");
        getch();
        system("cls");
        goto voltar;

    }
voltar2:
    MolduraCriarConta();
    gotoxy(34,15);
    printf("%s", usuario[cc].nome);

    gotoxy(35,17);
    fflush(stdin);
    gets(usuario[cc].senha);
    if (strlen(usuario[cc].senha)>=11|| strlen(usuario[cc].senha) < 4)
    {
        gotoxy(32,24);
        printf("MINIMO 3 CARATERES!");
        getch();
        system("cls");
        goto voltar2;

    }
repita:
    gotoxy(44,19);
    fflush(stdin);
    gets(check);
    if (strcmp(usuario[cc].senha, check)!=0)
    {
        system("cls");
        MolduraCriarConta();
        gotoxy(30,24);
        printf("SENHA NAO COMPATIVEL!");
        gotoxy(34,15);
        printf("%s", usuario[cc].nome);
        gotoxy(35,17);
        printf("%s", usuario[cc].senha);
        goto repita;
    }
////////////////////////////////////////////////
    fflush(stdin);
voltar1:
    system("cls");
    MolduraMenuIniciar();
    gotoxy(36,5);
    printf("EPIC DUEL");
    gotoxy(29,12);
    printf("CONTA CRIADA COM SUCESSO!");
    gotoxy(28,15);
    printf("Sua Conta: %s  \n", usuario[cc].nome);
    gotoxy(28,17);
    printf("Sua Senha: %s  \n", usuario[cc].senha);
    gotoxy(30,24);
    printf("DESEJA CONTINUAR S/N?");
    inpt = getch();
    inpt = toupper(inpt);
    if (inpt == 'S')
    {
        usuario[0].cont = cc;
        usuario[0].code = 666;
        usuario[0].code += usuario[0].cont;
        usuario[cc].nivel = 0;
        salvar = fopen("Save.txt", "w");
        fwrite(&usuario,sizeof(usuario),1,salvar);
        fclose(salvar);
        system("cls");
        MenuIniciar();
    }
    else
    {
        if (inpt == 'N')
        {
            system("cls");
            goto voltar;
        }
        else
            system("cls");
        goto voltar1;
    }

}
void Editar(int opt)
{
////carrega os dados da conta
    char checkit[15], var;
back:
    MolduraCriarConta();
    gotoxy(34,15);
    fflush(stdin);
    gets(usuario[opt].nome);
    if (strlen(usuario[opt].nome)>= 10 || strlen(usuario[opt].nome) <= 3)
    {
        gotoxy(32,24);
        printf("MINIMO 3 CARATERES!");
        getch();
        system("cls");
        goto back;

    }
voltar5:
    MolduraCriarConta();
    gotoxy(34,15);
    printf("%s", usuario[opt].nome);

    gotoxy(35,17);
    fflush(stdin);
    gets(usuario[opt].senha);
    if (strlen(usuario[opt].senha)>= 11 || strlen(usuario[opt].senha) < 3)
    {
        gotoxy(32,24);
        printf("MINIMO 3 CARATERES!");
        getch();
        system("cls");
        goto voltar5;

    }
re:
    fflush(stdin);
    gotoxy(44,19);
    gets(checkit);

    if (strcmp(usuario[opt].senha, checkit)!=0)
    {
        system("cls");
        MolduraCriarConta();
        gotoxy(30,24);
        printf("SENHA NAO COMPATIVEL!");
        gotoxy(34,15);
        printf("%s", usuario[opt].nome);
        gotoxy(35,17);
        printf("%s", usuario[opt].senha);
        goto re;
    }

    fflush(stdin);
back1:
    system("cls");
    MolduraMenuIniciar();
    gotoxy(36,5);
    printf("EPIC DUEL");
    gotoxy(29,12);
    printf("CONTA CRIADA COM SUCESSO!");
    gotoxy(28,15);
    printf("Sua Conta: %s  \n", usuario[opt].nome);
    gotoxy(28,17);
    printf("Sua Senha: %s  \n", usuario[opt].senha);
    gotoxy(30,24);
    printf("DESEJA CONTINUAR S/N?");
    var = getch();
    var = toupper(var);
    if (var == 'S')
    {
        salvar = fopen("Save.txt", "w");
        fwrite(&usuario,sizeof(usuario),1,salvar);
        fclose(salvar);
        system("cls");
        Logar();
    }
    else
    {
        if (var == 'N')
        {
            system("cls");
            goto back;
        }
        else
            system("cls");
        goto back1;
    }

}
void Deletar(int a)
{
    Mensagem();
    if (a==1 && usuario[0].cont > 0)
    {
        strcpy(usuario[1].nome,usuario[2].nome);
        strcpy(usuario[2].nome,usuario[3].nome);
        usuario[0].cont-=1;
        gotoxy(29,12);
        printf("Conta Removida Com Sucesso!");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
    }
    if (a==2 && usuario[0].cont > 0)
    {
        strcpy(usuario[2].nome,usuario[1].nome);
        strcpy(usuario[2].nome,usuario[3].nome);
        usuario[0].cont-=1;
        gotoxy(29,12);
        printf("Conta Removida Com Sucesso!");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
    }
    if (a==3 && usuario[0].cont > 0)
    {
        strcpy(usuario[3].nome,usuario[4].nome);
        usuario[0].cont-=1;
        gotoxy(29,12);
        printf("Conta Removida Com Sucesso!");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
    }
    if (a==4 && usuario[0].cont > 0)
    {
        strcpy(usuario[4].nome,"Voce ainda nao possui uma conta");
        usuario[0].cont-=1;
        gotoxy(29,12);
        printf("Conta Removida Com Sucesso!");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
    }
    salvar = fopen("Save.txt", "w");
    fwrite(&usuario,sizeof(usuario),1,salvar);
    fclose(salvar);
    if (usuario[0].cont == 0)
    {
        system("cls");
        MenuIniciar();
    }
    else
        Logar();
}
void Logar()
{

    int op, opx, z=1, k=2;
    if (logar==0)
        logar+=1;

    if (usuario[0].cont == 0)
    {
        Mensagem();
        gotoxy(26,12);
        printf("VOCE AINDA NAO POSSUI UMA CONTA!");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
        MenuIniciar();

    }
    MolduraLogar();
    gotoxy(33,11);
    printf("TROCAR DE USUARIO");
    gotoxy(33,15);
    printf("ESCOLHA SUA CONTA");
    salvar = fopen("Save.txt","r"); //carregar conta(s) criada (s).
    while(fread(&usuario,sizeof(usuario),1,salvar) || z<= usuario[0].cont)
    {
        gotoxy(30,k+17);
        printf("%d - Conta: %s \n", z, usuario[z].nome);
        z++;
        k+=2;
    }//fimwhile
    fflush(stdin);
    fclose(salvar);
    gotoxy(34,28);
    printf("Opcao: ");
    scanf("%d", &opx);/////escolha da conta
    if (opx >= z)
    {
        gotoxy(33,28);
        printf("Entrada invalida!");
        getch();
        system("cls");
        Logar();
    }
    system("cls");
comeback:
    MolduraLogar();
    gotoxy(27,11);
    printf("SELECIONE O QUE DESEJA FAZER");
    gotoxy(37,24);
    printf("%s", usuario[opx].nome);
    gotoxy(30,17);
    printf("1 ENTRAR");
    gotoxy(30,19);
    printf("2 REMOVER CONTA");
    gotoxy(34,28);
    printf("Opcao: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        system("cls");
        Verificacao(opx);
        break;
    case 2:
        system("cls");
        Deletar(opx);
        break;
    default:
        gotoxy(33,28);
        printf("Entrada Invalida");
        fflush(stdin);
        getch();
        system("cls");
        goto comeback;
    }

}
int Verificacao(int u)
{
    char nome[50], senha[50];
undo:
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(21,7); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(21,17); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<9; b++)  //Tamanho lados
    {
        gotoxy(21,b+8); //Escolha de linha lados
        putchar(186);
        gotoxy(62,b+8);
        putchar(186);
    }

    gotoxy(34,9);
    printf("TELA DE VERIFICACAO");
    gotoxy(26,11);
    printf("Login: ");
    gotoxy(26,13);
    printf("Senha: ");
    fflush(stdin);
    gotoxy(33,11);
    gets(nome);
    fflush(stdin);
    gotoxy(33,13);
    gets(senha);
    if (strcmp(nome,usuario[u].nome)==0 && strcmp(senha,usuario[u].senha)==0)
    {
        gotoxy(33,16);
        printf("ACESSO PERMITIDO!");
        getch();
        system("cls");
        fflush(stdin);
        you=u;
        MenuPrincipal();
        exit(0); //PARA O JOGO :D

    }
    else
    {
        if (strlen(nome)==0 && strlen(senha)==0)
        {
            gotoxy(30,16);
            printf("INFORME O LOGIN E SENHA!");
            getch();
            system("cls");
            goto undo;
        }
        else
        {
            gotoxy(35,16);
            printf("ACESSO NEGADO!");
            getch();
            system("cls");
            goto undo;
        }
    }
}
void MenuPrincipal()
{
    int op;
    strcpy(Player, usuario[you].nome);
    nivel=usuario[you].nivel;
    MolduraMenuPrincipal();
    gotoxy(32,11);
    printf("%s", usuario[you].nome);
    gotoxy(55,11);
    printf("%d", usuario[you].nivel);
    gotoxy(38,22);
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        system("cls");
        Jogar();
    case 2:
        system("cls");
        MolduraOpcao();
    case 3:
        system("cls");
        MenuIniciar();
    }

}

/////////////////////////////////
int rodada = 0;
int static Playerhp = 400, Himhp = 400;
void Jogar()
{
    MolduraGameplay();
    gotoxy(2,15);
    printf("%s", usuario[you].nome);

    while (Playerhp>=0 && Himhp>=0)
    {
        //printf("rodada %d\n", rodada);


        if ((rodada % 2) == 0)
        {
            rodada++;
            Jogador();
        }
        else
        {
            rodada++;
            Oponente(rodada);

        }
    }
    if ((rodada % 2) == 1)
    {
        Sleep(700);
        gotoxy(32,12);
        printf("VOCE VENCEU!");
        YouWin();
        usuario[you].nivel++;
        Playerhp = 400;
        Himhp = 400;
        rodada=0;
        salvar = fopen("Save.txt", "w");
        fwrite(&usuario,sizeof(usuario),1,salvar);
        fclose(salvar);
        system("cls");
        MenuPrincipal();
    }
    else
    {
        Sleep(700);
        gotoxy(32,12);;
        printf("VOCE PERDEU!");
        YouLose();
        Playerhp = 400;
        Himhp = 400;
        rodada=0;
        system("cls");
        MenuPrincipal();
    }



}

void Jogador()
{
    int a, b;
back:
    MolduraGameplay();
    gotoxy(4,18);
    printf("Escolha Sua Espada: ");
    gotoxy(4,21);
    printf("1 - Espada Joyeuse");
    gotoxy(4,23);
    printf("2 - Espada Goujian");
    srand(time(NULL));
    b = rand() % 10+1;
    gotoxy(24,18);
    scanf("%d",&a);
    fflush(stdin);
    system("cls");
    switch(a)
    {
    case 1:
        Sword1(a,b); //b==numero gerado para turnos//a numero gerado para indentificar espada escolhida
    case 2:
        Sword2(a,b);
    default:
        gotoxy(46,21);
        printf("Entrada Invalida!");
        goto back;
    }
}

int Sword1(int opsword, int turn)
{
    int static atk;
    int r=0, op, v=0;
    srand(time(NULL));
    if ((rodada % 2) == 1)
    {
        op=Oponente(op);
        //printf("op escolha boss escudo %d\n", op);
    }
    else
    {
        if ((rodada % 2)!= 1)
        {
back:
            fflush(stdin);
            MolduraGameplay();
            gotoxy(4,18);
            printf("Escolha a sua defesa: ");
            gotoxy(4,21);
            printf("1 - Escudo Ornamental");
            gotoxy(4,23);
            printf("2 - Escudo Da Conquista");
            gotoxy(26,18);
            scanf("%d", &op);
            if (op<=0 || op >2)
            {
                system("cls");
                gotoxy(46,21);
                printf("Entrada Invalida!");
                goto back;
            }
            system("cls");
        }
    }
    MolduraGameplay();

    for (int x=1; x<=turn; x++)
    {
        atk = rand() % 5 + 11;
        v+=atk;
        r=v;
        Sleep(100);
        if (op==1)
            r-=Shield1(opsword);
        if (op==2)
            r-=Shield2(opsword);
        //if critical
        gotoxy(36,10);
        printf("-%d\n", r);
        Sleep(200);
        system("cls");
        MolduraGameplay();

    }
    if ((rodada % 2) == 1)
    {
        system("cls");
        Himhp-=r;
        if (turn>=8)
        {
            gotoxy(30,10);
            printf("%d HITS CRITICAL !\n", turn);
            gotoxy(46,21);
            printf("Ge-Dois Perdeu -%d",r);
        }
        else
        {
            system("cls");
            gotoxy(34,10);
            printf("%d HITS\n", turn);
            gotoxy(46,21);
            printf("Ge-Dois Perdeu -%d",r);
        }
        Jogar();
    }
    else
    {
        system("cls");
        Playerhp-=r;
        if (turn>=8)
        {
            gotoxy(30,10);
            printf("%d HITS CRITICAL !\n", turn);
            gotoxy(46,21);
            printf("%s Perdeu -%d",Player,r);
        }
        else
        {
            system("cls");
            gotoxy(34,10);
            printf("%d HITS\n", turn);
            gotoxy(46,21);
            printf("%s Perdeu -%d",Player,r);
        }
        Jogar();
    }

    return(0);
}

int Oponente(int def)
{
    int ao, bo;
    MolduraGameplay();
    srand(time(NULL));
    if (rodada % 2 != 1)
    {
        //printf("boss turn");
        bo = rand() % 10+1;
        ao = rand() % 2 + 1;
        //printf("chefe escolha %d\n", ao);
        switch(ao)
        {
        case 1:
            Sword1(ao,bo);
        case 2:
            Sword2(ao,bo);
        }

        srand(time(NULL));
        def = rand() % 2 + 1;
        return (def);
    }
    return 1;
}

int Sword2(int opsword, int turn)
{
    int static atk;
    int r=0, op, v=0;
    srand(time(NULL));
    if ((rodada % 2) == 1)
    {
        op=Oponente(op);
    }
    else
    {
        if ((rodada % 2)!= 1)
        {
back:
            fflush(stdin);
            MolduraGameplay();
            gotoxy(4,18);
            printf("Escolha a sua defesa: ");
            gotoxy(4,21);
            printf("1 - Escudo Ornamental");
            gotoxy(4,23);
            printf("2 - Escudo Da Conquista");
            gotoxy(26,18);
            scanf("%d", &op);
            if (op<=0 || op >2)
            {
                system("cls");
                gotoxy(46,21);
                printf("Entrada Invalida!");
                goto back;
            }
            system("cls");
        }
        MolduraGameplay();
    }
    for (int x=1; x<=turn; x++)
    {
        atk = rand() % 5 + 11;
        v+=atk;
        r=v;
        Sleep(100);
        if (op==1)
            r-=Shield1(opsword); //opsword espada escolhida, op, defesa escolhida pelo rival
        if (op==2)
            r-=Shield2(opsword);
        gotoxy(36,10);
        printf("-%d\n", r);
        gotoxy(60,4);
        /*printf("HP %d\n", Himhp);
        gotoxy(2,15);
        printf("HP %d\n", Playerhp);*/
        Sleep(300);
        system("cls");
        MolduraGameplay();
    }
    if ((rodada % 2) == 1)
    {
        Himhp-=r;
        if (turn>=8)
        {
            system("cls");
            gotoxy(30,10);
            printf("%d HITS CRITICAL !\n", turn);
            printf("%d HITS\n", turn);
            gotoxy(46,21);
            printf("Ge-Dois Perdeu -%d",r);
        }
        else
        {
            system("cls");
            gotoxy(34,10);
            printf("%d HITS\n", turn);
            gotoxy(46,21);
            printf("Ge-Dois Perdeu -%d",r);
        }
        Jogar();
    }
    else
    {
        system("cls");
        Playerhp-=r;
        if (turn>=8)
        {
            gotoxy(30,10);
            printf("%d HITS CRITICAL !\n", turn);
            gotoxy(46,21);
            printf("%s -%d",Player,r);
        }
        else
        {
            system("cls");
            gotoxy(34,10);
            printf("%d HITS\n", turn);
            gotoxy(46,21);
            printf("%s -%d",Player,r);
        }
        Jogar();
    }
    return(0);
}

int Shield1(int typeatk1)
{
    int def = 5;
    if (typeatk1==1)
    {
        def=10;
    }

    return(def);
}

int Shield2(int typeatk2)
{
    int def = 5;
    if (typeatk2==2)
    {
        def=10;
    }
    return(def);
}
void MolduraOpcao()
{
    fflush(stdin);
    int op;
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,6); //Parte de cima
            putchar(201);
            for(int y=0; y<34; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,23); //Parte de baixo
                putchar(200);
                for(int y=0; y<34; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<16; b++)  //Tamanho lados
    {
        gotoxy(23,b+7); //linha esquerda
        putchar(186);
        gotoxy(58,b+7);//linha direita
        putchar(186);
    }
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(20,3); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(20,26); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<22; b++)  //Tamanho lados
    {
        gotoxy(20,b+4); //Escolha de linha lados
        putchar(186);
        gotoxy(61,b+4);
        putchar(186);
        gotoxy(34,5);
        printf("EPIC DUEL 1.0");
        gotoxy(38,9);
        printf("OPCOES");
        gotoxy(30,12);
        printf("1-DESATIVAR SOM");
        gotoxy(30,14);
        printf("2-TROCAR DE USUARIO");
        gotoxy(30,16);
        printf("3-EDITAR CONTA");
        gotoxy(30,18);
        printf("4-VOLTAR");
        gotoxy(30,22);
        printf("Escolha: ");
        gotoxy(28,24);
        printf("T&M entertainment - 2017");
        gotoxy(26,25);
        printf("todos os direitos reservados");
    }
    gotoxy(39,22);
    scanf("%d", &op);
    switch(op)
    {

    case 1:
        system("cls");
        Mensagem();
        gotoxy(29,12);
        printf("O JOGO NEM POSSUI MUSICA :P");
        gotoxy(23,18);
        printf("Aperte qualquer tecla para continuar...");
        getch();
        system("cls");
        MolduraOpcao();
        break;

    case 2:
        system("cls");
        Logar();
        break;

    case 3:
        system("cls");
        Editar(you);
        break;
    case 4:
        system("cls");
        MenuPrincipal();
        break;

    default:
        gotoxy(39,22);
        printf ("Entrada Invalida!");
        getch();
        system("cls");
        MolduraOpcao();
    }


}
void MolduraGameplay()
{
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(2,17); //parte de cima
            putchar(201);
            for(int y=0; y<35; y++) //comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(2,25); //parte de baixo
                putchar(200);
                for(int y=0; y<35; y++)//comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<7; b++)  //tamanho lados
    {
        gotoxy(2,b+18); //escolha de linha lados
        putchar(186);
        gotoxy(38,b+18);
        putchar(186);
    }
//////////////////////////////////////////////////////////////////
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(40,17); //parte de cima
            putchar(201);
            for(int y=0; y<27; y++) //comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(40,25); //parte de baixo
                putchar(200);
                for(int y=0; y<27; y++)//comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<7; b++)  //tamanho lados
    {
        gotoxy(40,b+18); //escolha de linha lados
        putchar(186);
        gotoxy(68,b+18);
        putchar(186);
    }
//////////////////////////////////////////

    for(int y=0; y<20; y++) //comprimento de cima
    {
        gotoxy(y+2,16);
        putchar(196);
    }
    for(int y=0; y<20; y++) //comprimento de cima
    {
        gotoxy(y+50,3);
        putchar(196);
    }
    gotoxy(22,16);
    putchar(217);
    gotoxy(22,15);
    putchar(179);

    gotoxy(50,3);
    putchar(218);
    gotoxy(50,4);
    putchar(179);

    gotoxy(2,3);
    printf("EPIC DUEL 1.0");
    gotoxy(52,4);
    printf("Ge-Dois");
    gotoxy(63,4);
    printf("HP %d\n", Himhp);
    gotoxy(15,15);
    printf("HP %d\n", Playerhp);
    gotoxy(2,15);
    printf("%s", Player);
    gotoxy(35,2);
    printf("Nvl:%d", nivel);


}
void YouWin()
{

    int x = 0;

    while (x != 13)
    {
        Sleep(300);
        gotoxy(32,12);
        printf("VOCE VENCEU!");
        Sleep(500);
        system("cls");
        if(kbhit())    //A função kbhit retorna 0 se o usuário não está precionando nenhuma tecla. Caso contrário, retorna um valor diferente de 0.
        {
            x = getch();
        }
    }

}
void YouLose()
{
    int x = 0;

    while (x != 13)
    {
        Sleep(300);
        gotoxy(32,12);;
        printf("VOCE PERDEU!");
        Sleep(500);
        system("cls");
        if(kbhit())    //A função kbhit retorna 0 se o usuário não está precionando nenhuma tecla. Caso contrário, retorna um valor diferente de 0.
        {
            x = getch();
        }
    }


}
void Sair()
{
    int sair;
    fflush(stdin);
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(23,6); //Parte de cima
            putchar(201);
            for(int y=0; y<34; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(23,23); //Parte de baixo
                putchar(200);
                for(int y=0; y<34; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<16; b++)  //Tamanho lados
    {
        gotoxy(23,b+7); //linha esquerda
        putchar(186);
        gotoxy(58,b+7);//linha direita
        putchar(186);
    }
    for(int x=0; x<10; x++)
    {
        if(x==0)
        {
            gotoxy(20,3); //Parte de cima
            putchar(201);
            for(int y=0; y<40; y++) //Comprimento de cima
            {
                putchar(205);
            }
            putchar(187);
        }
        else
        {
            if(x==9)
            {
                gotoxy(20,26); //Parte de baixo
                putchar(200);
                for(int y=0; y<40; y++)//Comprimento de baixo
                {
                    putchar(205);
                }
                putchar(188);
            }


        }
    }
    for(int b=0; b<22; b++)  //Tamanho lados
    {
        gotoxy(20,b+4); //Escolha de linha lados
        putchar(186);
        gotoxy(61,b+4);
        putchar(186);
        gotoxy(34,5);
        printf("EPIC DUEL 1.0");
        gotoxy(28,24);
        printf("T&M entertainment - 2017");
        gotoxy(26,25);
        printf("todos os direitos reservados");
        gotoxy(39,10);
        printf("SAIR");
        gotoxy(28,14);
        printf("VOCE REALMENTE DESEJA SAIR?");
        gotoxy(28,17);
        printf("1-SIM                2-NAO");

    }
    gotoxy(31,22);
    printf("Escolha: ");
    scanf("%d", &sair);
    switch(sair)
    {
    case 1:
        system("cls");
        Mensagem();
        gotoxy(35,12);
        printf("ATE A PROXIMA!");
        getch();
        system("cls");
        exit(0);
        break;
    case 2:
        system("cls");
        MenuIniciar();

    default:
        printf("Entrada Invalida!");
        system("cls");
        Sair();
    }
}








