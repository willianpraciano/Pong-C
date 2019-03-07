
//===================================================================
//Trabalho Inspirado no codigo do site (algumas coisas foram tiras desse site também):
//---> http://www.unidev.com.br/index.php?/topic/42577-linguagem-c-consegue-fazer-2-coisas-ao-mesmo-tempo/
//===================================================================

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <windows.h> // necessario para rodar a função gotoxy
#include <time.h>


//FUNÇÃO GOTOXY
// Tirado do site: ---> http://forum.imasters.com.br/topic/413810-resolvidogotoxy-fail/
void gotoxy(int x,int y)
{
    COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

//PAREDES DO JOGO
//baseado no codigo apresentado no video --> https://www.youtube.com/watch?v=jToAIdwkleM
void paredes()
{
    int i,j;
	char cen [21][60];

     for(i=0;i<21;i++)
     {
        if (i==0 || i==20)
        {
   		   for (j=0; j<60;j++)
   		    {
   		      cen[i][j]=178;
              printf ("%c", cen[ i][ j]); //imprime parede cima e baixo
             }
	         printf("\n"); //para pular a linha e inicar as barras laterais
	     }
	     else
	     {
           if (i>0||i<20)
		   {
		 	 for (j=0; j<60;j++)
   			  {
   		        if (j==0 || j==59)
			     {
                   cen[i][j]=178;
                   printf ("%c", cen[ i][ j]); //imprime parede laterais
	             }else
				     {
	                  printf(" ");
			         }
		 	   }
              printf("\n");
             }
            }
    }
}


//MENU DO JOGO
menu()
{

	//letra p
	paredes();
	gotoxy(3,3);
	printf("###########");
	gotoxy(3,4);
	printf("###########");
	gotoxy(3,5);
	printf("###     ###");
	gotoxy(3,6);
	printf("###     ###");
	gotoxy(3,7);
	printf("###########");
	gotoxy(3,8);
	printf("###########");
	gotoxy(3,9);
	printf("###");
	gotoxy(3,10);
	printf("###");
	gotoxy(3,11);
	printf("###");

	//letra o
	gotoxy(16,3);
	printf("###########");
	gotoxy(16,4);
	printf("###########");
	gotoxy(16,5);
	printf("###     ###");
	gotoxy(16,6);
	printf("###     ###");
	gotoxy(16,7);
	printf("###     ###");
	gotoxy(16,8);
	printf("###     ###");
	gotoxy(16,9);
	printf("###     ###");
	gotoxy(16,10);
	printf("###########");
	gotoxy(16,11);
	printf("###########");

	//letra n
	gotoxy(29,3);
	printf("###       ###");
	gotoxy(29,4);
	printf("###       ###");
	gotoxy(29,5);
	printf("###       ###");
	gotoxy(29,6);
	printf("###       ###");
	gotoxy(29,7);
	printf("###       ###");
	gotoxy(29,8);
	printf("###       ###");
	gotoxy(29,9);
	printf("###       ###");
	gotoxy(29,10);
	printf("###       ###");
	gotoxy(29,11);
	printf("###       ###");
	gotoxy(30,3);
	printf("###");
	gotoxy(31,4);
	printf("###");
	gotoxy(32,5);
	printf("###");
	gotoxy(33,6);
	printf("###");
	gotoxy(34,7);
	printf("###");
	gotoxy(35,8);
	printf("###");
	gotoxy(36,9);
	printf("###");
	gotoxy(37,10);
	printf("###");
	gotoxy(38,11);
	printf("###");

	//letra g.
	gotoxy(44,3);
	printf("###########");
	gotoxy(44,4);
	printf("###########");
	gotoxy(44,5);
	printf("###        ");
	gotoxy(44,6);
	printf("###   #####");
	gotoxy(44,7);
	printf("###   #####");
	gotoxy(44,8);
	printf("###     ###");
	gotoxy(44,9);
	printf("###     ###");
	gotoxy(44,10);
	printf("###########");
	gotoxy(44,11);
	printf("###########");

	gotoxy(3,13);
	printf("01 : Pressione para iniciar o jogo!");
	gotoxy(3,15);
	printf("02 : Pressione para jogar contra a m%cquina ( se puder!)",160);
	gotoxy(3,17);
	printf("03 : Pressione para sair do jogo!");



	switch(getch())
	{

		//"49"=1 na tabela ascii
		case 49:
			{

			 system("cls");
			paredes();
			 gotoxy(10,4);
			 printf("ATEN%c%cO:  MATENHA CAPS LOCK DESATIVADA!!!",128,199);
			 gotoxy(2,6);
			 printf("JOGADOR 1: Use as teclas 'w' e 's' ");
			 gotoxy(2,8);
			 printf("JOGADOR 2: Use as direcionais do teclado 'cima' e 'baixo'");
			 gotoxy(2,10);
			 sleep(5);
			 system("cls");
			 multiplayer();
			}
			//"50"=2 na tabela ascii
			case 50:
			{

			system("cls"); //limpa a tela
			paredes();
			 gotoxy(10,4);
			 printf("ATEN%c%cO:  MATENHA CAPS LOCK DESATIVADA!!!",128,199);
			 gotoxy(2,6);
			 printf("JOGADOR 1: Use as teclas 'w' e 's' ");
			 gotoxy(2,8);
			 printf("Ven%ca a m%cquina rebatendo 4 bolas!!!",135,160);
			 gotoxy(2,9);
			 printf("Se a bola passar duas vezes por voc%c%,voc%c perde!!!",136,136);
			 gotoxy(2,10);
			 sleep(5);
			 system("cls");
			 contramaquina();
		}
		//"51"=3 na tabela ascii
		case 51:
			{
				system("cls"); //limpa a tela
				exit(1); // se apertar 3 sai do jogo
			}
		default: {
			system("cls");
			menu(); //se apertar qualquer outra tecla volta para a propria função "menu()"
		}

	}

}


//TELA QUE APARECE QUANDO O JOGADOR 1 GANHA
vence1()
{
	system("cls");//limpa a tela
	paredes(); // imprime as paredes do jogo
	gotoxy(15,7);
	printf("JOGADOR 1 VENCEU !!!");
	gotoxy(15,9);
	printf("pressione 01 para voltar ao menu:");
	gotoxy(15,10);
	printf("pressione 02 para sair:");
	gotoxy(15,11);
	switch(getch())
		{
			 //"49"=1 na tabela ascii
			 case 49:{
				system("cls");
				menu(); // se apertar 1 o jogo volta para a função "menu"
				break;
			         }
			//"50"=2 na tabela ascii
			case 50:{
				system("cls");
				exit(1); // se apertar 2 sai do jogo
				break;
				    }
			default:{
				vence1(); //se apertar qualquer outra tecla volta para a propria função "vence1()"
				break;
				    }
		}
}


//TELA QUE APARECE QUANDO O JOGADOR 2 GANHA
vence2()
{
	system("cls");//Limpa a tela
	paredes(); //imprme as paredes do jogo
	gotoxy(15,7);
	printf("JOGADOR 2 VENCEU !!!");
	gotoxy(15,9);
	printf("pressione 01 para voltar ao menu: ");
	gotoxy(15,10);
	printf("pressione 02 para sair: ");
	gotoxy(15,11);
	switch(getch())
	  {
		//"49"=1 na tabela ascii
		case 49:{
			system("cls");
			menu(); // se apertar 1 o jogo volta para a função "menu"
			break;
				}
		//"50"=2 na tabela ascii
		case 50:{
			system("cls");
			exit(1);// se apertar 2 sai do jogo
			break;
				}
		default:{
			vence2();//se apertar qualquer outra tecla volta para a propria função "vence2()"
			break;
				}
	 }
}


//TELA QUE APARECE QUANDO O COMPUTADOR GANHA
vencecomp()
{
	system("cls"); //Limpa a tela
	paredes(); //imprme as paredes do jogo
	gotoxy(15,7);
	printf("O COMPUTADOR VENCEU !!!");
	gotoxy(15,9);
	printf("pressione 01 para voltar ao menu: ");
	gotoxy(15,10);
	printf("pressione 02 para sair: ");
	gotoxy(15,11);
	switch(getch())
		{
			//"49"=1 na tabela ascii
			case 49:{
				system("cls");
				menu(); // se apertar 1 o jogo volta para a função "menu"
				break;
				    }
			//"50"=2 na tabela ascii
			case 50:{
				system("cls");
				exit(1);// se apertar 2 sai do jogo
				break;
			        }
			default:{
					vencecomp(); //se apertar qualquer outra tecla volta para a propria função "vencecomp()"
					break;
				    }
		}

}


//PAYER1 VS PLAYER2
multiplayer()
{
	 int x=1,y=1,dx=1,dy=1,i; //variaveis bola

	 int a=58, b=8;//posição barra direita

	 int m=1,n=8; //posição barra esquerda

	 int pontos1=0,pontos2=0; //variaveis da pontuação


	 paredes();
 while(1)
  {
	while( !_kbhit() )
        {

		gotoxy(10,1);
		printf("Jogador 1: %d ",pontos1);
		gotoxy(35,1);
		printf("Jogador 2: %d ", pontos2);

		//IMPRIME BARRA 1
		for(i=0;i<5;i++)
        {
           gotoxy(a,b+i);
		   printf("%c",219);
        }

        //IMPRIME BARRA 2
        for(i=0;i<5;i++)
        {
           gotoxy(m,n+i);
		   printf("%c",219);
        }


        //MOVIMENTO DA BOLA (quase inteiramente tirado codigo do site(foi modificado) ---> https://www.vivaolinux.com.br/topico/C-C++/Erro-pingpong-em-C)
		gotoxy(x,y);
		putchar('o');
		Sleep(50);
		gotoxy(x,y);
		putchar(' ');
		x=x+dx;
		y=y+dy;
		if( x==1 || x==58)
		{
			dx = -dx;
		}
		if( y==1 || y==19)
		{
			dy = -dy;
		}

		//IMPRIME A BARRA QUE MARCA O CENTRO DA ARENA.
		for(i=0;i<14;i++)
        {
        	gotoxy(29,3+i);
        	printf("%c",179);
	    }

		//PONTOS JOGADOR 1
		if (x==58 && (y>b+4) )
		    {
			  //se a bola ("x" da bola) chegar na coluna 58 e ("y" da bola) estiver em baixo do desenho da barra o jogador 1 ganha 1 ponto
			  pontos1++;
		    }
		if (x==58 && (y<b) )
			   {
			     //se a bola ("x" da bola) chegar na coluna 58 e ("y" da bola) estiver em cima do desenho da barra o jogador 1 ganha 1 ponto
				 pontos1++;
		       }

		//PONTOS JOGADOR 2
		if (x==1 && (y>n+4) )
		    {
			  //se a bola ("x" da bola) chegar na coluna 1 e ("y" da bola) estiver em baixo do desenho da barra o jogador 2 ganha 1 ponto
			  pontos2++;
		    }
		if (x==1 && (y<n) )
			   {
			     //se a bola ("x" da bola) chegar na coluna 1 e ("y" da bola) estiver em cima do desenho da barra o jogador 2 ganha 1 ponto
				 pontos2++;
		       }

		//LIMITE DE PONTUAÇÃO
		if (pontos1==2){
            //Se o jogador 1 atingir  pontos ele ganha
			vence1();
		}
		if(pontos2==2)
		{
           //Se o jogador 2 atingir 2 pontos ele ganha
		   vence2();
		}

	}

		//QUANDO APERTA UMA TECLA SAI DO "while(!_kbhit)" E ENTRA AQUI
		//MOVIMENTO DAS BARRAS
		//inspirado do site: http://www.unidev.com.br/index.php?/topic/42577-linguagem-c-consegue-fazer-2-coisas-ao-mesmo-tempo/
		if(_kbhit!=0)
        {
           switch(getch()) {
                           //MOVIMENTO DA BARRA DA DIREITA, 72="CIMA" E 80="BAIXO"
						   case 72: {
                                if(b <= 1) // se a barra direita chegar nolimite da dela=1 ela parra
                                {
                                  break;
                                }
                                else
                                {
                                  gotoxy(a+1,b+4); //a+1 vai para uma posição à frente da barra, b+4 vai pra 4 posições em baixo do b e apaga o rastro
                                  printf("%c ",8);//8 na tabela ascii é equivalente ao BackSpace, apaga e da um espaço
                                  b--; //b perde posição e sobe
                                  break;
                                 }
                           case 80: {
                                if(b >= 15) //quando o b=15 a barra de comprimento 5 alcança o limite da tela=20
                                {
                                  break;
                                }
                                else
                                {
                                  gotoxy(a+1,b); //vai para uma posição a frente da barra
                                  printf("%c ",8);//8 na tabela ascii é equivalente ao BackSpace, apaga a posição anterior (a barra) e da um espaço
                                  b++;//b ganha posição e desce
                                  break;
                                }
                           }



                           //MOVIMENTO DA BARRA DA ESQUERDA,119="w" (VAI PARA CIMA) E 115="s" (VAI PARA BAIXO)
                           case 119: {
                                if(n <= 1)
                                {
                                  break; //A barra para se chegar na linha 1
                                }
                                else
                                {
                                  gotoxy(m+1,n+4); //b+4 vai pra 4 posições em baixo do b para apagar o rastro
                                  printf("%c ",8); //8 na tabela ascii é equivalente ao BackSpace, apaga a posição anterior(a barra) e da um espaço
                                  n--; //n perde posições e sobe
                                  break;
                                 }
                             }
                           case 115: {
                                if(n >= 15) //quando o b=15 a barra de comprimento 5 alcança o limite da tela=20 e para
                                {
                                  break; //A barra bara
                                }
                                else
                                {
                                  gotoxy(m+1,n); //vai para uma posição a frente da barra
                                  printf("%c ",8); //8 na tabela ascii é equivalente ao BackSpace, apaga a posição anterior (a barra)e da um espaço
                                  n++; //n ganha posições e desce
                                  break;
                                }
                              }


                           case 27: //27="Esc"
						   {
						    system("cls");
						     exit(1); // se apertar "Esc" o jogo para
						   }

                      }
                }
            }

 }
}


//CONTRA O COMPUTADOR
contramaquina()
{
	 int x=1,y=1,dx=1,dy=1,i; //variaveis bola

	 int a=58, b=1, db=1 ;//posição barra direita

	 int m=1,n=8; //posição barra esquerda

	 int pontos1=0,pontos2=0; // variaveis dos pontos


	 paredes();
 while(1)
  {

	while( !_kbhit() )
        {
        //corrigindo bug da barra
        gotoxy(58,20);
	    printf("%c",178);

	    //imprime a pontuação
		gotoxy(10,1);
		printf("Bolas rebatidas: %d ",pontos1);
		gotoxy(35,1);
		printf("Computador: %d ", pontos2);

		//IMPRIME BARRA 2(COMPUTADOR)
		for(i=0;i<5;i++)
        {

		   if(y<=16)
		   {
		    gotoxy(a,y+i);
		   printf("%c",219);
		   }
        }

        //IMPRIME BARRA 1
        for(i=0;i<5;i++)
        {
           gotoxy(m,n+i);
		   printf("%c",219);
        }


        //MOVIMENTO DA BOLA (quase inteiramente tirado codigo do site (foi modificado) ---> https://www.vivaolinux.com.br/topico/C-C++/Erro-pingpong-em-C)
		gotoxy(x,y);
		putchar('o');
		Sleep(40); //velocidade da bola e da barra

		//APAGA O RASTRO DA BARRA DIREITA (COMPUTADOR)
		if(y<16)
		{
		gotoxy(a,y);
	    putchar(' ');
	    gotoxy(a,y+4);
	    putchar(' ');
	    }


	    //APAGA O RASTRO DA BOLA
		gotoxy(x,y);
		putchar(' ');
		//MOVIMENTO DA BOLA
		x=x+dx;
		y=y+dy; //movimenta a barra 2 também



		//LIMITA O MOVIMENTO DA BOLA
		if( x==1 || x==58)
		{
			dx = -dx;
		}
		if( y==1 || y==19)
		{
			dy = -dy;
		}

         //LIMITA O MOVIMENTO DA BARRA DIREITA (COMPUTADOR)
		if( b==1 || b==15)
		{
			db = -db;
		}

		//IMPRIME A BARRA QUE MARCA O CENTRO DA ARENA.
		for(i=0;i<14;i++)
        {
        	gotoxy(29,3+i);
        	printf("%c",179);
	    }



		//PONTOS JOGADOR 1

		//====>DIFERENÇAS DA FUNÇÃO MULTIPLAYER E DA FUNÇÃO CONTRAMAQUINA<=====
		//É colocado um "if" dentro do outro para contar quantas vezes jogador1 REBATE a bola
		//As varivais são trocada "y" por "b"  e "58" por "1"
		// invete os sinais ">" e "<" e os substitui por "<=" e ">=" para contar os pontos apenas quando a bola bate na barra
		if (x==1 && (y<=n+4) )
		    {
			  if (x==1 && (y>=n) )
			   {
			     pontos1++;
		       }
		    }



		//PONTOS COMPUTADOR
		if (x==1 && (y>n+4) )
		    {
			  //se a bola ("x" da bola) chegar na coluna 1 e ("y" da bola) estiver em baixo do desenho da barra o computador ganha 1 ponto
			  pontos2++;
		    }
		if (x==1 && (y<n) )
			   {
			     //se a bola ("x" da bola) chegar na coluna 1 e ("y" da bola) estiver em cima do desenho da barra o computador ganha 1 ponto
				 pontos2++;
		       }

		//LIMITE DE PONTUAÇÃO
		if (pontos1==4)
		{
		   //Se o jogador 1 rebater a bola 4 vezes ele ganha
		   vence1();
		}

		if(pontos2==2)
		{
          // se o jogador 1 deixar a bola passar 2 vezes o computador ganha
		  vencecomp();
		}

	}

		//QUANDO APERTA UMA TECLA SAI DO "while(!_kbhit)" E ENTRA AQUI
		//MOVIMENTO DAS BARRAS
		//inspirado do site: http://www.unidev.com.br/index.php?/topic/42577-linguagem-c-consegue-fazer-2-coisas-ao-mesmo-tempo/
		if(_kbhit!=0)
        {
           switch(getch()) {

                           //MOVIMENTO DA BARRA DA ESQUERDA,119="w" (VAI PARA CIMA) E 115="s" (VAI PARA BAIXO)
                           case 119: {
                                if(n <= 1)
                                {
                                  break;  //A barra para se chegar na linha 1
                                }
                                else
                                {
                                  gotoxy(m+1,n+4); //b+4 vai pra 4 posições abaixo do b e apaga o rastro
                                  printf("%c ",8); //8 na tabela ascii é equivalente ao BackSpace, apaga e da um espaço
                                  n--; //n perde posições e sobe
                                  break;
                                 }
                             }
                           case 115: {
                                if(n >= 15) //quando o b(o inicio da barra)=15 a barra de comprimento=5 alcança o limite da tela=20
                                {
                                  break; //a barra para se b=15
                                }
                                else
                                {
                                  gotoxy(m+1,n); //vai para uma posição a frente da barra
                                  printf("%c ",8);//8 na tabela ascii é equivalente ao BackSpace, apaga a barra e da um espaço
                                  n++; //b ganha posições e desce
                                  break;
                                }
                              }


                           case 27: //27="Esc"
						   {
						    system("cls"); //limpa a tela
						     exit(1); // se apertar "Esc" o jogo para
						   }

                      }
                }
            }

}



main()
{
	menu();
	system("PAUSE");
}
