### **Segue-se uma explicação detalhada do código.** 

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





