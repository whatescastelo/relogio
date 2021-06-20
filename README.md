### **Explicação detalhada do código:** 

Os comandos 

`#include <LiquidCrystal.h>`

`LiquidCrystal lcd(12, 11, 5, 4, 3, 2);`

são responsáveis por incluir no código do TinkerCAD as bibliotecas necessárias para usar o LCD.

O comando `void setup()` é um função que é executada apenas uma vez quando o programa começa a funcionar. 

`void setup() {`

  `lcd.begin(16, 2);` 
  
  `Serial.begin(9600);`
  
  `pinMode(13, OUTPUT);`
  
`}`

Dentro do `void setup()`, há o comando `lcd.begin(16, 2);` que configura visor do LCD a ter 16 colunas e  2 linhas. 

O comando `Serial.begin(9600)` é responsável pela velocidade de bits por segundo que serão transmitidos através do monitor serial. Neste caso, esse valor corresponde a 9600 bits por segundo, que é o padrão para o arduino e adequado para a utilização neste projeto. 

Já o `pinMode(13, OUTPUT)` configura o pino 13 do Arduino como saída de corrente. Esse pino está ligado à entrada do Piezo e é responsável por ativá-lo quando a hora mostrada no visor for igual ao horário programado no alarme.

Após a função `void setup()`, os próximos comandos são os

`String stringAuxiliar;`

`byte hora=0, minuto=0, seg=0, horaAlarme=0, minAlarme=10;`

O comando `String stringAuxiliar;` define a variável “stringAuxiliar;” como sendo uma variável do tipo String. Essa variável será muito útil ao longo do código, pois será responsável pelo valor apresentado no visor do LDC.

O `byte hora=0, minuto=0, seg=0, horaAlarme=0, minAlarme=10;` é responsável pelos 
valores iniciais da hora, minuto e segundo; além da hora e minuto que o alarme, que no caso é o Piezo, deve soar. Aqui a hora, minuto e segundo são 0, mas podem receber quaisquer valores e esses valores serão atribuídos a hora e minuto mostrado no visor. Da mesma forma, o horaAlarme e o minAlarme recebem a hora e o minuto, respectivamente, do alarme. Nesse caso, como a hora e o minuto estão programados como 0, o minuto do alarme está 10 para que ele não seja ativado imediatamente após o programa começar a funcionar. Porém, o usuário pode programar essas variáveis com os valores que desejar. Na verdade, essa é a intenção.    

Após esses comandos, é iniciada a função `void loop()`, que é onde os comandos colocados nela serão executados infinitamente em looping enquanto o programa estiver funcionando.

O primeiro comando colocado dentro dela é o

`if (hora==horaAlarme && minuto==minAlarme){`

   `tone(13, 200, 100);` 
   
 `}`

Esse comando faz com que o Piezo seja ativado, ou seja, que o alarme soe, quando a hora e o minuto mostrados no visor LCD for igual a hora e o minuto que o alarme foi programado. É usada a função if , pois caso essa condição não seja verdadeira, os códigos dentro do if são ignorados e o Piezo não recebe a corrente vinda do pino 13.

Para que o relógio interaja com o monitor serial, é colocado também os códigos:

`if (Serial.available()){`

` hora = Serial.parseInt();`

`Serial.println(hora);` 
  
  `}`

Esse comando avalia se algum valor foi enviado pelo monitor serial do TinkerCAD. Caso o 
usuário digite um valor e clique em enviar ou enter, ela será atribuída à hora. Ou seja,
independente da hora que esteja sendo mostrada no visor do LCD, ela será trocada pelo valor que o usuário colocou através da porta serial. Se esse valor for maior que 23, a hora receberá 
00. O `Serial.println(hora);` serve apenas para mostrar no Monitor serial o valor que o usuário digitou na porta serial, para que ele tenha certeza que digitou o valor correto.

O comando `lcd.setCursor(5, 0);` serve para posicionar o cursor na coluna 5 e na primeira linha. Isso faz com que a hora seja mostrada no centro do visor do LCD.
 Os próximos comandos do código são
 
 `stringAuxiliar = String(hora);`
 
  `if (hora<10){`
  
  `stringAuxiliar = String("0"+stringAuxiliar);`  
    
  `}`
  
  `lcd.print(stringAuxiliar);`
  
  O `stringAuxiliar = String(hora);` faz a variável stringAuxiliar receber a hora, que foi programada inicialmente em byte, em formato string. Isso é importante, pois, nas próximas linhas do código, a hora precisará ser tratada como número, mas para mostrar no visor do LCD, ela precisa estar no formato string
  
  A função if serve para verificar se a hora é menor que 10. Caso essa condição seja verdadeira, a variável `stringAuxiliar` receberá, antes do valor da hora, o número 0. Isso fará com que a hora tenha sempre dois números. Por exemplo, se a hora for 6, será mostrado “06”.

O comando `lcd.print(stringAuxiliar);` é usado para mostrar o valor da hora no visor do LCD. Lembrando que o valor da hora está armazenado na variável stringAuxiliar.

Após esses comandos é colocado o comando `lcd.print(":");`, que serve apenas para mostrar no visor do LCD dois pontos (:). Esses dois pontos serão responsáveis por separar a hora do minuto.

Os próximos comandos do codigo são:

`stringAuxiliar = String(minuto);`

 ` if (minuto<10){`
 
  `	stringAuxiliar = String("0"+stringAuxiliar);`
  
  `}`
  
  `lcd.print(stringAuxiliar);`
  
  `delay(1000);`
  
  O `stringAuxiliar = String(minuto);` faz a variável stringAuxiliar receber o minuto, que foi programada inicialmente em byte, em formato string, pelos mesmos motivos explicados anteriormente no caso da hora.
  
  O if é usado para verificar se o valor do minuto é menor que 10. Se essa condição for verdadeira, a variável `stringAuxiliar` receberá, antes do valor do minuto, o número 0. Isso fará com que o minuto tenha sempre dois números. Por exemplo, se for 8, será mostrado “08”.

O comando `lcd.print(stringAuxiliar);`, assim como no caso da hora, é usado para mostrar o valor do minuto no visor do LCD. Esse valor será mostrado depois da hora e dos dois pontos (:). Por exemplo, se a hora for 14 e o minuto 7, será mostrado “14:07”.

O `delay(1000);` faz com que o looping, que ocorre muito rapidamente, ocorra de um em um segundo. Entre outras palavras, ele faz com que o programa espere 1 segundo para ler a próxima linha de código. Isso será muito importante para que a hora seja mostrada corretamente, e os segundos contados de um em um, a cada novo looping. 

Por fim, as últimas linhas de código são

`seg++;`

`if (seg>59){`

 `minuto++;`
 
  `seg=0;`
  
  `}`
  
  `if (minuto>59){`
  
 `hora++;`
 
 `minuto=0;`
 
 `}`
 
 `if(hora>23){`
 
  `hora=0;`
  
  `}`

O `seg++` faz com a valor do segundo seja acrescido de 1 a cada looping, que como vimos irá ocorrer de um em um segundo. Apesar de não ser mostrado no Visor do LCD, os segundos estão sendo contados.  

O comando `if (seg>59)` é usado aqui para quando a contagem dos segundos chegar a 60, o minuto ser acrescido de 1, ou seja, soma-se 1 ao seu valor. Essa alteração no minuto será mostrado no visor. Também, cada vez que o valor do segundo chegar a 60, ele receberá novamente o valor 0.
  
A função `if (minuto>59)` faz com que quando o valor do minuto chegue a 60, some-se 1 ao valor da hora, e o valor do minuto se torne 0 novamente, iniciando assim uma nova contagem.
  
Por fim, a função `if(hora>23)` é usada para fazer com que a hora se torne “0” quando o seu valor for 24, e assim começar a contagem da hora novamente, a partir do 0.

  
  
  
  
  
  
  
  
  
  
  
  
  

 
 
 
 
 
 




