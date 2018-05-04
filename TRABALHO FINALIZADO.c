#include <stdio.h>
#include<locale.h>

int main()
{ 
	setlocale(LC_ALL,"Portuguese");
	//menu
	char op;
	float saldo=0;
	//saque
	float saque=0,v=0,limite=0,juros=0,lins=0; 
	//deposito
	float deposito=0;
	//emprestimo
	float emprestimo=0,pagamento=0,v_emprestimo=0;
	int  cont_op=0,cont_emprestimo=0;	
	
	printf("Entre com o saldo inicial da sua conta:");
	scanf("%f",&saldo);
	fflush(stdin);

	do
	{	
		//contando a quantidade de parcelas para serem descontadas
		cont_op++;
		// quando a quantidade de operação dividida por 5 der resto 0 e quando for menor ou igual a 25 desconte a porcela do emprestimo
		if((cont_emprestimo==1) && (cont_op % 5 == 0) && (cont_op<= 25))
		{
			saldo-=pagamento; // variavel pagamento que consta quando acessar o emprestimo
			printf("Desconto Emprestimo Automatico Realizado! \n Saldo em Conta = R$ %.2f",saldo);			
		}
		else // Quando não tiver mais parcelas valor do emprestimo vai ser 0, então poderá realizar outro emprestimo;
		{	
			if(cont_op >25)
			{
				cont_emprestimo=0; // zero o contador do emprestimo para que novo emprestimo seja realizado!
				printf("\n Emprestimo Pago! Consulte seu novo saldo de Emprestimo!");
				printf("\n Saldo = R$ %.2f",saldo);
			}
		}
	
		printf("\n \n ************************************************************** \n \n ");
		printf("\n \n Selecione a opcao desejada:\n (S)aque\n (D)eposito\n (E)mprestimo\n (A)Saida: ");
		scanf("%c",&op);
					
		printf("\n \n ************************************************************** \n \n ");
		fflush(stdin);

		switch(op)
		{
			case's': //saque
				printf(" \n Entre com o valor a ser sacado: "); scanf("%f",&v);			 
				fflush(stdin);
				saque = saldo-v; // saldo atual - o valor que o usuario deseja retirar
				
				if((saque<-1000)) // caso ultrapasse o valor negativo de -1000,00
				{
					printf("\n Ultrapassou o Limite de Saldo Negativo Disponivél! \n Saque e Emprestimo Bloqueados! \n Por favor Deposite!");
					saldo=-1000; // ele receberá  -1000,00, e não deixará ultrapassar o valor
					printf("\n Saldo = R$ %.2f ",saldo); // lendo o saldo anterior ,sem modificações ,pois ultrapassou o limite do lins
				}
				else
				{
					if(saque<0) // caso o saque de valor negativo no saldo
					{
						printf("\n Saldo Negativo! \n Entrou no Limite Especial de até R$ 1000,00 \n");
						printf("\n Cobraremos 1% de Juros em cada operação realizada! \n");
						limite=1000;
						 
						saldo = limite + saque; // saque, menos o limmite especial
						lins = saldo-limite; // valor do lins
						juros= lins * 0.01; // o juros em cima do saldo em conta
						saldo = lins+juros;  // juros  em cima do limite especial
						printf("\n Lins = R$ %.2f ",lins);
						printf("\n Juros = R$ %.2f ",juros);
						printf("\n Saldo em Conta = R$ %.2f ",saldo);
					}
					else
					{
						if(saque<=saque)
						{	
							// o saque sem precisar do lins 
							saldo=saque;
							printf("\n O valor desejado para saque: R$ %.2f",v);
							printf("\n Saldo Atual: R$ %.2f",saldo);
						}
					}
				}
				printf("\n \n ************************************************************** \n \n ");
			break;
		
			case 'd': // deposito
				printf("Digite o Valor do Deposito:"); scanf("%f",&deposito);
				fflush(stdin);
				
				if(deposito<0) //Não pode depositar valor negativo
				{
					printf(" Deposite Valor Positivo! \n");
				}
				else // depositando valor positivo
				{
					saldo+=deposito;
					printf(" Saldo = R$ %.2f",saldo);
				}
				if(saldo<0) // ainda cobrando juros ,porque mesmo com o deposito o saldo ainda continua negativo
				{
					saldo=saldo*1.01;
					printf("\n Ajuste Com Juros%.2f",saldo);
				}
				printf("\n \n ************************************************************** \n \n ");
			break;
			
			case 'e': //emprestimo
				cont_emprestimo++;
				cont_op=0; // quando entrar no emprestimo o loop da op 0 .. assim vai contar até 25
				if(saldo<0) // não pode obter emprestimo com o saldo negativo
				{
					printf("\n Sem Limite p/ Emprestimo! \n Por favor Deposite!");
					saldo=saldo*1.01; // cobrando juros pelo saldo negativo
					printf("\n Saldo = R$ %.2f ",saldo); // lendo o saldo anterior ,sem modificações ,pois ultrapassou o limite do lins
				}
				else
				{					
					if(cont_emprestimo == 1) // se tiver apenas 1 emprestimo faça
					{
						emprestimo=saldo*0.40;
						printf("Você tem até R$ %.2f de Emprestimo.\n",emprestimo);
						printf(" Qual o Valor do Emprestimo:"); scanf("%f",&v_emprestimo);
						fflush(stdin);
						
						if( v_emprestimo <= emprestimo)  	// se o valor do emprestimo for menor ou igual que 40% do saldo, 
						{ //sem esse if ele não da a oportunidade do usuario escolher quanto ele quer de emprestimo ,ai da logo os 40%
							juros = v_emprestimo*0.10; 
							v_emprestimo+=juros;
							pagamento=v_emprestimo/5;
							saldo+=emprestimo;
							printf("\n Com Juros = R$ %.2f \n Saldo = %.2f",juros ,saldo);
							printf("\n Desconto = R$ %.2f \n",pagamento);
						}
						else // se o emprestimo for maior que o valor disponivél
						{
							printf("\n Não pode ser realizado! \n");
						}
					}
					else // se não peça para quitar o emprestimo anterior
					{
						printf("\n\n POR FAVOR QUITE O SEU EMPRESTIMO ANTERIOR! \n");
						printf(" Quite essas Parcelas de R$ %.2f",pagamento);
					}
			}
				printf("\n \n ************************************************************** \n \n ");
			break;
			
			case 'a': //saida
				if(saldo<0) // ainda cobrando juros ,caos o saldo ainda esteja negativo
				{
					saldo=saldo*1.01;
					printf("\n Saldo Final = R$ %.2f ",saldo);
				}
				else
				{
					printf("*** Obrigada pela preferência! *** \n");	
					saldo=saldo;
					printf("Saldo Final = R$ %.2f",saldo);
				}
			break;
		
			default:
				printf("Digite a Opção Correta!! ");
			break;
		}
	}
	while(op!='a');

return 0;
}
